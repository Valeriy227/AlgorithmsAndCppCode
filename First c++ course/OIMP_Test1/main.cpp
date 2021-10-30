//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string_view>
//#include <stack>
//#include <tuple>
//
//using namespace std;
//
//typedef long long ll;
//
//struct Substr {
//    int cnt = 0;
//    string s;
//};
//
//bool operator>(Substr& a, Substr& b) {
//    int sza = a.s.size();
//    int szb = b.s.size();
//    return tie(a.cnt, sza, b.s) > tie(b.cnt, szb, a.s);
//}
//
//string get_best(const string& s) {
//    vector<int> cnt(26);
//    for (char c : s) {
//        cnt[c - 'a']++;
//    }
//    int max_n = *max_element(cnt.begin(), cnt.end());
//    string res;
//    for (int i = 0; i < 26; ++i) {
//        if (cnt[i] == max_n) {
//            res.push_back('a' + i);
//        }
//    }
//    return res;
//}
//
//Substr f(string& s, char c, Substr prev) {
//    Substr next;
//    vector<int> inds;
//    for (int i = 0; i < s.size(); ++i) {
//        if (s[i] == c) {
//            inds.push_back(i + 1);
//        }
//    }
//    next.cnt = 1;
//    next.s.push_back(c);
//    while (true) {
//        bool flag = true;
//        for (int ind : inds) {
//            if (ind >= s.size() || s[ind] != s[inds.back()]) {
//                flag = false;
//                break;
//            }
//        }
//        if (!flag) {
//            break;
//        }
//        next.s.push_back(s[inds.back()]);
//        next.cnt++;
//        for (int& ind : inds) {
//            ind++;
//        }
//    }
//    if (next > prev) {
//        return next;
//    }
//    return prev;
//}
//
//int main() {
//    string s;
//    cin >> s;
//    auto best = get_best(s);
//
//    Substr ans;
//    for (char c : best) {
//        ans = f(s, c, ans);
//    }
//    cout << ans.s << endl;
//}