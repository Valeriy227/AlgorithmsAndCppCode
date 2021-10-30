//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//typedef long double ld;
//
//int n;
//ld min_dist;
//pair<ll, ll> ansa, ansb;
//vector<pair<ll, ll>> v;
//
//ld dist(int a, int b) {
//    return sqrt((v[a].first - v[b].first) * (v[a].first - v[b].first) +
//                (v[a].second - v[b].second) * (v[a].second - v[b].second));
//}
//
//void update(int a, int b) {
//    ld new_dist = dist(a, b);
//    if (new_dist < min_dist) {
//        min_dist = new_dist;
//        ansa = v[a];
//        ansb = v[b];
//    }
//}
//
//void div_and_conq(int l, int r) {
//    if (l + 1 == r) {
//        return;
//    }
//    if (l + 2 == r) {
//        if (v[l].second > v[l + 1].second) {
//            swap(v[l], v[l + 1]);
//        }
//        update(l, l + 1);
//        return;
//    }
//
//    int mid = (l + r) / 2;
//    ll x = v[mid].first;
//    div_and_conq(l, mid);
//    div_and_conq(mid, r);
//    vector<pair<ll, ll>> sorted;
//    int j = mid;
//    for (int i = l; i < mid; ++i) {
//        while (j < r && v[i].second > v[j].second) {
//            sorted.push_back(v[j]);
//            j++;
//        }
//        sorted.push_back(v[i]);
//    }
//    while (j < r) {
//        sorted.push_back(v[j]);
//        j++;
//    }
//
//    for (int i = l; i < r; ++i) {
//        v[i] = sorted[i - l];
//    }
//    vector<int> interesting;
//    for (int i = l; i < r; ++i) {
//        if (abs(x - v[i].first) <= min_dist) {
//            interesting.push_back(i);
//        }
//    }
//    for (int i = 0; i < interesting.size(); ++i) {
//        for (j = max(0, i - 8); j < i; ++j) {
//            update(interesting[i], interesting[j]);
//        }
//    }
//}
//
//void gen() {
//    v.clear();
//    n = rand() % 10000 + 1;
//    v.resize(n);
//    for (int i = 0; i < n; ++i) {
//        v[i] = {rand() % 1000, rand() % 1000};
//    }
//}
//
//ld solve1() {
//    cin >> n;
//    v.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i].first >> v[i].second;
//    }
//    sort(v.begin(), v.end());
//    min_dist = 1e12;
//    div_and_conq(0, n);
//    cout << ansa.first << " " << ansa.second << endl;
//    cout << ansb.first << " " << ansb.second << endl;
//    return min_dist;
//}
//
//ld solve2() {
//    ld ans = 1e12;
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            ans = min(ans, dist(i, j));
//        }
//    }
//    return ans;
//}
//
//int main() {
//    freopen("rendezvous.in", "r", stdin);
//    freopen("rendezvous.out", "w", stdout);
//    solve1();
////    srand(time(0));
////    for (int i = 0; i < 100; ++i) {
////        gen();
////        ld a = solve1();
////        ld b = solve2();
////        if (a != b) {
////            cout << "Pamm!!" << endl;
////            cout << n << endl;
////            for (auto i : v) {
////                cout << i.first << " " << i.second << endl;
////            }
////            break;
////        }
////    }
//}
//
