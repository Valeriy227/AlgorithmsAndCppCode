//#include <iostream>
//
//using namespace std;
//
//void decode() {
//    string str;
//    getline(cin, str);
//    int bytes = str.size() / 8;
//    int64_t res = 0;
//    int64_t pow = 1;
//    for (int i = bytes - 1; i >= 0; --i) {
//        int64_t cur = 0;
//        for (int j = 0; j < 8; ++j) {
//            cur <<= 1;
//            cur += str[i * 8 + j];
//        }
//        if (i != bytes - 1) {
//            cur -= (1u << 7u);
//        }
//
//    }
//    for (int i = 0; i < str.size(); ++i) {
//        if (i % 8 != 0) {
//
//        }
//    }
//}
//
//int main() {
//    decode();
//}