//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//
//int x, y;
//int x_targ, y_targ;
//vector<pair<int, int>> ans;
//
//int dist() {
//    return abs(x_targ - x) + abs(y_targ - y);
//}
//
//void go(int dx, int dy) {
//    x += dx;
//    y += dy;
//    ans.push_back({x, y});
//}
//
//void step(int &xc, int &xt, int d) {
//    if (xc < xt) {
//        xc += d;
//    } else {
//        xc -= d;
//    }
//}
//
//void go() {
//    if (abs(x_targ - x) > abs(y_targ - y)) {
//        step(x, x_targ, 2);
//        step(y, y_targ, 1);
//    } else {
//        step(x, x_targ, 1);
//        step(y, y_targ, 2);
//    }
//    ans.push_back({x, y});
//}
//
//void norm(int x_neg, int y_neg) {
//    for (auto &i : ans) {
//        i.first *= x_neg;
//        i.second *= y_neg;
//    }
//}
//
//void print() {
//    for (auto i : ans) {
//        cout << i.first << " " << i.second << endl;
//    }
//}
//
//int main() {
//    cin >> x_targ >> y_targ;
//    int x_neg = 1, y_neg = 1;
//    if (x_targ < 0) {
//        x_neg = -1;
//        x_targ = -x_targ;
//    }
//    if (y_targ < 0) {
//        y_neg = -1;
//        y_targ = -y_targ;
//    }
//
//    x = 0;
//    y = 0;
//    while (dist() > 1) {
//        go();
//    }
//    if (dist() == 0) {
//        norm(x_neg, y_neg);
//        print();
//    } else {
//        if (x + 1 == x_targ) {
//            go(1, -2);
//            go(-2, 1);
//            go(2, 1);
//        } else if (x - 1 == x_targ) {
//            go(-1, -2);
//            go(2, 1);
//            go(-2, 1);
//        } else if (y + 1 == y_targ) {
//            go(-2, 1);
//            go(1, -2);
//            go(1, 2);
//        } else {
//            go(2, -1);
//            go(-1, -2);
//            go(-1, 2);
//        }
//        norm(x_neg, y_neg);
//        print();
//    }
//}
