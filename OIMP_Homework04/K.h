#include <algorithm>
#include <vector>

using std::vector;

template <typename T>
class Polynomial {
public:
    Polynomial(vector<T> vec) : data(vec) {
        to_shape();
    }

    Polynomial(T val = T()) : data{val} {
        to_shape();
    }

    template <typename Iter>
    Polynomial(Iter begin, Iter end) : data(begin, end) {
        to_shape();
    }

    int Degree() const {
        if (data.size() == 0) {
            return -1;
        }
        return data.size() - 1;
    }

    T operator[](size_t i) const {
        if (i >= data.size()) {
            return 0;
        }
        return data[i];
    }

    friend bool operator==(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        for (size_t i = 0; i < std::max(p1.data.size(), p2.data.size()); ++i) {
            if (p1[i] != p2[i]) {
                return false;
            }
        }
        return true;
    }

    friend bool operator!=(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        return !(p1 == p2);
    }

    friend Polynomial<T> operator+(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(p1);
        res.data.resize(std::max(p1.data.size(), p2.data.size()));
        for (size_t i = 0; i < p2.data.size(); ++i) {
            res.data[i] += p2[i];
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator-(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(p1);
        res.data.resize(std::max(p1.data.size(), p2.data.size()));
        for (size_t i = 0; i < p2.data.size(); ++i) {
            res.data[i] -= p2[i];
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T>& operator+=(Polynomial<T>& p1, const Polynomial<T>& p2) {
        p1 = p1 + p2;
        return p1;
    }

    friend Polynomial<T>& operator-=(Polynomial<T>& p1, const Polynomial<T>& p2) {
        p1 = p1 - p2;
        return p1;
    }

    typename vector<T>::const_iterator begin() const {
        return data.begin();
    }

    typename vector<T>::const_iterator end() const {
        return data.end();
    }

private:
    vector<T> data;

    void to_shape() {
        while (!data.empty() && data.back() == T(0)) {
            data.pop_back();
        }
    }
};