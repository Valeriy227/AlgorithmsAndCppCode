//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n;
//    cin >> n;
//    if (n % 2 == 0) {
//        cout << "NO" << endl;
//    } else {
//        cout << "YES" << endl;
//        vector<int> ans(2 * n);
//        for (int i = 0; i < n; ++i) {
//            int cur = i * 2 + 1;
//            if (i % 2 == 0) {
//                ans[i] = cur;
//                ans[i + n] = cur + 1;
//            } else {
//                ans[i] = cur + 1;
//                ans[i + n] = cur;
//            }
//        }
//        for (int i : ans) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//}
