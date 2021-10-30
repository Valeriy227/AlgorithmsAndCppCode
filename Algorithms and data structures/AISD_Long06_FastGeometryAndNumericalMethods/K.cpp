#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

bool equal(ld a, ld b) {
    return abs(a - b) < EPS;
}

struct Vector {
    ld x, y;
    Vector() : x(0), y(0) {}
    Vector(ld x, ld y) : x(x), y(y) {}
    Vector(Vector a, Vector b) : x(b.x - a.x), y(b.y - a.y) {}
    ld operator*(Vector v) const {
        return x * v.y - y * v.x;
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    Vector operator*(ld k) const {
        Vector res(x * k, y * k);
        return res;
    }
    Vector normal() const {
        return Vector(y, -x);
    }
};

Vector operator+(Vector p, Vector v) {
    return Vector(p.x + v.x, p.y + v.y);
}

struct Line {
    ld a, b, c;
    Line() : a(0), b(0), c(0) {}
    Line(Vector p1, Vector p2) : a(p2.y - p1.y), b(p1.x - p2.x), c(-(a * p1.x + b * p1.y)) {}
};

Vector cross(Line l1, Line l2) {
    if (l1.a == 0 && l2.a == 0) {
        return {1e10, 1e10};
    }
    Vector res;
    res.y = (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);
    if (l1.a != 0) {
        res.x = -(l1.b * res.y + l1.c) / l1.a;
    } else {
        res.x = -(l2.b * res.y + l2.c) / l2.a;
    }
    return res;
}

ld dist(Vector a, Vector b) {
    return Vector(a, b).len();
}

double rand_double(double a, double b) {
    static default_random_engine gen;
    static uniform_real_distribution<double> distr(a, b);
    return distr(gen);
}

Vector randp(double n) {
    return {rand_double(-n/2, n/2), rand_double(-n/2, n/2)};
}

Vector transform(Vector a, Vector b, Vector p) {
    Vector ab(a, b);
    Vector ap(a, p);
    auto triangle_square = ap * ab / 2;
    if (triangle_square < 0) {
        return {1e5, 1e5};
    }
    auto d = triangle_square * 2 / ab.len();

    auto norm = ab.normal();
    norm = norm * (1 / norm.len());
    norm = norm * d;

    return p + norm * -2;
}

struct Segment {
    Vector p1, p2;
    int ind;
    inline static double x_scan;
    Segment() : p1(), p2(), ind(0) {}
    Segment(Vector p1, Vector p2) : p1(p1), p2(p2) {}
    Segment(Vector p1, Vector p2, int ind) : p1(p1), p2(p2), ind(ind) {}
    bool operator<(Segment& other) {
        auto y1_scan = cross_with_scanline();
        auto y2_scan = other.cross_with_scanline();
        return make_tuple(-y1_scan, ind) < make_tuple(-y2_scan, other.ind);
    }
    double cross_with_scanline() {
        auto tmp = (p1.x - x_scan) * (p1.y - p2.y) / (p1.x - p2.x);
        return p1.y - tmp;
    }
};

//--------------------start of dd-------------------

random_device rd;
mt19937 rnd(rd());

struct Node {
    int size;
    Segment value;
    int priority;
    Node* left;
    Node* right;

    Node(Segment val) : size(1), value(val), priority(rnd()), left(nullptr), right(nullptr) {}
};

//int size(Node* root) {
//    if (root) {
//        return root->size;
//    }
//    return 0;
//}
//
//void relax(Node* root) {
//    if (root) {
//        root->max = size(root->left) + size(root->right) + 1;
//    }
//}

pair<Node*, Node*> split(Node* root, Segment& val) {
    if (!root) {
        return {0, 0};
    }
//    if (k == 0) {
//        return {0, root};
//    }
    if (val < root->value) {
        auto [left_res, right_res] = split(root->left, val);
        root->left = right_res;
//        relax(root);
        return {left_res, root};
    } else {
        auto [left_res, right_res] = split(root->right, val);
        root->right = left_res;
//        relax(root);
        return {root, right_res};
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
//        relax(left);
        return left;
    } else {
        right->left = merge(left, right->left);
//        relax(right);
        return right;
    }
}

Node* insert(Node* root, Segment seg) {
    auto [l, r] = split(root, seg);
    return merge(merge(l, new Node(seg)), r);
}

Node* erase(Node* root, Segment seg) {
    auto [l1, r1] = split(root, seg);
    seg.ind--;
    auto [l2, r2] = split(l1, seg);
    return merge(l2, r1);
}

Segment get_destination(Node* root, double y) {
    if (!root) {
        return {{-1e6, -1e6}, {1e6, -1e5}, -1};
    }
    if (y > root->value.cross_with_scanline()) {
        auto seg = get_destination(root->left, y);
        if (root->value < seg) {
            seg = root->value;
        }
        return seg;
    } else {
        return get_destination(root->right, y);
    }
}

//-------------------end of dd------------------

struct Event {
    int status;
    int x;
    int ind;
    Event(int status, int x, int ind) : status(status), x(x), ind(ind) {}
    bool operator<(Event& other) {
        return make_tuple(x, status, ind) < make_tuple(other.x, other.status, other.ind);
    }
};

void dfs(vector<int>& g, vector<int>& drop, int cv) {
    if (drop[g[cv]] < -1e6) {
        dfs(g, drop, g[cv]);
    }
    drop[cv] = drop[g[cv]];
}

int main() {
    vector<Event> events;

    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].p1.x >> segments[i].p1.y;
        cin >> segments[i].p2.x >> segments[i].p2.y;
        segments[i].ind = i;
        if (segments[i].p1.x > segments[i].p2.x) {
            swap(segments[i].p1, segments[i].p2);
        }
        events.emplace_back(0, segments[i].p1.x, i);
        events.emplace_back(2, segments[i].p2.x, i);
    }
    int m;
    cin >> m;
    vector<int> xs(m);
    for (int i = 0; i < m; ++i) {
        cin >> xs[i];
        events.emplace_back(1, xs[i], i);
    }

    sort(events.begin(), events.end());

    vector<vector<int>> coins(n);
    vector<int> g(n, -1);

    vector<int> ans(m, -1e7);
    vector<int> drop(n, -1e7);

    Node* root = nullptr;
    for (auto& event : events) {
        Segment::x_scan = event.x;
        if (event.status == 1) {
            auto seg = get_destination(root, 1e7);
            if (seg.ind == -1) {
                ans[event.ind] = event.x;
            } else {
                coins[seg.ind].push_back(event.ind);
            }
        } else if (event.status == 0) {
            if (segments[event.ind].p1.y < segments[event.ind].p2.y) {
                auto seg = get_destination(root, segments[event.ind].p1.y);
                if (seg.ind == -1) {
                    drop[event.ind] = event.x;
                } else {
                    g[event.ind] = seg.ind;
                }
            }
            root = insert(root, segments[event.ind]);
        } else {
            if (segments[event.ind].p1.y > segments[event.ind].p2.y) {
                auto seg = get_destination(root, segments[event.ind].p2.y);
                if (seg.ind == -1) {
                    drop[event.ind] = event.x;
                } else {
                    g[event.ind] = seg.ind;
                }
            }
            root = erase(root, segments[event.ind]);
        }
    }


    for (int i = 0; i < n; ++i) {
        if (drop[i] < -1e6)  {
            dfs(g, drop, i);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int ind : coins[i]) {
            ans[ind] = drop[i];
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
