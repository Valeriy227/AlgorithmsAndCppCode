//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//int ff(int b, int p, int f, int h, int c) {
//    int cnt = min(b / 2, p);
//    return cnt * h + min((b - cnt * 2) / 2, f) * c;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while (t) {
//        t--;
//        int b, p, f;
//        cin >> b >> p >> f;
//        int h, c;
//        cin >> h >> c;
//        cout << max(ff(b, p, f, h, c), ff(b, f, p, c, h)) << endl;
//    }
//}
