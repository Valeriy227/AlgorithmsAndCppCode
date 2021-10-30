//#include <bits/stdc++.h>
//#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//int n, m;
//ll sum[4][1000][1000];
//
//int next(int ind) {
//    return ((ind + 1) | ind);
//}
//
//int prev(int ind) {
//    return ((ind + 1) & ind) - 1;
//}
//
//void add(ll val, int indi, int indj) {
//    for (int i = indi; i < n; i = next(i)) {
//        for (int j = indj; j < m; j = next(j)) {
//            sum[0][i][j] += val;
//            sum[1][i][j] += val * (j - indj + 1);
//            sum[2][i][j] += val * (i - indi + 1);
//            sum[3][i][j] += val * (i - indi + 1) * (j - indj + 1);
//        }
//    }
//}
//
//ll get(int indi, int indj) {
//    ll res = 0;
//    for (int i = indi; i >= 0; i = prev(i)) {
//        for (int j = indj; j >= 0; j = prev(j)) {
//            res += sum[3][i][j] + sum[1][i][j] * (indi - i) + (sum[2][i][j] + sum[0][i][j] * (indi - i)) * (indj - j);
//        }
//    }
//    return res;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> n >> m;
////    sum.resize(4, vector<vector<ll>>(n, vector<ll>(m)));
//    for (int k = 0; k < 4; ++k) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                sum[k][i][j] = 0;
//            }
//        }
//    }
//    int q;
//    cin >> q;
//    while (q) {
//        q--;
//        int c;
//        cin >> c;
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        if (c == 1) {
//            int w;
//            cin >> w;
//            add(w, x1 - 1, y1 - 1);
//            add(-w, x2, y1 - 1);
//            add(-w, x1 - 1, y2);
//            add(w, x2, y2);
//        }
//        else {
//            cout << get(x2 - 1, y2 - 1) -
//                    get(x2 - 1, y1 - 2) -
//                    get(x1 - 2, y2 - 1) +
//                    get(x1 - 2, y1 - 2) << endl;
//        }
//    }
//}
