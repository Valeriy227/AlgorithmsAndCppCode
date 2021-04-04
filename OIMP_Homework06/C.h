#include <cstddef>
#include <memory>
#include <tuple>

template <typename T, class Deleter = std::default_delete<T>>
class UniquePtr {
public:
    UniquePtr();
    UniquePtr(T*);
    UniquePtr(T*, const Deleter&);
    UniquePtr(UniquePtr<T, Deleter>&&);

    ~UniquePtr() noexcept;

    UniquePtr<T, Deleter>& operator=(std::nullptr_t);
    UniquePtr<T, Deleter>& operator=(UniquePtr<T, Deleter>&&) noexcept;

    T& operator*() const;
    T* operator->() const;

    T* release();
    void reset(T*);
    T* get() const;
    void swap(UniquePtr<T, Deleter>&);

    Deleter& get_deleter();
    const Deleter& get_deleter() const;

    explicit operator bool() const;

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

private:
    std::tuple<T*, Deleter> data;
};

template <typename T, class Deleter>
UniquePtr<T, Deleter>::UniquePtr() : data(nullptr, Deleter()) {}

template <typename T, class Deleter>
UniquePtr<T, Deleter>::UniquePtr(T* _ptr) : data(_ptr, Deleter()) {}

template <typename T, class Deleter>
UniquePtr<T, Deleter>::UniquePtr(T* _ptr, const Deleter& _deleter) : data(_ptr, _deleter) {}

template <typename T, class Deleter>
UniquePtr<T, Deleter>::UniquePtr(UniquePtr<T, Deleter>&& other) : data(other.data) {
    std::get<0>(other.data) = nullptr;
}

template <typename T, class Deleter>
UniquePtr<T, Deleter>& UniquePtr<T, Deleter>::operator=(std::nullptr_t) {
    std::get<1>(data)(std::get<0>(data));
    std::get<0>(data) = nullptr;
    return *this;
}

template <typename T, class Deleter>
UniquePtr<T, Deleter>& UniquePtr<T, Deleter>::operator=(UniquePtr<T, Deleter>&& other) noexcept {
    std::get<1>(data)(std::get<0>(data));
    std::get<0>(data) = std::get<0>(other.data);
    std::get<0>(other.data) = nullptr;
    return *this;
}

template <typename T, class Deleter>
UniquePtr<T, Deleter>::~UniquePtr() noexcept {
    std::get<1>(data)(std::get<0>(data));
}

template <typename T, class Deleter>
T & UniquePtr<T, Deleter>::operator*() const {
    return *std::get<0>(data);
}

template <typename T, class Deleter>
T * UniquePtr<T, Deleter>::operator->() const {
    return std::get<0>(data);
}

template <typename T, class Deleter>
T * UniquePtr<T, Deleter>::release() {
    auto tmp = std::get<0>(data);
    std::get<0>(data) = nullptr;
    return tmp;
}

template <typename T, class Deleter>
void UniquePtr<T, Deleter>::reset(T* _ptr) {
    std::get<1>(data)(std::get<0>(data));
    std::get<0>(data) = _ptr;
}

template <typename T, class Deleter>
void UniquePtr<T, Deleter>::swap(UniquePtr<T, Deleter>& other) {
    auto tmp = std::get<0>(data);
    std::get<0>(data) = std::get<0>(other.data);
    std::get<0>(other.data) = tmp;
}

template <typename T, class Deleter>
Deleter& UniquePtr<T, Deleter>::get_deleter() {
    return std::get<1>(data);
}

template <typename T, class Deleter>
const Deleter& UniquePtr<T, Deleter>::get_deleter() const {
    return std::get<1>(data);
}

template <typename T, class Deleter>
T* UniquePtr<T, Deleter>::get() const {
    return std::get<0>(data);
}

template <typename T, class Deleter>
UniquePtr<T, Deleter>::operator bool() const {
    return (std::get<0>(data) != nullptr);
}