//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//const int log_maxn = 20;
//int curt = 0;
//vector<int> tin;
//vector<int> tout;
//vector<vector<int>> g;
//vector<vector<int>> bin_rises;
//
//void calc_bin_rises(int cv, int par) {
//    bin_rises[cv][0] = par;
//    for (int i = 1; i < log_maxn; ++i) {
//        if (bin_rises[cv][i - 1] == -1) {
//            break;
//        }
//        bin_rises[cv][i] = bin_rises[bin_rises[cv][i - 1]][i - 1];
//    }
//}
//
//void calc_tin_tout(int cv, int par) {
//    tin[cv] = curt++;
//    calc_bin_rises(cv, par);
//    for (int nv : g[cv]) {
//        if (nv != par) {
//            calc_tin_tout(nv, cv);
//        }
//    }
//    tout[cv] = curt++;
//}
//
//bool is_ancestor(int a, int b) {
//    if (a < 0) {
//        return true;
//    }
//    return tin[a] <= tin[b] && tout[b] <= tout[a];
//}
//
//int get_lca(int a, int b) {
//    if (is_ancestor(a, b)) {
//        return a;
//    }
//    if (is_ancestor(b, a)) {
//        return b;
//    }
//    for (int i = log_maxn - 1; i >= 0; --i) {
//        if (!is_ancestor(bin_rises[a][i], b)) {
//            a = bin_rises[a][i];
//        }
//    }
//    a = bin_rises[a][0];
//    return a;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    while (n != 0) {
//        g.clear();
//        tin.clear();
//        tout.clear();
//        bin_rises.clear();
//
//        g.resize(n);
//        tin.resize(n);
//        tout.resize(n);
//        bin_rises.resize(n, vector<int>(log_maxn, -1));
//        for (int i = 0; i < n - 1; ++i) {
//            int a, b;
//            cin >> a >> b;
//            g[a - 1].push_back(b - 1);
//            g[b - 1].push_back(a - 1);
//        }
//
//        calc_tin_tout(0, -1);
//
//        int root = 0;
//        int q;
//        cin >> q;
//        while (q) {
//            q--;
//            char c;
//            cin >> c;
//            if (c == '?') {
//                int a, b;
//                cin >> a >> b;
//                a--;
//                b--;
//                cout << (get_lca(a, b) ^ get_lca(a, root) ^ get_lca(b, root)) + 1 << endl;
//            } else {
//                cin >> root;
//                root--;
//            }
//        }
//        cin >> n;
//    }
//}
