class Rational {
public:
    Rational(int num_ = 0, int denom_ = 1) : num(num_), denom(denom_) {
        to_shape();
    }

    int numerator() const {
        return num;
    }

    int denominator() const {
        return denom;
    }

    Rational operator+() const {
        Rational res(num, denom);
        return res;
    }

    Rational operator-() const {
        Rational res(-num, denom);
        return res;
    }

    friend Rational operator+(const Rational& a, const Rational& b) {
        Rational res(a.num * b.denom + a.denom * b.num, a.denom * b.denom);
        res.to_shape();
        return res;
    }

    friend Rational operator-(const Rational& a, const Rational& b) {
        Rational res = a + -b;
        return res;
    }

    friend Rational operator*(const Rational& a, const Rational& b) {
        Rational res(a.num * b.num, a.denom * b.denom);
        res.to_shape();
        return res;
    }

    friend Rational operator/(const Rational& a, const Rational& b) {
        Rational res(a.num * b.denom, a.denom * b.num);
        res.to_shape();
        return res;
    }

    friend Rational& operator+=(Rational& a, const Rational& b) {
        a = a + b;
        return a;
    }

    friend Rational& operator-=(Rational& a, const Rational& b) {
        a = a - b;
        return a;
    }

    friend Rational& operator*=(Rational& a, const Rational& b) {
        a = a * b;
        return a;
    }

    friend Rational& operator/=(Rational& a, const Rational& b) {
        a = a / b;
        return a;
    }

    friend Rational& operator++(Rational& r) {
        r = r + 1;
        return r;
    }

    friend Rational& operator--(Rational& r) {
        r = r - 1;
        return r;
    }

    friend Rational operator++(Rational& r, int) {
        Rational prev_r(r);
        r = r + 1;
        return prev_r;
    }

    friend Rational operator--(Rational& r, int) {
        Rational prev_r(r);
        r = r - 1;
        return prev_r;
    }

    friend bool operator==(const Rational& a, const Rational& b) {
        return (a.num == b.num && a.denom == b.denom);
    }

    friend bool operator!=(const Rational& a, const Rational& b) {
        return !(a == b);
    }

private:
    int num, denom;

    void to_shape() {
        int g = gcd(num, denom);
        num /= g;
        denom /= g;
        if (denom < 0) {
            denom = -denom;
            num = -num;
        }
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};