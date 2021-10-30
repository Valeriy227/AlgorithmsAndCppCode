#include <iostream>
#include <vector>

using namespace std;

struct node {
   int next[26];
   int anc;
   int suff;

   node() {
       for (int i = 0; i < 26; ++i) {
           next[i] = -1;
       }
       suff = -1;
       anc = -1;
   }
};

vector<node> s;
vector<int> sz;

int add(int a, int ch) {
   int b = s.size();
   s.push_back(node());
   s[b].anc = a;
   s[b].suff = 0;

   for (; a != -1; a = s[a].suff) {
       if (s[a].next[ch] == -1) {
           s[a].next[ch] = b;
           continue;
       }

       int c = s[a].next[ch];
       if (s[c].anc == a) {
           s[b].suff = c;
           break;
       }

       int d = s.size();
       s.push_back(node());
       s[d].anc = a;
       s[d].suff = s[c].suff;
       s[c].suff = d;
       s[b].suff = d;
       for (int i = 0; i < 26; ++i) {
           s[d].next[i] = s[c].next[i];
       }
       for (; a != -1 && s[a].next[ch] == c; a = s[a].suff) {
           s[a].next[ch] = d;
       }
       break;
   }
   return b;
}

//void dfs(int cv, vector<bool> &used) {
//    used[cv] = 1;
//    if (cv != 0) {
//        sz[cv] += sz[s[cv].anc];
//        if (!used[s[cv].suff]) {
//            dfs(s[cv].suff, used);
//        }
//        sz[cv] += sz[s[cv].suff];
//    }
//    for (int i = 0; i < 26; ++i) {
//        if (s[cv].next[i] != -1 && !used[s[cv].next[i]]) {
//            dfs(s[cv].next[i], used);
//        }
//    }
//}

void calc_cnt(int cv, vector<long long> &cnt) {
   cnt[cv] = 0;
   for (int i = 0; i < 26; ++i) {
       if (s[cv].next[i] != -1) {
           if (cnt[s[cv].next[i]] == -1) {
               calc_cnt(s[cv].next[i], cnt);
           }
           cnt[cv] += cnt[s[cv].next[i]] + 1;
       }
   }
}

bool find_kth_str(int cv, vector<long long>& cnt, long long k) {
   if (k == 0) {
       return true;
   }
   for (int i = 0; i < 26; ++i) {
       if (s[cv].next[i] != -1) {
           if (cnt[s[cv].next[i]] + 1 >= k) {
               cout << (char)('a' + i);
               find_kth_str(s[cv].next[i], cnt, k - 1);
               return true;
           }
           k -= cnt[s[cv].next[i]] + 1;
       }
   }
   return false;
}

void find_last_str(int cv, vector<long long>& cnt) {
   for (int i = 25; i >= 0; --i) {
       if (s[cv].next[i] != -1) {
           cout << (char)('a' + i);
           find_last_str(s[cv].next[i], cnt);
           break;
       }
   }
}

int main() {
   string a;
   cin >> a;
   s.push_back(node());
   int cr = 0;
   for (int i = 0; i < a.length(); ++i) {
       cr = add(cr, a[i] - 'a');
   }

   vector<long long> cnt(s.size(), -1);
   calc_cnt(0, cnt);

   long long k;
   cin >> k;
   if (!find_kth_str(0, cnt, k)) {
       find_last_str(0, cnt);
   }
   cout << endl;
//    sz.resize(s.size(), 1);
//    sz[0] = 0;
//    vector<bool> used(sz.size());
//    dfs(0, used);
//    cr = 0;
//    for (int i = 0; i < a.length(); ++i) {
//        cout << sz[cr] << endl;
//        cr = s[cr].next[a[i] - 'a'];
//    }
}