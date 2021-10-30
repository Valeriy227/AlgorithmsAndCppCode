//#include <bits/stdc++.h>
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
//void factorize(ll n, vector<ll> &ans, bool flag = true) {
//    if (flag) {
//        for (ll i = 2; i <= 1e6; ++i) {
//            while (n % i == 0) {
//                n /= i;
//                ans.push_back(i);
//            }
//        }
//    }
//
//    if (n == 1) {
//        return;
//    }
//    for (int i = 0; i < 5; ++i) {
//        ll d = pollard(n);
//        if (d != n) {
//            factorize(d, ans, false);
//            factorize(n / d, ans, false);
//            return;
//        }
//    }
//    ans.push_back(n);
//}
//
//vector<ll> get_mix(vector<ll> &divs) {
//    if (divs.empty()) {
//        return {1, 1, 1};
//    }
//    ll last = divs[0];
//    ll prod = 1;
//    ll pow = 0;
//    ll sum = 0;
//    ll ans_euler = 1;
//    ll ans_cntdivs = 1;
//    ll ans_sumdivs = 1;
//    for (auto i : divs) {
//        if (last == i) {
//            prod *= i;
//            sum += prod;
//            pow++;
//        }
//        else {
//            ans_euler *= prod - prod / last;
//            ans_cntdivs *= pow + 1;
//            ans_sumdivs *= sum + 1;
//            sum = i;
//            prod = i;
//            pow = 1;
//        }
//        last = i;
//    }
//    ans_euler *= prod - prod / last;
//    ans_cntdivs *= pow + 1;
//    ans_sumdivs *= sum + 1;
//    return {ans_euler, ans_cntdivs, ans_sumdivs};
//}
//
//int main() {
//    gen.seed(time(0));
//    int m;
//    cin >> m;
//    for (int t = 0; t < m; ++t) {
//        ll n;
//        cin >> n;
//        vector<ll> divs;
//        factorize(n, divs);
//        sort(divs.begin(), divs.end());
//        auto res = get_mix(divs);
//        cout << res[0] << " " << res[1] << " " << res[2] << endl;
//    }
//}
