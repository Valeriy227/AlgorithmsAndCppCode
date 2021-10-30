//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<vector<int>> set(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> set[i][j];
//        }
//    }
//
//    bool is_associative = true;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int k = 0; k < n; ++k) {
//                if (set[set[i][j]][k] != set[i][set[j][k]]) {
//                    is_associative = false;
//                }
//            }
//        }
//    }
//
//    if (is_associative) {
//        cout << "YES" << endl;
//    } else {
//        cout << "NO" << endl;
//    }
//}