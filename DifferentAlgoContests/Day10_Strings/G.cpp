#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

//const int THE_SIZE_OF_THE_ENGLISH_ALPHABET_AS_THE_CONSTANT_INTEGER_NUMBER = 26;
const int ALPHABET_SZ = 26;

struct node {
    int suf;
    int parent;
    int height;
    vector<int> next;
    node() : suf(-1), parent(-1), height(0) {
        next.resize(ALPHABET_SZ, -1);
    }
};

ll ans = 0;
vector<node> s;

int add(int a, int ch) {
    int b = s.size();
    s.push_back({});
    s[b].height = s[a].height + 1;
    s[b].suf = 0;
    s[b].parent = a;
    for (; a != -1; a = s[a].suf) {
        if (s[a].next[ch] == -1) {
            s[a].next[ch] = b;
            continue;
        }
        int c = s[a].next[ch];
        if (s[c].parent == a) {
            s[b].suf = c;
            break;
        }
        int d = s.size();
        s.push_back({});
        s[d].parent = a;
        s[d].suf = s[c].suf;
        s[d].height = s[a].height + 1;
        s[c].suf = d;
        s[b].suf = d;
        for (int i = 0; i < ALPHABET_SZ; ++i) {
            s[d].next[i] = s[c].next[i];
        }
        for (; a != -1 && s[a].next[ch] == c; a = s[a].suf) {
            s[a].next[ch] = d;
        }
        break;
    }
    ans += s[b].height - s[s[b].suf].height;
    return b;
}

bool go(int &cv, int ch) {
    if (s[cv].next[ch] == -1) {
        return false;
    }
    cv = s[cv].next[ch];
    return true;
}

void low_case(string &str) {
    for (char &c : str) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
}

int main() {
//    freopen("nenokku.in", "r", stdin);
//    freopen("nenokku.out", "w", stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int last = 0;
    s.push_back({});
    char com;
    while (cin >> com) {
        string str;
        cin >> str;
        low_case(str);
        if (com == '?') {
            int cv = 0;
            bool flag = true;
            for (char ch : str) {
                if (!go(cv, ch - 'a')) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            for (char ch : str) {
                last = add(last, ch - 'a');
            }
        }
    }
}
