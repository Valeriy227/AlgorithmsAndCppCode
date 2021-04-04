#include <algorithm>

template <typename OuterCollection>
class RangeClass {
public:
    class RangeIterator {
    public:
        RangeIterator() {}
        RangeIterator(const RangeIterator& other) {
            outer = other.outer;
            rbegin = other.rbegin;
            inner = other.inner;
        }
        RangeIterator& operator=(const RangeIterator& other) {
            outer = other.outer;
            rbegin = other.rbegin;
            inner = other.inner;
        }
        RangeIterator& operator++() {
            ++inner;
            set_next();
            return *this;
        }
        RangeIterator operator++(int) {
            auto tmp(*this);
            ++inner;
            set_next();
            return tmp;
        }
        friend void swap(RangeIterator& a, RangeIterator& b) {
            std::swap(a.inner, b.inner);
            std::swap(a.outer, b.outer);
            std::swap(a.rbegin, b.rbegin);
        }
        typename OuterCollection::value_type::value_type operator*() const {
            return *inner;
        }
        typename OuterCollection::value_type::value_type* operator->() const {
            return &(*inner);
        }
        bool operator==(const RangeIterator& other) const {
            return (outer == other.outer && inner == other.inner);
        }
        bool operator!=(const RangeIterator& other) const {
            return !(outer == other.outer && inner == other.inner);
        }

        typename OuterCollection::const_iterator outer;
        typename OuterCollection::const_iterator rbegin;
        typename OuterCollection::value_type::const_iterator inner;

        bool set_next() {
            while (inner == outer->end()) {
                if (outer == rbegin) {
                    return false;
                }
                ++outer;
                inner = outer->begin();
            }
            return true;
        }
    };

    RangeClass(const OuterCollection& _collection) : collection(_collection) {
        set_rbegin();
        it_begin.rbegin = it_end.rbegin = rbegin;
        it_begin.outer = collection.begin();
        it_begin.inner = it_begin.outer->begin();
        it_begin.set_next();
        it_end.outer = rbegin;
        it_end.inner = rbegin->end();
    }

    RangeIterator begin() {
        return it_begin;
    }

    RangeIterator end() {
        return it_end;
    }

private:
    const OuterCollection& collection;
    RangeIterator it_begin, it_end;
    typename OuterCollection::const_iterator rbegin;

    void set_rbegin() {
        auto prev = collection.begin(), cur = collection.begin();
        while (cur != collection.end()) {
            prev = cur;
            ++cur;
        }
        rbegin = prev;
    }
};

template <typename OuterCollection>
RangeClass<OuterCollection> MakeRange(const OuterCollection& collection) {
    return RangeClass(collection);
}