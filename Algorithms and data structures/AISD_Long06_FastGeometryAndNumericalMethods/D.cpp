#include <bits/stdc++.h>

using namespace std;

// [a1 + v1t, b1 + v1t] [a2 + v2t, b2 + v2t]
// a1 - a2 = v2t - v1t
// t = (a1 - a2) / (v2 - v1)

pair<int, int> cross(int a, int b, int c, int d) {
    return {max(a, c), min(b, d)};
}

pair<double, double> cross(vector<int> x, vector<int> y) {
    if (x[2] == y[2]) {
        auto [l, r] = cross(x[0], x[1], y[0], y[1]);
        if (l <= r) {
            return {0, 1e4};
        } else {
            return {-1, 0};
        }
    } else {
        double l = (double)(x[0] - y[1]) / (y[2] - x[2]);
        double r = (double)(x[1] - y[0]) / (y[2] - x[2]);
        if (l > r) {
            swap(l, r);
        }
        l = max((double) 0, l);
        return {l, r};
    }
}

pair<double, double> get_moment(vector<vector<int>>& v) {
    int n = v.size();
    double lt = 0, rt = 1e4;
    mt19937 gen(2007);
    for (int it = 0; it < 50; ++it) {
        int i = gen() % n;
        int j = gen() % n;

        auto [l, r] = cross(v[i], v[j]);
        lt = max(l, lt);
        rt = min(r, rt);
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            auto [l, r] = cross(v[i], v[j]);
//            lt = max(l, lt);
//            rt = min(r, rt);
//        }
//    }
    return {lt, rt};
}

double f(vector<vector<int>>& v, double t) {
    double l = v[0][0] + v[0][2] * t;
    double r = v[0][1] + v[0][2] * t;

    for (auto& i : v) {
        l = max(l, i[0] + i[2] * t);
        r = min(r, i[1] + i[2] * t);
    }

    return r - l;
}

double get_max(vector<vector<int>>& v, double l, double r) {
    for (int i = 0; i < 50; ++i) {
        double m1 = l + (r - l) / 3;
        double m2 = l + (r - l) / 3 * 2;

        double v1 = f(v, m1);
        double v2 = f(v, m2);

        if (v1 > v2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return f(v, l);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("out.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int& j : v[i]) {
            cin >> j;
        }
    }
    auto [l, r] = get_moment(v);
    if (l > r) {
        cout << 0 << endl;
        return 0;
    }
    cout << fixed << setprecision(15) << get_max(v, l, r) << endl;
//    int n = 1e5;
//    mt19937 gen(0);
//    cout << n << endl;
//    for (int i = 0; i < n; ++i) {
//        int a = gen() % 20000 - 10000;
//        int b = gen() % 20000 - 10000;
//        int v = gen() % 10000;
//        if (a > b) {
//            swap(a, b);
//        }
//        cout << a << " " << b << " " << v << "\n";
//    }
}
