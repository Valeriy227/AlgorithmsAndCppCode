#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    vector<vector<ll>> events;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, b, 0});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, b, 1});
    }
    sort(events.begin(), events.end());

    vector<priority_queue<ll>> p(2);
    for (auto &event : events) {
        int pi = event[2];
        if (p[pi].empty() || -p[pi].top() > event[0]) {
            p[pi].push(-event[0]);
        }
        p[1 - pi].push(-event[1] - t);
        p[pi].pop();
    }
    cout << p[0].size() + p[1].size() << endl;
}
