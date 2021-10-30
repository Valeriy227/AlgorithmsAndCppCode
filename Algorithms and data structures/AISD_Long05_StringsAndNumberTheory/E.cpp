#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e7 + 1;
bool is_prime[MAX_N];
int pref[MAX_N];
//vector<bool> is_prime(MAX_N);
//vector<int> pref(MAX_N);

void eratosthen() {
   for (int i = 0; i < MAX_N; ++i) {
       is_prime[i] = true;
   }
   is_prime[0] = is_prime[1] = false;
   for (long long i = 2; i < MAX_N; ++i) {
       if (!is_prime[i]) {
           continue;
       }
       for (long long j = i * i; j < MAX_N; j += i) {
           is_prime[j] = false;
       }
   }
}

void calc_pref() {
   pref[0] = 0;
   for (int i = 1; i < MAX_N; ++i) {
       pref[i] = pref[i - 1] + is_prime[i];
   }
}

int get_cnt(int l, int r) {
   return pref[r] - pref[l - 1];
}

void find_segment(int len, int k) {
//    for (int i = 1; i <= MAX_N - len; ++i) {
//        if (get_cnt(i, i + len - 1) == k) {
//            cout << i << " " << i + len - 1 << endl;
//            return;
//        }
//    }
//    cout << -1 << endl;
   int l = 1, r = MAX_N - len;
   while (l + 1 < r) {
       int mid = (l + r) / 2;
       if (get_cnt(mid, mid + len - 1) < k) {
           r = mid;
       } else {
           l = mid;
       }
   }

   for (int i = -100; i < 100; ++i) {
       if (l + i < 1 || l + i + len > MAX_N) {
           continue;
       }
       if (get_cnt(l + i, l + i + len - 1) == k) {
           cout << l + i << " " << l + i + len - 1 << endl;
           return;
       }
   }
   cout << -1 << endl;
}

int main() {
   eratosthen();

   calc_pref();

   int q;
   cin >> q;
   for (int i = 0; i < q; ++i) {
       int l, k;
       cin >> l >> k;
       find_segment(l, k);
   }
}
