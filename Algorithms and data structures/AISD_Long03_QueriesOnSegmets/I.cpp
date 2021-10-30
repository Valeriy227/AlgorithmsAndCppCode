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

void dinic() {
   int n = g.size();
   while (true) {
       bfs(0);
       bool flag = false;
       first.assign(n, 0);
       while (true) {
           int res = dfs(0, n - 1, 1e9);
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
}

int dfs_dec(int cv, int finish, int cmin, vector<int>& path) {
   if (cv == finish) {
       return cmin;
   }
   for (; first[cv] < (int)g[cv].size(); ++first[cv]) {
       int e = g[cv][first[cv]];
       if (edges[e].flow > 0) {
           path.push_back(e / 2);
           int res = dfs_dec(edges[e].to, finish, min(cmin, edges[e].flow), path);
           edges[e].flow -= res;
           return res;
//            if (res > 0) {
//            }
       }
   }
   return 0;
}

void decomposition(vector<int>& flows, vector<vector<int>>& paths) {
   int n = g.size();
   first.assign(n, 0);
   while (true) {
       paths.emplace_back();
       int res = dfs_dec(0, n - 1, 1e9, paths.back());
       if (res == 0) {
           paths.pop_back();
           break;
       }
       flows.push_back(res);
   }
}

int main() {
   int n, m;
   cin >> n >> m;

   g.resize(n);
   lvl.resize(n);
   first.resize(n);

   for (int i = 0; i < m; ++i) {
       int a, b, c;
       cin >> a >> b >> c;
       edges.emplace_back(a - 1, b - 1, c);
       edges.emplace_back(b - 1, a - 1, 0);
       g[a - 1].push_back(edges.size() - 2);
       g[b - 1].push_back(edges.size() - 1);
   }

   dinic();

   vector<int> flows;
   vector<vector<int>> paths;
   decomposition(flows, paths);
   cout << flows.size() << endl;
   for (int i = 0; i < flows.size(); ++i) {
       cout << flows[i] << " ";
       cout << paths[i].size() << " ";
       for (int j : paths[i]) {
           cout << j + 1 << " ";
       }
       cout << "\n";
   }
}
