#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int from;
    int to;
    int capacity;
    int flow;
    Edge() {}
    Edge(int from, int to, int capacity) : from(from), to(to), capacity(capacity), flow(0) {}
};

vector<vector<int>> g;
vector<Edge> edges;
vector<int> first;
vector<int> lvl;

int dfs(int cv, int finish, int cmin) {
    if (cv == finish) {
        return cmin;
    }
    for (; first[cv] < (int)g[cv].size(); ++first[cv]) {
        int e = g[cv][first[cv]];
        int rest = edges[e].capacity - edges[e].flow;
        if (lvl[edges[e].to] == lvl[cv] + 1 && rest > 0) {
            int res = dfs(edges[e].to, finish, min(cmin, rest));
            if (res > 0) {
                edges[e].flow += res;
                edges[e ^ 1].flow -= res;
                return res;
            }
        }
    }
    return 0;
}

void bfs(int start) {
    for (int &i : lvl) {
        i = 1e9;
    }
    lvl[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cv = q.front();
        q.pop();
        for (int e : g[cv]) {
            if (lvl[cv] + 1 < lvl[edges[e].to] && edges[e].capacity - edges[e].flow > 0) {
                lvl[edges[e].to] = lvl[cv] + 1;
                q.push(edges[e].to);
            }
        }
    }
}

void get_s(int cv, vector<bool> &used) {
    used[cv] = true;
    for (int e : g[cv]) {
        if (!used[edges[e].to] && edges[e].capacity - edges[e].flow > 0) {
            get_s(edges[e].to, used);
        }
    }
}

int main() {
    freopen("cut.in", "r", stdin);
    freopen("cut.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    lvl.resize(n);
    first.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].push_back(4 * i);
        g[b - 1].push_back(4 * i + 1);
        g[b - 1].push_back(4 * i + 2);
        g[a - 1].push_back(4 * i + 3);
        edges.emplace_back(a - 1, b - 1, c);
        edges.emplace_back(b - 1, a - 1, 0);
        edges.emplace_back(b - 1, a - 1, c);
        edges.emplace_back(a - 1, b - 1, 0);
    }

    ll cut = 0;
    while (true) {
        bfs(0);
        bool flag = false;
        first.assign(n, 0);
        while (true) {
            int res = dfs(0, n - 1, 1e9);
            cut += res;
            if (res > 0) {
                flag = true;
            } else {
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    vector<bool> used(n);
    get_s(0, used);

    vector<int> ans;
    for (int i = 0; i < 4 * m; ++i) {
        if (used[edges[i].from] && !used[edges[i].to] && edges[i].flow > 0) {
            ans.push_back(i / 4);
        }
    }
    cout << ans.size() << " " << cut << endl;
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;
}
