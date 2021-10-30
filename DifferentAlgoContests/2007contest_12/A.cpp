//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//void dfs(int i, int j, vector<int> &borders, vector<vector<int>> &room) {
//    room[i][j] = -1;
//    borders[0] = min(borders[0], j);
//    borders[2] = max(borders[2], j);
//    borders[3] = max(borders[3], i);
//    borders[1] = min(borders[1], i);
//    for (int di = -1; di < 2; di += 2) {
//        if (0 <= i + di && i + di < room.size() && room[i + di][j] == 1) {
//            dfs(i + di, j, borders, room);
//        }
//    }
//    for (int dj = -1; dj < 2; dj += 2) {
//        if (0 <= j + dj && j + dj < room[0].size() && room[i][j + dj] == 1) {
//            dfs(i, j + dj, borders, room);
//        }
//    }
//}
//
//int main() {
//    int n, m;
//    vector<vector<int>> room;
//    cin >> n >> m;
//    room.resize(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            char c;
//            cin >> c;
//            if (c == '.') {
//                room[i][j] = 1;
//            }
//        }
//    }
//
//    vector<vector<int>> rects;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (room[i][j] == 1) {
//                rects.push_back({n, m, 0, 0});
//                dfs(i, j, rects.back(), room);
//            }
//        }
//    }
//
//
//}
