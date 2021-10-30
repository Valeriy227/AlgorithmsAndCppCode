class Figure {
public:
    virtual int Perimeter() const {
        return 0;
    }
    virtual ~Figure() {}
};

class Triangle: public Figure {
public:
    Triangle(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    int Perimeter() const override {
        return a + b + c;
    }
    ~Triangle() {}

    int a, b, c;
};

class Rectangle: public Figure {
public:
    Rectangle(int _a, int _b) : a(_a), b(_b) {}
    int Perimeter() const override {
        return 2 * (a + b);
    }
    ~Rectangle() {}

    int a, b;
};