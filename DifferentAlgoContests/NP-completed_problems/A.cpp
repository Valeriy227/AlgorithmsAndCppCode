//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//vector<ll> v;
//
//unordered_map<ll, ll> f(int l, int r) {
//    if (l == r) {
//        unordered_map<ll, ll> res;
//        res[0] += 1;
//        return res;
//    }
//    if (l + 1 == r) {
//        unordered_map<ll, ll> res;
//        res[v[l]] = 1;
//        res[0] += 1;
//        return res;
//    }
//    int mid = (l + r) / 2;
//    auto res1 = f(l, mid);
//    auto res2 = f(mid, r);
//    unordered_map<ll, ll> res;
////    for (auto i : res1) {
////        res[i.first] = i.second;
////    }
////    for (auto i : res2) {
////        res[i.first] += i.second;
////    }
//    for (auto i : res1) {
//        for (auto j : res2) {
//            res[i.first + j.first] += i.second * j.second;
//        }
//    }
//    return res;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    v.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    ll c;
//    cin >> c;
//    int mid = n / 2;
//    auto res1 = f(0, mid);
//    auto res2 = f(mid, n);
//    ll ans = 0;
//    vector<pair<ll, ll>> v2;
//    vector<pair<ll, ll>> pref = {{-1ll, 0ll}};
//    for (auto i : res2) {
//        v2.push_back(i);
//    }
//    sort(v2.begin(), v2.end());
//    for (auto i : v2) {
//        pref.push_back({i.first, pref.back().second + i.second});
//    }
//    for (auto i : res1) {
//        int ind = upper_bound(pref.begin(), pref.end(),
//                make_pair(c - i.first, (ll)1e15)) - pref.begin();
//        if (ind > 0) {
//            ans += i.second * pref[ind - 1].second;
//        }
//    }
//    cout << ans << endl;
//}
