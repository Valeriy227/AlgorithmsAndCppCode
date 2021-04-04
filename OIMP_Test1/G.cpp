//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//
//std::map<std::string, int> final_standings(
//        const std::vector<std::map<std::string, int>>& contests) {
//    std::map<std::string, int> res;
//    for (const auto& contest : contests) {
//        for (const auto& [name, mark] : contest) {
//            if (res.count(name) == 0) {
//                res[name] = mark;
//            } else {
//                res[name] = std::max(res[name], mark);
//            }
//        }
//    }
//    return res;
//}
//
//void solve() {
//
//}
//
//int main() {
//    solve();
//}