//#include <iostream>
//#include <list>
//#include <vector>
//
//void get_order() {
//    const int MAX_N = 100000;
//    int n;
//    std::cin >> n;
//    std::list<int> order;
//    std::vector<bool> used(MAX_N + 1);
//    std::vector<std::list<int>::iterator> link(MAX_N + 1);
//    for (int i = 0; i < n; ++i) {
//        int next, prev;
//        std::cin >> next >> prev;
//        if (!used[prev]) {
//            link[next] = order.insert(order.begin(), next);
//        } else {
//            auto it = link[prev];
//            ++it;
//            link[next] = order.insert(it, next);
//        }
//        used[next] = true;
//    }
//    for (auto i : order) {
//        std::cout << i << std::endl;
//    }
//}
//
//int main() {
//    get_order();
//}