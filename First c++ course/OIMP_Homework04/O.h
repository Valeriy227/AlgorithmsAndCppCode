#include <algorithm>
#include <ostream>
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

    friend Polynomial<T> operator*(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        res.data.resize(p1.data.size() + p2.data.size() - 1);
        for (size_t i = 0; i < p1.data.size(); ++i) {
            for (size_t j = 0; j < p2.data.size(); ++j) {
                res.data[i + j] += p1.data[i] * p2.data[j];
            }
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator&(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        Polynomial power(1);
        for (size_t i = 0; i < p1.data.size(); ++i) {
            res += p1[i] * power;
            power *= p2;
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator/(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        vector<T> coefficients;
        auto reminder = p1;
        Polynomial<T> multiplier(0);
        multiplier.to_nth_degree(p1.Degree() - p2.Degree());
        for (size_t i = reminder.data.size() - 1; i + 1 >= p2.data.size(); --i) {
            auto coefficient = reminder[i] / p2.data.back();
            coefficients.push_back(coefficient);
            reminder -= coefficient * p2 * multiplier;
            multiplier.decrease_degree();
        }
        std::reverse(coefficients.begin(), coefficients.end());
        auto res(coefficients);
        return res;
    }

    friend Polynomial<T> operator%(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        auto divider = p1 / p2;
        auto res = p1 - p2 * divider;
        return res;
    }

    friend Polynomial<T> operator,(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        auto a = p1, b = p2;
        while (b != Polynomial<T>(0)) {
            a = a % b;
            a.swap(b);
        }
        if (!a.data.empty()) {
            a = a / Polynomial<T>(a.data.back());
        }
        return a;
    }

    friend Polynomial<T>& operator+=(Polynomial<T>& p1, const Polynomial<T>& p2) {
        p1 = p1 + p2;
        return p1;
    }

    friend Polynomial<T>& operator-=(Polynomial<T>& p1, const Polynomial<T>& p2) {
        p1 = p1 - p2;
        return p1;
    }

    friend Polynomial<T>& operator*=(Polynomial<T>& p1, const Polynomial<T>& p2) {
        p1 = p1 * p2;
        return p1;
    }

    typename vector<T>::const_iterator begin() const {
        return data.begin();
    }

    typename vector<T>::const_iterator end() const {
        return data.end();
    }

    T operator()(const T& val) const {
        T res = 0;
        T power = 1;
        for (const auto& coef : data) {
            res += power * coef;
            power *= val;
        }
        return res;
    }

private:
    vector<T> data;

    void to_shape() {
        while (!data.empty() && data.back() == T(0)) {
            data.pop_back();
        }
    }

    void to_nth_degree(int n) {
        data.clear();
        for (int i = 0; i < n; ++i) {
            data.push_back(T(0));
        }
        data.push_back(T(1));
    }

    void decrease_degree() {
        if (data.size() > 1) {
            data[data.size() - 2] = data.back();
        }
        data.pop_back();
    }

    void swap(Polynomial<T>& other) {
        data.swap(other.data);
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p) {
    if (p.Degree() == -1) {
        out << 0;
    } else if (p.Degree() == 0) {
        out << p[0];
    } else {
        for (int i = p.Degree(); i >= 0; --i) {
            if (p[i] == T(0)) {
                continue;
            }

            if (p[i] > T(0) && i < p.Degree()) {
                out << '+';
            }

            if (i > 0) {
                if (p[i] != T(1) && p[i] != T(-1)) {
                    out << p[i];
                    out << '*';
                }
                if (p[i] == T(-1)) {
                    out << '-';
                }
            } else {
                out << p[i];
            }

            if (i > 0) {
                out << 'x';
            }
            if (i > 1) {
                out << '^' << i;
            }
        }
    }
    return out;
}