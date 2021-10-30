#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll a, ll d) {
    if (d == 0) {
        return 0;
    }
    ll k = a / d;
    ll cnt2 = a % d;
    ll cnt1 = d - cnt2;
    return k * k * cnt1 + (k + 1) * (k + 1) * cnt2;
}

int max_d(int a, ll max_dif) {
    int l = 0, r = a;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (f(a, a - mid) - f(a, a - mid + 1) <= max_dif) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}

bool check(int n, ll e, vector<int> &v, ll max_dif) {
    for (int i = 0; i < n; ++i) {
        int cnt = v[i] - max_d(v[i], max_dif);
        e -= f(v[i], cnt);
    }
    return (e >= 0);
}

ll get_ans(int n, ll e, vector<int> &v, ll max_dif) {
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[i] = v[i] - max_d(v[i], max_dif);
        e -= f(v[i], cnt[i]);
    }
    max_dif++;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > 1) {
            ll dif = f(v[i], cnt[i] - 1) - f(v[i], cnt[i]);
            if (dif == max_dif && e >= dif) {
                e -= dif;
                cnt[i]--;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cnt[i];
    }
    return ans;
}

int main() {
    int n;
    ll e;
    cin >> n >> e;
    vector<int> potions(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> potions[i];
        //todo fenwick
        for (int j = 0; j < i; ++j) {
            if (potions[j] > potions[i]) {
                v[i]++;
            }
        }
    }

    ll l = -1, r = e;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(n, e, v, mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    if (l == -1) {
        cout << -1 << endl;
    }
    else {
        cout << get_ans(n, e, v, l) << endl;
    }
}
