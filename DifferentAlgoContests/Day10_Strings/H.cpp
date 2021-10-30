//#include <bits/stdc++.h>
////#define endl "\n"
//
//using namespace std;
//
//typedef long long ll;
//
//struct node {
//    int suf;
//    int parent;
//    int height;
//    vector<int> next;
//    node() {
//        height = 0;
//        suf = -1;
//        parent = -1;
//        next.resize(26, -1);
//    }
//};
//
//ll ans = 0;
//vector<node> s;
//
//int add(int a, int ch) {
//    int b = s.size();
//    s.push_back({});
//    s[b].height = s[a].height + 1;
//    s[b].suf = 0;
//    s[b].parent = a;
//    for (; a != -1; a = s[a].suf) {
//        if (s[a].next[ch] == -1) {
//            s[a].next[ch] = b;
//            continue;
//        }
//        int c = s[a].next[ch];
//        if (s[c].parent == a) {
//            s[b].suf = c;
//            break;
//        }
//        int d = s.size();
//        s.push_back({});
//        s[d].parent = a;
//        s[d].suf = s[c].suf;
//        s[d].height = s[a].height + 1;
//        s[c].suf = d;
//        s[b].suf = d;
//        for (int i = 0; i < 26; ++i) {
//            s[d].next[i] = s[c].next[i];
//        }
//        for (; a != -1 && s[a].next[ch] == c; a = s[a].suf) {
//            s[a].next[ch] = d;
//        }
//        break;
//    }
//    ans += s[b].height - s[s[b].suf].height;
//    return b;
//}
//
//int main() {
//    freopen("keepcounted.in", "r", stdin);
//    freopen("keepcounted.out", "w", stdout);
//    string str;
//    cin >> str;
//    s.push_back({});
//    int last = 0;
//    for (char c : str) {
//        last = add(last, c - 'a');
//        cout << ans << endl;
//    }
//}
//
////abbacabccacaac
