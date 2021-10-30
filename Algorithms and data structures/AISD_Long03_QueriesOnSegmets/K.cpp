#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
   int from;
   int to;
   int capacity;
   int cost;
   int flow;
   Edge() {}
   Edge(int from, int to, int capacity, int cost) : from(from), to(to), capacity(capacity), cost(cost), flow(0) {}
};

vector<vector<int>> g;
vector<Edge> edges;
vector<int> first;

int find_min_cost_path() {
   //ford-bellman
   int n = g.size();
   vector<int> dist(n, 2e9 + 1);
   dist[0] = 0;
   vector<int> prev(n);
   for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < edges.size(); ++j) {
           auto& e = edges[j];
           if (e.capacity - e.flow > 0 && dist[e.to] > dist[e.from] + e.cost) {
               dist[e.to] = dist[e.from] + e.cost;
               prev[e.to] = {j};
           }
       }
   }

   //find path
   if (dist[n - 1] > 2e9) {
       return -1;
   }
   int cv = n - 1;
   vector<bool> used(n);
   used[cv] = true;
   while (true) {
       edges[prev[cv]].flow++;
       edges[prev[cv] ^ 1].flow--;
       cv = edges[prev[cv]].from;
       if (cv == 0 || used[cv]) {
           used[cv] = true;
           break;
       }
       used[cv] = true;
   }
   return used[0];
}

bool min_cost_k_flow(int k) {
   for (int i = 0; i < k; ++i) {
       auto res = find_min_cost_path();
       if (res == -1) {
           return false;
       } else if (res == 0) {
           --i;
       }
   }
   return true;
}

void dfs_dec(int cv, int finish, vector<int>& path, int& sum) {
   if (cv == finish) {
       return;
   }
   for (; first[cv] < (int)g[cv].size(); ++first[cv]) {
       int e = g[cv][first[cv]];
       if (edges[e].flow > 0) {
           path.push_back(e / 4);
           edges[e].flow--;
           sum += edges[e].cost;
           dfs_dec(edges[e].to, finish, path, sum);
           return;
       }
   }
}

double decomposition(vector<vector<int>>& paths, int k) {
   int n = g.size();
   first.assign(n, 0);
   int sum = 0;
   for (int i = 0; i < k; ++i) {
       paths.emplace_back();
       dfs_dec(0, n - 1, paths.back(), sum);
   }
   return ((double)sum) / k;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m, k;
   cin >> n >> m >> k;

   g.resize(n);
   first.resize(n);

   for (int i = 0; i < m; ++i) {
       int a, b, c;
       cin >> a >> b >> c;
       edges.emplace_back(a - 1, b - 1, 1, c);
       edges.emplace_back(b - 1, a - 1, 0, -c);
       edges.emplace_back(b - 1, a - 1, 1, c);
       edges.emplace_back(a - 1, b - 1, 0, -c);
       g[a - 1].push_back(edges.size() - 4);
       g[b - 1].push_back(edges.size() - 3);
       g[b - 1].push_back(edges.size() - 2);
       g[a - 1].push_back(edges.size() - 1);
   }

   if (!min_cost_k_flow(k)) {
       cout << -1 << endl;
       return 0;
   }

   vector<vector<int>> paths;
   cout << fixed << setprecision(8) << decomposition(paths, k) << "\n";
   for (auto& path : paths) {
       cout << path.size() << " ";
       for (int i : path) {
           cout << i + 1 << " ";
       }
       cout << "\n";
   }
}
