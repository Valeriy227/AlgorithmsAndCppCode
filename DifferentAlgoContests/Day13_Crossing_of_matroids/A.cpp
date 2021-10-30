#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int from;
    int to;
    int color;
    Edge() {}
};

vector<Edge> edges;
vector<int> ans;
vector<int> not_ans;

struct DSU {
    int n;
    vector<int> p;
    vector<int> sz;
    DSU(int n) : n(n) {
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        sz.resize(n, 1);
    }
    int get_root(int x) {
        if (p[x] == x) {
            return x;
        }
        return p[x] = get_root(p[x]);
    }
    void merge(int a, int b) {
        a = get_root(a);
        b = get_root(b);
        if (sz[a] > sz[b]) {
            p[b] = a;
            sz[a] += sz[b];
        } else {
            p[a] = b;
            sz[b] += sz[a];
        }
    }
};

void build_left(int n, int m, int cnt_v, vector<vector<int>> &left) {
    left.resize(n);
    for (int i = 0; i < n; ++i) {
        DSU dsu(cnt_v);
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            dsu.merge(edges[ans[j]].from, edges[ans[j]].to);
        }
        for (int j = 0; j < m; ++j) {
            if (dsu.get_root(edges[not_ans[j]].from) != dsu.get_root(edges[not_ans[j]].to)) {
                left[i].push_back(j);
            }
        }
    }
}

void build_right(int n, int m, vector<vector<int>> &right) {
    right.resize(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (edges[ans[i]].color == edges[not_ans[j]].color) {
                right[j].push_back(i);
            }
        }
    }
}

void get_e1(int n, int m, int cnt_v, vector<int> &e1) {
    DSU dsu(cnt_v);
    for (int i = 0; i < n; ++i) {
        dsu.merge(edges[ans[i]].from, edges[ans[i]].to);
    }
    for (int i = 0; i < m; ++i) {
        if (dsu.get_root(edges[not_ans[i]].from) != dsu.get_root(edges[not_ans[i]].to)) {
            e1.push_back(i);
        }
    }
}

void get_e2(int n, int m, vector<int> &e2) {
    unordered_set<int> us;
    for (int i = 0; i < n; ++i) {
        us.insert(edges[ans[i]].color);
    }
    for (int i = 0; i < m; ++i) {
        if (us.count(edges[not_ans[i]].color) == 0) {
            e2.push_back(i);
        }
    }
}

bool bfs(int n, int m, vector<vector<vector<int>>> &g, vector<int> &e1, vector<int> &e2) {
    vector<vector<int>> dist(2);
    dist[0].resize(n, 1e9);
    dist[1].resize(m, 1e9);
    vector<vector<int>> anc(2);
    anc[0].resize(n, -1);
    anc[1].resize(m, -1);
    vector<bool> is_e2(m);
    for (int i : e2) {
        is_e2[i] = true;
    }
    queue<pair<int, int>> q;
    for (int i : e1) {
        q.push({1, i});
        dist[1][i] = 0;
    }
    int finish = -1;
    while (!q.empty()) {
        auto cv = q.front();
        if (cv.first == 1 && is_e2[cv.second]) {
            finish = cv.second;
            break;
        }
        q.pop();
        for (int nv : g[cv.first][cv.second]) {
            if (dist[1 - cv.first][nv] > dist[cv.first][cv.second] + 1) {
                dist[1 - cv.first][nv] = dist[cv.first][cv.second] + 1;
                q.push({1 - cv.first, nv});
                anc[1 - cv.first][nv] = cv.second;
            }
        }
    }
    if (finish == -1) {
        return false;
    }
    vector<bool> is_ans(n + m);
    for (int i : ans) {
        is_ans[i] = true;
    }
    int c = 1;
    int cv = finish;
    while (true) {
        if (c == 1) {
            is_ans[not_ans[cv]] = true;
        } else {
            is_ans[ans[cv]] = false;
        }
        if (dist[c][cv] == 0) {
            break;
        }
        cv = anc[c][cv];
        c = 1 - c;
    }
    ans.clear();
    not_ans.clear();
    for (int i = 0; i < n + m; ++i) {
        if (is_ans[i]) {
            ans.push_back(i);
        } else {
            not_ans.push_back(i);
        }
    }
    return true;
}

int main() {
//    freopen("highways.in", "r", stdin);
//    freopen("highways.out", "w", stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int cnt_v, cnt_e;
    cin >> cnt_v >> cnt_e;
    edges.resize(cnt_e);
    for (int i = 0; i < cnt_e; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].color;
        edges[i].from--;
        edges[i].to--;
    }

    not_ans.resize(cnt_e);
    for (int i = 0; i < cnt_e; ++i) {
        not_ans[i] = i;
    }

    while (true) {
        int n = ans.size();
        int m = not_ans.size();
        vector<vector<vector<int>>> g(2);
        build_left(n, m, cnt_v, g[0]);
        build_right(n, m, g[1]);
        vector<int> e1, e2;
        get_e1(n, m, cnt_v, e1);
        get_e2(n, m, e2);
        if (!bfs(n, m, g, e1, e2)) {
            break;
        }
    }

    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;
}
