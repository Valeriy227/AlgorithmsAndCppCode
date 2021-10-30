//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void push_back_symbol(string& str, size_t code) {
//    static const vector<int> board = {1u << 7u, 1u << 11u, 1u << 16u, 1u << 21u};
//    for (size_t i = 0; i < 4; ++i) {
//        if (code < board[i]) {
//            vector<size_t> stack;
//            for (size_t j = 0; j < i; ++j) {
//                stack.push_back((1u << 7u) + code % (1u << 6u));
//                code >>= 6u;
//            }
//            for (size_t j = 0; i > 0 && j < i + 1; ++j) {
//                code += (1u << (7u - j));
//            }
//            str.push_back(code);
//            while (!stack.empty()) {
//                str.push_back(stack.back());
//                stack.pop_back();
//            }
//            break;
//        }
//    }
//}
//
//int main() {
//    string res;
//    size_t code;
//    while (cin >> code) {
//        push_back_symbol(res, code);
//    }
//    cout << res << endl;
//}