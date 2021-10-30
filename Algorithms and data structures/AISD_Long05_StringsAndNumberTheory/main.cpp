//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> col;
//vector<int> cur;
//
//int solve(int l, int r) {
//    if (r == l) {
//        return 0;
//    }
//    int ans = 1e9;
//    if (cur[l] == col[l]) {
//        ans = solve(l + 1, r);
//    }
//    vector<int> store;
//    for (int i = l; i < r; ++i) {
//        store.push_back(cur[i]);
//        cur[i] = col[l];
//        ans = min(ans, solve(l + 1, i + 1) + solve(i + 1, r) + 1);
//    }
//    for (int i = l; i < r; ++i) {
//        cur[i] = store[i - l];
//    }
//    return ans;
//}
//
//vector<int> f(string& s) {
//    vector<int> v(s.length());
//    for (int i = 0; i < s.length(); ++i) {
//        v[i] = s[i] - 'A' + 1;
//    }
//    return v;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    col = f(s);
//    cur.resize(n);
//    cout << solve(0, n) << endl;
//}
