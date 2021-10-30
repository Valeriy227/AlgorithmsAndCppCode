//#include <iostream>
//#include <list>
//#include <string>
//
//class Vim {
//    enum Mode {
//        view_mode,
//        insert_mode
//    };
//    Mode mode;
//    std::list<char> str;
//    std::list<char>::iterator it;
//
//public:
//    Vim() {
//        mode = view_mode;
//        str.push_back(-1);
//        it = str.begin();
//    }
//
//    void get_symbol(char c) {
//        if (mode == view_mode) {
//            if (c == 'i') {
//                mode = insert_mode;
//            } else if (c == 'h') {
//                if (it != str.begin()) {
//                    --it;
//                }
//            } else if (c == 'l') {
//                if (it != (--str.end())) {
//                    ++it;
//                }
//            }
//        } else {
//            if (c == '<') {
//                mode = view_mode;
//            } else {
//                str.insert(it, c);
//            }
//        }
//    }
//
//    std::string to_string() const {
//        std::string res;
//        for (const auto i : str) {
//            if (i != -1) {
//                res += i;
//            }
//        }
//        return res;
//    }
//};
//
//int main() {
//    Vim vim;
//    std::string str;
//    std::cin >> str;
//    for (const auto i : str) {
//        vim.get_symbol(i);
//    }
//    std::cout << vim.to_string() <<  std::endl;
//}