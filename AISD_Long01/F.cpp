//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> events(2 * n);
//    for (int &i : events) {
//        char c;
//        cin >> c;
//        cin >> i;
//        if (c == '-') {
//            i = -i;
//        }
//    }
//
//    reverse(events.begin(), events.end());
//
//    vector<double> res;
//    double timeout_expected = 0;
//    int contest_reminder = 0;
//    for (int i : events) {
//        if (i > 0) {
//            res.push_back(timeout_expected - i);
//            contest_reminder--;
//        } else {
//            contest_reminder++;
//            timeout_expected *= (contest_reminder - 1.0) / contest_reminder;
//            timeout_expected += (-i + 0.0) / (contest_reminder);
//        }
//    }
//
//    reverse(res.begin(), res.end());
//
//    for (auto i : res) {
//        cout << fixed << setprecision(10) << i << "\n";
//    }
//}