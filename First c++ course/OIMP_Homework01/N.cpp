//#include <string>
//#include <string_view>
//
//bool checkPalindrome(const std::string_view& str) {
//    for (size_t i = 0; i < str.size(); ++i) {
//        if (str[i] != str[str.size() - i - 1]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int countPalindromes(const std::string& str) {
//    int cnt =  0;
//    size_t pos = 0;
//    std::string_view view = str;
//    while (pos < str.size()) {
//        size_t space_ind = str.find(' ', pos);
//        if (space_ind == std::string::npos) {
//            space_ind = str.size();
//        }
//        if (space_ind > pos && checkPalindrome(view.substr(pos, space_ind - pos))) {
//            ++cnt;
//        }
//        pos = space_ind + 1;
//    }
//    return cnt;
//}