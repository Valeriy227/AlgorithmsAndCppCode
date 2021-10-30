#include <iostream>
#include <vector>
#include <map>

using namespace std;

int insert(map<int, pair<int, int>>& m, int val) {
    auto next_it = m.upper_bound(val);
    int res;
    if (next_it == m.end() || next_it->second.first != 0) {
        next_it--;
        next_it->second.second = val;
    } else {
        next_it->second.first = val;
    }
    res = next_it->first;
    m[val] = {0, 0};
    return res;
}

int main() {
    int n;
    cin >> n;
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (i == 0) {
            m[val] = {0, 0};
        } else {
            cout << insert(m, val) << " ";
        }
    }
    cout << endl;
}