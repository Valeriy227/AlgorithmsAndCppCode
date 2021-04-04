#include <algorithm>
#include <cstdio>

class Vector {
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    ~Vector() noexcept;

    void push_back(int elem);
    void pop_back();
    size_t size() const;
    int& operator[](size_t i) const;

private:
    size_t sz;
    size_t capacity;
    int* data;
};

Vector::Vector() : sz(0), capacity(1) {
    data = new int[capacity];
}

Vector::Vector(const Vector& other) : sz(other.sz), capacity(other.capacity) {
    data = new int[capacity];
    for (size_t i = 0; i < sz; ++i) {
        data[i] = other.data[i];
    }
}

Vector& Vector::operator=(const Vector &other) {
    sz = other.sz;
    capacity = other.capacity;
    delete[] data;
    data = new int[capacity];
    for (size_t i = 0; i < sz; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    delete[] data;
    sz = other.sz;
    capacity = other.capacity;
    data = other.data;
    other.data = nullptr;
    return *this;
}

Vector::~Vector() noexcept {
    delete[] data;
}

void Vector::push_back(int elem) {
    if (sz >= capacity) {
        capacity *= 2;
        auto tmp = data;
        data = new int[capacity];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = tmp[i];
        }
        delete[] tmp;
    }
    data[sz] = elem;
    ++sz;
}

void Vector::pop_back() {
    --sz;
    data[sz] = 0;
}

size_t Vector::size() const {
    return sz;
}

int& Vector::operator[](size_t i) const {
    return data[i];
}