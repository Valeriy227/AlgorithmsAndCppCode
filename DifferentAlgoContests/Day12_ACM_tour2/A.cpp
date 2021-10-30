//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//int main() {
//    int k, n;
//    cin >> k >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    vector<ld> dp(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        int cnt = 0;
//        for (int j = i; j >= 1; --j) {
//            if (v[i - 1] == v[j - 1]) {
//                cnt++;
//            }
//            dp[i] = max(dp[i], dp[j - 1] + pow(cnt, k / 2.0));
//        }
//    }
//    cout << fixed << setprecision(10) << endl;
//    cout << dp[n] << endl;
//}
