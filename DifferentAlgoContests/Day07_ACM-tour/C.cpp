#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> a;

bool dfs(int cv, int aid, vector<vector<int>> &g) {
    if (cv == aid) {
        return true;
    }
    for (int nv : g[cv]) {
        if (dfs(nv, aid, g)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        edges.push_back({i + 1, p - 1});
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        vector<vector<int>> g(n);
        for (int j = 0; j < n - 1; ++j) {
            if (mask & (1 << j)) {
                g[edges[j].first].push_back(edges[j].second);
            }
            else {
                g[edges[j].second].push_back(edges[j].first);
            }
        }

        ll cur_ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (dfs(i, j, g)) {
                    if (i == j) {
                        cur_ans += a[i] * (a[i] - 1);
                    }
                    else {
                        cur_ans += a[i] * a[j];
                    }
                }
            }
        }
        ans = max(cur_ans, ans);
    }
    cout << ans << endl;
}
