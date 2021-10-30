//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> v;
//    for (int i = 0; i < n; ++i) {
//        int a, b;
//        cin >> a >> b;
//        auto it = find(v.begin(), v.end(), b);
//        if (it != v.end()) {
//            it++;
//            v.insert(it, a);
//        } else {
//            v.insert(v.begin(), a);
//        }
//    }
//    for (int i : v) {
//        cout << i << endl;
//    }
//}