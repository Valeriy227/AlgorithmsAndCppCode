//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    ll n, l, r;
//    cin >> n >> l >> r;
//    ll mins = 0, maxs = 0;
//    for (int i = 0; i < n - (l - 1); ++i) {
//        mins += 1;
//    }
//    int p = 2;
//    for (int i = 0; i < l - 1; ++i) {
//        mins += p;
//        p *= 2;
//    }
//
//    p = 1;
//    for (int i = 0; i < r; ++i) {
//        maxs += p;
//        p *= 2;
//    }
//    p /= 2;
//    maxs += p * (n - r);
//    cout << mins << " " << maxs << endl;
//}
