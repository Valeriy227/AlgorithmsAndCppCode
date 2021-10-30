//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//ll manaker(string &s, bool flag) {
//    ll res = 0;
//    int n = s.length();
//    vector<int> pal(n, 1 - flag);
//    int r = 0;
//    int mid = 0;
//    for (int i = 1; i < n; ++i) {
//        if (r > i) {
//            pal[i] = min(pal[mid - (i - mid)], r - i);
//        }
//        while (i - pal[i] - flag >= 0 &&
//               i + pal[i] < n &&
//               s[i - pal[i] - flag] == s[i + pal[i]]) {
//            pal[i]++;
//        }
//        if (r < i + pal[i]) {
//            r = i + pal[i];
//            mid = i;
//        }
//        res += pal[i] - (1 - flag);
//    }
//    return res;
//}
//
//int main() {
//    freopen("palindrome.in", "r", stdin);
//    freopen("palindrome.out", "w", stdout);
//    string s;
//    cin >> s;
//    ll res = manaker(s, true);
//    res += manaker(s, false);
//    cout << res << endl;
//}
