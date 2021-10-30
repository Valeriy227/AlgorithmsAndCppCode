//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> v(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            v[i][j] = i * m + j;
//        }
//    }
//    for (int i = 0; i < k; ++i) {
//        char c;
//        cin >> c;
//        int x1, x2, y1, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        x1--, x2--, y1--, y2--;
//        if (c == 'V') {
//            for (int i = x1; i <= (x1 + x2) / 2; i++) {
//                for (int j = y1; j <= y2; ++j) {
//                    swap(v[i][j], v[x2 - (i - x1)][j]);
//                }
//            }
//        }
//        else {
//            for (int i = x1; i <= x2; i++) {
//                for (int j = y1; j <= (y1 + y2) / 2; ++j) {
//                    swap(v[i][j], v[i][y2 - (j - y1)]);
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        ll sum = 0;
//        for (int j = 0; j < m; ++j) {
//            sum += v[i][j];
//        }
//        cout << sum << " ";
//    }
//    cout << endl;
//    for (int j = 0; j < m; ++j) {
//        ll sum = 0;
//        for (int i = 0; i < n; ++i) {
//            sum += v[i][j];
//        }
//        cout << sum << " ";
//    }
//    cout << endl;
//}
