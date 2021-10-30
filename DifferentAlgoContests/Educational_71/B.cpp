//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n, m;
//vector<vector<int>> v;
//
//bool is_square(int i, int j) {
//    if (i == -1 || j == -1 || i == n - 1 || j == m - 1) {
//        return false;
//    }
//    for (int ii = 0; ii < 2; ++ii) {
//        for (int jj = 0; jj < 2; ++jj) {
//            if (v[i + ii][j + jj] != 1) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//int main() {
//    cin >> n >> m;
//    v.resize(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> v[i][j];
//        }
//    }
//    vector<pair<int, int>> ans;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (v[i][j] == 0) {
//                continue;
//            }
//            bool flag = false;
//            for (int ii = -1; ii < 1 && !flag; ++ii) {
//                for (int jj = -1; jj < 1 && !flag; ++jj) {
//                    if (is_square(ii + i, jj + j)) {
//                        flag = true;
//                        ans.push_back({i + ii + 1, j + jj + 1});
//                    }
//                }
//            }
//            if (!flag) {
//                cout << -1 << endl;
//                return 0;
//            }
//        }
//    }
//    cout << ans.size() << endl;
//    for (auto i : ans) {
//        cout << i.first << " " << i.second << endl;
//    }
//}
