#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int curt = 0;
int n;
vector<vector<int>> g;
vector<int> parent;
vector<int> sz;
vector<int> tin;
vector<int> tout;
vector<int> lift;
vector<int> wizards;
vector<int> st;
vector<int> order;

void calc_sz(int cv, int pv) {
    parent[cv] = pv;
    sz[cv] = 1;
    int ind = -1;
    for (int i = 0; i < (int)g[cv].size(); ++i) {
        int nv = g[cv][i];
        if (nv != pv) {
            calc_sz(nv, cv);
            sz[cv] += sz[nv];
            if (ind == -1 || sz[nv] > sz[g[cv][ind]]) {
                ind = i;
            }
        }
    }
    if (ind > -1) {
        swap(g[cv][ind], g[cv][0]);
    }
}

void calc_tin_tout(int cv, int pv) {
    tin[cv] = curt++;
    for (int nv : g[cv]) {
        if (nv != pv) {
            calc_tin_tout(nv, cv);
        }
    }
    tout[cv] = curt;
}

void build_hld(int cv, int pv, int start) {
    lift[cv] = start;
    if (sz[cv] > 1) {
        build_hld(g[cv][0], cv, start);
    }
    for (int i = 1; i < (int)g[cv].size(); ++i) {
        int nv = g[cv][i];
        if (nv != pv) {
            build_hld(nv, cv, nv);
        }
    }
}

void build_st(int l = 0, int r = n, int cv = 1) {
    if (l + 1 == r) {
        st[cv] = wizards[order[l]];
    } else {
        int mid = (l + r) / 2;
        build_st(l, mid, cv * 2);
        build_st(mid, r, cv * 2 + 1);
        st[cv] = max(st[cv * 2], st[cv * 2 + 1]);
    }
}

void update_st(int ind, int x, int l = 0, int r = n, int cv = 1) {
    if (l + 1 == r) {
        st[cv] = x;
    } else {
        int mid = (l + r) / 2;
        if (ind < mid) {
            update_st(ind, x, l, mid, cv * 2);
        } else {
            update_st(ind, x, mid, r, cv * 2 + 1);
        }
        st[cv] = max(st[cv * 2], st[cv * 2 + 1]);
    }
}

int get_st(int ll, int rr, int l = 0, int r = n, int cv = 1) {
    if (ll >= rr) {
        return -1;
    }
    if (ll == l && rr == r) {
        return st[cv];
    }
    int mid = (l + r) / 2;
    return max(get_st(ll, min(rr, mid), l, mid, cv * 2),
               get_st(max(ll, mid), rr, mid, r, cv * 2 + 1));
}

bool is_ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int get_up(int &a, int &b) {
    int res = wizards[a];
    while (!is_ancestor(a, b)) {
        if (lift[a] == a) {
            a = parent[a];
            res = max(res, wizards[a]);
        } else {
            if (is_ancestor(lift[a], b)) {
                break;
            } else {
                res = max(res, get_st(tin[lift[a]], tin[a] + 1));
                a = lift[a];
            }
        }
    }
    return res;
}

int main() {
    cin >> n;
    g.resize(n);
    parent.resize(n);
    tin.resize(n);
    tout.resize(n);
    sz.resize(n);
    lift.resize(n);
    wizards.resize(n);
    st.resize(4 * n);
    order.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> wizards[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    calc_sz(0, -1);
    calc_tin_tout(0, -1);
    build_hld(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        order[tin[i]] = i;
    }
    build_st();

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        if (c == '?') {
            a--;
            b--;
            int res = get_up(a, b);
            res = max(res, get_up(b, a));
            a = tin[a];
            b = tin[b];
            if (a > b) {
                swap(a, b);
            }
            res = max(res, get_st(a, b));
            cout << res << endl;
        } else {
            wizards[a - 1] = b;
            a = tin[a - 1];
            update_st(a, b);
        }
    }
}
