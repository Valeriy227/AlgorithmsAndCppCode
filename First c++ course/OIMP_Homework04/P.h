#include <algorithm>
#include <ostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

template <typename T>
class Polynomial {
public:
    Polynomial(vector<T> vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            data[i] = vec[i];
        }
        to_shape();
    }

    Polynomial(T val = T()) {
        data[0] = val;
        to_shape();
    }

    template <typename Iter>
    Polynomial(Iter begin, Iter end) {
        int ind = 0;
        while (begin != end) {
            data[ind] = *begin;
            ++ind;
        }
        to_shape();
    }

    int Degree() const {
        if (data.size() == 0) {
            return -1;
        }
        return data.rbegin()->first;
    }

    T operator[](size_t i) const {
        if (data.count(i) == 0) {
            return 0;
        }
        return data[i];
    }

    friend bool operator==(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        if (p1.data.size() != p2.data.size()) {
            return false;
        }
        for (auto it : p1) {
            if (p2[it.first] != it.second) {
                return false;
            }
        }
        return true;
    }

    friend bool operator!=(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        return !(p1 == p2);
    }

    friend Polynomial<T> operator+(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        for (const auto& [ind, coef] : p1) {
            res.data[ind] += coef;
        }
        for (const auto& [ind, coef] : p2) {
            res.data[ind] += coef;
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator-(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        for (const auto& [ind, coef] : p1) {
            res.data[ind] -= coef;
        }
        for (const auto& [ind, coef] : p2) {
            res.data[ind] -= coef;
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator*(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        for (const auto& [ind1, coef1] : p1) {
            for (const auto& [ind2, coef2] : p2) {
                res.data[ind1 + ind2] += coef1 * coef2;
            }
        }
        res.to_shape();
        return res;
    }

    friend Polynomial<T> operator&(const Polynomial<T>& p1, const Polynomial<T>& p2) {
        Polynomial res(0);
        int cnt = 0;
        Polynomial power(1);
        for (const auto& [ind, coef] : p1) {
            while (cnt < ind) {
                power *= p2;
                ++cnt;
            }
            res += coef * power;
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
            auto coefficient = reminder[i] / p2.data.rbegin()->second;
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
        for (const auto& [ind, coef] : data) {
            res += power * coef;
            power *= val;
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p) {
        if (p.Degree() == -1) {
            out << 0;
        } else if (p.Degree() == 0) {
            out << p[0];
        } else {
            for (auto it = p.data.rbegin(); it != p.data.rend(); ++it) {
                auto i = it->first;
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

private:
    map<size_t, T> data;

    void to_shape() {
        vector<int> to_del;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->second == T(0)) {
                to_del.push_back(it->first);
            }
        }
        for (auto i : to_del) {
            data.erase(i);
        }
    }

    void to_nth_degree(int n) {
        data.clear();
        data[n] = T(1);
    }

    void decrease_degree() {
        if (data.size() > 1) {
            data[data.rbegin()->first] = T(1);
        }
        data.erase(data.rbegin());
    }

    void swap(Polynomial<T>& other) {
        data.swap(other.data);
    }
};
