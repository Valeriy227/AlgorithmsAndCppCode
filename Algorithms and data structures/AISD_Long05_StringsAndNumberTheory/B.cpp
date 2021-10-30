#include <bits/stdc++.h>

using namespace std;

struct Node {
    vector<Node*> go;
    Node* suf;
    int used;
    bool has_term;

    Node() {
        go.resize(2);
        has_term = false;
        suf = 0;
        used = 0;
    }
};

void add_word(Node* root, string& s) {
    auto cur = root;
    for (int i = 0; i < s.length(); ++i) {
        int val = s[i] - '0';
        if (!cur->go[val]) {
            cur->go[val] = new Node;
        }
        if (i + 1 == s.length()) {
            cur->go[val]->has_term = true;
        }
        cur = cur->go[val];
    }
}

Node* get_suf(Node* cur, int val, Node* v) {
    if (cur->go[val]) {
        if (cur->go[val] == v) {
            return cur;
        }
        return cur->go[val];
    } else {
        if (cur->suf == cur) {
            return cur;
        }
        return get_suf(cur->suf, val, v);
    }
}

void calc_suf_links(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int val = 0; val < 2; ++val) {
            if (cur->go[val]) {
                if (!cur->go[val]->suf) {
                    cur->go[val]->suf = get_suf(cur->suf, val, cur->go[val]);
                    if (cur->go[val]->suf->has_term || cur->has_term) {
                        cur->go[val]->has_term = true;
                    }
                }
                q.push(cur->go[val]);
            }
        }
    }
}

void close_jupms(Node* root) {
    queue<Node*> q;
    q.push(root);
    vector<Node*> v;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int val = 0; val < 2; ++val) {
            if (!cur->go[val]) {
                if (!cur->suf->go[val]) {
                    cur->go[val] = cur->suf;
                } else {
                    cur->go[val] = cur->suf->go[val];
                }
            } else {
                q.push();

                v.push_back(cur->go[val]);
            }
        }
    }
    for (auto cur ) {
        auto cur = q.front();
        q.pop();
        for (int val = 0; val < 2; ++val) {
            if (!cur->go[val]) {
                if (!cur->suf->go[val]) {
                    cur->go[val] = cur->suf;
                } else {
                    cur->go[val] = cur->suf->go[val];
                }
            } else {
                q.push();

                v.push_back(cur->go[val]);
            }
        }
    }
}

bool find_circle(Node* cur) {
    cur->used = 1;
    for (int val = 0; val < 2; ++val) {
        if (!cur->go[val]->has_term) {
            if (cur->go[val]->used == 1) {
                return true;
            }
            if (find_circle(cur->go[val])) {
                return true;
            }
        }
    }
    cur->used = 2;
    return false;
}

int main() {
    auto root = new Node;
    root->suf = root;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add_word(root, s);
    }

    calc_suf_links(root);
    close_jupms(root);

    if (find_circle(root)) {
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }
}
