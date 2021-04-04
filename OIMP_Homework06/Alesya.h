#include <iostream>
#include <cstddef>

template<typename T>
class UniquePtr {
private:
    T* elem = nullptr;

public:
    UniquePtr() {}

    UniquePtr(T* ptr): elem(ptr) {
        ptr = nullptr;
    }

    UniquePtr(UniquePtr&& other): elem(other.elem) {
        other.elem = nullptr;
    }

    UniquePtr(const UniquePtr&) = delete;

    UniquePtr& operator=(std::nullptr_t) {
        delete elem;
        elem = nullptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) {
        delete elem;
        elem = other.elem;
        other.elem = nullptr;
        return *this;
    }

    UniquePtr& operator=(const UniquePtr&) = delete;

    ~UniquePtr() {
        delete elem;
    }

    T operator*() const {
        return *elem;
    }

    T* operator->() const {
        return elem;
    }

    T* release() {
        T* ptr = elem;
        elem = nullptr;
        return ptr;
    }

    void reset(T* ptr) {
        delete elem;
        elem = ptr;
        ptr = nullptr;
    }

    void swap(UniquePtr& other) {
        std::swap(elem, other.elem);
    }

    T* get() const {
        return elem;
    }

    explicit operator bool() const {
        return elem != nullptr;
    }
};