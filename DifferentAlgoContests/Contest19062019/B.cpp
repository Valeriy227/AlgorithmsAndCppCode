//#include <bits/stdc++.h>
//#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//struct segment_tree {
//    int n;
//    vector<int> v;
//    vector<pair<bool, int>> st;
//
//    segment_tree(int nn, vector<int> &a) {
//        n = nn;
//        v.resize(n);
//        for (int i = 0; i < n; ++i) {
//            v[i] = a[i];
//        }
//        st.resize(4 * n);
//        build();
//    }
//
//    void build(int l = 0, int r = n, int cv = 1) {
//        if (l + 1 == r) {
//            st[cv] = {0, v[l]};
//        }
//        else {
//            int mid = (l + r) / 2;
//            build(l, mid, cv * 2);
//            build(mid, r, cv * 2 + 1);
//            st[cv] = min(st[cv * 2], st[cv * 2 + 1]);
//        }
//    }
//
//    void update(int ind, int l = 0, int r = n, int cv = 1) {
//        if (l + 1 == r) {
//            st[cv].first = 1;
//        }
//        else {
//            int mid = (l + r) / 2;
//            if (ind < mid) {
//                update(ind, l, mid, cv * 2);
//            }
//            else {
//                update(ind, mid, l, cv * 2 + 1);
//            }
//        }
//    }
//
//    pair<bool, int> get_min(int ll, int rr, int l = 0, int r = n, int cv = 1) {
//        if (ll >= rr) {
//            return {1, 1e9};
//        }
//        if (ll == l && rr == r) {
//            return st[cv];
//        }
//        else {
//            int mid = (l + r) / 2;
//            return min(get_min(ll, min(rr, mid), l, mid, cv * 2),
//                       get_min(max(ll, mid), rr, mid, r, cv * 2 + 1));
//        }
//    };
//};
//
//vector<vector<pair<int, int>>> g;
//vector<pair<int, int>> anc;
//vector<int> sz;
//vector<int> h;
//vector<segment_tree*> trees;
//vector<int> root;
//
//void get_sz(int cv) {
//    sz[cv] = 1;
//    int maxsz = 0, ind = 0;
//    for (int i = 0; i < g[cv].size(); ++i) {
//        auto nv = g[cv][i];
//        if (nv.first != anc[cv].first) {
//            anc[nv.first] = {cv, nv.second};
//            get_sz(nv.first);
//            sz[cv] += sz[nv.first];
//            if (sz[nv.first] > maxsz) {
//                ind = i;
//                maxsz = sz[nv.first];
//            }
//        }
//    }
//    if (!g[cv].empty()) {
//        swap(g[cv][ind], g[cv][0]);
//    }
//}
//
//void get_h(int cv, int curh) {
//    h[cv] = curh;
//    for (auto nv : g[cv]) {
//        if (nv.first != anc[cv].first) {
//            get_h(nv.first, curh + 1);
//        }
//    }
//}
//
//void build_hld(int cv, bool is_start, vector<int> &branch) {
//    if (is_start) {
//        root[cv] = cv;
//    }
//    else {
//        root[cv] = root[anc[cv].first];
//    }
//    branch.push_back(cv);
//
//    if (g[cv][0].first != anc[cv].first) {
//        build_hld(g[cv][0].first, false, branch);
//    }
//
//    if (g[cv].size() <= 1) {
//        trees[root[cv]] = new segment_tree()
//    }
//
//    for (int i = 1; i < g[cv].size(); ++i) {
//        auto nv = g[cv][i];
//        if (nv.first != anc[cv].first) {
//            vector<int> new_branch;
//            build_hld(nv.first, true, new_branch);
//        }
//    }
//}
//
//bool dfs(int cv, int anc, vector<int> &path, int aim) {
//    if (cv == aim) {
//        return true;
//    }
//    for (auto nv : g[cv]) {
//        if (nv.first != anc && dfs(nv.first, cv, path, aim)) {
//            path.push_back(nv.second);
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<pair<int, int>> edges(m);
//    bool group5 = (n == m);
//    for (int i = 0; i < m; ++i) {
//        int a, b;
//        cin >> a >> b;
//        if (a != i + 1 || b != (i + 1) % n + 1) {
//            group5 = false;
//        }
//        edges[i] = {a - 1, b - 1};
//    }
//
//    g.resize(n);
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
//    vector<int> ans(m);
//    int cnt = 1;
//    if (n <= 1000 && m <= 1000 && !group5) {
//        for (int i = 0; i < m; ++i) {
//            if (ans[i] > 0) {
//                continue;
//            }
//            if (is_frame[i]) {
//                ans[i] = cnt++;
//            }
//            else {
//                vector<int> path;
//                dfs(edges[i].first, -1, path, edges[i].second);
//                sort(path.begin(), path.end());
//                for (int j = 0; j < path.size(); ++j) {
//                    if (ans[path[j]] < 1) {
//                        ans[path[j]] = cnt++;
//                    }
//                }
//                ans[i] = cnt++;
//            }
//        }
//        for (int i : ans) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    else if (n == m && group5) {
//
//        for (int i = 0; i < n; ++i) {
//            if (is_frame[i]) {
//                ans[i] = cnt++;
//            }
//            else {
//                ans[i] = n;
//            }
//        }
//        for (int i : ans) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//    else {
//        return -1;
//    }
//}
