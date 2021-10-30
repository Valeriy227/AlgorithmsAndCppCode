//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<int> sz;
//vector<vector<int>> g;
//vector<pair<int, int>> ans;
//vector<int> next_x;
//
//void calc_sz(int cv, int pv) {
//    sz[cv] = 1;
//    int ind = -1;
//    for (int i = 0; i < (int)g[cv].size(); ++i) {
//        int nv = g[cv][i];
//        if (nv != pv) {
//            calc_sz(nv, cv);
//            sz[cv] += sz[nv];
//            if (ind == -1 || sz[nv] > sz[g[cv][ind]]) {
//                ind = i;
//            }
//        }
//    }
//    if (ind > -1) {
//        swap(g[cv][ind], g[cv][0]);
//    }
//}
//
//void dfs(int cv, int pv, int y) {
//    ans[cv] = {next_x[y - 1], y};
//    next_x[y - 1]++;
//    for (int i = 1; i < (int)g[cv].size(); ++i) {
//        int nv = g[cv][i];
//        if (nv != pv) {
//            dfs(nv, cv, y + 1);
//        }
//    }
//    if (!g[cv].empty() && g[cv][0] != pv) {
//        dfs(g[cv][0], cv, y);
//    }
//}
//
//int main() {
//    //freopen("file.in", "r", stdin);
//    //freopen("file.out", "w", stdout);
//    int n;
//    cin >> n;
//    int maxy = 20;
//    g.resize(n);
//    for (int i = 0; i < n - 1; ++i) {
//        int a, b;
//        cin >> a >> b;
//        g[a - 1].push_back(b - 1);
//        g[b - 1].push_back(a - 1);
//    }
//
//    sz.resize(n);
//    calc_sz(0, -1);
//
//    ans.resize(n);
//    next_x.resize(maxy, 1);
//    dfs(0, -1, 1);
//    for (int i = 0; i < n; ++i) {
//        cout << ans[i].first << " " << ans[i].second << endl;
//    }
//}
