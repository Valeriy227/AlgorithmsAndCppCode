#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<bool>> hor, vert;
vector<vector<bool>> ans;

void fill(int h) {
    for (int i = 0; i < m - 1; ++i) {
        if (hor[h][i]) {
            ans[h][i + 1] = ans[h][i];
        } else {
            ans[h][i + 1] = !ans[h][i];
        }
    }
}

bool fit(int h) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        bool equal = (ans[h - 1][i] == ans[h][i]);
        sum += !(equal ^ vert[h - 1][i]);
    }
    if (sum * 2 < m) {
        for (int i = 0; i < m; ++i) {
            ans[h][i] = !ans[h][i];
        }
    }
}

int input_hor() {

}

int main() {
    int k;
    cin >> n >> m >> k;
    hor.resize(max(n, m), vector<bool>(max(n, m)));
    vert.resize(max(n, m), vector<bool>(max(n, m)));

    bool to_T = (n > m);
    int cnt_e = 0;
    for (int i = 0; i < n * 2 - 1; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m - 1; ++j) {
                char c;
                cin >> c;
                if (!to_T) {
                    hor[i / 2][j] = (c == 'E');
                    cnt_e += hor[i / 2][j];
                } else {
                    vert[j][i / 2] = (c == 'E');
                    cnt_e += vert[j][i / 2];
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if (!to_T) {
                    vert[i / 2][j] = (c == 'E');
                    cnt_e += vert[i / 2][j];
                } else {
                    hor[j][i / 2] = (c == 'E');
                    cnt_e += hor[j][i / 2];
                }
            }
        }
    }

    if (k == 1) {
        if (cnt_e * 4 >= 3 * ((n - 1) * m + n * (m - 1))) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << 1 << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (to_T) {
            swap(n, m);
        }
        cout << "YES" << endl;
        ans.resize(n, vector<bool>(m));
        fill(0);
        for (int i = 1; i < n; ++i) {
            fill(i);
            fit(i);
        }
        if (to_T) {
            swap(n, m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << (int)(to_T ? ans[j][i] : ans[i][j]) + 1 << " ";
            }
            cout << endl;
        }
    }
}