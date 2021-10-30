#include <bits/stdc++.h>
#include "grader.h"

using namespace std;

typedef long long ll;

vector<int> v;

int solve(int n, int a, int b, int *s, int *x, int *y) {
    v.clear();
    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            v.push_back(i);
        }
    }
    int m = v.size();
    if (m == 0) {
        return -1;
    }

    vector<int> pref;
    if (v[0] <= b) {
        pref.push_back(a);
    }
    for (int i = 1; i < m; ++i) {
        if (v[i] > pref[i - 1] + b) {
            return -1;
        }
        pref.push_back(min(n - 1, min(pref[i - 1], v[i] + b) + a));
        if (pref[i] == n - 1) {
            break;
        }
    }

    vector<pair<int, int>> ans;
    int ind = n - 1, j = pref.size() - 1;
    while (ind > 0) {
        while (j > 0 && pref[j - 1] >= ind) {
            j--;
        }
        ans.push_back({ind + 1, v[j] + 1});
        ind = max(ind - a, v[j] - b);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        x[i] = ans[i].first;
        y[i] = ans[i].second;
    }
    return ans.size();
}

//int main() {
//    int n, a, b;
//    while (cin >> n >> a >> b) {
//        int s[n], x[n], y[n];
//        for (int i = 0; i < n; ++i) {
//            char c;
//            cin >> c;
//            s[i] = (c == '1');
//        }
//        int ans = solve(n, a, b, s, x, y);
//        cout << ans << endl;
//        for (int i = 0; i < ans; ++i) {
//            cout << x[i] << " " << y[i] << endl;
//        }
//        cout << endl;
//    }
//}

