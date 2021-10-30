//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int n;
//vector<int> a;
//
//int next(int ind) {
//    return ((ind + 1) | ind);
//}
//
//int prev(int ind) {
//    return ((ind + 1) & ind) - 1;
//}
//
//void add(int ind, int k) {
//    while (ind < n) {
//        a[ind] += k;
//        ind = next(ind);
//    }
//}
//
//int sum(int ind) {
//    int res = 0;
//    while (ind >= 0) {
//        res += a[ind];
//        ind = prev(ind);
//    }
//    return res;
//}
//
//int kth(int l, int r, int k) {
//    if (l + 1 == r) {
//        return l;
//    }
//    int mid = (l + r) / 2;
//    int left = sum(mid - 1) - sum(l - 1);
//    if (left >= k) {
//        return kth(l, mid, k);
//    }
//    else {
//        return kth(mid, r, k - left);
//    }
//}
//
//int main() {
//    cin >> n;
//    vector<int> v(n);
//    a.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//        if (v[i] == 0) {
//            add(i, 1);
//        }
//    }
//    int q;
//    cin >> q;
//    while (q > 0) {
//        q--;
//        char c;
//        cin >> c;
//        if (c == 'u') {
//            int ind, val;
//            cin >> ind >> val;
//            ind--;
//            if (v[ind] == 0) {
//                if (val != 0) {
//                    add(ind, -1);
//                }
//            }
//            else {
//                if (val == 0) {
//                    add(ind, 1);
//                }
//            }
//            v[ind] = val;
//        }
//        else {
//            int l, r, k;
//            cin >> l >> r >> k;
//            l--;
//            r--;
//            k += sum(l - 1);
//            if (sum(n - 1) < k) {
//                cout << -1 << endl;
//                continue;
//            }
//            int ind = kth(0, n, k);
//            if (ind > r) {
//                cout << -1 << endl;
//            }
//            else {
//                cout << ind + 1 << endl;
//            }
//        }
//    }
//}
