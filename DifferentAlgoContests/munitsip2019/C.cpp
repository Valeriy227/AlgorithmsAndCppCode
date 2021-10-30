//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//    }
//    sort(v.rbegin(), v.rend());
//    int ans = 0;
//    int ans_ind = 0;
//    for (int i = 0; i < n; ++i) {
//        int cans = (i + 1) * v[i];
//        if (ans < cans) {
//            ans = cans;
//            ans_ind = i;
//        }
//    }
//    cout << ans_ind + 1 << " " << v[ans_ind] << endl;
//}
