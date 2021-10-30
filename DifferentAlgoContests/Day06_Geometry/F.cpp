#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

struct Point {
    ld x, y;
    Point() : x(0), y(0) {}
    Point(ld x, ld y) : x(x), y(y) {}
};

struct Vector {
    ld x, y;
    Vector() : x(0), y(0) {}
    Vector(ld x, ld y) : x(x), y(y) {}
    Vector(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}
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

Point operator+(Point p, Vector v) {
    return Point(p.x + v.x, p.y + v.y);
}

struct Line {
    ld a, b, c;
    Line() : a(0), b(0), c(0) {}
    Line(Point p1, Point p2) : a(p2.y - p1.y), b(p1.x - p2.x), c(-(a * p1.x + b * p1.y)) {}
};

Point cross(Line l1, Line l2) {
    if (l1.a == 0 && l2.a == 0) {
        return {1e10, 1e10};
    }
    Point res;
    res.y = (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);
    if (l1.a != 0) {
        res.x = -(l1.b * res.y + l1.c) / l1.a;
    } else {
        res.x = -(l2.b * res.y + l2.c) / l2.a;
    }
    return res;
}

ld dist(Point a, Point b) {
    return Vector(a, b).len();
}

struct Circle {
    Point cent;
    ld r;
    Circle() : cent(0, 0), r(0) {}
    Circle(Point p) : cent(p), r(0) {}
    Circle(Point a, Point b) {
        Vector v(a, b);
        v = v * (1.0 / 2);
        r = v.len();
        cent = a + v;
    }
    Circle(Point a, Point b, Point c) {
        Vector v1(a, b);
        v1 = v1 * (1.0 / 2);
        Point mid1 = a + v1;
        Line l1(mid1, mid1 + v1.normal());

        Vector v2(b, c);
        v2 = v2 * (1.0 / 2);
        Point mid2 = b + v2;
        Line l2(mid2, mid2 + v2.normal());

        cent = cross(l1, l2);
        r = dist(cent, a);
    }
};

vector<Point> points;

Circle get_circle(vector<Point> &border) {
    if (border.empty()) {
        return Circle();
    } else if (border.size() == 1) {
        return Circle(border[0]);
    } else if (border.size() == 2) {
        return Circle(border[0], border[1]);
    } else {
        return Circle(border[0], border[1], border[2]);
    }
}

bool is_in_circle(Point p, vector<Point> &border) {
    if (border.empty()) {
        return false;
    }
    Circle c = get_circle(border);
    ld d = dist(c.cent, p);
    return c.r >= d - EPS;
}

bool is_in_circle(Point p, Circle c) {
    ld d = dist(c.cent, p);
    return c.r >= d - EPS;
}

void choose_opt(Point p, vector<Point> &border) {
    if (border.empty()) {
        border.push_back(p);
        return;
    }
    vector<Point> new_border;
    ld best = 1e9;
    for (int i = 0; i < (int)border.size(); ++i) {
        for (int j = i; j < (int)border.size(); ++j) {
            Circle c;
            if (i == j) {
                c = Circle(p, border[i]);
            } else {
                c = Circle(p, border[i], border[j]);
            }
            bool flag = true;
            for (auto chp : border) {
                if (!is_in_circle(chp, c)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (c.r < best) {
                    best = c.r;
                    if (i == j) {
                        new_border = {p, border[i]};
                    } else {
                        new_border = {p, border[i], border[j]};
                    }
                }
            }
        }
    }
    swap(border, new_border);
}

void get_circle(int n, vector<Point> &border) {
    for (int i = 0; i < n; ++i) {
        if (!is_in_circle(points[i], border)) {
            choose_opt(points[i], border);
            get_circle(i, border);
        }
    }
}

int main() {
    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(points.begin(), points.end(), g);
    vector<Point> border;
    get_circle(n, border);
    Circle c = get_circle(border);
    cout << fixed << setprecision(10);
    cout << c.cent.x << " " << c.cent.y << endl;
    cout << c.r << endl;
}
