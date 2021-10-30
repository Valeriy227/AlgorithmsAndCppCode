//#include <bits/stdc++.h>
//#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//int t = 0;
//int cnt = 1;
//vector<vector<pair<int, int>>> g;
//vector<pair<int, int>> par;
//vector<int> r;
//vector<int> tin, tout;
//vector<int> ans;
//
//void get_tin_tout(int cv) {
//    tin[cv] = t++;
//    for (auto nv : g[cv]) {
//        if (nv.first != par[cv].first) {
//            par[nv.first] = {cv, nv.second};
//            get_tin_tout(nv.first);
//        }
//    }
//    tout[cv] = t++;
//}
//
//int get_root(int cv) {
//    if (cv == r[cv]) {
//        return cv;
//    }
//    return r[cv] = get_root(r[cv]);
//}
//
//bool is_anc(int a, int b) {
//    return tin[a] <= tin[b] && tout[a] >= tout[b];
//}
//
//void paint_frame(int a, int b) {
//    vector<int> path;
//    a = get_root(a);
//    b = get_root(b);
//    while (!is_anc(a, b)) {
//        path.push_back(par[a].second);
//        r[a] = par[a].first;
//        a = par[a].first;
//        a = get_root(a);
//    }
//    while (!is_anc(b, a)) {
//        path.push_back(par[b].second);
//        r[b] = par[b].first;
//        b = par[b].first;
//        b = get_root(b);
//    }
//    sort(path.begin(), path.end());
//    for (int i : path) {
//        if (ans[i] < 1) {
//            ans[i] = cnt++;
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//
//    g.resize(n);
//    par.resize(n, {-1, -1});
//    tin.resize(n);
//    tout.resize(n);
//    ans.resize(m);
//    r.resize(n);
//    for (int i = 0; i < n; ++i) {
//        r[i] = i;
//    }
//
//    vector<pair<int, int>> edges(m);
//    for (int i = 0; i < m; ++i) {
//        int a, b;
//        cin >> a >> b;
//        edges[i] = {a - 1, b - 1};
//    }
//
//    vector<int> frame(n - 1);
//    vector<bool> is_frame(m);
//    for (int i = 0; i < n - 1; ++i) {
//        cin >> frame[i];
//        frame[i]--;
//        is_frame[frame[i]] = true;
//        g[edges[frame[i]].first].push_back({edges[frame[i]].second, frame[i]});
//        g[edges[frame[i]].second].push_back({edges[frame[i]].first, frame[i]});
//    }
//
//    get_tin_tout(0);
//
//    for (int i = 0; i < m; ++i) {
//        if (ans[i] > 0) {
//            continue;
//        }
//        if (is_frame[i]) {
//            ans[i] = cnt++;
//        }
//        else {
//            paint_frame(edges[i].first, edges[i].second);
//            ans[i] = cnt++;
//        }
//    }
//    for (int i : ans) {
//        cout << i << " ";
//    }
//    cout << endl;
//}
