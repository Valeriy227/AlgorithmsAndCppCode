//template <typename It, typename OutputIt>
//OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
//    if (first2 == last2) {
//        while (first1 != last1) {
//            *out = *first1;
//            ++out;
//            ++first1;
//        }
//        return out;
//    }
//    do {
//        --last2;
//        while (first1 != last1 && *first1 < *last2) {
//            *out = *first1;
//            ++out;
//            ++first1;
//        }
//        *out = *last2;
//        ++out;
//    } while (first2 != last2);
//    while (first1 != last1) {
//        *out = *first1;
//        ++out;
//        ++first1;
//    }
//    return out;
//}
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    vector<int> a = {1, 2, 3};
//    vector<int> b = {3, 1};
//    vector<int> c(10);
//    auto it = sideways_merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
//    for (auto i = c.begin(); i != it; ++i) {
//        cout << *i << " ";
//    }
//}