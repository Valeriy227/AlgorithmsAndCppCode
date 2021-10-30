#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;
unordered_map<ll, ll> dp;
vector<vector<bool>> g;
ll n;

ll f(ll mask) {
   auto it = dp.find(mask);
   if (it != dp.end()) {
       return it->second;
   }
   if (mask == (1ll << n) - 1) {
       dp[mask] = 1;
       return 1;
   }
   ll ans = 0;
   for (ll i = 0; i < n; ++i) {
       if (!((mask >> i) & 1)) {
           for (ll j = i + 1; j < n; ++j) {
               if (!((mask >> j) & 1)) {
                   if (g[i][j]) {
                       mask ^= (1ll << i);
                       mask ^= (1ll << j);
                       ans += f(mask);
                       ans %= mod;
                       mask ^= (1ll << i);
                       mask ^= (1ll << j);
                   }
               }
           }
           break;
       }
   }
   dp[mask] = ans;
   return ans;
}

int main() {
   int m;
   cin >> n >> m;
//    if (n % )
   g.resize(n, vector<bool>(n));
   for (int i = 0; i < m; ++i) {
       int a, b;
       cin >> a >> b;
       g[a - 1][b - 1] = true;
       g[b - 1][a - 1] = true;
   }
   cout << f(0) << endl;
}
