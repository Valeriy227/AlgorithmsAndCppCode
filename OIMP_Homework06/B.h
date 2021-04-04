#include <cstddef>

template <typename T>
class UniquePtr {
public:
    UniquePtr();
    UniquePtr(T*);
    UniquePtr(UniquePtr<T>&&);
    UniquePtr<T>& operator=(std::nullptr_t);
    UniquePtr<T>& operator=(UniquePtr<T>&&) noexcept;
    ~UniquePtr() noexcept;
    T& operator*() const;
    T* operator->() const;
    T* release();
    void reset(T*);
    void swap(UniquePtr<T>&);
    T* get() const;
    explicit operator bool() const;

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

private:
    T* ptr;
};

template <typename T>
UniquePtr<T>::UniquePtr() : ptr(nullptr) {}

template <typename T>
UniquePtr<T>::UniquePtr(T* _ptr) : ptr(_ptr) {
    _ptr = nullptr;
}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) : ptr(other.ptr) {
    other.ptr = nullptr;
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(std::nullptr_t) {
    delete ptr;
    ptr = nullptr;
    return *this;
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept {
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
}

template <typename T>
UniquePtr<T>::~UniquePtr() noexcept {
    delete ptr;
}

template <typename T>
T & UniquePtr<T>::operator*() const {
    return *ptr;
}

template <typename T>
T * UniquePtr<T>::operator->() const {
    return ptr;
}

template <typename T>
T * UniquePtr<T>::release() {
    auto tmp = ptr;
    ptr = nullptr;
    return tmp;
}

template <typename T>
void UniquePtr<T>::reset(T* _ptr) {
    delete ptr;
    ptr = _ptr;
    _ptr = nullptr;
}

template <typename T>
void UniquePtr<T>::swap(UniquePtr<T>& other) {
    auto tmp = ptr;
    ptr = other.ptr;
    other.ptr = tmp;
}

template <typename T>
T* UniquePtr<T>::get() const {
    return ptr;
}

template <typename T>
UniquePtr<T>::operator bool() const {
    return (ptr != nullptr);
}