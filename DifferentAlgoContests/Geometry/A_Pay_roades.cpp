//#include <bits/stdc++.h>
//#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//struct Point {
//    ll x, y;
//
//    Point() {}
//    Point(ll xx, ll yy) {
//        x = xx;
//        y = yy;
//    }
//};
//
//bool operator<(Point a, Point b) {
//    if (a.x == b.x) {
//        return a.y < b.y;
//    }
//    return a.x < b.x;
//}
//
//struct Vector {
//    ll x, y;
//
//    Vector() {}
//    Vector(ll xx, ll yy) {
//        x = xx;
//        y = yy;
//    }
//    Vector(Point a, Point b) {
//        x = b.x - a.x;
//        y = b.y - a.y;
//    }
//    ll operator*(Vector v) {
//        return x * v.y - v.x * y;
//    }
//};
//
//struct Line {
//    ll a, b, c;
//
//    Line() {}
//    Line (ll aa, ll bb, ll cc) {
//        a = aa;
//        b = bb;
//        c = cc;
//    }
//    Line(Point p1, Point p2) {
//        b = -p2.x + p1.x;
//        a = p2.y - p1.y;
//        c = -a * p1.x - b * p1.y;
//    }
//};
//
//Vector get_normal(Line l) {
//    return Vector(l.a, l.b);
//}
//
//Vector get_normal(Vector v) {
//    return Vector(v.y, -v.x);
//}
//
//double dist(Point a, Point b) {
//    return sqrt((a.x - b.x) * (a.x - b.x) +
//                (a.y - b.y) * (a.y - b.y));
//}
//
//double dist(Point p, Line l) {
//    return (l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
//}
//
//Point get_farthest(vector<Point> &points) {
//    Point res(1e9, 1e9);
//    for (auto i : points) {
//        res = min(res, i);
//    }
//    return res;
//}
//
//void get_convex_hull(int m, vector<Point> &points, vector<Point> &hull) {
//    auto farthest = get_farthest(points);
//    sort(points.begin(), points.end(), [farthest](Point a, Point b) {
//        if (Vector(farthest, a) * Vector(farthest, b) == 0) {
//            return dist(farthest, a) < dist(farthest, b);
//        }
//        return Vector(farthest, a) * Vector(farthest, b) > 0;
//    });
//
//    hull = {farthest};
//    for (int i = 1; i < m; ++i) {
//        while (hull.size() > 1) {
//            Vector a(hull[hull.size() - 2], hull.back());
//            Vector b(hull.back(), points[i]);
//            if (a * b <= 0) {
//                hull.pop_back();
//            }
//            else {
//                break;
//            }
//        }
//        hull.push_back(points[i]);
//    }
//
//    if (hull.size() > 3) {
//        while (hull.size() > 1) {
//            Vector a(hull[hull.size() - 2], hull.back());
//            Vector b(hull.back(), farthest);
//            if (a * b <= 0) {
//                hull.pop_back();
//            }
//            else {
//                break;
//            }
//        }
//    }
//}
//
//bool cmp(pair<Point, Point> pa, pair<Point, Point> pb) {
//    Vector a(pa.first, pa.second);
//    Vector b(pb.first, pb.second);
//    bool type1 = !(a.y > 0 || (a.y == 0 && a.x >= 0));
//    bool type2 = !(b.y > 0 || (b.y == 0 && b.x >= 0));
//    if (type1 == type2) {
//        return a * b > 0;
//    }
//    return type1 < type2;
//}
//
//Point get_stickly(vector<pair<Point, Point>> &sorted, Vector v, bool flag) {
//    if (sorted.size() == 1) {
//        return (flag ? sorted[0].second : sorted[0].first);
//    }
//
//    pair<Point, Point> pv = {{0, 0}, {v.x, v.y}};
//    int ind = upper_bound(sorted.begin(), sorted.end(), pv, cmp)
//            - sorted.begin();
//    if (ind == 0) {
//        return sorted[ind].first;
//    }
//    return sorted[ind - 1].second;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<Line> lines(n);
//    for (int i = 0; i < n; ++i) {
////        Point a, b;
////        cin >> a.x >> a.y >> b.x >> b.y;
////        lines[i] = {a, b};
//        cin >> lines[i].a >> lines[i].b >> lines[i].c;
//    }
//
//    vector<Point> stations(m);
//    for (int i = 0; i < m; ++i) {
//        cin >> stations[i].x >> stations[i].y;
//    }
//
//    vector<Point> hull;
//    get_convex_hull(m, stations, hull);
//    m = hull.size();
//    vector<pair<Point, Point>> sorted(m);
//    for (int i = 0; i < m; ++i) {
//        if (i == m - 1) {
//            sorted[i] = {hull[i], hull[0]};
//        }
//        else {
//            sorted[i] = {hull[i], hull[i + 1]};
//        }
//    }
//    sort(sorted.begin(), sorted.end(), cmp);
//
//    vector<int> city_roads;
//    for (int i = 0; i < n; ++i) {
//        auto normal = get_normal(lines[i]);
//        auto forward = get_normal(normal);
//        auto backward = Vector(-forward.x, -forward.y);
//
//        Point p1 = get_stickly(sorted, forward, false);
//        Point p2 = get_stickly(sorted, backward, true);
//
//        double dist1 = dist(p1, lines[i]);
//        double dist2 = dist(p2, lines[i]);
//
//        if (dist1 == 0 || dist2 == 0 || dist1 * dist2 < 0) {
//            city_roads.push_back(i + 1);
//        }
//    }
//
//    cout << city_roads.size() << endl;
//    for (int i : city_roads) {
//        cout << i << " ";
//    }
//    cout << endl;
//}
