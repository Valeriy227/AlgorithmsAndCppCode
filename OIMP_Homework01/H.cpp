//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> field(n + 2, vector<int>(m + 2));
//    for (int i = 0; i < k; ++i) {
//        int row, col;
//        cin >> row >> col;
//        field[row][col] = -1;
//    }
//
//    for (int i = 1; i < n + 1; ++i) {
//        for (int j = 1; j < m + 1; ++j) {
//            if (field[i][j] == -1) {
//                continue;
//            }
//            for (int delta_i = -1; delta_i < 2; ++delta_i) {
//                for (int delta_j = -1; delta_j < 2; ++delta_j) {
//                    if (delta_i == 0 && delta_j == 0) {
//                        continue;
//                    }
//                    field[i][j] += (field[i + delta_i][j + delta_j] == -1);
//                }
//            }
//        }
//    }
//
//    for (int i = 1; i < n + 1; ++i) {
//        for (int j = 1; j < m + 1; ++j) {
//            if (field[i][j] == -1) {
//                cout << '*' << " ";
//            } else {
//                cout << field[i][j] << " ";
//            }
//        }
//        cout << endl;
//    }
//}