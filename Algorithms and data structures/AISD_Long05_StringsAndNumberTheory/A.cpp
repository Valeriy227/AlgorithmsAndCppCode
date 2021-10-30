#include <bits/stdc++.h>

using namespace std;

int type(char c) {
   if (c == '@') {
       return 0;
   }
   if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
       return 1;
   }
   if (c == '.') {
       return 2;
   }
   return 3;
}

vector<vector<int>> graph = {{7, 2, 7, 0},
                            {7, 2, 7, 0},
                            {4, 2, 3, 0},
                            {7, 2, 7, 0},
                            {7, 5, 7, 0},
                            {7, 5, 6, 1},
                            {7, 5, 7, 0},
                            {7, 7, 7, 0}};



int get_email_cnt(string& s) {
   s.push_back(' ');
   int state = 0;
   int res = 0;
   for (auto c : s) {
       state = graph[state][type(c)];
       if (state == 1) {
           res++;
       }
   }
   return res;
}

int main() {
   string s;
   int ans = 0;
   while (cin >> s) {
       ans += get_email_cnt(s);
   }
   cout << ans << endl;
}
