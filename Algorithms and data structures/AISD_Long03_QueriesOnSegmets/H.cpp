#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
   int from;
   int to;
   ll cost;
};

vector<ll> get_dist(vector<vector<Edge>>& g, int start) {
   int n = g.size();
   vector<ll> dist(n, 2e9);
   set<pair<int, int>> set1;
   set1.insert({0, start});
   while (!set1.empty()) {
       auto cur = *set1.begin();
       set1.erase(set1.begin());
       int cv = cur.second;
       dist[cv] = cur.first;
       for (auto e : g[cv]) {
           int nv = e.to;
           ll cost = max(dist[cv], e.cost);
           if (dist[nv] > cost) {
               set1.erase({dist[nv], nv});
               dist[nv] = cost;
               set1.insert({cost, nv});
           }
       }
   }
   return dist;
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<Edge> edges(m);
   vector<vector<Edge>> g(n);
   for (int i = 0; i < m; ++i) {
       cin >> edges[i].from >> edges[i].to >> edges[i].cost;
       edges[i].from--;
       edges[i].to--;

       g[edges[i].from].push_back(edges[i]);
       g[edges[i].to].push_back(edges[i]);
       swap(g[edges[i].to].back().from, g[edges[i].to].back().to);

   }

   int start, finish;
   cin >> start >> finish;
   start--;
   finish--;

   auto dist_start = get_dist(g, start);
   auto dist_finish = get_dist(g, finish);

   ll ans = 2e9 + 1;
   for (auto e : edges) {
       if (dist_start[e.from] <= e.cost && dist_finish[e.to] <= e.cost) {
           ans = min(ans, e.cost + max(dist_start[e.from], dist_finish[e.to]));
       }
       if (dist_start[e.to] <= e.cost && dist_finish[e.from] <= e.cost) {
           ans = min(ans, e.cost + max(dist_start[e.to], dist_finish[e.from]));
       }
   }
   cout << ans << endl;
}
