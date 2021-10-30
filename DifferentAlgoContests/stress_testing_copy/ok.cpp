#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_people_cnt(vector<int>& height) {
    int n = height.size();
    vector<int> res(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (height[j] >= height[i]) {
                res[i] = res[j] + 1;
                break;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    auto people_cnt = calc_people_cnt(height);
    for (int i : people_cnt) {
        cout << i << " ";
    }
    cout << endl;
}
