//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n;
//unordered_set<int> sets;
//
//bool check(int k, vector<int> &v) {
//    vector<bool> used(n);
//    for (int i = 0; i < k; ++i) {
//        if (v[i] > n || used[v[i] - 1]) {
//            return false;
//        }
//        used[v[i] - 1] = true;
//    }
//    return true;
//}
//
//int get_hash(int k, vector<int> &v) {
//    int h = 0;
//    for (int i = 0; i < k; ++i) {
//        h += (1 << (v[i] - 1));
//    }
//    return h;
//}
//
//bool check_subsets(int h) {
//    for (int i = 0; i < n; ++i) {
//        if (h & (1 << i)) {
//            h -= (1 << i);
//            if (sets.count(h) == 0) {
//                return false;
//            }
//            h += (1 << i);
//        }
//    }
//    return true;
//}
//
//int get_sz(int h) {
//    int res = 0;
//    for (int i = 0; i < n; ++i) {
//        if (h & (1 << i)) {
//            res++;
//        }
//    }
//    return res;
//}
//
//bool check_drop(int a, int b) {
//    for (int i = 0; i < n; ++i) {
//        if ((b & (1 << i)) && !(a & (1 << i))) {
//            a += (1 << i);
//            if (sets.count(a) != 0) {
//                return true;
//            }
//            a -= (1 << i);
//        }
//    }
//    return false;
//}
//
//int main() {
//    int m;
//    cin >> n >> m;
//    if (m == 0) {
//        cout << "NO" << endl;
//        return 0;
//    }
//    for (int i = 0; i < m; ++i) {
//        int k = 0;
//        cin >> k;
//        vector<int> v(k);
//        for (int j = 0; j < k; ++j) {
//            cin >> v[j];
//        }
//        if (!check(k, v)) {
//            cout << "NO" << endl;
//            return 0;
//        }
//        int h = get_hash(k, v);
//        sets.insert(h);
//    }
//
//    for (int i : sets) {
//        if (!check_subsets(i)) {
//            cout << "NO" << endl;
//            return 0;
//        }
//    }
//
//    for (int i : sets) {
//        for (int j : sets) {
//            if (get_sz(i) < get_sz(j)) {
//                if (!check_drop(i, j)) {
//                    cout << "NO" << endl;
//                    return 0;
//                }
//            }
//        }
//    }
//    cout << "YES" << endl;
//}
