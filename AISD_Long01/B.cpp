#include <iostream>
#include <vector>
#include <deque>

using namespace std;

pair<int, int> get_ans(int n, int diff, vector<int>& v) {
    deque<int> mn, mx;
    int l = 0;
    int ansl = 0, ansr = -1;
    for (int i = 0; i < n; ++i) {
        while (!mn.empty() && v[mn.back()] >= v[i]) {
            mn.pop_back();
        }
        mn.push_back(i);

        while (!mx.empty() && v[mx.back()] <= v[i]) {
            mx.pop_back();
        }
        mx.push_back(i);

        while (!mn.empty() && !mx.empty() && v[mx.front()] - v[mn.front()] > diff) {
            if (mn.front() == l) {
                mn.pop_front();
            }
            if (mx.front() == l) {
                mx.pop_front();
            }
            l++;
        }
        if (!mn.empty()) {
            if (ansr - ansl < i - l) {
                ansl = l;
                ansr = i;
            }
        }
    }
    return {ansl, ansr};
}

int main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> measures(n);
    for (int &i : measures) {
        cin >> i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int diff;
        cin >> diff;
        auto [l, r] = get_ans(n, diff, measures);
        cout << l + 1 << " " << r + 1 << endl;
    }
}