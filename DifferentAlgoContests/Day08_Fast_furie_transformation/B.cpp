#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> cmpl;

int n;

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
                wp *= w;
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
        resc[i] /= (n + 0.0);
    }
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = (int)round(resc[i].real());
    }
    return res;
}

void print(vector<cmpl> &v) {
    for (auto i : v) {
        cout << i.real() << " " << i.imag() << endl;
    }
    cout << endl;
}

int main() {
//    freopen("multiply.in", "r", stdin);
//    freopen("multiply.out", "w", stdout);


//    n = 8;
//    vector<cmpl> a(n);
//    for (int i = 0; i < n; ++i) {
//        a[i] = n - i;
//    }
//    print(a);
//    fft(a, false);
//    print(a);
//    fft(a, false);
//    print(a);


//    string sa;
//    cin >> sa;
//    string sb;
//    cin >> sb;
//    int sign = 1;
//    reverse(sa.begin(), sa.end());
//    reverse(sb.begin(), sb.end());
//    if (sa.back() == '-') {
//        sign *= -1;
//        sa.pop_back();
//    }
//    if (sb.back() == '-') {
//        sign *= -1;
//        sb.pop_back();
//    }
//    n = sa.length() + sb.length();
//    int pow2 = 1;
//    while (pow2 < n) {
//        pow2 *= 2;
//    }
//    n = pow2;
//    vector<int> a(n), b(n);
//    for (int i = 0; i < (int)sa.length(); ++i) {
//        a[i] = sa[i] - '0';
//    }
//    for (int i = 0; i < (int)sb.length(); ++i) {
//        b[i] = sb[i] - '0';
//    }
//
//    auto res = multiply(a, b);
//    res.push_back(0);
//    for (int i = 0; i < n; ++i) {
//        res[i + 1] += res[i] / 10;
//        res[i] %= 10;
//    }
//    while (!res.empty() && res.back() == 0) {
//        res.pop_back();
//    }
//    if (res.empty()) {
//        cout << 0 << endl;
//    } else {
//        if (sign == -1) {
//            cout << '-';
//        }
//        reverse(res.begin(), res.end());
//        for (int i : res) {
//            cout << i;
//        }
//        cout << endl;
//    }
}
