//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<int> cnt;
//
//void insert(int &res, int x) {
//    if (cnt[x] == 0) {
//        res++;
//    }
//    cnt[x]++;
//}
//
//void erase(int &res, int x) {
//    if (cnt[x] == 1) {
//        res--;
//    }
//    cnt[x]--;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    cnt.resize(1e6 + 1);
//    while (t) {
//        t--;
//        int n, k, d;
//        cin >> n >> k >> d;
//        vector<int> v(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> v[i];
//            cnt[v[i]] = 0;
//        }
//        int res = 0;
//        for (int i = 0; i < d; ++i) {
//            insert(res, v[i]);
//        }
//        int ans = res;
//        for (int i = d; i < n; ++i) {
//            insert(res, v[i]);
//            erase(res, v[i - d]);
//            ans = min(ans, res);
//        }
//        cout << ans << endl;
//    }
//}
