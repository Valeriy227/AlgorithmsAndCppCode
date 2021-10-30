#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

bool equal(double a, double b) {
    return abs(a - b) < EPS;
}

struct Vector {
    double x, y;
    Vector() : x(0), y(0) {}
    Vector(double x, double y) : x(x), y(y) {}
    Vector(Vector a, Vector b) : x(b.x - a.x), y(b.y - a.y) {}
    double operator*(Vector v) const {
        return x * v.y - y * v.x;
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    Vector operator*(double k) const {
        Vector res(x * k, y * k);
        return res;
    }
    Vector normal() const {
        return Vector(y, -x);
    }
};

using Point = Vector;

Vector operator+(Vector p, Vector v) {
    return Vector(p.x + v.x, p.y + v.y);
}

double rand_double(double a, double b) {
    static default_random_engine gen;
    static uniform_real_distribution<double> distr(a, b);
    return distr(gen);
}

Vector randp(double n) {
    return {rand_double(-n, n), rand_double(-n, n)};
}

Vector transform(Vector a, Vector b, Vector p, bool is_forw) {
    Vector ab(a, b);
    Vector ap(a, p);
    auto triangle_square = ap * ab / 2;

    if (is_forw) {
        if (triangle_square >= 0) {
            return p;
        }
    } else {
        if (triangle_square < 0) {
            return {1e8, 1e8};
        }
    }

    auto d = triangle_square * 2 / ab.len();

    auto norm = ab.normal();
    norm = norm * (1 / norm.len());
    norm = norm * d;

    return p + norm * -2;
}

Point transform(vector<vector<Point>>& v, int mask, bool is_forw, Point p) {
    if (is_forw) {
        for (int i = 0; i < v.size(); ++i) {
            p = transform(v[i][0], v[i][1], p, true);
        }
    } else {
        for (int i = (int)v.size() - 1; i >= 0; --i) {
            if (mask & (1 << i)) {
                p = transform(v[i][0], v[i][1], p, false);
            }
        }
    }
    return p;
}

bool equal(Point a, Point b) {
    return equal(a.x, b.x) && equal(a.y, b.y);
}

int main() {
//    int b = 300;
    int n, k;
    cin >> n >> k;
    vector<vector<Vector>> v(k, vector<Vector>(2));
    for (int i = 0; i < k; ++i) {
        cin >> v[i][0].x >> v[i][0].y >> v[i][1].x >> v[i][1].y;
    }

    auto c_tr = transform(v, 0, true, {0, 0});
//    reverse(v.begin(), v.end());

    int total = 0;
    int ok = 0;
    clock_t start = clock();
    while (true) {
        for (int i = 0; i < 100; ++i) {
            total++;
            auto p = c_tr + randp(n);
//            if (-15 <= p.x && p.x <= -10 && -5 <= p.y && p.y <= 0) {
//                cout << p.x << " " << p.y << endl;
//            }
            for (int mask = 0; mask < (1 << k); ++mask) {
                auto start = transform(v, mask, false, p);

                if (-n <= 2 * start.x && start.x * 2 <= n && -n <= start.y * 2 && start.y * 2 <= n) {
                    auto end = transform(v, mask, true, start);
                    if (equal(p, end)) {
                        ok++;
                        break;
                    }
//                    cout << first_p.x << " " << first_p.y << endl;
                }
            }
        }
        if ((double)(clock() - start) / CLOCKS_PER_SEC > 2.97) {
            break;
        }
    }

    auto s1 = ok * n * 2. * n * 2 / total;
    auto s2 = n * n;
    auto percentage = 100 * s1 / s2;
    cout << round(percentage) << endl;
}
