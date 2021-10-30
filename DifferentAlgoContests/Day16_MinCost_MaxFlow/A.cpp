#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int from;
    int to;
    ll capacity;
    ll flow;
    ll cost;
    Edge() {}
    Edge(int from, int to, ll capacity, ll cost) :
            from(from), to(to), capacity(capacity), flow(0), cost(cost) {}
};

vector<Edge> edges;
vector<vector<int>> g;

bool better(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

ll fb2() {
    int n = g.size();
    vector<pair<ll, ll>> dist(n, {1e9, 1e9});
    dist[0] = {0, 1e9};
    vector<int> anc(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int e = 0; e < (int)edges.size(); ++e) {
            auto edge = edges[e];
            if (edge.capacity == edge.flow) {
                continue;
            }
            pair<ll, ll> cur = {dist[edge.from].first + edge.cost, min(edge.capacity - edge.flow, dist[edge.from].second)};
            if (better(cur, dist[edge.to])) {
                dist[edge.to] = cur;
                anc[edge.to] = e;
            }
        }
    }
    int cv = n - 1;
    ll res = 0;
    if (anc[n - 1] == -1) {
        return 0;
    }
    ll cmin = dist[n - 1].second;
    while (cv > 0) {
        int e = anc[cv];
        if (e < 0) {
            return 0;
        }
        res += cmin * edges[e].cost;
        edges[e].flow += cmin;
        edges[e ^ 1].flow -= cmin;
        cv = edges[e].from;
    }
    return res;
}

int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a - 1].push_back(i * 2 + 0);
        g[b - 1].push_back(i * 2 + 1);
        edges.emplace_back(a - 1, b - 1, c, d);
        edges.emplace_back(b - 1, a - 1, 0, -d);
    }

    ll ans = 0;
    while (true) {
        ll res = fb2();
        ans += res;
        if (res == 0) {
            break;
        }
    }
    cout << ans << endl;
}
