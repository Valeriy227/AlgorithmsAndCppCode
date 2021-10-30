#include <bits/stdc++.h>
#include <iomanip>

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

struct Circle {
    Vector center;
    ld r;
    Circle(Vector center = {0, 0}, int r = 0) : center(center), r(r) {}
    bool contains(Circle other) {
        auto x = center.x - other.center.x;
        auto y = center.y - other.center.y;
        return x * x + y * y <= r * r;
    }
};

Circle input() {
    int x, y, r;
    cin >> x >> y >> r;
    return Circle(Vector(x, y), r);
}

vector<Vector> cross(Circle a, Circle b) {
    if (a.contains(b) && dist(b.center, a.center) + b.r < a.r) {
        return {};
    }
    if (b.contains(a) && dist(b.center, a.center) + a.r < b.r) {
        return {};
    }
    if (dist(b.center, a.center) > a.r + b.r) {
        return {};
    }

    if (equal(dist(a.center, b.center), 0) && equal(a.r, b.r)) {
        return {{}, {}, {}};
    }

    // if (a.contains(b) && equal(dist(b.center, a.center) + b.r, a.r)) {
    //     return {};
    // }

    // r1^2 = x^2 + t1^2  r2^2 = x^2 + t2^2  t1 + t2 = d -> t2 = d - t1
    // r1^2 - t1^2 = r2^2 - t2^2
    // r1^2 - r2^2 = t1^2 - d^2 + 2dt1 - t1^2
    // t1 = ... / 2d
    Vector ab(a.center, b.center);
    auto t1_len = (a.r * a.r - b.r * b.r + ab.len() * ab.len()) / (2 * ab.len());
    auto w_len = sqrt(a.r * a.r - t1_len * t1_len);

    auto t1 = ab * (1 / ab.len()) * t1_len;
    auto w1 = t1.normal() * (1 / t1_len) * w_len;
    auto w2 = w1 * (-1);

    auto p1 = a.center + t1 + w1;
    auto p2 = a.center + t1 + w2;

    if (equal(dist(p1, p2), 0)) {
        return {p1};
    }

    return {p1, p2};
}

int main() {
    int q;
    cin >> q;
    while (q) {
        q--;

        Circle a = input(), b = input();
        auto res = cross(a, b);

        if (res.size() > 2) {
            cout << -1 << endl;
        } else {
            cout << res.size() << endl;
            for (auto p : res) {
                cout << fixed << setprecision(10) << p.x << " " << p.y << endl;
            }
        }
    }
}
