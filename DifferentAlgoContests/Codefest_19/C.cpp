//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n;
//    cin >> n;
//    int t = 0;
//    vector<vector<int>> ans(n, vector<int>(n));
//    for (int i = 0; i < n / 2; ++i) {
//        for (int j = 0; j < n / 2; ++j) {
//            ans[i * 2][j * 2] = t++;
//            ans[i * 2][j * 2 + 1] = t++;
//            ans[i * 2 + 1][j * 2] = t++;
//            ans[i * 2 + 1][j * 2 + 1] = t++;
//        }
//    }
//    for (auto &i : ans) {
//        for (int j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//}
