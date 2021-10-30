//#include <iostream>
//#include <string>
//#include <vector>
//
//std::string common_prefix(const std::vector<std::string>& words) {
//    if (words.empty()) {
//        return "";
//    }
//    size_t max_pref = words[0].size();
//    for (size_t i = 1; i < words.size(); ++i) {
//        max_pref = std::min(max_pref, words[i].size());
//        for (int j = 0; j < max_pref; ++j) {
//            if (words[i - 1][j] != words[i][j]) {
//                max_pref = j;
//                break;
//            }
//        }
//    }
//    return words.back().substr(0, max_pref);
//}
//
//void solve() {
//    std::vector<std::string> v = {"apple", "apricot", "application"};
//    std::cout << common_prefix(v) << std::endl;
//}
//
//int main() {
//    solve();
//}