#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void push_x_dist(vector<pair<int, int>>& v, vector<int>& dists) {
    int n = v.size();
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    for (int i = 1; i < n; ++i) {
        dists.push_back(v[i].first - v[0].first);
    }
    for (int i = 1; i < n - 1; ++i) {
        dists.push_back(v[n - 1].first - v[i].first);
    }
}

void push_y_dist(vector<pair<int, int>>& v, vector<int>& dists) {
    int n = v.size();
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    for (int i = 1; i < n; ++i) {
        dists.push_back(v[i].second - v[0].second);
    }
    for (int i = 1; i < n - 1; ++i) {
        dists.push_back(v[n - 1].second - v[i].second);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> dists;
    push_x_dist(v, dists);
    push_y_dist(v, dists);
    sort(dists.rbegin(), dists.rend());

    cout << dists[1] << endl;
}
