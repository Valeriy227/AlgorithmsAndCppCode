//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int rest_q;
////string s, t;
//
//bool query(int a, int b, bool for_t = false) {
////    if (for_t) {
////        return s[a] == t[b];
////    }
////    else {
////        return s[a] == s[b];
////    }
//    cout << "s " << a + 1;
//    if (for_t) {
//        cout << " t ";
//    } else {
//        cout << " s ";
//    }
//    cout << b + 1 << endl;
//    string res;
//    cin >> res;
//    rest_q--;
//    return res == "Yes";
//}
//
//bool pref_go(vector<int> &pref, int &cur, int ind, bool flag) {
//    if (cur + 1 < (int)pref.size() && query(cur, ind, flag)) {
//        cur++;
//        return true;
//    }
//    if (cur > 0) {
//        cur = pref[cur - 1];
//    }
//    return false;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> pref(n + 1, 0);
//    int max_suf_t = 0;
//    queue<int> rest_s;
//    queue<int> rest_t;
//    for (int i = 1; i < n; ++i) {
//        rest_s.push(i);
//    }
//    int cnt = 0;
//    for (int i = 0; i < m; ++i) {
//        rest_t.push(i);
//        rest_q = 5;
//        while (rest_q > 0 && !rest_t.empty()) {
//            int prev = max_suf_t;
//            bool res = pref_go(pref, max_suf_t, rest_t.front(), true);
//            if (max_suf_t == prev || res) {
//                rest_t.pop();
//            }
//            if (max_suf_t == n) {
//                cnt++;
//            }
//        }
//        while (rest_q > 0 && !rest_s.empty()) {
//            int ind = rest_s.front();
//            int prev = pref[ind];
//            bool res = pref_go(pref, pref[ind], ind, false);
//            if (pref[ind] == prev || res) {
//                rest_s.pop();
//            }
//            pref[ind + 1] = pref[ind];
//        }
//        cout << "$ " << cnt << endl;
//    }
//}
