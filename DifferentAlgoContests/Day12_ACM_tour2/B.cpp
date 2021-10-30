#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> is_sword(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        is_sword[a - 1][b - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (is_sword[i][j] && is_sword[i][k]) {
                    is_sword[j][k] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (is_sword[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
