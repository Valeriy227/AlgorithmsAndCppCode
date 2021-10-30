//#include <algorithm>
//#include <iostream>
//#include <tuple>
//#include <unordered_map>
//#include <vector>
//
//void calculate_n_grams() {
//    int n, m;
//    std::cin >> n >> m;
//    std::vector<std::string> words(n);
//    std::unordered_map<std::string, int> cnt;
//    for (int i = 0; i < n; ++i) {
//        std::cin >> words[i];
//        if (i >= m - 1) {
//            std::string n_gram;
//            for (int j = i - m + 1; j <= i; ++j) {
//                if (j > i - m + 1) {
//                    n_gram.push_back(' ');
//                }
//                n_gram += words[j];
//            }
//            ++cnt[n_gram];
//        }
//    }
//    std::vector<std::pair<std::string, int>> n_grams;
//    for (const auto& i : cnt) {
//        n_grams.push_back(i);
//    }
//    std::sort(n_grams.begin(), n_grams.end(),
//            [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
//        return tie(b.second, a.first) < tie(a.second, b.first);
//    });
//    for (const auto& [n_gram, number] : n_grams) {
//        std::cout << n_gram << " - " << number << std::endl;
//    }
//}
//
//int main() {
//    calculate_n_grams();
//}