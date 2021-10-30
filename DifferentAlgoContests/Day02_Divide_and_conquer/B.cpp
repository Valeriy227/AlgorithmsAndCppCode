//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int m;
//int cnt;
//vector<int> p;
//vector<int> sz;
//vector<vector<pair<int, int>>> edges;
//vector<int> ans;
//
//void add_event(pair<int, int> e, int ll, int rr, int l = 0, int r = m, int cv = 1) {
//    if (ll >= rr) {
//        return;
//    }
//    if (ll == l && rr == r) {
//        edges[cv].push_back(e);
//        return;
//    }
//    int mid = (l + r) / 2;
//    add_event(e, ll, min(rr, mid), l, mid, cv * 2);
//    add_event(e, max(ll, mid), rr, mid, r, cv * 2 + 1);
//}
//
//int get_root(int x) {
//    if (p[x] == x) {
//        return x;
//    }
//    return get_root(p[x]);
//}
//
//pair<int, int> merge(int a, int b) {
//    a = get_root(a);
//    b = get_root(b);
//    if (a == b) {
//        return {-1, -1};
//    }
//    pair<int, int> back;
//    if (sz[a] > sz[b]) {
//        p[b] = a;
//        sz[a] += sz[b];
//        back = {b, a};
//    } else {
//        p[a] = b;
//        sz[b] += sz[a];
//        back = {a, b};
//    }
//    cnt--;
//    return back;
//}
//
//void split(int a, int b) {
//    p[a] = a;
//    sz[b] -= sz[a];
//    cnt++;
//}
//
//bool cmp(pair<int, int> a, pair<int, int> b) {
//    if (a.first == -1) {
//        return 0;
//    }
//    if (b.first == -1) {
//        return 1;
//    }
//    if (a.first == b.first) {
//        return a.second < b.second;
//    }
//    return a.first < b.first;
//}
//
//void dfs(int l = 0, int r = m, int cv = 1) {
//    if (l >= r) {
//        return;
//    }
//    for (auto &e : edges[cv]) {
//        if (e.first == -1) {
//            ans.push_back(cnt);
//        }
//        else {
//            e = merge(e.first, e.second);
//        }
//    }
//    if (l + 1 < r) {
//        int mid = (l + r) / 2;
//        dfs(l, mid, cv * 2);
//        dfs(mid, r, cv * 2 + 1);
//    }
//    for (auto &e : edges[cv]) {
//        if (e.first != -1) {
//            split(e.first, e.second);
//        }
//    }
//}
//
//int main() {
//    freopen("connect.in", "r", stdin);
//    freopen("connect.out", "w", stdout);
//    int n;
//    cin >> n >> m;
//    edges.resize(4 * m);
//    map<pair<int, int>, int> open;
//    for (int i = 0; i < m; ++i) {
//        char c;
//        cin >> c;
//        if (c == '?') {
//            add_event({-1, -1}, i, i + 1);
//        }
//        else {
//            int a, b;
//            cin >> a >> b;
//            if (a > b) {
//                swap(a, b);
//            }
//            if (c == '+') {
//                open[{a, b}] = i;
//            }
//            else {
//                add_event({a - 1, b - 1}, open[{a, b}], i + 1);
//                open.erase({a, b});
//            }
//        }
//    }
//    for (auto i : open) {
//        add_event({i.first.first - 1, i.first.second - 1}, i.second, m);
//    }
//    for (int i = 0; i < 4 * m; ++i) {
//        sort(edges[i].begin(), edges[i].end(), cmp);
//    }
//
//    cnt = n;
//    p.resize(n);
//    sz.resize(n, 1);
//    for (int i = 0; i < n; ++i) {
//        p[i] = i;
//    }
//    dfs();
//    for (int i : ans) {
//        cout << i << endl;
//    }
//}
