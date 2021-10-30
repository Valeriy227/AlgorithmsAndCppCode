//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<vector<pair<int, ll>>> g;
//vector<int> sz;
//vector<bool> used;
//vector<int> par;
//vector<unordered_map<int, ll>> dist;
//vector<vector<vector<ll>>> events;
//
//void calc_sz(int cv, int prev) {
//    sz[cv] = 1;
//    for (auto nv : g[cv]) {
//        if (nv.first != prev) {
//            calc_sz(nv.first, cv);
//            sz[cv] += sz[nv.first];
//        }
//    }
//}
//
//int get_centroid(int cv, int prev) {
//    bool is_centroid = true;
//    for (auto nv : g[cv]) {
//        if (!used[nv.first]) {
//            if (sz[nv.first] * 2 > sz[cv]) {
//                is_centroid = false;
//                break;
//            }
//        }
//    }
//    if (is_centroid) {
//        return cv;
//    }
//    for (auto nv : g[cv]) {
//        if (!used[nv.first] && nv.first != prev) {
//            swap(sz[cv], sz[nv.first]);
//            sz[cv] = sz[nv. first] - sz[cv];
//            int res = get_centroid(nv.first, cv);
//            if (res != -1) {
//                return res;
//            }
//            swap(sz[cv], sz[nv.first]);
//            sz[nv.first] = sz[cv] - sz[nv.first];
//        }
//    }
//    return -1;
//}
//
//void get_all_dist(int cv, int prev, ll cur_dist, int cur_centroid) {
//    dist[cur_centroid][cv] = cur_dist;
//    for (auto nv : g[cv]) {
//        if (!used[nv.first] && prev != nv.first) {
//            get_all_dist(nv.first, cv, cur_dist + nv.second, cur_centroid);
//        }
//    }
//}
//
//void build_centroid(int cv, int cur_par) {
//    int cur_centroid = get_centroid(cv, -1);
//    par[cur_centroid] = cur_par;
//    get_all_dist(cur_centroid, -1, 0, cur_centroid);
//    used[cur_centroid] = true;
//    for (auto nv : g[cur_centroid]) {
//        if (!used[nv.first]) {
//            build_centroid(nv.first, cur_centroid);
//        }
//    }
//}
//
//void add_event(int cv, int col, ll cur_dist, int cur_time) {
//    while (!events[cv].empty() && events[cv].back()[0] <= cur_dist) {
//        events[cv].pop_back();
//    }
//    events[cv].push_back({cur_dist, col, cur_time});
//}
//
//bool cmp(vector<ll> a, vector<ll> b) {
//    return a[0] > b[0];
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    g.resize(n);
//    sz.resize(n);
//    used.resize(n);
//    par.resize(n);
//    dist.resize(n);
//    events.resize(n);
//
//    for (int i = 0; i < n - 1; ++i) {
//        int a, b, w;
//        cin >> a >> b >> w;
//        g[a - 1].push_back({b - 1, w});
//        g[b - 1].push_back({a - 1, w});
//    }
//
//    calc_sz(0, -1);
//    build_centroid(0, -1);
//
//    int q;
//    cin >> q;
//    for (int t = 0; t < q; ++t) {
//        int c;
//        cin >> c;
//        if (c == 1) {
//            int v, col;
//            ll d;
//            cin >> v >> d >> col;
//            v--;
//            int cv = v;
//            while (cv != -1) {
//                ll cur_dist = d - dist[cv][v];
//                if (cur_dist < 0) {
//                    cv = par[cv];
//                    continue;
//                }
//                add_event(cv, col, cur_dist, t);
//                cv = par[cv];
//            }
//        } else {
//            int v;
//            cin >> v;
//            v--;
//            int cv = v;
//            int maxt = -1;
//            int ans_col = 0;
//            while (cv != -1) {
//                ll cur_dist = dist[cv][v];
//                int ind = upper_bound(events[cv].begin(), events[cv].end(),
//                        (vector<ll>){cur_dist, 0, 0}, cmp) - events[cv].begin();
//                if (ind == 0) {
//                    cv = par[cv];
//                    continue;
//                }
//                if (maxt < events[cv][ind - 1][2]) {
//                    maxt = events[cv][ind - 1][2];
//                    ans_col = events[cv][ind - 1][1];
//                }
//                cv = par[cv];
//            }
//            cout << ans_col << endl;
//        }
//    }
//}
