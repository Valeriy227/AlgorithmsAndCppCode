#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Bitset {
   int x = 0;
   Bitset(){}
   Bitset(int x) : x(x) {}
   void push_back(int val) {
       x <<= 2;
       x += val;
   }
   int back() {
       return x % 4;
   }
   void pop_back() {
       x >>= 2;
   }
};

ll hash_v(vector<int>& v) {
//    int mod = 1e9 + 7;
   ll p0 = 1791791791;
   ll p1 = 200720077;
   ll p2 = 45212177;
   return (p0 - v[0]) * (p0 - v[1]) * (p0 - v[2]);
//    return v[0] * p0 + v[1] * p1 + v[2] * p2;
}

void enumeration(vector<int>& val, Bitset& order, vector<vector<int>>& delta,
                int n, int k, unordered_map<ll, vector<int>>& map) {
   if (k == n) {
       int d = val[0];
       val[0] -= d;
       val[1] -= d;
       val[2] -= d;
       val.push_back(d);
       val.push_back(order.x);

       map[hash_v(val)] = val;

       d = -d;
       val[0] -= d;
       val[1] -= d;
       val[2] -= d;
       val.pop_back();
       val.pop_back();
       return;
   }
   for (int i = 0; i < 3; ++i) {
       val[i] += delta[k][i];
       order.push_back(i + 1);
       enumeration(val, order, delta, n, k + 1, map);
       order.pop_back();
       val[i] -= delta[k][i];
   }
}

unordered_map<ll, vector<int>> get_set(vector<vector<int>>& delta, int n) {
   unordered_map<ll, vector<int>> map;
   vector<int> val(3);
   Bitset order;
   enumeration(val, order, delta, n, 0, map);
   return map;
}

int max_val = -1e9;
Bitset ord1, ord2;

void enumeration2(vector<int>& val, Bitset& order, vector<vector<int>>& delta,
                 int n, int k, unordered_map<ll, vector<int>>& map) {
   if (k == n) {
       int d = val[0];
       val[0] -= d;
       val[1] -= d;
       val[2] -= d;

       auto cur = map.find(hash_v(val));

       if (cur != map.end()) {
           auto val2 = cur->second;
           if (val[0] == val2[0] &&
               val[1] == val2[1] &&
               val[2] == val2[2]) {
               if ((val[0] + d) - (val2[0] + val2[3]) > max_val) {
                   max_val = (val[0] + d) - (val2[0] + val2[3]);
                   ord1 = val2.back();
                   ord2 = order;
               }
           }
       }

       d = -d;
       val[0] -= d;
       val[1] -= d;
       val[2] -= d;
       return;
   }

   for (int i = 0; i < 3; ++i) {
       val[i] -= delta[k][i];
       order.push_back(i + 1);
       enumeration2(val, order, delta, n, k + 1, map);
       order.pop_back();
       val[i] += delta[k][i];
   }
}

vector<string> decode(Bitset bitset) {
   vector<string> res;
   while (bitset.x > 0) {
       int code = bitset.back();
       bitset.pop_back();
       if (code == 1) {
           res.push_back("MW");
       } else if (code == 2) {
           res.push_back("LW");
       } else {
           res.push_back("LM");
       }
   }
   reverse(res.begin(), res.end());
   return res;
}

int main() {
   int n;
   cin >> n;
   vector<int> sum(3);
   vector<vector<int>> delta(n, vector<int>(3));
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < 3; ++j) {
           cin >> delta[i][j];
           sum[j] += delta[i][j];
       }
   }

   auto set = get_set(delta, n / 2);

   Bitset order;
   enumeration2(sum, order, delta, n, n / 2, set);
   if (max_val == -1e9) {
       cout << "Impossible" << endl;
   } else {
       auto ans1 = decode(ord1);
       for (auto s : ans1) {
           cout << s << endl;
       }

       auto ans2 = decode(ord2);
       for (auto s : ans2) {
           cout << s << endl;
       }
   }
}
