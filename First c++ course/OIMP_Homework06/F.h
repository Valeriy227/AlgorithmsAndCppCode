#include <utility>

struct BadOptionalAccess {
};

template <typename T>
class Optional {
private:
    alignas(T) unsigned char data[sizeof(T)];
    bool defined = false;

public:
    Optional() = default;
    Optional(const T& elem);
    Optional(T && elem);
    Optional(const Optional& other);

    Optional<T>& operator=(const Optional<T>& other);
    Optional<T>& operator=(const T& elem);
    Optional<T>& operator=(T && elem);

    bool has_value() const;

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;

    T& value();
    const T& value() const;

    void reset();

    ~Optional();
};

template <typename T>
Optional<T>::Optional(const T& elem) : defined(true) {
    new (data) T(elem);
}

template <typename T>
Optional<T>::Optional(T && elem) : defined(true) {
    new (data) T(std::move(elem));
}

template <typename T>
Optional<T>::Optional(const Optional& other) {
    if (other.defined) {
        defined = true;
        new (data) T(*other);
    }
}

template <typename T>
Optional<T>& Optional<T>::operator=(const Optional& other) {
    if (other.defined) {
        if (defined) {
            **this = *other;
        } else {
            defined = true;
            new (data) T(*other);
        }
    } else {
        reset();
    }
    return *this;
}

template <typename T>
Optional<T>& Optional<T>::operator=(const T& elem) {
    if (defined) {
        **this = elem;
    } else {
        defined = true;
        new (data) T(elem);
    }
    return *this;
}

template <typename T>
Optional<T>& Optional<T>::operator=(T&& elem) {
    if (defined) {
        **this = std::move(elem);
    } else {
        defined = true;
        new (data) T(std::move(elem));
    }
    return *this;
}

template <typename T>
bool Optional<T>::has_value() const {
    return defined;
}

template <typename T>
T& Optional<T>::operator*() {
    if (!defined) {
        throw BadOptionalAccess();
    }
    return *reinterpret_cast<T*>(const_cast<unsigned char*>(data));
}

template <typename T>
const T& Optional<T>::operator*() const {
    if (!defined) {
        throw BadOptionalAccess();
    }
    return *reinterpret_cast<T*>(const_cast<unsigned char*>(data));
}

template <typename T>
T* Optional<T>::operator->() {
    if (!defined) {
        throw BadOptionalAccess();
    }
    return reinterpret_cast<T*>(data);
}

template <typename T>
const T* Optional<T>::operator->() const {
    if (!defined) {
        throw BadOptionalAccess();
    }
    return reinterpret_cast<T*>(const_cast<unsigned char*>(data));
}

template <typename T>
T& Optional<T>::value() {
    return **this;
}

template <typename T>
const T& Optional<T>::value() const {
    return **this;
}

template <typename T>
void Optional<T>::reset() {
    if (defined) {
        defined = false;
        reinterpret_cast<T*>(data)->~T();
    }
}

template <typename T>
Optional<T>::~Optional() {
    reset();
}