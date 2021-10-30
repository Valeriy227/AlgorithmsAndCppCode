#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;

int main() {
    cin >> s;
    int n = s.length();
    unordered_map<ll, ll> res1;
    for (int mask = 0; mask < (1 << n / 2); ++mask) {
        if (__builtin_popcount(mask) * 2 < n / 2) {
            continue;
        }
        vector<int> ind1, ind2;
        for (int i = 0; i < n / 2; ++i) {
            if ((1 << i) & mask) {
                ind1.push_back(i);
            }
            else {
                ind2.push_back(i);
            }
        }
        bool flag = true;
        for (int i = 0; i < ind2.size(); ++i) {
            if (s[ind1[i]] != s[ind2[i]]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        ll num = 1;
        for (int i = ind2.size(); i < ind1.size(); ++i) {
            num <<= 1;
            num += (s[ind1[i]] == 'x');
        }
        res1[num]++;
    }

    unordered_map<ll, ll> res2;
    for (int mask = 0; mask < (1 << n / 2); ++mask) {
        if (__builtin_popcount(mask) * 2 < n / 2) {
            continue;
        }
        vector<int> ind1, ind2;
        for (int i = 0; i < n / 2; ++i) {
            if ((1 << i) & mask) {
                ind1.push_back(i + n / 2);
            }
            else {
                ind2.push_back(i + n / 2);
            }
        }
        reverse(ind1.begin(), ind1.end());
        reverse(ind2.begin(), ind2.end());
        bool flag = true;
        for (int i = 0; i < ind2.size(); ++i) {
            if (s[ind1[i]] != s[ind2[i]]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        ll num = 1;
        for (int i = ind1.size() - 1; i >= (int)ind2.size(); --i) {
            num <<= 1;
            num += (s[ind1[i]] == 'x');
        }
        res2[num]++;
    }

    ll ans = 0;

    for (auto i : res1) {
        ans += i.second * res2[i.first];
    }
    cout << ans * 2 - res1[1] * res2[1] << endl;
}
