//#include <cctype>
//#include <iostream>
//#include <vector>
//
//int get_type(char symbol) {
//    if (isdigit(symbol)) {
//        return 0;
//    }
//    if (islower(symbol)) {
//        return 1;
//    }
//    if (isupper(symbol)) {
//        return 2;
//    }
//    return 3;
//}
//
//bool is_password(const std::string& str) {
//    if (str.length() < 8 || str.length() > 14) {
//        return false;
//    }
//
//    std::vector<int> cnt(4);
//    for (const auto& i : str) {
//        if (i < 33 || i > 126) {
//            return false;
//        }
//        ++cnt[get_type(i)];
//    }
//
//    int var = 0;
//    for (const auto& i : cnt) {
//        if (i > 0) {
//            ++var;
//        }
//    }
//
//    return (var >= 3);
//}
//
//int main() {
//    std::string str;
//    std::cin >> str;
//
//    if (is_password(str)) {
//        std::cout << "YES" << std::endl;
//    } else {
//        std::cout << "NO" << std::endl;
//    }
//}
