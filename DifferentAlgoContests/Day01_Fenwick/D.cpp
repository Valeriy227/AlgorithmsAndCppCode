//#include <bits/stdc++.h>
//#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//mt19937 gen(2007);
//
//struct node {
//    pair<int, int> val;
//    ll priority;
//    int sz;
//    node *left, *right;
//    node(pair<int, int> val) : val(val), priority(gen()), sz(1), left(0), right(0) {}
//};
//
//int get_sz(node *root) {
//    if (!root) {
//        return 0;
//    }
//    return root->sz;
//}
//
//void resize(node *root) {
//    root->sz = get_sz(root->left) + get_sz(root->right) + 1;
//}
//
//node* merge(node* l, node* r) {
//    if (!l) {
//        return r;
//    }
//    if (!r) {
//        return l;
//    }
//    if (l->priority > r->priority) {
//        l->right = merge(l->right, r);
//        resize(l);
//        return l;
//    } else {
//        r->left = merge(l, r->left);
//        resize(r);
//        return r;
//    }
//}
//
//pair<node*, node*> split(node* root, pair<int, int> val) {
//    if (!root) {
//        return {0, 0};
//    }
//    if (root->val <= val) {
//        auto res = split(root->right, val);
//        root->right = res.first;
//        resize(root);
//        return {root, res.second};
//    } else {
//        auto res = split(root->left, val);
//        root->left = res.second;
//        resize(root);
//        return {res.first, root};
//    }
//}
//
//int order_by_key(node *root, pair<int, int> val) {
//    if (!root) {
//        return 0;
//    }
//    if (root->val <= val) {
//        return get_sz(root->left) + 1 + order_by_key(root->right, val);
//    } else {
//        return order_by_key(root->left, val);
//    }
//}
//
//node* insert(node *root, pair<int, int> val) {
//    auto cv = new node(val);
//    auto res = split(root, val);
//    return merge(res.first, merge(cv, res.second));
//}
//
//node* erase(node *root, pair<int, int> val) {
//    auto res2 = split(root, val);
//    auto res1 = split(res2.first, {val.first, val.second - 1});
//    return merge(res1.first, res2.second);
//}
//
//int n;
//vector<node*> s;
//
//void del(int ind, int x) {
//    for (int i = ind; i < n; i = ((i + 1) | i)) {
//        s[i] = erase(s[i], {x, ind});
//    }
//}
//
//void add(int ind, int x) {
//    for (int i = ind; i < n; i = ((i + 1) | i)) {
//        s[i] = insert(s[i], {x, ind});
//    }
//}
//
//int get(int p, int q, int ind) {
//    int res = 0;
//    for (; ind >= 0; ind = ((ind + 1) & ind) - 1) {
//        res += order_by_key(s[ind], {q, n + 1});
//        res -= order_by_key(s[ind], {p, -1});
//    }
//    return res;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int m;
//    cin >> n >> m;
//    vector<int> v(n);
//    s.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//        add(i, v[i]);
//    }
//    for (int i = 0; i < m; ++i) {
//        string q;
//        cin >> q;
//        if (q == "SET") {
//            int ind, val;
//            cin >> ind >> val;
//            ind--;
//            del(ind, v[ind]);
//            v[ind] = val;
//            add(ind, v[ind]);
//        } else {
//            int l, r, x, y;
//            cin >> l >> r >> x >> y;
//            cout << get(x, y, r - 1) - get(x, y, l - 2) << endl;
//        }
//    }
//}
