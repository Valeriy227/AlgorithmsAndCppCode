#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

mt19937 gen;

int main() {
    int ss;
    cin >> ss;
    gen.seed(ss);

    int maxh = 2000;
    int n = gen() % 1000 + 1;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << gen() % maxh + 1 << " ";
    }
    cout << endl;
}
