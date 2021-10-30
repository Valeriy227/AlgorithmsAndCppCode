#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> take1(int n, vector<int> &v) {
    vector<int> ans;
    int other = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            ans.push_back(1);
        } else if (is_prime(v[i] + 1)) {
            other = v[i];
        }
    }
    if (other != -1) {
        ans.push_back(other);
    }
    return ans;
}

vector<int> not_take1(int n, vector<int> &v) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (is_prime(v[i] + v[j])) {
                return {v[i], v[j]};
            }
        }
    }
    return {v[0]};
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    auto res1 = take1(n, v);
    auto res2 = not_take1(n, v);
    if (res1.size() > res2.size()) {
        cout << res1.size() << endl;
        for (int i : res1) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << res2.size() << endl;
        for (int i : res2) {
            cout << i << " ";
        }
        cout << endl;
    }
}
