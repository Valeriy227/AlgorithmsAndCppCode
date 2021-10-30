#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll mod = 998244353;
vector<pair<int, int>> v;

bool are_equal() {
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        if (v[i].second < v[i - 1].second) {
            return false;
        }
    }
    return true;
}

void swap_pairs() {
    for (int i = 0; i < n; ++i) {
        swap(v[i].first, v[i].second);
    }
}

ll get_product(ll a, ll b) {
    ll res = 1;
    for (ll i = a; i <= b; ++i) {
        res *= i;
        res %= mod;
    }
    return res;
}

ll calc_cnt() {
    sort(v.begin(), v.end());
    ll ans = 1;
    ll cur_cnt = 0;
    pair<int, int> last = {-1, -1};
    for (int i = 0; i < n; ++i) {
        if (v[i].first == last.first) {
            cur_cnt++;
        } else {
            ans *= get_product(1, cur_cnt);
            ans %= mod;
            cur_cnt = 1;
        }
        last = v[i];
    }
    ans *= get_product(1, cur_cnt);
    ans %= mod;
    return ans;
}

ll sorted_cnt() {
    if (are_equal()) {
        if (n > 1000) {
            cout << "Equal" << endl;
        }
        return calc_cnt();
    } else {
        ll res = calc_cnt();
        swap_pairs();
        res += calc_cnt();
        res %= mod;
        return res;
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    ll res = get_product(1, n);
    cout << (res - sorted_cnt() + 2 * mod) % mod << endl;
}
