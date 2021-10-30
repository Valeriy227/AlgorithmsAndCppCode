#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> used;
vector<vector<int>> dp;
vector<vector<int>> mid;
vector<vector<pair<int, int>>> edge;

void rebuild(int l, int r) {
    if (l == r) {
        return;
    }
    int ind = lower_bound(edge[l].begin(), edge[l].end(), make_pair(r, 0)) - edge[l].begin();
    if (ind < edge[l].size() && edge[l][ind].first == r) {
        used[edge[l][ind].second - 1] = true;
    }
    if (l + 1 == r) {
        return;
    }
    if (dp[l][l + 1] + dp[l + 1][r] > dp[l][r - 1] + dp[r - 1][r]) {
        rebuild(l, l + 1);
        rebuild(l + 1, r);
    }
    else {
        rebuild(l, r - 1);
        rebuild(r - 1, r);
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> v(n);
    set<int> us;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        us.insert(l);
        us.insert(r);
        v[i] = {l, r};
    }
    unordered_map<int, int> um;
    int m = 0;
    for (auto i : us) {
        um[i] = m++;
    }
    edge.resize(m);
    for (int i = 0; i < n; ++i) {
        edge[um[v[i].first]].push_back({um[v[i].second], i + 1});
    }
    for (int i = 0; i < m; ++i) {
        sort(edge[i].begin(), edge[i].end());
    }

    dp.resize(m, vector<int>(m));
    mid.resize(m, vector<int>(m));
    for (int i = m - 2; i >= 0; --i) {
        for (int j = i + 1; j < m; ++j) {
            if (dp[i + 1][j] > dp[i][j - 1]) {
                mid[i][j] = i + 1;
            }
            else {
                mid[i][j] = j - 1;
            }
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

            bool is_edge = false;
            for (auto e : edge[i]) {
                if (e.first == j) {
                    is_edge = true;
                }
                if (e.first >= j) {
                    break;
                }
                if (dp[i][e.first] + dp[e.first][j] > dp[i][j]) {
                    mid[i][j] = e.first;
                    dp[i][j] = dp[i][e.first] + dp[e.first][j];
                }
            }
            dp[i][j] += is_edge;
        }
    }

    used.resize(n);
    rebuild(0, m - 1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}
