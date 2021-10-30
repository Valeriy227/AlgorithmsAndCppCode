#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<bool> used;

void read(int k, int i, int j, int x) {
   used[x] = true;
   if (k == 0) {
       return;
   }
   for (int di = -1; di < 2; di += 2) {
       if (0 <= i + di && i + di < n) {
           read(k - 1, i + di, j, x * 10 + v[i + di][j]);
       }
   }
   for (int dj = -1; dj < 2; dj += 2) {
       if (0 <= j + dj && j + dj < m) {
           read(k - 1, i, j + dj, x * 10 + v[i][j + dj]);
       }
   }
}

int find_least() {
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < m; ++j) {
           if (v[i][j]) {
               read(5, i, j, v[i][j]);
           }
       }
   }
   for (int i = 1; i < 1e8; ++i) {
       if (!used[i]) {
           return i;
       }
   }
   return 0;
}

int main() {
   int t;
   cin >> t;
   while (t) {
       --t;

       used.assign(1e8, false);
       cin >> n >> m;
       v.clear();
       v.resize(n, vector<int>(m));
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               char c;
               cin >> c;
               v[i][j] = c - '0';
           }
       }

       cout << find_least() << endl;
   }
}
