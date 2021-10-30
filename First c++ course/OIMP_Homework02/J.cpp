//#include <deque>
//#include <iostream>
//#include <string>
//
//void solve() {
//    int n;
//    std::cin >> n;
//    std::deque<std::string> stack;
//    for (int i = 0; i < n; ++i) {
//        std::string name, side;
//        std::cin >> name >> side;
//        if (side == "top") {
//            stack.push_front(name);
//        } else {
//            stack.push_back(name);
//        }
//    }
//    int m;
//    std::cin >> m;
//    for (int i = 0; i < m; ++i) {
//        int k;
//        std::cin >> k;
//        std::cout << stack[k - 1] << std::endl;
//    }
//}
//
//int main() {
//    solve();
//}