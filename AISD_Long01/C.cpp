//#include <iostream>
//
//using namespace std;
//
//bool check(int a, int b, int order) {
//    if (order == 1) {
//        cout << a << " " << b << endl;
//    } else {
//        cout << b << " " << a << endl;
//    }
//    int result;
//    cin >> result;
//    return result;
//}
//
//int detect_coordinate(int other, int order) {
//    int left = 0, right = 1e9;
//    while (left < right) {
//        int middle = (left + right) / 2;
//        check(left, other, order);
//        if (check(right, other, order)) {
//            left = middle + 1;
//        } else {
//            right = middle;
//        }
//    }
//    return left;
//}
//
//int main() {
//    auto x = detect_coordinate(0, 1);
//    auto y = detect_coordinate(x, 2);
//    cout << "A " << x << " " << y << endl;
//}