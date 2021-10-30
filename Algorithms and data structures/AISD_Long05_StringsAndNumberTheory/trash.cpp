// #include <bits/stdc++.h>
// #include "C:\Users\User\Downloads\ttmath-0.9.4.prerelease-src-2019.07.31\ttmath-0.9.4.prerelease-src-2019.07.31\ttmath\ttmath.h"
// using namespace std;
// using namespace ttmath;

// const int SIZE = 32;

// using BigInt = Int<SIZE>; //размер BigInt равен W * SIZE, где W - длина машинного слова

// struct RSA {
//    BigInt e, d, n;
// };

// BigInt gen_rand(mt19937& rnd, int bits) {
//    BigInt res(0);
//    bits /= 32;
//    for (int i = 0; i < bits; ++i) {
//        res *= BigInt("4294967296");
//        res += rnd();
//    }
//    return res;
// }

// BigInt binpow(BigInt a, BigInt p, BigInt mod) {
//    BigInt res = 1;
//    BigInt cur = a;
//    while (p > 0) {
//        if (p % 2 == 1) {
//            res *= cur;
//            res %= mod;
//        }
//        cur *= cur;
//        cur %= mod;
//        p /= 2;
//    }
//    return res;
// }

// bool prime(mt19937& rnd, const BigInt& x) {
//    if (x == 2) {
//        return true;
//    }
//    if (x % 2 == 0) {
//        return false;
//    }
//    BigInt d = x - 1;
//    int s = 0;
//    while (d % 2 == 0) {
//        d /= 2;
//        ++s;
//    }
//    for (int k = 0; k < 256; ++k) {
//        BigInt a = gen_rand(rnd, 256);
//        a %= x - 3;
//        a += 2;
//        a = binpow(a, d, x);
//        if (a == 1 || a == x - 1) continue;
//        bool composite = true;
//        for (int i = 0; i < s - 1; ++i) {
//            a *= a;
//            a %= x;
//            if (a == x - 1) {
//                composite = false;
//                break;
//            }
//        }
//        if (composite) return false;
//    }
//    return true;
// }

// BigInt gcd (BigInt a, BigInt b, BigInt & x, BigInt & y) {
//    if (a == 0) {
//        x = 0; y = 1;
//        return b;
//    }
//    BigInt x1, y1;
//    BigInt d = gcd (b % a, a, x1, y1);
//    x = y1 - (b / a) * x1;
//    y = x1;
//    return d;
// }

// BigInt inverse(BigInt x, BigInt mod) {
//    BigInt a, b;
//    gcd(x, mod, a, b);
//    return (a % mod + mod) % mod;
// }

// RSA generate_keys() {
//    int seed = time(0);
//    mt19937 rnd(seed);
//    BigInt p = gen_rand(rnd, 256);
//    while (true) {
//        if (prime(rnd, p)) {
//            break;
//        }
//        --p;
//    }
//    BigInt q = gen_rand(rnd, 256);
//    while (true) {
//        if (prime(rnd, q)) {
//            break;
//        }
//        --q;
//    }
//    BigInt euler = (p - 1) * (q - 1);
//    BigInt e = 257;
//    BigInt d = inverse(e, euler);
//    return {e, d, p * q};
// }

// int main() {
//    auto res = generate_keys();
// }