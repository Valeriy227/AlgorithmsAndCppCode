//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//string tostr(int x) {
//    string res;
//    while (x > 0) {
//        res.push_back(x % 10 + '0');
//        x /= 10;
//    }
//    while (res.size() < 3) {
//        res.push_back('0');
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//void open(const char *p, bool flag) {
//    if (flag) {
//        freopen(p, "r", stdin);
//    }
//    else {
//        freopen(p, "w", stdout);
//    }
//}
//
//int main() {
//    for (int i = 0; i < 20; ++i) {
//        string num = tostr(i + 1);
//        char pathin[3];
//        char pathout[7];
//        pathout[0] = pathin[0] = num[0];
//        pathout[1] = pathin[1] = num[1];
//        pathout[2] = pathin[2] = num[2];
//        pathout[3] = '.';
//        pathout[4] = 'o';
//        pathout[5] = 'u';
//        pathout[6] = 't';
//        open(pathin, 1);
//        open(pathout, 0);
////        freopen(pathin, "r", stdin);
////        freopen(pathout, "w", stdout);
//        string s;
//        cin >> s;
//        int n, k;
//        cin >> n >> k;
//
//        for (int i = 0; i < n; ++i) {
//            cout << rand() % k + 1 << " ";
//        }
//        cout << endl;
//
//        fclose(stdin);
//        fclose(stdout);
//    }
//}
