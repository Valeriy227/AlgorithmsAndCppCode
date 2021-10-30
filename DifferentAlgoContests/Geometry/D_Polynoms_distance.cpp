#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Point {
    ll x, y;

    Point() {}
    Point(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
};

bool operator<(Point a, Point b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

struct Vector {
    ll x, y;

    Vector() {}
    Vector(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    ll operator*(Vector v) {
        return x * v.y - v.x * y;
    }
    ll operator^(Vector v) {
        return x * v.x + y * v.y;
    }
};

struct Line {
    ll a, b, c;

    Line() {}
    Line (ll aa, ll bb, ll cc) {
        a = aa;
        b = bb;
        c = cc;
    }
    Line(Point p1, Point p2) {
        b = -p2.x + p1.x;
        a = p2.y - p1.y;
        c = -a * p1.x - b * p1.y;
    }
};

ld dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}

ld dist(Point p, Line l) {
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

int sign(ll x) {
    if (x < 0) {
        return -1;
    }
    return 1;
}

int get_extreme(vector<Point> &hull, int n, Point from) {
    int s = sign(Vector(from, hull[0]) * Vector(from, hull[1]));
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int t = sign(Vector(from, hull[mid]) * Vector(from, hull[mid + 1]));
        if (s != t) {
            r = mid;
        }
        else if (sign(Vector(from, hull[0]) * Vector(from, hull[mid])) == s) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return r;
}

ld dist(Point p, Point a, Point b) {
    if ((Vector(a, p) ^ Vector(a, b)) < 0 ||
        (Vector(b, p) ^ Vector(b, a)) < 0) {
        return min(dist(a, p), dist(b, p));
    }
    else {
        return dist(p, Line(a, b));
    }
}

ld nearest(vector<Point> &points, int l, int r, Point from) {
    if (l == r) {
        return 1e20;
    }
    while (l + 2 < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ld val1 = dist(from, points[m1], points[m1 + 1]);
        ld val2 = dist(from, points[m2], points[m2 + 1]);
        if (val1 < val2) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    ld res = 1e20;
    for (int i = l; i < r; ++i) {
        res = min(res, dist(from, points[i], points[i + 1]));
    }
    return res;
}

ld dist(int n, int m, vector<Point> &a, vector<Point> &b) {
//    cout << n << " " << m << " start!" << endl;
    ld res = 1e20;
    for (int i = 0; i < n; ++i) {
//        cout << i << ": " << endl;
        if (m == 1) {
            res = min(res, dist(a[i], b[0]));
        }
        else if (m == 2) {
            res = min(res, dist(a[i], b[0], b[1]));
        }
        else {
            int ind1 = get_extreme(b, m, a[i]);
//            cout << ind1 << endl;
            reverse(b.begin(), b.end());
            int ind2 = m - get_extreme(b, m, a[i]);
//            cout << ind2 << endl;
            reverse(b.begin(), b.end());

            if (ind1 == ind2) {
                ind1 = 0;
            }
//            cout << "sz: " << b.size() << endl;
            res = min(res, nearest(b, 0, ind1, a[i]));
//            cout << "1 --- " << res << endl;
            res = min(res, nearest(b, ind1, ind2, a[i]));
//            cout << "2 --- " << res << endl;
            res = min(res, nearest(b, ind2, m, a[i]));
//            cout << "3 --- " << res << " " << ind2 << " " << m + 1 << endl;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    a.push_back(a[0]);

    int m;
    cin >> m;
    vector<Point> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    b.push_back(b[0]);

    ld ans = dist(m, n, b, a);
    ans = min(ans, dist(n, m, a, b));
    cout << fixed << setprecision(15) << ans << endl;
}
