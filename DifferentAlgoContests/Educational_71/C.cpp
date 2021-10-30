//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t) {
//        t--;
//        int n;
//        ll a, b;
//        cin >> n >> a >> b;
//        vector<bool> v(n);
//        for (int i = 0; i < n; ++i) {
//            char c;
//            cin >> c;
//            v[i] = (c == '1');
//        }
//        ll ans = b;
//        int last = -2;
//        ll cost0 = 0;
//        for (int i = 0; i < n; ++i) {
//            if (v[i] == 0) {
//                if (i > 0 && v[i - 1] == 1) {
//                    if (i < n - 1 && v[i + 1] == 1) {
//                        ans += a + 2 * b;
//                        last = i;
//                    } else {
//                        cost0 = 2 * a + b;
//                    }
//                } else {
//                    if (i < n - 1 && v[i + 1] == 1) {
//                        cost0 += 2 * a + 2 * b;
//                    } else {
//                        cost0 += a + b;
//                    }
//                }
//            } else {
//                if (last < i - 1) {
//                    if (last >= 0) {
//                        ll alt = (i - last - 1) * (2 * b + a);
//                        ans += min(alt, cost0);
//                    } else {
//                        ans += cost0;
//                    }
//                }
//                ans += a + 2 * b;
//                last = i;
//            }
//        }
//        ans += cost0;
//        cout << ans << endl;
//    }
//}
