//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//bool cross(vector<int> &a, vector<int> &b, bool f1, bool f2) {
//    if (f1) {
//        if (f2) {
//            return ((a[0] <= b[0] && b[0] <= a[2]) ||
//                    (a[0] <= b[2] && b[2] <= a[2]) ||
//                    (b[0] <= a[0] && a[0] <= b[2]));
//        }
//        else {
//            return (a[0] <= b[0] && b[0] <= a[2]) &&
//                   (b[1] <= a[1] && a[1] <= b[3]);
//        }
//    }
//    else {
//        if (f2) {
//            return (a[0] <= b[0] && b[0] <= a[2]) &&
//                   (b[1] <= a[1] && a[1] <= b[3]);
//        }
//        else {
//            return 1;
//        }
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    int k;
//    cin >> k;
//    ll ans = 0;
//    vector<vector<int>> vert, hor;
//    for (int i = 0; i < k; ++i) {
//        vector<int> v(4);
//        cin >> v[0] >> v[1];
//        v[2] = v[0];
//        v[3] = v[1];
//        char c;
//        cin >> c;
//        if (c == 'W') {
//            ans += v[0];
//            v[0] = 1;
//            hor.push_back(v);
//        }
//        else if (c == 'N') {
//            ans += m - v[1] + 1;
//            v[3] = m;
//            vert.push_back(v);
//        }
//        else if (c == 'E') {
//            ans += n - v[0] + 1;
//            v[2] = n;
//            hor.push_back(v);
//        }
//        else if (c == 'S') {
//            ans += v[1];
//            v[1] = 1;
//            vert.push_back(v);
//        }
//    }
//
//    for (int i = 0; i < hor.size(); ++i) {
//        for (int j = i + 1; j < hor.size(); ++j) {
//            if (hor[i][1] != hor[j][1]) {
//                continue;
//            }
//            int l = max(hor[i][0], hor[j][0]);
//            int r = min(hor[i][2], hor[j][2]);
//            if (r >= l) {
//                ans -= r - l + 1;
//                if (l == hor[i][0]) {
//                    hor[i][0] = r + 1;
//                }
//                else if (l == hor[j][0]) {
//                    hor[j][0] = r + 1;
//                }
//                else if (r == hor[j][2]) {
//                    hor[j][2] = l - 1;
//                }
//                else if (r == hor[i][2]) {
//                    hor[i][2] = l - 1;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < vert.size(); ++i) {
//        for (int j = i + 1; j < vert.size(); ++j) {
//            if (vert[i][0] != vert[j][0]) {
//                continue;
//            }
//            int l = max(vert[i][1], vert[j][1]);
//            int r = min(vert[i][3], vert[j][3]);
//            if (r >= l) {
//                ans -= r - l + 1;
//                if (l == vert[i][1]) {
//                    vert[i][1] = r + 1;
//                }
//                else if (l == vert[j][1]) {
//                    vert[j][1] = r + 1;
//                }
//                else if (r == vert[j][3]) {
//                    vert[j][3] = l - 1;
//                }
//                else if (r == vert[i][3]) {
//                    vert[i][3] = l - 1;
//                }
//            }
//        }
//    }
//
//    vector<unordered_set<ll>> us(vert.size());
//    for (int i = 0; i < vert.size(); ++i) {
//        for (int j = 0; j < hor.size(); ++j) {
//            if (vert[i][1] <= hor[j][1] && hor[j][1] <= vert[i][3] &&
//                hor[j][0] <= vert[i][0] && vert[i][0] <= hor[j][2]) {
//                int x = vert[i][0];
//                int y = hor[j][1];
//                if (us[i].find(((x * 1000000ll) + y)) == us[i].end()) {
//                    ans -= 1;
//                    us[i].insert((x * 1000000ll) + y);
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//}