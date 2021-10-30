#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> get_primes(int n) {
    vector<int> res = {};
    vector<bool> is_prime(n + 1, true);

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            res.push_back(i);
            for (int j = i; i * j <= n; ++j) {
                is_prime[i * j] = false;
            }
        }
    }
    return res;
}

int f(int p, int ind, int delta, vector<int> &v, int n) {
    if (delta > 2 * n) {
        return 0;
    }
    int res = 1e9;
    for (int i = 0; i < p; ++i) {
        int cur = 0;
        cur += f(p, ind + i * delta / p, delta * p, v, n);
        for (int j = ind + i * delta / p; j < n; j += delta) {
            cur += v[j];
        }
        res = min(res, cur);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> primes = get_primes(n);
    int m = primes.size();
    vector<int> min_pow(m, 1e9);
    for (int indp = 0; indp < m; ++indp) {
        int p = primes[indp];
        min_pow[indp] = f(p, 0, p, v, n);
    }
    ll mod = 1e9 + 7;
    ll res = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < min_pow[i]; ++j) {
            res = res * primes[i] % mod;
        }
    }
    cout << res << endl;
}