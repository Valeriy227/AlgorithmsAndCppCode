#include <cmath>

class Complex {
private:
    double real, imaginary;

public:
    Complex(double _real, double _imaginary = 0) : real(_real), imaginary(_imaginary) {}

    Complex operator-() const {
        Complex res(-real, -imaginary);
        return res;
    }

    Complex operator+() const {
        Complex res(real, imaginary);
        return res;
    }

    double Re() const {
        return real;
    }

    double Im() const {
        return imaginary;
    }

    friend Complex operator+(const Complex& a, const Complex& b) {
        Complex res(a.real + b.real, a.imaginary + b.imaginary);
        return res;
    }

    friend Complex operator-(const Complex& a, const Complex& b) {
        Complex res(a.real - b.real, a.imaginary - b.imaginary);
        return res;
    }

    friend Complex operator*(const Complex& a, const Complex& b) {
        Complex res(a.real * b.real - a.imaginary * b.imaginary,
                a.real * b.imaginary + a.imaginary * b.real);
        return res;
    }

    friend Complex operator/(const Complex& a, const Complex& b) {
        double denominator = b.real * b.real + b.imaginary * b.imaginary;
        Complex res((a.real * b.real + a.imaginary * b.imaginary) / denominator,
                    (a.imaginary * b.real - a.real * b.imaginary) / denominator);
        return res;
    }

    friend bool operator==(const Complex& a, const Complex& b) {
        return (a.real == b.real && a.imaginary == b.imaginary);
    }

    friend bool operator!=(const Complex& a, const Complex& b) {
        return !(a == b);
    }
};

double abs(const Complex& number) {
    return std::sqrt(number.Re() * number.Re() + number.Im() * number.Im());
}