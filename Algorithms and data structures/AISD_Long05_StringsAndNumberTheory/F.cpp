#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string& s) {
   int n = s.size();
   vector<int> pref(n);
   for (int i = 1; i < n; ++i) {
       int cur = pref[i - 1];
       while (cur > 0 && s[cur] != s[i]) {
           cur = pref[cur - 1];
       }
       if (s[cur] == s[i]) {
           pref[i] = cur + 1;
       }
   }
   return pref;
}

vector<int> z_function(string& s) {
   int n = s.size();
   vector<int> z(n);
   int left = 0, right = 0;
   for (int i = 1; i < n; ++i) {
       z[i] = max(0, min(right - i, z[i - left]));
       for (int j = z[i]; j < n; ++j) {
           if (i + j < n && s[j] == s[i + j]) {
               z[i] = j + 1;
           } else {
               break;
           }
       }
       if (i + z[i] > right) {
           right = i + z[i];
           left = i;
       }
   }
//    auto pref = prefix_function(s);
//    vector<int> z(n);
//    for (int i = 0; i < n; ++i) {
//        z[i - pref[i] + 1] = max(z[i - pref[i] + 1], pref[i]);
//    }
//    for (int i = 1; i < n; ++i) {
//        z[i] = max(z[i], z[i - 1] - 1);
//    }
   return z;
}

vector<int> get_pref(string& p, string& t) {
   auto s = p + "#" + t;
   auto z = z_function(s);
   vector<int> res;
   copy(z.begin() + p.size() + 1, z.end(), back_inserter(res));
   return res;
}

vector<int> get_suf(string p, string t) {
   reverse(p.begin(), p.end());
   reverse(t.begin(), t.end());
   auto s = p + "#" + t;
   auto z = z_function(s);
   vector<int> res;
   copy(z.begin() + p.size() + 1, z.end(), back_inserter(res));
   reverse(res.begin(), res.end());
   return res;
}

void print(vector<int>& v) {
   for (int i : v) {
       cout << i << " ";
   }
   cout << endl;
}

int main() {
   string p, t;
   cin >> p >> t;
   vector<int> pref = get_pref(p, t);
   vector<int> suf = get_suf(p, t);

   vector<int> res;
   int n = p.size(), m = t.size();
   for (int i = 0; i + n - 1 < m; ++i) {
       if (pref[i] + suf[i + n - 1] >= n - 1) {
           res.push_back(i + 1);
       }
   }

   cout << res.size() << endl;
   print(res);
}
