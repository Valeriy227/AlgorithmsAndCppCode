//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//
//void solve() {
//    int n;
//    std::cin >> n;
//    std::map<std::string, std::vector<std::pair<int, int>>> marks;
//    for (int i = 0; i < n; ++i) {
//        int k;
//        std::cin >> k;
//        for (int j = 0; j < k; ++j) {
//            std::string name;
//            int mark;
//            std::cin >> name >> mark;
//            marks[name].emplace_back(i, mark);
//        }
//    }
//    for (const auto& [name, submitted] : marks) {
//        std::vector<int> res(n);
//        for (const auto [contest, mark] : submitted) {
//            res[contest] = mark;
//        }
//        std::cout << name;
//        for (auto mark : res) {
//            std::cout << "\t" << mark;
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    solve();
//}