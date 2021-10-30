//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//
//struct Word {
//    inline static int dim = 0;
//    std::string str;
//    std::vector<int> coord;
//    Word() {
//        coord.resize(dim);
//    }
//    int distance(const Word& word) {
//        int dist = 0;
//        for (int i = 0; i < dim; ++i) {
//            dist += coord[i] * word.coord[i];
//        }
//        return dist;
//    }
//};
//
//std::istream& operator>>(std::istream& in, Word& word) {
//    in >> word.str;
//    for (auto& i : word.coord) {
//        in >> i;
//    }
//    return in;
//}
//
//void solve() {
//    int n;
//    std::cin >> n >> Word::dim;
//    n--;
//    Word object;
//    std::cin >> object;
//    std::vector<Word> words(n);
//    for (auto& word : words) {
//        std::cin >> word;
//    }
//    auto ans = *min_element(words.begin(), words.end(), [object](Word& a, Word& b) {
//        return a.distance(object) > b.distance(object);
//    });
//    for (auto& word : words) {
//        if (word.distance(object) == ans.distance(object)) {
//            std::cout << word.str << std::endl;
//        }
//    }
//}
//
//int main() {
//    solve();
//}