//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//
//struct Contest {
//    int count;
//    bool is_digit;
//    int number;
//    std::vector<bool> solved;
//    Contest(int _count, bool _is_digit, int _number) {
//        count = _count;
//        is_digit = _is_digit;
//        number = _number;
//        solved.resize(count);
//    }
//    void solve(int problem) {
//        solved[problem] = true;
//    }
//    void solve(char problem) {
//        solved[problem - 'A'] = true;
//    }
//};
//
//void solve() {
//    freopen("input.txt", "r", stdin);
//    std::string str;
//    std::vector<Contest> contests;
//    while (getline(std::cin, str)) {
//        std::stringstream in;
//        in << str;
//        int number, count;
//        in >> number >> count;
//
//        bool is_digit = false;
//        std::vector<std::string> solved(1);
//        while (in >> solved.back()) {
//            solved.emplace_back();
//        }
//        solved.pop_back();
//        if (solved.empty() || ('0' <= solved.back()[0] && solved.back()[0] <= '9')) {
//            is_digit = true;
//        }
//
//        contests.emplace_back(count, is_digit, number);
//        auto& contest = contests.back();
//        for (const auto& problem : solved) {
//            if (is_digit) {
//                contest.solve(stoi(problem) - 1);
//            } else {
//                contest.solve(problem[0]);
//            }
//        }
//    }
//    for (const auto& contest : contests) {
//        std::cout << contest.number;
//        for (int i = 0; i < contest.count; ++i) {
//            if (!contest.solved[i]) {
//                if (contest.is_digit) {
//                    std::cout << " " << i + 1;
//                } else {
//                    std::cout << " " << static_cast<char>('A' + i);
//                }
//            }
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    solve();
//}