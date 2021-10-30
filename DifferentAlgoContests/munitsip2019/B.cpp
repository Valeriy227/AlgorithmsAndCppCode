//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll f(ll mid, ll n, ll m) {
//    if (mid * 2 > n || mid * 2 > m) {
//        return n * m;
//    }
//    ll res = mid * 2 * (n + m) - 4 * mid * mid;
//    return res;
//}
//
//int main() {
//    ll n, m, k;
//    cin >> n >> m >> k;
//    ll l = 0, r = n;
//    while (l + 1 < r) {
//        ll mid = (l + r) / 2;
//        if (f(mid, n, m) <= k) {
//            l = mid;
//        } else {
//            r = mid;
//        }
//    }
//    cout << l << endl;
//}
