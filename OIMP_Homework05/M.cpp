//#include <algorithm>
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <vector>
//#include "query.h"
//
//const size_t RESULTS_TO_PRINT = 3;
//
//int main() {
//    std::unordered_map<std::string, size_t> login_stats;
//    std::string line;
//    while (std::getline(std::cin, line)) {
//        Query* q = parse_query(line.c_str());
//
//        if (q->action == ACTION_COMMIT) {
//            login_stats[q->sender_login] += 1;
//        }
//        delete(q);
//    }
//
//    std::vector<std::pair<std::string, int>> stats_vec(
//            login_stats.begin(), login_stats.end());
//    std::sort(stats_vec.begin(), stats_vec.end(), [](
//            const std::pair<std::string, int>& a,
//            const std::pair<std::string, int>& b) {
//        return std::tie(a.second, b.first) > std::tie(b.second, a.first);
//    });
//
//    for (size_t i = 0; i < std::min(stats_vec.size(), RESULTS_TO_PRINT); ++i) {
//        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
//    }
//}