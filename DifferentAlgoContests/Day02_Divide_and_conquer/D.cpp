#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> dp;
vector<vector<int>> subrect;

void calc_subrect(vector<vector<int>> &distaste, int n) {
    subrect.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            subrect[i + 1][j + 1] = subrect[i + 1][j] + subrect[i][j + 1] - subrect[i][j] + distaste[i][j];
        }
    }
}

int sum(int l, int r) {
    return (subrect[r + 1][r + 1] - 2 * subrect[l][r + 1] + subrect[l][l]) / 2;
}

void div_and_conq(int l, int r, int optl, int optr, int k) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    int optmid = optl;
    int best = 2e9;
    for (int i = optl; i <= min(mid, optr); ++i) {
        int cur_best = sum(i - 1, mid - 1) + dp[i - 1][k - 1];
        if (cur_best < best) {
            best = cur_best;
            optmid = i;
        }
    }
    dp[mid][k] = best;
    div_and_conq(l, mid - 1, optl, optmid, k);
    div_and_conq(mid + 1, r, optmid, optr, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    dp.resize(n + 1, vector<int>(k + 1, 1e9));
    dp[0][0] = 0;
    vector<vector<int>> distaste(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distaste[i][j];
        }
    }

    calc_subrect(distaste, n);
    for (int i = 1; i <= k; ++i) {
        div_and_conq(1, n, 1, n, i);
    }
    cout << dp[n][k] << endl;
}
