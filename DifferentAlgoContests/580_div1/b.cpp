#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans = 1e9;
vector<vector<int>> g;

void dfs(int cv, int pv, int start, vector<int> &depth) {
    for (int nv : g[cv]) {
        if (nv == pv) {
            continue;
        }
        if (nv == start) {
            ans = min(ans, depth[cv]);
        } else if (depth[nv] > depth[cv] + 1) {
            depth[nv] = depth[cv] + 1;
            dfs(nv, cv, start, depth);
        }
    }
}

void drop_zero(vector<ll> &v) {
    vector<ll> res;
    for (ll i : v) {
        if (i != 0) {
            res.push_back(i);
        }
    }
    swap(res, v);
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int m = 70;
    vector<vector<int>> bit_carriers(m);
    for (int i = 0; i < n; ++i) {
        ll p = 1;
        for (int j = 0; j < m; ++j) {
            if ((p & v[i]) != 0) {
                bit_carriers[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (bit_carriers[i].size() > 2) {
            cout << 3 << endl;
            return 0;
        }
    }
    drop_zero(v);
    n = v.size();
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((v[i] & v[j]) != 0) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<int> depth(n, 1e9);
        depth[i] = 1;
        dfs(i, -1, i, depth);
    }
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
