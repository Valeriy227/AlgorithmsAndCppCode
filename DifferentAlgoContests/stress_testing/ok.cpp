#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return max(abs(a.first - b.first), abs(a.second - b.second));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> dists;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dists.push_back(dist(v[i], v[j]));
        }
    }
    sort(dists.rbegin(), dists.rend());

    cout << dists[1] << endl;
}
