//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int l, r;
//    cin >> l >> r;
//    int n = r + 1;
//    int min_prime[n];
//    int primes[n];
//    int cnt_primes = 0;
//    for (int i = 0; i < n; ++i) {
//        min_prime[i] = i;
//    }
//    for (int i = 2; i < n; ++i) {
//        if (min_prime[i] == i) {
//            primes[cnt_primes++] = i;
//        }
//        for (int j = 0; j < cnt_primes; ++j) {
//            int p = primes[j];
//            if (p * (ll)i >= n) {
//                break;
//            }
//            min_prime[p * i] = p;
//        }
//    }
//    ll ans = 0;
//    for (int i = l; i <= r; ++i) {
//        ans += min_prime[i];
//    }
//    cout << ans << endl;
//}
