//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll power(ll x, ll p) {
//    if (p == 0) {
//        return 1;
//    }
//    return x * power(x, p - 1);
//}
//
//int main() {
//    ll n, m;
//    cin >> n >> m;
//    cout << power(2, n * m) - power(2, n * (m - 1)) - power(2, (n - 1) * m) + power(2, (n - 1) * (m - 1)) << endl;
//}
