//#include <iostream>
//#include <string>
//#include <vector>
//
//void paste() {
//    int n;
//    std::cin >> n;
//    std::vector<std::vector<std::string>> files(n);
//    int max_m = 0;
//    for (int i = 0; i < n; ++i) {
//        int m;
//        std::cin >> m;
//        max_m = std::max(m, max_m);
//        for (int j = 0; j < m; ++j) {
//            files[i].emplace_back();
//            std::cin >> files[i].back();
//        }
//    }
//    for (int i = 0; i < max_m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (files[j].size() > i) {
//                std::cout << files[j][i];
//            }
//            std::cout << '\t';
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    paste();
//}