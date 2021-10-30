//#include <bits/stdc++.h>  //CHANGE LL ON INT128!!!!
//
//using namespace std;
//
//typedef unsigned long long ll;
//
//mt19937 gen(2007);
//
//ll gcd(ll a, ll b) {
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//ll mulmod(ll a, ll b, ll mod) {
//    if (b == 0) {
//        return 0;
//    }
//    if (b % 2 == 0) {
//        return mulmod(a, b / 2, mod) * 2 % mod;
//    }
//    return (mulmod(a, b - 1, mod) + a) % mod;
//}
//
//ll power(ll x, ll p, ll mod) {
//    if (p == 0) {
//        return 1;
//    }
//    if (p % 2 == 0) {
//        ll bigx = x;
////        __int128 bigx = x;
//        return power(bigx * bigx % mod, p / 2, mod);
//    }
//    ll bigres = power(x, p - 1, mod);
////    __int128 bigres = power(x, p - 1, mod);
//    return bigres * x % mod;
//}
//
//bool miller_rabin(ll n, ll x) {
//    ll p = n - 1;
//    while (p % 2 == 0) {
//        p /= 2;
//        ll pow = power(x, p, n);
//        if (pow == n - 1) {
//            return true;
//        }
//        if (pow != 1) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool is_prime(ll n) {
//    if (n == 2 || n == 3) {
//        return true;
//    }
//    if (n == 1 || n % 2 == 0) {
//        return false;
//    }
//    for (int i = 0; i < 5; ++i) {
//        ll x = gen() % (n - 3) + 2;
//        if (gcd(x, n) > 1 || !miller_rabin(n, x)) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    gen.seed(time(0));
////    freopen("again.in", "r", stdin);
////    freopen("again.out", "w", stdout);
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; ++i) {
//        ll x;
//        cin >> x;
//        if (is_prime(x)) {
//            cout << "YES" << endl;
//        }
//        else {
//            cout << "NO" << endl;
//        }
//    }
//}
