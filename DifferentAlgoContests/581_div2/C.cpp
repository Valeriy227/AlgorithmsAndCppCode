#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '1') {
                g[i][j] = 1;
            } else {
                g[i][j] = 1e5;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        g[i][i] = 0;
    }

    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> ans = {p[0]};
    for (int i = 2; i < m; ++i) {
        if (g[ans.back()][p[i]] < g[ans.back()][p[i - 1]] + g[p[i - 1]][p[i]]) {
            ans.push_back(p[i - 1]);
        }
    }
    ans.push_back(p[m - 1]);

    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;
}
