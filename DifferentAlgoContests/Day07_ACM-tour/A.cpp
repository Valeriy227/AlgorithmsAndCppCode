//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n, m;
//int j, d;
//
//vector<double> store;
//
//bool check(int i, int j, vector<vector<int>> &pos) {
//    if (i < 0 || j < 0 || i >= n || j >= m) {
//        return false;
//    }
//    return pos[i][j] > 0;
//}
//
//int get_hash(vector<vector<int>> &pos) {
//    int res = 0;
//    int p = 1;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            res += p * pos[i][j];
//            p *= 3;
//        }
//    }
//    return res;
//}
//
//double move(vector<vector<int>> &pos, int turn) {
//    int cur_hash = get_hash(pos);
//    if (store[cur_hash] >= 0) {
//        return store[cur_hash];
//    }
//    vector<double> possibility;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (pos[i][j] == turn) {
//                for (int di = -1; di < 2; di += 2) {
//                    int new_i = i + di, new_j = j;
//                    if (check(new_i, new_j, pos)) {
//                        int take = pos[new_i][new_j];
//                        pos[new_i][new_j] = turn;
//                        pos[i][j] = 0;
//                        possibility.push_back(1 - move(pos, 3 - turn));
//                        pos[new_i][new_j] = take;
//                        pos[i][j] = turn;
//                    }
//                }
//                for (int dj = -1; dj < 2; dj += 2) {
//                    int new_i = i, new_j = j + dj;
//                    if (check(new_i, new_j, pos)) {
//                        int take = pos[new_i][new_j];
//                        pos[new_i][new_j] = turn;
//                        pos[i][j] = 0;
//                        possibility.push_back(1 - move(pos, 3 - turn));
//                        pos[new_i][new_j] = take;
//                        pos[i][j] = turn;
//                    }
//                }
//            }
//        }
//    }
//    if (possibility.empty()) {
//        return store[cur_hash] = 0;
//    }
//    sort(possibility.rbegin(), possibility.rend());
//    double sum = 0;
//    int cnt = 0;
//    for (int i = 0; i < min((int)possibility.size(), (turn == 1 ? j : d)); ++i) {
//        cnt++;
//        sum += possibility[i];
//    }
//    return store[cur_hash] = sum / cnt;
//}
//
//int main() {
//    store.resize(2000000, -1);
//    cin >> n >> m;
//    vector<vector<int>> pos(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            char c;
//            cin >> c;
//            if (c == 'J') {
//                pos[i][j] = 1;
//            }
//            else {
//                pos[i][j] = 2;
//            }
//        }
//    }
//    cin >> j >> d;
//    cout << move(pos, 1) << endl;
//}
