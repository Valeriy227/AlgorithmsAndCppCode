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
   Edge(int from, int to, int capacity, int cost) :
   from(from), to(to), capacity(capacity), cost(cost), flow(0) {}
};

vector<vector<int>> g;
vector<Edge> edges;

int find_min_cost_path() {
   //ford-bellman
   int n = g.size();
   vector<int> dist(n, 2e9 + 1);
   dist[0] = 0;
   vector<pair<int, int>> prev(n, {-1, 1e9});
   for (int i = 0; i < n - 1; ++i) {
       for (int j = 0; j < edges.size(); ++j) {
           auto& e = edges[j];
           if (e.capacity - e.flow > 0 && dist[e.to] > dist[e.from] + e.cost) {
               dist[e.to] = dist[e.from] + e.cost;
               prev[e.to] = {j, min(prev[e.from].second, e.capacity - e.flow)};
           }
       }
   }

   //find path
   if (dist[n - 1] > 1e9) {
       return -1e9;
   }
   int cv = n - 1;
   vector<bool> used(n);
   used[cv] = true;
   int d = prev[cv].second;
   int cost = 0;
   while (true) {
       cost += d * edges[prev[cv].first].cost;
       edges[prev[cv].first].flow += d;
       edges[prev[cv].first ^ 1].flow -= d;
       cv = edges[prev[cv].first].from;
       if (cv == 0 || used[cv]) {
           used[cv] = true;
           break;
       }
       used[cv] = true;
   }
   if (used[0]) {
       return cost;
   }
   return -2e9;
}

int min_cost_max_flow() {
   int cost = 0;
   while (true) {
       auto res = find_min_cost_path();
//        if (res == -1e9 || res == 0) {
       if (res == -1e9) {
           break;
       }
       cost += res;
   }
   return cost;
}

int ctoi(char c) {
   if ('a' <= c && c <= 'z') {
       return c - 'a';
   }
   return c - 'A' + 26;
}

void add_edge(int from, int to, int capacity, int cost) {
   edges.emplace_back(from, to, capacity, cost);
   edges.emplace_back(to, from, 0, -cost);
   g[from].push_back(edges.size() - 2);
   g[to].push_back(edges.size() - 1);
}

void make_graph(string& a, string& b, int k) {
   int n = a.length();
   g.resize(2 * k + 5);

   //edges between
   int sum = 0;
   vector<vector<int>> summ(k, vector<int>(k));
   for (int i = 0; i < n; ++i) {
       ++summ[ctoi(a[i])][ctoi(b[i])];
   }
   for (int i = 0; i < k; ++i) {
       for (int j = 0; j < k; ++j) {
           sum += summ[i][j];
           add_edge(i + 3, j + k + 3, 1, -summ[i][j]);
       }
   }

   //edges from s and to t
   for (int i = 0; i < k; ++i) {
       add_edge(2, i + 3, 1, 0);
       add_edge(i + 3 + k, 2 * k + 3, 1, 0);
   }

   //the rest
   add_edge(1, 2, sum, 0);
   add_edge(2 * k + 3, 2 * k + 4, sum, 0);
   add_edge(1, 2 * k + 4, sum, 0);
   add_edge(0, 1, sum, 0);
}

char itoc(int x) {
   if (x <= 25) {
       return 'a' + x;
   }
   return 'A' + x - 26;
}

vector<char> get_swap(int k) {
   map<int, char> change;
   set<char> rest;
   for (int i = 0; i < k; ++i) {
       rest.insert(itoc(i));
   }
   for (auto& e : edges) {
       if (e.cost < 0 && e.flow == 1) {
           char val = itoc(e.to - 3 - k);
           change[e.from - 3] = val;
           rest.erase(val);
       }
   }

   vector<char> res(k, -1);
   for (auto item : change) {
       res[item.first] = item.second;
   }
   for (auto& i : res) {
       if (i == -1) {
           i = *rest.begin();
           rest.erase(rest.begin());
       }
   }
   return res;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, k;
   cin >> n >> k;
   string a, b;
   cin >> a >> b;

   g.resize(n);

   make_graph(a, b, k);

   cout << -min_cost_max_flow() << endl;

   auto res = get_swap(k);
   for (char c : res) {
       cout << c;
   }
   cout << endl;
}
