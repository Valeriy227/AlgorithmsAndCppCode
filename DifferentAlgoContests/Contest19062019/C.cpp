//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<int> cost;
//
//vector<vector<int>> g;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    cost.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> cost[i];
//    }
//    g.resize(n);
//    for (int i = 0; i < m; ++i) {
//        int a, b;
//        cin >> a >> b;
//        g[a - 1].push_back(b - 1);
//        g[b - 1].push_back(a - 1);
//    }
//
//    int ans = 1e9;
//    for (int i = 0; i < (1 << n); ++i) {
//        vector<bool> checked(n);
//        int cur = 0;
//        for (int j = 0; j < n; ++j) {
//            if (i & (1 << j)) {
//                checked[j] = true;
//                cur += cost[j];
//                for (int nv : g[j]) {
//                    checked[nv] = true;
//                }
//            }
//        }
//        bool flag = true;
//        for (int j = 0; j < n; ++j) {
//            if (!checked[j]) {
//                flag = false;
//                break;
//            }
//        }
//        if (flag && cur < ans) {
//            ans = cur;
//        }
//    }
//    cout << ans << endl;
//}
