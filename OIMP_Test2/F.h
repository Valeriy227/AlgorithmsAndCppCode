#include <algorithm>
#include <vector>
#include <tuple>

template <typename C>
bool Compare(const C& x, const C& y) {
    return x.Serialize() < y.Serialize();
}

template <typename C>
bool Equal(const C& x, const C& y) {
    return x.Serialize() == y.Serialize();
}

template <typename C>
bool HaveDifference(std::vector<C> a, std::vector<C> b) {
    if (a.size() != b.size()) {
        return true;
    }
    std::sort(a.begin(), a.end(), Compare<C>);
    std::sort(b.begin(), b.end(), Compare<C>);
    return !equal(a.begin(), a.end(), b.begin(), b.end(), Equal<C>);
}