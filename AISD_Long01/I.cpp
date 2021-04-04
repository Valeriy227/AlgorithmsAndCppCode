//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    priority_queue<int> ms;
//    vector<pair<string, int>> res;
//    for (int i = 0; i < n; ++i) {
//        string query;
//        cin >> query;
//        if (query == "insert") {
//            int x;
//            cin >> x;
//            res.push_back({query, x});
//            ms.push(-x);
//        } else if (query == "removeMin") {
//            if (ms.empty()) {
//                res.push_back({"insert", -1e9});
//                ms.push(-1e9);
//            }
//            res.push_back({"removeMin", 0});
//            ms.pop();
//        } else {
//            int x;
//            cin >> x;
//            while (!ms.empty() && ms.top() > -x) {
//                res.push_back({"removeMin", 0});
//                ms.pop();
//            }
//            if (ms.empty() || ms.top() != -x) {
//                res.push_back({"insert", x});
//                ms.push(-x);
//            }
//            res.push_back({query, x});
//        }
//    }
//    cout << res.size() << endl;
//    for (auto& i : res) {
//        cout << i.first;
//        if (i.first != "removeMin") {
//            cout << " " << i.second;
//        }
//        cout << "\n";
//    }
//}