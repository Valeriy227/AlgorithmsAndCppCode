//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//struct Vector {
//    ll x, y;
//    Vector() : x(0), y(0) {}
//    Vector(Vector a, Vector b) {
//        x = b.x - a.x;
//        y = b.y - a.y;
//    }
//    ll operator*(Vector v) {
//        return x * v.y - y * v.x;
//    }
//};
//
//ll cross_product(Vector a, Vector p1, Vector p2) {
//    Vector v1(a, p1);
//    Vector v2(a, p2);
//    return v1 * v2;
//}
//
//bool is_in_triangle(Vector a, Vector b, Vector c, Vector p) {
//    ll s1 = 0;
//    s1 += abs(cross_product(p, a, b));
//    s1 += abs(cross_product(p, b, c));
//    s1 += abs(cross_product(p, c, a));
//    ll s2 = abs(cross_product(a, b, c));
//    return s1 == s2;
//}
//
//int main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<Vector> ship(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> ship[i].x >> ship[i].y;
//    }
//
//    for (int i = 0; i < m; ++i) {
//        Vector p;
//        cin >> p.x >> p.y;
//        if (cross_product(ship[0], ship[1], p) < 0 &&
//            cross_product(ship[0], ship[n - 1], p) > 0) {
//            continue;
//        }
//        int l = 1, r = n - 1;
//        while (l + 1 < r) {
//            int mid = (l + r) / 2;
//            if (cross_product(ship[0], ship[mid], p) >= 0) {
//                l = mid;
//            } else {
//                r = mid;
//            }
//        }
//        k -= is_in_triangle(ship[0], ship[l], ship[l + 1], p);
//    }
//    if (k <= 0) {
//        cout << "YES" << endl;
//    } else {
//        cout << "NO" << endl;
//    }
//}
