#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   cin >> n;
   vector<bool> state(n);
   for (int i = 0; i < n; ++i) {
       char c;
       cin >> c;
       state[i] = (c == '+');
   }
   int a, b;
   cin >> a >> b;

   vector<vector<long long>> dp(n + 1, vector<long long>(2, 1e18));
   dp[0][0] = 0;
   for (int i = 1; i < n + 1; ++i) {
       if (state[i - 1]) {
           dp[i][0] = min(dp[i][0], dp[i - 1][0]);
           dp[i][0] = min(dp[i][0], dp[i - 1][1] + a);

           dp[i][1] = min(dp[i][1], dp[i - 1][1] + a);
       } else {
           dp[i][0] = min(dp[i][0], dp[i - 1][0] + a);
           dp[i][0] = min(dp[i][0], dp[i - 1][1]);

           dp[i][1] = min(dp[i][1], dp[i - 1][0] + a + b);
           dp[i][1] = min(dp[i][1], dp[i - 1][1]);
       }
   }

   cout << min(dp[n][0], dp[n][1] + b) << endl;
}
