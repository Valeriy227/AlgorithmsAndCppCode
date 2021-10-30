//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
//    if (a.first == b.first) {
//        return a.second > b.second;
//    }
//    return a.first > b.first;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<pair<ll, ll>> v(n);
//    ll sum = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i].first >> v[i].second;
//        sum += v[i].second;
//    }
//    sort(v.begin(), v.end(), cmp);
//    ll rest = 0;
//    multiset<ll> goal;
//    for (int i = 0; i < n; ++i) {
//        if (i > 0) {
//            rest = v[i - 1].first - v[i].first;
//        }
//        while (rest > 0 && !goal.empty()) {
//            rest--;
//            sum += *goal.begin();
//            goal.erase(goal.begin());
//        }
//        goal.insert(-v[i].second);
//    }
//    rest = v[n - 1].first;
//    while (rest > 0 && !goal.empty()) {
//        rest--;
//        sum += *goal.begin();
//        goal.erase(goal.begin());
//    }
//    cout << sum << endl;
//}
