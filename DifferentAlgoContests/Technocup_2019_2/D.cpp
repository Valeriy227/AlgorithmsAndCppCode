//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int cnt_primes;
//vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397};
//
//int get_ps(int x, vector<int> &ps, int k) {
//    for (int i = 0; i < cnt_primes; ++i) {
//        while (x % primes[i] == 0) {
//            ps[i]++;
//            x /= primes[i];
//        }
//    }
//    for (int j = 0; j < cnt_primes; ++j) {
//        ps[j] %= k;
//    }
//    return x;
//}
//
//ll hashh(vector<int> &v) {
//    ll mod = 1e9 + 7;
//    ll p = 31;
//    ll res = 0;
//    for (int i = 0; i < cnt_primes; ++i) {
//        res = (res * p + (v[i] + 1)) % mod;
//    }
//    return res;
//}
//
//int main() {
//    cnt_primes = primes.size();
//    int n, k;
//    cin >> n >> k;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    map<ll, vector<int>> m;
//    vector<vector<int>> ps(n, vector<int>(cnt_primes));
//    for (int i = 0; i < n; ++i) {
//        int x = get_ps(v[i], ps[i], k);
//        v[i] = x;
//        ll h = hashh(ps[i]);
//        m[h].push_back(x);
//    }
//    unordered_set<ll> us;
//    ll ans = 0;
//    for (int i = 0; i < n; ++i) {
//        int x = v[i];
//        ll h = hashh(ps[i]);
//        if (us.count(h) > 0) {
//            continue;
//        }
//        us.insert(h);
//        vector<int> neg(cnt_primes);
//        for (int j = 0; j < cnt_primes; ++j) {
//            neg[j] = (k - ps[i][j]) % k;
//        }
//        ll neg_h = hashh(neg);
//        us.insert(neg_h);
//        if (k > 2) {
//            ll cnt = 0;
//            for (int j : m[h]) {
//                if (j == 1) {
//                    cnt++;
//                }
//            }
//            if (neg_h == h) {
//                ans += cnt * (cnt - 1) / 2;
//                continue;
//            }
//            ll neg_cnt = 0;
//            for (int j : m[neg_h]) {
//                if (j == 1) {
//                    neg_cnt++;
//                }
//            }
//            ans += neg_cnt * cnt;
//        } else {
//            unordered_map<int, ll> um;
//            for (int j : m[h]) {
//                if (um.count(j) == 0) {
//                    um[j] = 1;
//                } else {
//                    um[j]++;
//                }
//            }
//            if (neg_h == h) {
//                for (auto j : um) {
//                    ans += j.second * (j.second - 1) / 2;
//                }
//            } else {
//                for (int j : m[neg_h]) {
//                    if (um.count(j) > 0) {
//                        ans += um[j];
//                    }
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//}
