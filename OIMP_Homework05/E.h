#include <cstdio>

double GetX(double a, double b, int n, int k) {
    return a + (b - a) / n * k;
}

template <typename T>
class IntegrationMethod {
public:
    IntegrationMethod() {}
    virtual double Integrate(T func, double a, double b, int n) {}
};

template <typename T>
class RectangleRule: public IntegrationMethod<T> {
public:
    RectangleRule() {}
    double Integrate(T func, double a, double b, int n) {
        double res = 0;
        for (size_t i = 0; i < n; ++i) {
            auto cur = GetX(a, b, n, i);
            auto next = GetX(a, b, n, i + 1);
            res += func((cur + next) / 2) * (next - cur);
        }
        return res;
    }
};

template <typename T>
class TrapezoidalRule: public IntegrationMethod<T> {
public:
    TrapezoidalRule() {}
    double Integrate(T func, double a, double b, int n) {
        double res = 0;
        for (size_t i = 0; i < n; ++i) {
            auto cur = GetX(a, b, n, i);
            auto next = GetX(a, b, n, i + 1);
            res += (func(cur) + func(next)) / 2 * (next - cur);
        }
        return res;
    }
};