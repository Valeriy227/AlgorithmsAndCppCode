//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//bool check(int x, vector<ll> &len, vector<int> &v) {
//    for (int i = 0; i < v.size(); ++i) {
//        if (x == v[i]) {
//            for (int j = 0; j < v.size(); ++j) {
//                if (v[j] == x - 1) {
//                    if (abs(j - i) - 1 != (x == 1 ? 0 : len[x - 2])) {
//                        return false;
//                    }
//                }
//            }
//        }
//    }
//    return true;
//}
//
//bool check_the_same(int x, vector<ll> &len, vector<int> &v) {
//    for (int i = 0; i < v.size(); ++i) {
//        for (int j = i + 1; j < v.size(); ++j) {
//            if (x == v[i]) {
//                if (x == v[j]) {
//                    if (abs(i - j) - 1 != len[x]) {
//                        return false;
//                    }
//                }
//            }
//        }
//    }
//    return true;
//}
//
//vector<int> gen() {
//    int cur = 0;
//    vector<int> res = {0};
//    int cnt = 1;
//    while (cnt < 100) {
//        cur++;
//        res.resize(res.size() * 2 + 1);
//        res[cnt] = cur;
//        for (int i = 0; i < cnt; ++i) {
//            res[i + cnt + 1] = res[i];
//        }
//        cnt = res.size();
//    }
//    return res;
//}
//
//int main() {
//    string s;
//    cin >> s;
//    int n = s.length();
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        if ('a' <= s[i] && s[i] <= 'z') {
//            v[i] = s[i] - 'a';
//        }
//        else {
//            v[i] = s[i] - '0' + 26;
//        }
//    }
//    int maxc = -1, ind = 0;
//    for (int i = 0; i < n; ++i) {
//        if (maxc < v[i]) {
//            maxc = v[i];
//            ind = i;
//        }
//    }
//    int cnt = 0;
//    for (int i = 0; i < n; ++i) {
//        if (maxc == v[i]) {
//            cnt++;
//        }
//    }
//    if (cnt > 1) {
//        cout << 0 << endl;
//        return 0;
//    }
//    vector<ll> len(maxc + 1);
//    len[0] = 1;
//    for (int i = 1; i < maxc + 1; ++i) {
//        len[i] = len[i - 1] * 2 + 1;
//    }
//    auto pref = gen();
//    for (int i = 0; i < ind; ++i) {
//        if (pref[i] != v[ind - i - 1]) {
//            cout << 0 << endl;
//            return 0;
//        }
//    }
//    for (int i = 0; i < n - ind - 1; ++i) {
//        if (pref[i] != v[ind + i + 1]) {
//            cout << 0 << endl;
//            return 0;
//        }
//    }
//    cout << maxc + 1 << " " << (maxc == 0 ? 0 : len[maxc - 1]) - ind << endl;
//}
