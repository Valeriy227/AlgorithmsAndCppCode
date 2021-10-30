#include <list>
#include <set>
#include <tuple>

class Stock {
public:
    Stock();
    void add(int w, int v);
    int get_by_w(int min_w);
    int get_by_v(int min_v);

private:
    struct Box {
        int volume;
        int weight;
        int index;
        Box(int _v, int _w, int _index);
    };
    struct comp_by_v {
        bool operator()(Box* a, Box* b) const;
    };
    struct comp_by_w {
        bool operator()(Box* a, Box* b) const;
    };

    int cnt;
    std::list<Box> boxes;
    std::set<Box*, comp_by_v> sorted_by_v;
    std::set<Box*, comp_by_w> sorted_by_w;
};

Stock::Stock() : cnt(0) {}

void Stock::add(int w, int v) {
    boxes.emplace_back(v, w, cnt);
    sorted_by_v.insert(&boxes.back());
    sorted_by_w.insert(&boxes.back());
    cnt += 1;
}

int Stock::get_by_w(int min_w) {
    auto im_box = Box(0, min_w, cnt);
    auto it = sorted_by_w.lower_bound(&im_box);

    Box* box;
    if (it == sorted_by_w.end()) {
        return -1;
    } else {
        box = *it;
    }

    sorted_by_w.erase(box);
    sorted_by_v.erase(box);
    return box->index;
}

int Stock::get_by_v(int min_v) {
    auto im_box = Box(min_v, 0, cnt);
    auto it = sorted_by_v.lower_bound(&im_box);

    Box* box;
    if (it == sorted_by_v.end()) {
        return -1;
    } else {
        box = *it;
    }

    sorted_by_w.erase(box);
    sorted_by_v.erase(box);
    return box->index;
}

Stock::Box::Box(int _v, int _w, int _index) : volume(_v), weight(_w), index(_index) {}

bool Stock::comp_by_w::operator()(Stock::Box *a, Stock::Box *b) const {
    return std::tie(a->weight, b->index) < std::tie(b->weight, a->index);
}

bool Stock::comp_by_v::operator()(Stock::Box *a, Stock::Box *b) const {
    return std::tie(a->volume, b->index) < std::tie(b->volume, a->index);
}