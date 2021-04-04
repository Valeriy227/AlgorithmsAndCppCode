class B: public A {
public:
    B() : A(42) {
        a = new A(17);
    }
    ~B() {
        delete a;
    }

private:
    A* a;
};