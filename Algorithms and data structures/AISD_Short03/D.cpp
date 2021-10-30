#include <bits/stdc++.h>

using namespace std;

struct Event {
   int x;
   int y;
   int type;
   int ind;
   Event(int a, int b, int type, int ind) : x(a), y(b), type(type), ind(ind) {}
   bool operator<(Event e) const {
       return tie(y, x, type, ind) <
              tie(e.y, e.x, e.type, e.ind);
   }
};

int main() {
   vector<Event> events;

   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
       int a, b;
       cin >> a >> b;
       events.emplace_back(b, a, 0, i);
   }

   int m;
   cin >> m;
   for (int i = 0; i < m; ++i) {
       int a, b;
       cin >> a >> b;
       events.emplace_back(a, b, 1, i);
   }

   sort(events.begin(), events.end(), [](Event e1, Event e2) {
       return tie(e1.x, e1.y, e1.type, e1.ind) <
       tie(e2.x, e2.y, e2.type, e2.ind);
   });

   set<Event> s;
   vector<pair<int, int>> ans;
   for (auto e : events) {
       if (e.type == 0) {
           s.insert(e);
       } else {
           Event e_set(0, e.y, 0, 0);
           auto it = s.lower_bound(e_set);
           if (it != s.end()) {
               ans.emplace_back(it->ind + 1, e.ind + 1);
               s.erase(it);
           }
       }
   }

   cout << ans.size() << endl;
   for (auto i : ans) {
       cout << i.first << " " << i.second << endl;
   }
}
