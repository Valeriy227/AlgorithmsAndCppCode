#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

mt19937 gen;

int main() {
    int seed;
    cin >> seed;
    gen.seed(seed);

    int n = 1000;
    int mod = 1e9;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << gen() % (2 * mod) - mod << " " << gen() % (2 * mod) - mod << endl;
    }
}