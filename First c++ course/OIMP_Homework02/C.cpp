//#include <iostream>
//#include <string>
//#include <vector>
//
//void print_common_letters() {
//    const size_t N = 26;
//    freopen("input.txt", "r", stdin);
//    std::string word;
//    int words_cnt = 0;
//    std::vector<int> letters_cnt(N);
//    while (std::cin >> word) {
//        ++words_cnt;
//        for (const auto i : word) {
//            if (letters_cnt[i - 'a'] == words_cnt - 1) {
//                ++letters_cnt[i - 'a'];
//            }
//        }
//    }
//    for (int i = 0; i < N; ++i) {
//        if (letters_cnt[i] == words_cnt) {
//            std::cout << static_cast<char>('a' + i);
//        }
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//    print_common_letters();
//}