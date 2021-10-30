#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void insert_min(pair<int, int> key, int val, map<pair<int, int>, int>& map1) {
   auto it = map1.find(key);
   if (it == map1.end()) {
       map1[key] = val;
   } else {
       it->second = min(it->second, val);
   }
}

pair<int, int> attack(vector<int> v, int a) {
   pair<int, int> res = {v[1], v[2]};
   a -= v[0];
   if (a <= 0) {
       return res;
   }

   a -= v[1];
   res.first -= v[1];
   if (a <= 0) {
       res.first = -a;
       return res;
   }

   a -= v[2];
   res.second -= v[2];
   if (a <= 0) {
       res.second = -a;
       return res;
   }

   return {-1, -1};
}

int main() {
   freopen("squads.in", "r", stdin);
   freopen("squads.out", "w", stdout);
   int n;
   cin >> n;
   vector<int> a(n + 2), c(n + 2), w(n + 2);
   for (int i = 0; i < n; ++i) {
       cin >> a[i + 1] >> c[i + 1] >> w[i + 1];
   }
   vector<vector<map<pair<int, int>, int>>> dp(n + 2,vector<map<pair<int, int>, int>>(2));
   dp[0][0][{0, 0}] = 0;
   for (int i = 1; i <= n + 1; ++i) {
       //j = 1
       for (auto item : dp[i - 1][1]) {
           //not attack
           insert_min({item.first.second, 0}, item.second, dp[i][0]);

           //attack
           auto rest = attack({item.first.first, item.first.second, 0}, a[i]);
           if (rest.first != -1) {
               insert_min(rest, item.second, dp[i][1]);
           }
       }
       //j = 0
       for (auto item : dp[i - 1][0]) {
           //not attack
           insert_min({item.first.second, 0}, item.second + c[i - 1], dp[i][0]);
           insert_min({item.first.second, a[i - 1]}, item.second + w[i - 1], dp[i][0]);

           //attack
           auto rest = attack({item.first.first, item.first.second, 0}, a[i]);
           if (rest.first != -1) {
               insert_min(rest, item.second + c[i - 1], dp[i][1]);
           }
           rest = attack({item.first.first, item.first.second, a[i - 1]}, a[i]);
           if (rest.first != -1) {
               insert_min(rest, item.second + w[i - 1], dp[i][1]);
           }
       }
   }

   int ans = 1e9;
   for (auto item : dp[n + 1][0]) {
       ans = min(ans, item.second);
   }
   for (auto item : dp[n + 1][1]) {
       ans = min(ans, item.second);
   }
   cout << ans << endl;
}
