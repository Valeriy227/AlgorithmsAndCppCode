#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> v;
vector<ll> d;
vector<pair<ll, int>> st;

pair<ll, int> opt(pair<ll, int> a, pair<ll, int> b) {
    if (a.first == b.first) {
        if (a.second > b.second) {
            return a;
        } else {
            return b;
        }
    } else if (a.first < b.first) {
        return a;
    } else {
        return b;
    }
};

void build(int l = 0, int r = n, int cv = 1) {
    if (l + 1 == r) {
        st[cv] = {v[l], l};
    } else {
        int mid = (l + r) / 2;
        build(l, mid, cv * 2);
        build(mid, r, cv * 2 + 1);
        st[cv] = opt(st[cv * 2], st[cv * 2 + 1]);
    }
}

void push(int cv) {
    st[cv].first += d[cv];
    if (cv * 2 < 4 * n) {
        d[cv * 2] += d[cv];
        d[cv * 2 + 1] += d[cv];
    }
    d[cv] = 0;
}

void update(int ll, int rr, int x, int l = 0, int r = n, int cv = 1) {
    push(cv);
    if (ll >= rr) {
        return;
    }
    if (ll == l && rr == r) {
        d[cv] += x;
        push(cv);
        return;
    }
    int mid = (l + r) / 2;
    update(ll, min(rr, mid), x, l, mid, cv * 2);
    update(max(ll, mid), rr, x, mid, r, cv * 2 + 1);
    st[cv] = opt(st[cv * 2], st[cv * 2 + 1]);
}

int main() {
    cin >> n;
    v.resize(n);
    st.resize(4 * n);
    d.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    build();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int ind = st[1].second;
        update(ind, ind + 1, 1e18);
        update(ind + 1, n, -(i + 1));
        ans[ind] = i + 1;
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
