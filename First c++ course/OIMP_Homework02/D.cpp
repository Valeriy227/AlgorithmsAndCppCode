//#include <iostream>
//#include <set>
//#include <string>
//#include <string_view>
//#include <vector>
//
//void process_string(const std::string& str, std::set<std::string_view>& paths) {
//    size_t cur = 0;
//    std::string_view str_v = str;
//    while (cur < str.size()) {
//        auto next = str_v.find('/', cur);
//        if (next == std::string::npos) {
//            break;
//        }
//        paths.insert(str_v.substr(0, next + 1));
//        cur = next + 1;
//    }
//}
//
//void solve() {
//    freopen("input.txt", "r", stdin);
//    std::string str;
//    std::vector<std::string> lines;
//    std::set<std::string_view> paths;
//    while (std::cin >> str) {
//        lines.emplace_back(str);
//    }
//    for (const auto& i : lines) {
//        process_string(i, paths);
//    }
//    for (const auto& i : paths) {
//        std::cout << i << std::endl;
//    }
//}
//
//int main() {
//    solve();
//}