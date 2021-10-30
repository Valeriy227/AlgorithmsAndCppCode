//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    ll n, p;
//    cin >> n >> p;
//    for (int i = 0; i < 1000; ++i) {
//        n -= p;
//        int cnt = __builtin_popcount(n);
//        if (cnt <= i + 1 && n >= i + 1) {
//            cout << i + 1 << endl;
//            return 0;
//        }
//    }
//    cout << -1 << endl;
//}
