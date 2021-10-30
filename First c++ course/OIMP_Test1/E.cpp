//#include <vector>
//
//template <typename T>
//void Duplicate(std::vector<T>& v) {
//    v.resize(2 * v.size());
//    for (auto it = v.begin(); it != v.begin() + v.size() / 2; ++it) {
//        *(it + v.size() / 2) = *it;
//    }
//}
//
//#include <iostream>
//
//using namespace std;
//
//void solve() {
//    vector<int> v = {1, 2, 3};
//    Duplicate(v);
//    for (int i : v) {
//        cout << i << " ";
//    }
//}
//
//int main() {
//    solve();
//}