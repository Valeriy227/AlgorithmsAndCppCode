#include <iostream>
#include "J.h"

using namespace std;

int main() {
    char str[30];
    for (int i = 0; i < 30; ++i) {
        str[i] = 0;
    }
    str[0] = 0;
    str[4] = 3;
    str[11] = 4;
//    str[9] = 101;
//    str[10] = 108;
//    str[11] = 108;
//    str[12] = 111;
//    str[13] = 6;
//    str[]
    cout << CountValues(str, 19);
//    stringstream ss;
//    size_t ln = 5;
//    ss.write(reinterpret_cast<char*>(&ln), sizeof(ln));
//    string s = "hello";
//    ss.write(s.data(), sizeof(char) * 5);
//    size_t sz = sizeof(ln) + sizeof(char) * 5;
//    auto a = ss.str();
//    for (int i = 0; i < a.length(); ++i) {
//        str[i] = a[i];
//    }
//    cout << CountValues(str, sz) << endl;
}