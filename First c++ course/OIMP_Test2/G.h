template <typename It1, typename It2>
int count_subsegments(It1 begin1, It1 end1, It2 begin2, It2 end2) {
    int cnt = 0;
    for (auto it1 = begin1; it1 != end1; ++it1) {
        auto tmp = it1;
        bool has_entrance = true;
        for (auto it2 = begin2; it2 != end2; ++it2, ++tmp) {
            if (tmp == end1) {
                has_entrance = false;
                break;
            }
            if (*tmp != *it2) {
                has_entrance = false;
                break;
            }
        }
        if (has_entrance) {
            ++cnt;
        }
    }
    return cnt;
}