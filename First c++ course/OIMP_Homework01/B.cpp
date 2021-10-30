//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//string get_code(const string& str) {
//    vector<int> val = {-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5,
//                       5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2};
//
//    string res;
//    res += str[0];
//    for (size_t i = 1; i < str.length(); ++i) {
//        int digit = val[str[i] - 'a'];
//        if (digit > 0 && res.back() != '0' + digit) {
//            res.push_back('0' + digit);
//        }
//    }
//    res = res.substr(0, 4);
//    while (res.length() < 4) {
//        res.push_back('0');
//    }
//
//    return res;
//}
//
//int main() {
//    string word;
//    cin >> word;
//    cout << get_code(word) << endl;
//}