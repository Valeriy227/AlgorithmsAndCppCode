#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container container;

public:
    Queue() {}

    T front() const {
        return container.front();
    }

    T& front() {
        return container.front();
    }

    void pop() {
        container.pop_front();
    }

    void push(const T& elem) {
        container.push_back(elem);
    }

    size_t size() {
        return container.size();
    }

    bool empty() {
        return container.empty();
    }

    bool operator==(const Queue& other) {
        return container == other.container;
    }

    bool operator!=(const Queue& other) {
        return container != other.container;
    }
};