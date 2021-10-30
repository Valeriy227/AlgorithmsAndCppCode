//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void solve() {
//    string bytes;
//    getline(cin, bytes);
//    int remainder = 0;
//    const unsigned char FIRST = 1u << 7u;
//    const unsigned char THIRD = 1u << 5u;
//    const unsigned char FOURTH = 1u << 4u;
//    int cnt = 0;
//    for (const auto byte : bytes) {
//        if (remainder > 0) {
//            --remainder;
//            continue;
//        }
//        ++cnt;
//        if (byte & FIRST) {
//            ++remainder;
//            if (byte & THIRD) {
//                ++remainder;
//                if (byte & FOURTH) {
//                    ++remainder;
//                }
//            }
//        }
//    }
//    cout << cnt << endl;
//}
//
//int main() {
//    solve();
//}