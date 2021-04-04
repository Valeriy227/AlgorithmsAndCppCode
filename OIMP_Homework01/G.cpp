//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void solve() {
//    string bytes;
//    getline(cin, bytes);
//    size_t last = 0;
//    size_t remainder = 0;
//    for (const unsigned char byte : bytes) {
//        if (remainder > 0) {
//            last <<= 6u;
//            last += byte - (1u << 7u);
//        } else {
//            ++remainder;
//            for (size_t i = 0; (byte & (1u << 7u)) && i < 3; ++i) {
//                if (!(byte & (1u << (7u - i - 1)))) {
//                    break;
//                }
//                ++remainder;
//            }
//            last = byte % (1u << (7u - remainder + (remainder == 1)));
//        }
//        --remainder;
//        if (remainder == 0) {
//            cout << last << " ";
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    solve();
//}