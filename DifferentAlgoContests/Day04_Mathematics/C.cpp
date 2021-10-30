//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef unsigned long long ll;
//
//mt19937 gen(2007);
//vector<ll> ans;
//
//ll gcd(ll a, ll b) {
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//ll mulmod(ll a, ll b, ll mod) {
////    if (b == 0) {
////        return 0;
////    }
////    if (b % 2 == 0) {
////        return mulmod(a, b / 2, mod) * 2 % mod;
////    }
////    return (mulmod(a, b - 1, mod) + a) % mod;
//
//    __int128 biga = a;
//    __int128 bigb = b;
//    return biga * bigb % mod;
//}
//
//ll f(ll x, ll mod) {
//    return (mulmod(x, x, mod) + 1) % mod;
//}
//
//ll pollard(ll n) {
//    ll x0 = gen() % n;
//    ll x1 = f(x0, n);
//    for (int i = 0; i < 50000; ++i) {
//        ll d = gcd(max(x0, x1) - min(x0, x1), n);
//        if (d != 1 && d != n) {
//            return d;
//        }
//        x0 = f(x0, n);
//        x1 = f(f(x1, n), n);
//    }
//    return n;
//}
//
//void factorize(ll n) {
//    if (n == 1) {
//        return;
//    }
//    for (int i = 0; i < 5; ++i) {
//        ll d = pollard(n);
//        if (d != n) {
//            factorize(d);
//            factorize(n / d);
//            return;
//        }
//    }
//    ans.push_back(n);
//}
//
//int main() {
//    gen.seed(time(0));
//    freopen("pollard.in", "r", stdin);
//    freopen("pollard.out", "w", stdout);
//    ll n;
//    cin >> n;
//    for (ll i = 2; i <= 1e6; ++i) {
//        while (n % i == 0) {
//            n /= i;
//            ans.push_back(i);
//        }
//    }
//    factorize(n);
//    sort(ans.begin(), ans.end());
//    for (ll i : ans) {
//        cout << i << " ";
//    }
//    cout << endl;
//}
