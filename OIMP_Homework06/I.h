#include <cstdio>
#include <utility>

template <typename T>
class SharedPtr {
public:
    SharedPtr() : ptr(nullptr), count(nullptr) {}

    explicit SharedPtr(T* _ptr) : ptr(_ptr), count(nullptr) {
        if (ptr != nullptr) {
            count = new size_t(1);
        }
    }

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), count(other.count) {
        if (ptr != nullptr) {
            *count += 1;
        }
    }

    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), count(other.count) {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    SharedPtr& operator=(T* _ptr) {
        reset();
        ptr = _ptr;
        if (ptr != nullptr) {
            count = new size_t(1);
        }
        return *this;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (other.ptr != nullptr) {
            *other.count += 1;
        }
        reset();
        ptr = other.ptr;
        count = other.count;
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        swap(other);
        if (&other != this) {
            other.reset();
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    ~SharedPtr() {
        reset();
    }

    T& operator*() {
        return *ptr;
    }

    const T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    void reset(T* _ptr) {
        reset();
        ptr = _ptr;
        if (ptr != nullptr) {
            count = new size_t(1);
        }
    }

    void swap(SharedPtr& other) {
        std::swap(ptr, other.ptr);
        std::swap(count, other.count);
    }

    T* get() const {
        return ptr;
    }

    explicit operator bool() const {
        return (ptr != nullptr);
    }

private:
    T* ptr;
    size_t* count;

    void reset() {
        if (ptr != nullptr) {
            *count -= 1;
            if (*count == 0) {
                delete count;
                delete ptr;
                ptr = nullptr;
                count = nullptr;
            }
        }
    }
};