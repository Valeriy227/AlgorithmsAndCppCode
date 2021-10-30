#include <iostream>
#include <vector>

using namespace std;

vector<int> key(26);

void calc_key() {
    int a = 2, b = 0;
    for (int i = 0; i < 26; ++i) {
        key[i] = a;
        b++;
        if (a == 7 || a == 9) {
            if (b == 4) {
                a++;
                b = 0;
            }
        } else {
            if (b == 3) {
                a++;
                b = 0;
            }
        }
    }
}

struct Node {
    int size;
    bool is_term;
    string* str;
    vector<Node*> next;
    int height;

    Node() {
        size = 0;
//        is_term = false;
        str = 0;
        next.resize(10);
        height = 0;
    }
};

void insert(Node* root, string* str) {
    auto cur = root;
    cur->size++;
    for (char c : *str) {
        if (!cur->str) {
            cur->str = str;
        } else {
            if (cur->str->length() != cur->height) {
                cur->str = nullptr;
            }
        }

        int k = key[c - 'a'];
        if (!cur->next[k]) {
            cur->next[k] = new Node();
            cur->next[k]->size = 0;
//            cur->next[k]->str = str;
            cur->next[k]->height = cur->height + 1;
        }
        cur = cur->next[k];
        cur->size++;
    }

    if (!cur->str) {
        cur->str = str;
    } else {
        if (cur->str->length() > str->length()) {
            cur->str = str;
        } else {
            if (cur->str > str) {
                cur->str = str;
            }
        }
    }
}

Node* go(Node* cur, int k, Node* root, string& ans) {
    if (!cur) {
        if (k == 1) {
            return root;
        }
        return nullptr;
    }
    if (k == 1) {
        if (!cur) {
            return root;
        } else {
            if (!cur->str || cur->height != cur->str->length()) {
                return root;
            } else {
                ans += *cur->str;
                ans += " ";
                return root;
            }
        }
    } else {
        cur = cur->next[k];
        if (cur && cur->size == 1) {
            ans += *cur->str;
            ans += " ";
            return root;
        }
        return cur;
    }
}

int main() {
    calc_key();
    int n;
    cin >> n;
    vector<string> v(n);
    auto root = new Node;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        insert(root, &v[i]);
    }
    int m;
    cin >> m;
    auto cur = root;
    string ans;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        cur = go(cur, k, root, ans);
    }
    cout << ans << endl;
}