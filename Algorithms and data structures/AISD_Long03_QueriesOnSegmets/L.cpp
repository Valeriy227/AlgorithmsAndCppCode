#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int from;
    int to;
    int capacity;
    int flow;
    Edge() {}
    Edge(int from, int to, int capacity) :
            from(from), to(to), capacity(capacity), flow(0) {}
};

vector<Edge> edges;
vector<vector<int>> g;
vector<int> first;
vector<int> lvl;

int ceil_ind(int i, int j, int n, int m, int t) {
    return i * m + j + 1 + t * n * m;
}

void add_edge(int from, int to, int capacity) {
    edges.emplace_back(from, to, capacity);
    edges.emplace_back(to, from, 0);
    g[from].push_back(edges.size() - 2);
    g[to].push_back(edges.size() - 1);
}

void make_graph(vector<vector<bool>>& field, int w_cost, int b_cost, int g_cost) {
    int n = field.size();
    int m = field[0].size();
    g.resize(2 * n * m + 2);

    //edges from s
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j]) {
                int to = ceil_ind(i, j, n, m, 0);
                add_edge(0, to, b_cost);
            }
        }
    }

    //edges to t
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!field[i][j]) {
                int t = g.size() - 1;
                int from = ceil_ind(i, j, n, m, 1);
                add_edge(from, t, w_cost);
            }
        }
    }

    //edges between
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j]) {
                int from = ceil_ind(i, j, n, m, 0);
                for (int di = -1; di < 2; di += 2) {
                    if (0 <= i + di && i + di < n && !field[i + di][j]) {
                        int to = ceil_ind(i + di, j, n, m, 1);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
                for (int dj = -1; dj < 2; dj += 2) {
                    if (0 <= j + dj && j + dj < m && !field[i][j + dj]) {
                        int to = ceil_ind(i, j + dj, n, m, 1);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j]) {
                int from = ceil_ind(i, j, n, m, 0);
                for (int di = -1; di < 2; di += 2) {
                    if (0 <= i + di && i + di < n && field[i + di][j]) {
                        int to = ceil_ind(i + di, j, n, m, 0);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
                for (int dj = -1; dj < 2; dj += 2) {
                    if (0 <= j + dj && j + dj < m && field[i][j + dj]) {
                        int to = ceil_ind(i, j + dj, n, m, 0);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!field[i][j]) {
                int from = ceil_ind(i, j, n, m, 1);
                for (int di = -1; di < 2; di += 2) {
                    if (0 <= i + di && i + di < n && !field[i + di][j]) {
                        int to = ceil_ind(i + di, j, n, m, 1);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
                for (int dj = -1; dj < 2; dj += 2) {
                    if (0 <= j + dj && j + dj < m && !field[i][j + dj]) {
                        int to = ceil_ind(i, j + dj, n, m, 1);
                        add_edge(from, to, g_cost);
                        add_edge(to, from, g_cost);
                    }
                }
            }
        }
    }
}

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

int dinic() {
    int n = g.size();
    int flow = 0;
    while (true) {
        bfs(0);
        bool flag = false;
        first.assign(n, 0);
        while (true) {
            int res = dfs(0, n - 1, 1e9);
            flow += res;
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
    return flow;
}

int main() {
    int n, m, w_cost, b_cost, g_cost;
    cin >> n >> m >> w_cost >> b_cost >> g_cost;

    vector<vector<bool>> field(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            field[i][j] = (c == 'W');
        }
    }

    make_graph(field, w_cost, b_cost, g_cost);

    first.resize(g.size());
    lvl.resize(g.size());

    cout << dinic() << endl;
}
