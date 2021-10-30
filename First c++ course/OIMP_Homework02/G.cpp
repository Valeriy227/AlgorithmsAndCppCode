//#include <iostream>
//#include <map>
//#include <set>
//#include <string>
//
//void solve() {
//    int n;
//    std::cin >> n;
//    std::map<int, std::set<std::string>> pages;
//    for (int i = 0; i < n; ++i) {
//        std::string word;
//        int page;
//        std::cin >> word >> page;
//        pages[page].insert(word);
//    }
//    for (const auto& [page, words] : pages) {
//        std::cout << page;
//        for (const auto& word : words) {
//            std::cout << " " << word;
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    solve();
//}