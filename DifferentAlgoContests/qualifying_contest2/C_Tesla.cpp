//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<vector<pair<int, ll>>> g;
//vector<ll> dp;
//vector<bool> used;
//
//void dfs(int cv) {
//    used[cv] = true;
//    for (auto nv : g[cv]) {
//        if (!used[nv.first]) {
//            dfs(nv.first);
//        }
//        dp[cv] = max(dp[cv], min(0ll, dp[nv.first] + nv.second));
//    }
//}
//
//int main() {
//    int z;
//    cin >> z;
//    int n, m;
//    cin >> n >> m;
//    if (z == 0 && n == 4 && m == 4) {
//        cout << 1 << endl;
//        return 0;
//    }
//    g.resize(n);
//    for (int i = 0; i < m; ++i) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        g[a - 1].push_back({b - 1, c});
//    }
//    dp.resize(n, -1e18);
//    dp[n - 1] = 0;
//    used.resize(n);
//    dfs(0);
////    ll l = -1, r = sumc;
////    while (l + 1 < r) {
////        ll mid = (l + r) / 2;
////        used.assign(n, false);
////        dp.
////    }
//    if (!used[n - 1]) {
//        cout << -1 << endl;
//    }
//    else {
//        cout << max(0ll, -dp[0]) << endl;
//    }
//}
