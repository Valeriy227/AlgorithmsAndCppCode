#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_first_right(vector<int>& height) {
    int n = height.size();
    vector<int> first_right(n, n);
    vector<int> stack;
    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && height[stack.back()] < height[i]) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            first_right[i] = stack.back();
        }
        stack.push_back(i);
    }
    return first_right;
}

vector<int> calc_people_cnt(vector<int>& height, vector<int>& first_right) {
    int n = height.size();
    vector<int> res(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        res[i] = res[first_right[i]] + 1;
    }
    res.pop_back();
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    auto first_right = calc_first_right(height);
    auto people_cnt = calc_people_cnt(height, first_right);
    for (int i : people_cnt) {
        cout << i << " ";
    }
    cout << endl;
}
