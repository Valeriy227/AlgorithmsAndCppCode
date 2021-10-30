#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int to_ind(int p) {
   int res = 0;
   while (p > 1) {
       p /= 2;
       res++;
   }
   return res;
}

int main() {
   int n, k;
   cin >> n >> k;
   vector<vector<int>> v;
   for (int i = 0; i < n; ++i) {
       int a, b, c;
       cin >> a >> b >> c;
       v.push_back({a, b, c});
   }

   int max_cnt = 0;
   int opt_mask = -1;
   vector<int> dp(1 << n, -2e5), prev(1 << n);
   dp[0] = k;
   for (int mask = 0; mask < (1 << n); ++mask) {
       int cnt = 0;
       for (int j = 0; j < n; ++j) {
           if ((mask >> j) & 1) {
               cnt++;
               auto cur = dp[mask ^ (1 << j)];
               if (v[j][0] <= cur && cur <= v[j][1]) {
                   dp[mask] = cur + v[j][2];
                   prev[mask] = (mask ^ (1 << j));
               }
           }
       }
       if (cnt > max_cnt && dp[mask] > -1e5) {
           max_cnt = cnt;
           opt_mask = mask;
       }
   }
   cout << max_cnt << endl;
   vector<int> order;
   while (opt_mask > 0) {
       int bit = (opt_mask ^ prev[opt_mask]);
       int ind = to_ind(bit);
       order.push_back(ind + 1);
       opt_mask = prev[opt_mask];
   }
   reverse(order.begin(), order.end());
   for (int i : order) {
       cout << i << " ";
   }
   cout << endl;
}
