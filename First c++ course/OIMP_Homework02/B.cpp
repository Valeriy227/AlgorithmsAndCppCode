//#include <iostream>
//#include <string>
//#include <unordered_set>
//
//void solve() {
//    std::unordered_set<std::string> set;
//    char operation;
//    std::cin >> operation;
//    while (operation != '#') {
//        std::string str;
//        std::cin >> str;
//        if (operation == '?') {
//            if (set.count(str)) {
//                std::cout << "YES" << std::endl;
//            } else {
//                std::cout << "NO" << std::endl;
//            }
//        } else if (operation == '+') {
//            set.insert(str);
//        } else {
//            set.erase(str);
//        }
//        std::cin >> operation;
//    }
//}
//
//int main() {
//    solve();
//}