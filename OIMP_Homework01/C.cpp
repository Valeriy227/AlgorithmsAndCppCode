//#include <iostream>
//
//using namespace std;
//
//int main() {
//    for (int i = 0; i < 7; ++i) {
//        for (int j = 0; j < 17; ++j) {
//            if (i == 0) {
//                if (j != 0) {
//                    if (j <= 10) {
//                        cout << j - 1;
//                    } else {
//                        cout << static_cast<char>('A' + j - 11);
//                    }
//                }
//            } else if (j == 0) {
//                cout << i + 1;
//            } else {
//                cout << static_cast<char>(32 + (i - 1) * 16 + (j - 1));
//            }
//            cout << '\t';
//        }
//        cout << endl;
//    }
//}