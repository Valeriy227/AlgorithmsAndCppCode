//template <typename Iter>
//Iter unique(Iter first, Iter last) {
//    if (first == last) {
//        return first;
//    }
//    auto prev = first;
//    ++first;
//    for (auto cur = first; cur != last; ++cur, ++prev) {
//        if (*cur != *prev) {
//            *first = *cur;
//            ++first;
//        }
//    }
//    return first;
//}
//int main() {}