//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//struct Hashes {
//    int n;
//    ll mod = 200720077;
//    ll p = 113;
//    vector<ll> pref;
//    vector<ll> pow;
//    Hashes(vector<int> &v) {
//        n = v.size();
//        pref.resize(n + 1);
//        pow.resize(n + 1, 1);
//        for (int i = 0; i < n; ++i) {
//            pow[i + 1] = pow[i] * p % mod;
//            pref[i + 1] = (pref[i] * p % mod + (v[i] + 1)) % mod;
//        }
//    }
//    ll get_hash(int l, int r) {
//        return (pref[r] - pref[l] * pow[r - l] % mod + mod) % mod;
//    }
//};
//
//vector<int> get_suf_mass(int n, vector<int> &v) {
//    vector<pair<int, int>> one_symbol(n);
//    for (int i = 0; i < n; ++i) {
//        one_symbol[i] = {v[i], i};
//    }
//    sort(one_symbol.begin(), one_symbol.end());
//    vector<int> col(n), h(n), a(n);
//    for (int i = 0; i < n; ++i) {
//        a[i] = one_symbol[i].second;
//        if (i > 0) {
//            col[a[i]] = col[a[i - 1]];
//        }
//        if (i > 0 && one_symbol[i].first != one_symbol[i - 1].first) {
//            col[a[i]]++;
//            h[col[a[i]]] = i;
//        }
//    }
//    int k = 1;
//    vector<int> new_a(n), new_col(n), new_h(n);
//    while (k < n) {
//        for (int i = 0; i < n; ++i) {
//            int ind = (a[i] - k + 2 * n) % n;
//            new_a[h[col[ind]]] = ind;
//            h[col[ind]]++;
//        }
//        new_h[0] = 0;
//        for (int i = 1; i < n; ++i) {
//            new_col[new_a[i]] = new_col[new_a[i - 1]];
//            if (col[new_a[i]] != col[new_a[i - 1]] ||
//                col[(new_a[i] + k) % n] != col[(new_a[i - 1] + k) % n]) {
//                new_col[new_a[i]]++;
//                new_h[new_col[new_a[i]]] = i;
//            }
//        }
//        swap(h, new_h);
//        swap(col, new_col);
//        swap(a, new_a);
//        k *= 2;
//    }
//    return a;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    while (n > 0) {
//        vector<int> v(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> v[i];
//        }
//        auto a = get_suf_mass(n, v);
//        vector<int> v2(2 * n);
//        for (int i = 0; i < n; ++i) {
//            v2[i] = v2[i + n] = v[i];
//        }
//        Hashes hs(v2);
//        ll ans = 0;
//        for (int i = 0; i < n - 1; ++i) {
//            int l = 0, r = n + 1;
//            while (l + 1 < r) {
//                int mid = (l + r) / 2;
//                ll h1 = hs.get_hash(a[i], a[i] + mid);
//                ll h2 = hs.get_hash(a[i + 1], a[i + 1] + mid);
//                if (h1 == h2) {
//                    l = mid;
//                } else {
//                    r = mid;
//                }
//            }
//            ans += l;
//        }
//        cout << ans << endl;
//        cin >> n;
//    }
//}
