////#include <iostream>
////
////int main() {
////    std::cout << "Hello, World!" << std::endl;
////    return 0;
////}
//
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool exist(const string& text, char c) {
//    for (const auto& i : text) {
//        if (i == c) {
//            return true;
//        }
//    }
//    return false;
//}
//
//bool check(const string& s) {
//    static const string SPECIAL = "#$%^{}[]№@()";
//    for (const char& i : s) {
//        if (exist(SPECIAL, i)) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    string s = "HELLO";
//    transform(s.begin(), s.end(), s.begin(), ::tolower);
//    cout << s << endl;
//}
