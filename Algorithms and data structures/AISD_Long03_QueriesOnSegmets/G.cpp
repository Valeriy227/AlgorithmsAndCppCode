#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
   int a;
   int b;
   int cost;
   int ind;
   Edge() {}
   Edge(int a, int b, int c, int ind = 0) : a(a), b(b), cost(c), ind(ind) {}
};

bool operator<(const Edge& a, const Edge& b) {
   if (a.cost == b.cost) {
       return a.ind < b.ind;
   }
   return a.cost < b.cost;
}

bool get_mst(vector<vector<Edge>>& g, vector<bool>& is_mst) {
   int n = g.size();
   set<Edge> s;
   s.insert({0, 0, 0, -1});
   vector<bool> used(n);
   int rest = n;
   while (!s.empty()) {
       auto min_edge = *s.begin();
       s.erase(s.begin());
       if (used[min_edge.b]) {
           continue;
       }
       used[min_edge.b] = true;
       rest--;
       if (min_edge.ind >= 0) {
           is_mst[min_edge.ind] = true;
       }
       for (auto& e : g[min_edge.b]) {
           if (!used[e.b]) {
               s.insert(e);
           }
       }
   }
   return (rest == 0);
}

void group_by(vector<Edge>& edges, vector<bool>& is_mst, unordered_map<int,
       vector<int>>& from_mst, unordered_map<int, vector<int>>& not_from_mst) {
   for (auto& edge : edges) {
       if (is_mst[edge.ind]) {
           from_mst[edge.cost].push_back(edge.ind);
       } else {
           not_from_mst[edge.cost].push_back(edge.ind);
       }
   }
}

void get_tin_tout(int cv, int pv, vector<vector<Edge>>& g,
                 vector<bool>& is_mst, vector<int>& tin, vector<int>& tout, int& t) {
   tin[cv] = t++;
   for (auto& e : g[cv]) {
       if (!is_mst[e.ind]) {
           continue;
       }
       if (e.b != pv) {
           get_tin_tout(e.b, cv, g, is_mst, tin, tout, t);
       }
   }
   tout[cv] = t++;
}

bool consists(int a, int b, vector<int>& tin, vector<int>& tout) {
   return tin[a] <= tin[b] && tout[a] >= tout[b];
}

bool is_replaceable(Edge from, Edge not_from, vector<int>& tin, vector<int>& tout) {
   if (consists(from.b, from.a, tin, tout)) {
       swap(from.a, from.b);
   }

   if (consists(from.b, not_from.a, tin, tout)) {
       return !consists(from.b, not_from.b, tin, tout);
   } else if (consists(from.b, not_from.b, tin, tout)) {
       return !consists(from.b, not_from.a, tin, tout);
   } else {
       return false;
   }
}

ll calc_vars(vector<vector<Edge>>& g, vector<Edge>& edges, vector<bool>& is_mst,
            unordered_map<int, vector<int>>& from_mst,
            unordered_map<int, vector<int>>& not_from_mst) {
   int n = g.size();
   vector<int> tin(n), tout(n);
   int t = 0;
   get_tin_tout(0, -1, g, is_mst, tin, tout, t);

   ll res = 1;
   ll mod = 1e9 + 7;

   for (auto& item : from_mst) {
       int cur_var = 1;
       int cost = item.first;
       for (int i : item.second) {
           for (int j : not_from_mst[cost]) {
               if (is_replaceable(edges[i], edges[j], tin, tout)) {
                   cur_var++;
               }
           }
       }
       res *= cur_var;
       res %= mod;
   }

   return res;
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<Edge> edges(m);
   vector<vector<Edge>> g(n);
   for (int i = 0; i < m; ++i) {
       int a, b;
       cin >> a >> b;
       a--;
       b--;
       edges[i].a = a;
       edges[i].b = b;
       cin >> edges[i].cost;
       edges[i].ind = i;

       g[a].push_back(edges[i]);
       g[b].push_back(edges[i]);
       swap(g[b].back().a, g[b].back().b);
   }

   vector<bool> is_mst(m);
   if (!get_mst(g, is_mst)) {
       cout << 0 << endl;
       return 0;
   }

   unordered_map<int, vector<int>> from_mst, not_from_mst;
   group_by(edges, is_mst, from_mst, not_from_mst);
   cout << calc_vars(g, edges, is_mst, from_mst, not_from_mst) << endl;
}