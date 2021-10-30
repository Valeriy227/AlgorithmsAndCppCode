//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//void f(vector<int> &v, int n) {
//    unordered_map<int, int> um;
//    int col = 0;
//    for (int i = 0; i < n; ++i) {
//        if (um.count(v[i]) == 0) {
//            um[v[i]] = col;
//            col++;
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        v[i] = um[v[i]];
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    f(v, n);
//    vector<vector<int>> inds(n);
//    for (int i = 0; i < n; ++i) {
//        inds[v[i]].push_back(i);
//    }
//    int ans = n;
//    for (int i = 0; i < n; ++i) {
//        int r = i - 1;
//        for (int j = 0; j < n; ++j) {
//            if (inds[j].size() <= 1) {
//                continue;
//            }
//            if (inds[j][1] < i) {
//                r = 1e9;
//                break;
//            }
//            if (inds[j][0] < i) {
//                r = max(inds[j].back(), r);
//            } else {
//                r = max(inds[j][(int)inds[j].size() - 2], r);
//            }
//        }
//        ans = min(ans, r - i + 1);
//    }
//    cout << ans << endl;
//}
