#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

struct cmpl {
   double real;
   double im;
   cmpl() : real(0), im(0) {}
   cmpl(double real) : real(real), im(0) {}
   cmpl(double real, double im) : real(real), im(im) {}
   cmpl operator*(cmpl t) const {
       cmpl res(real * t.real - im * t.im, real * t.im + t.real * im);
       return res;
   }
   cmpl operator/(double c) {
       cmpl res(real / c, im / c);
       return res;
   }
   cmpl operator+(cmpl t) const {
       cmpl res(real + t.real, im + t.im);
       return res;
   }
   cmpl operator-(cmpl t) const {
       cmpl res(real - t.real, im - t.im);
       return res;
   }
};

int reverse(int x) {
   vector<bool> bin;
   while (x > 0) {
       bin.push_back(x & 1);
       x /= 2;
   }
   while ((1 << (int)bin.size()) < n) {
       bin.push_back(0);
   }
   reverse(bin.begin(), bin.end());
   int res = 0;
   int p = 1;
   for (int i : bin) {
       res += p * i;
       p *= 2;
   }
   return res;
}

void fft(vector<cmpl> &a, bool flag) {
   for (int i = 0; i < n; ++i) {
       int j = reverse(i);
       if (i < j) {
           swap(a[i], a[j]);
       }
   }
   for (int l = 1; l < n; l *= 2) {
       double alpha = (flag ? -1 : 1) * M_PI / l;
       cmpl w(cos(alpha), sin(alpha));
       for (int i = 0; i < n; i += 2 * l) {
           cmpl wp(1.0);
           for (int j = 0; j < l; ++j) {
               cmpl u = a[i + j];
               cmpl v = a[i + j + l] * wp;
               a[i + j] = u + v;
               a[i + j + l] = u - v;
               wp = wp * w;
           }
       }
   }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
   vector<cmpl> ac(n), bc(n);
   for (int i = 0; i < n; ++i) {
       ac[i] = a[i];
       bc[i] = b[i];
   }
   fft(ac, false);
   fft(bc, false);
   vector<cmpl> resc(n);
   for (int i = 0; i < n; ++i) {
       resc[i] = (ac[i] * bc[i]);
   }
   fft(resc, true);
   for (int i = 0; i < n; ++i) {
       resc[i] = resc[i] / (n + 0.0);
   }
   vector<int> res(n);
   for (int i = 0; i < n; ++i) {
       res[i] = (int)round(resc[i].real);
   }
   return res;
}

void pow(int& xx) {
   int res = 2;
   while (res < xx) {
       res *= 2;
   }
   xx = res;
}

int main() {
   freopen("duel.in", "r", stdin);
   freopen("duel.out", "w", stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin >> s;
   int nn = s.length();
   n = s.length() * 2;
   pow(n);
   vector<int> v(n);
   for (int i = 0; i < nn; ++i) {
       v[i] = s[i] - '0';
   }
   auto res = multiply(v, v);
   ll sum = 0;
   for (int i = 0; i < nn; ++i) {
       if (v[i]) {
           sum += res[2 * i] / 2;
       }
   }
   cout << sum << endl;
}
