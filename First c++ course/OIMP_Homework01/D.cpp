//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<string> get_words(const string& text) {
//    vector<string> res;
//    res.emplace_back();
//    for (const char i : text) {
//        if (i == '-' || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z')) {
//            res.back().push_back(i);
//        } else {
//            if (!res.back().empty()) {
//                res.emplace_back();
//            }
//        }
//    }
//    if (res.back().empty()) {
//        res.pop_back();
//    }
//    return res;
//}
//
//vector<bool> get_keys(const string& text) {
//    vector<bool> used(4);
//    auto words = get_words(text);
//    for (const auto& word : words) {
//        if (word == "-l") {
//            used[0] = true;
//        } else if (word == "-w") {
//            used[1] = true;
//        } else if (word == "-m") {
//            used[2] = true;
//        } else {
//            used[3] = true;
//        }
//    }
//    return used;
//}
//
//int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    string keys_str;
//    getline(cin, keys_str);
//    auto keys = get_keys(keys_str);
//
//    string line;
//    vector<size_t> ans(4);
//
//    while (getline(cin, line)) {
//        ++ans[0];
//        auto words = get_words(line);
//        ans[1] += words.size();
//        ans[2] += line.length() + 1;
//        ans[3] = max(ans[3], line.length());
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        if (keys[i]) {
//            cout << ans[i] << " ";
//        }
//    }
//    cout << endl;
//}