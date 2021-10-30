//#include <iostream>
//#include <set>
//#include <vector>
//
//void solve() {
//    int n, k;
//    std::cin >> n >> k;
//    std::vector<int> v(n);
//    for (int i = 0; i < n; ++i) {
//        std::cin >> v[i];
//    }
//    std::multiset<int> window;
//    for (int i = 0; i < n; ++i) {
//        window.insert(v[i]);
//        if (i < k - 1) {
//            continue;
//        }
//        std::cout << *window.begin() << std::endl;
//        window.erase(window.find(v[i - k + 1]));
//    }
//}
//
//int main() {
//    solve();
//}