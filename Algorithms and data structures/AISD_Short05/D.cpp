#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& g, int cv, vector<bool>& used, vector<bool>& useless, int t) {
    used[cv] = true;
    if (t == 0) {
        return;
    } else {
        useless[cv] = true;
    }
    for (int nv : g[cv]) {
        if (t == 2) {
            if (!useless[nv]) {
                dfs(g, nv, used, useless, t - 1);
            }
        } else {
            if (!used[nv]) {
                dfs(g, nv, used, useless, t - 1);
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = {g[i].size(), i};
    }
//    sort(v.rbegin(), v.rend());

    vector<bool> used(n);
    vector<bool> useless(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int cv = v[i].second;
        if (!used[cv]) {
            ans.push_back(cv);
            dfs(g, cv, used, useless, 2);
        }
    }
    if (ans.size() > k) {
        return -1;
    } else {
        cout << ans.size() << endl;
        for (int i : ans) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}