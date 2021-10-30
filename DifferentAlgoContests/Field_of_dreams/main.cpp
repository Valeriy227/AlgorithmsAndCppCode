#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(int x) {
    vector<int> v(10);
    while (x > 0) {
        v[x % 10]++;
        x /= 10;
    }
    int cnt = 0;
    for (int i : v) {
        if (i > 0) {
            cnt++;
        }
    }
    if (cnt > 2) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 100000; ++i) {
        if (check(i + n)) {
            cout << i + n << endl;
            return 0;
        }
        if (n > i && check(n - i)) {
            cout << n - i << endl;
            return 0;
        }
    }
}