//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n;
//vector<vector<vector<ll>>> a;
//
//int next(int ind) {
//    return ((ind + 1) | ind);
//}
//
//int prev(int ind) {
//    return ((ind + 1) & ind) - 1;
//}
//
//void add(int x, int y, int z, int k) {
//    for (int i = x; i < n; i = next(i)) {
//        for (int j = y; j < n; j = next(j)) {
//            for (int l = z; l < n; l = next(l)) {
//                a[i][j][l] += k;
//            }
//        }
//    }
//}
//
//ll sum(int x, int y, int z) {
//    ll res = 0;
//    for (int i = x; i >= 0; i = prev(i)) {
//        for (int j = y; j >= 0; j = prev(j)) {
//            for (int l = z; l >= 0; l = prev(l)) {
//                res += a[i][j][l];
//            }
//        }
//    }
//    return res;
//}
//
//int main() {
//    freopen("stars.in", "r", stdin);
//    freopen("stars.out", "w", stdout);
//    cin >> n;
//    a.resize(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
//    int q;
//    cin >> q;
//    while (q != 3) {
//        if (q == 1) {
//            int x, y, z, k;
//            cin >> x >> y >> z >> k;
//            add(x, y, z, k);
//        }
//        else if (q == 2) {
//            int x1, y1, z1, x2, y2, z2;
//            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
//            cout << sum(x2, y2, z2)
//                    - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1)
//                    + sum(x1 - 1, y1 - 1, z2) + sum(x1 - 1, y2, z1 - 1) + sum(x2, y1 - 1, z1 - 1)
//                    - sum(x1 - 1, y1 - 1, z1 - 1) << endl;
//        }
//        cin >> q;
//    }
//}
