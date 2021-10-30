//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n, m;
//vector<vector<bool>> field;
//vector<vector<int>> used;
//vector<vector<int>> delta;
//
//bool check(int x, int y) {
//    if (x < 0 || x >= n || y < 0 || y >= m) {
//        return false;
//    }
//    return field[x][y];
//}
//
//void move(int x, int y, vector<pair<int, int>> &passed) {
//    used[x][y] = 2;
//    passed.emplace_back(x, y);
//    for (int dx = -1; dx < 2; dx += 2) {
//        if (check(x + dx, y) && !used[x + dx][y]) {
//            move(x + dx, y, passed);
//        }
//    }
//    for (int dy = -1; dy < 2; dy += 2) {
//        if (check(x, y + dy) && !used[x][y + dy]) {
//            move(x, y + dy, passed);
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    field.resize(n, vector<bool>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            char c;
//            cin >> c;
//            field[n - i - 1][j] = (c == '#');
//        }
//    }
//
//    priority_queue<vector<int>> q;
//    used.resize(n, vector<int>(m));
//    delta.resize(n, vector<int>(m));
//
//    for (int i = 0; i < m; ++i) {
//        q.push({0, 0, i});
//    }
//    while (!q.empty()) {
//        auto ceil = q.top();
//        q.pop();
//        ceil[0] = -ceil[0];
//        int x = ceil[1];
//        int y = ceil[2];
//        if (field[x][y]) {
//            if (used[x][y]) {
//                continue;
//            }
//            int cur_delta = ceil[0] + (x - ceil[0] > 0 ? delta[x - ceil[0] - 1][y] : 0);
//            vector<pair<int, int>> passed;
//            move(x, y, passed);
//            for (auto c : passed) {
//                delta[c.first][c.second] = cur_delta;
//                if (c.first + 1 < n && !used[c.first + 1][c.second]) {
//                    q.push({0, c.first + 1, c.second});
//                }
//            }
//        }
//        if (x + 1 < n && !used[x + 1][y]) {
//            ceil[0] = -ceil[0] - 1;
//            ceil[1]++;
//            q.push(ceil);
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (!field[i][j]) {
//                continue;
//            }
//            field[i][j] = false;
//            field[i - delta[i][j]][j] = true;
//        }
//    }
//    cout << endl;
//    for (int i = n - 1; i >= 0; --i) {
//        for (int j = 0; j < m; ++j) {
//            cout << (field[i][j] ? '#' : '.');
//        }
//        cout << endl;
//    }
//}
