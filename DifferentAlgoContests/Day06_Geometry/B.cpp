//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
////Struct Vector is equal struct Point
//
//struct Vector {
//    ll x, y;
//    Vector() : x(0), y(0) {}
//    Vector(ll x, ll y) : x(x), y(y) {}
//    Vector(Vector a, Vector b) {
//        x = b.x - a.x;
//        y = b.y - a.y;
//    }
//    ll operator*(Vector v) {
//        return x * v.y - y * v.x;
//    }
//    double len() {
//        return sqrt(x * x + y * y);
//    }
//    Vector operator-() {
//        return Vector(-x, -y);
//    }
//};
//
//bool operator<(Vector a, Vector b) {
//    if (a.x == b.x) {
//        return a.y < b.y;
//    }
//    return a.x < b.x;
//}
//
//struct Line {
//    ll a, b, c;
//    Line() : a(0), b(0), c(0) {}
//    Line(Vector p1, Vector p2) {
//        a = p2.y - p1.y;
//        b = p1.x - p2.x;
//        c = -(a * p1.x + b * p1.y);
//    }
//};
//
//ll cross_product(Vector a, Vector p1, Vector p2) {
//    Vector v1(a, p1);
//    Vector v2(a, p2);
//    return v1 * v2;
//}
//
//double dist(Vector a, Vector b) {
//    return Vector(a, b).len();
//}
//
//double dist(Line l, Vector p) {
//    return (l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
//}
//
//vector<Vector> get_convex_hull(vector<Vector> &v, int n) {
//    Vector in_hull(1e12, 1e12);
//    for (int i = 0; i < n; ++i) {
//        in_hull = min(in_hull, v[i]);
//    }
//    sort(v.begin(), v.end(), [in_hull](Vector a, Vector b) {
//        if (cross_product(in_hull, a, b) == 0) {
//            return dist(in_hull, a) < dist(in_hull, b);
//        }
//        return cross_product(in_hull, a, b) > 0;
//    });
//    v.push_back(v[0]);
//
//    vector<Vector> hull = {v[0], v[1]};
//    for (int i = 2; i < n + 1; ++i) {
//        while (hull.size() > 2 && cross_product(*(hull.rbegin() + 1), hull.back(), v[i]) <= 0) {
//            hull.pop_back();
//        }
//        hull.push_back(v[i]);
//    }
//    hull.pop_back();
//    return hull;
//}
//
//bool cmp(pair<Vector, Vector> a, pair<Vector, Vector> b) {
//    Vector va(a.first, a.second);
//    Vector vb(b.first, b.second);
//    bool ta = (va.y > 0 || (va.y == 0 && va.x >= 0));
//    bool tb = (vb.y > 0 || (vb.y == 0 && vb.x >= 0));
//    if (ta == tb) {
//        return va * vb >= 0;
//    }
//    return ta > tb;
//}
//
//Vector get_furthest(vector<pair<Vector, Vector>> &sorted, Vector v) {
//    int ind = upper_bound(sorted.begin(), sorted.end(), make_pair(Vector(), Vector(v.x, v.y)), cmp) - sorted.begin();
//    if (ind < (int)sorted.size()) {
//        return sorted[ind].first;
//    } else {
//        return sorted[ind - 1].second;
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<Line> roads(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> roads[i].a >> roads[i].b >> roads[i].c;
//    }
//    vector<Vector> stations(m);
//    for (int i = 0; i < m; ++i) {
//        cin >> stations[i].x >> stations[i].y;
//    }
//
//    auto hull = get_convex_hull(stations, m);
//    m = hull.size();
//    hull.push_back(hull[0]);
//    vector<pair<Vector, Vector>> sorted;
//    for (int i = 0; i < m; ++i) {
//        sorted.push_back({hull[i], hull[i + 1]});
//    }
//    sort(sorted.begin(), sorted.end(), cmp);
//
//    vector<int> in_city;
//    for (int i = 0; i < n; ++i) {
//        Vector toward(roads[i].b, -roads[i].a);
//        auto p1 = get_furthest(sorted, toward);
//        auto p2 = get_furthest(sorted, -toward);
//        double d1 = dist(roads[i], p1);
//        double d2 = dist(roads[i], p2);
//        if (d1 * d2 <= 0) {
//            in_city.push_back(i);
//        }
//    }
//
//    cout << in_city.size() << endl;
//    for (int i : in_city) {
//        cout << i + 1 << " ";
//    }
//    cout << endl;
//}
