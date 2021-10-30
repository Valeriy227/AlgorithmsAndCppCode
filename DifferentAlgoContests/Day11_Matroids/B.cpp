#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> right_opt;
vector<int> left_opt;
vector<vector<int>> g;
vector<bool> used;

bool check_chain(int cv) {
    used[cv] = true;
    for (int nv : g[cv]) {
        if (right_opt[nv] == -1) {
            left_opt[cv] = nv;
            right_opt[nv] = cv;
            return true;
        }
    }
    for (int nv : g[cv]) {
        if (!used[right_opt[nv]]) {
            if (check_chain(right_opt[nv])) {
                left_opt[cv] = nv;
                right_opt[nv] = cv;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].first = -v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<int> priority_ind(n);
    for (int i = 0; i < n; ++i) {
        priority_ind[v[i].second] = i;
    }

    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int ind = priority_ind[i];
        g[ind].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> g[ind][j];
            g[ind][j]--;
        }
    }
    right_opt.resize(n, -1);
    left_opt.resize(n, -1);
    while (true) {
        bool flag = false;
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (left_opt[i] == -1 && !used[i]) {
                if (check_chain(i)) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int ind = priority_ind[i];
        cout << left_opt[ind] + 1 << " ";
    }
    cout << endl;
}
