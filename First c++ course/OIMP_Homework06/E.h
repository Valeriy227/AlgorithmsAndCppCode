#include <cstdio>
#include <memory>

template <typename T>
class List {
private:
    class Node {
    public:
        std::unique_ptr<T> val;
        Node* prev;
        Node* next;

        Node();
        explicit Node(const T& _val);
        void add(Node* new_prev, Node* new_next);
        void remove();
    };

    class Iterator {
    public:
        explicit Iterator(Node* _node);
        T& operator*();
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator& other);
        bool operator!=(const Iterator& other);

    private:
        Node* node = nullptr;
    };

    Node* first;
    Node* last;
    size_t list_size;

public:
    List();
    ~List();
    List& operator=(const List& other);

    void pop_back();
    void pop_front();
    void push_back(const T& elem);
    void push_front(const T& elem);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator end() const;
};

template <typename T>
List<T>::List() : first(new Node()), last(new Node()), list_size(0) {
    first->next = last;
    last->prev = first;
}

template <typename T>
List<T>::~List() {
    while (list_size > 0) {
        pop_back();
    }
    delete first;
    delete last;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    while (list_size > 0) {
        pop_back();
    }
    for (auto it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
    return *this;
}

template <typename T>
void List<T>::pop_back() {
    auto back = last->prev;
    back->remove();
    delete back;
    list_size -= 1;
}

template <typename T>
void List<T>::pop_front() {
    auto front = first->next;
    front->remove();
    delete front;
    list_size -= 1;
}

template <typename T>
void List<T>::push_back(const T& elem) {
    auto new_back = new Node(elem);
    new_back->add(last->prev, last);
    list_size += 1;
}

template <typename T>
void List<T>::push_front(const T& elem) {
    auto new_front = new Node(elem);
    new_front->add(first, first->next);
    list_size += 1;
}

template <typename T>
size_t List<T>::size() const {
    return list_size;
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(first->next);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(last);
}


template <typename T>
List<T>::Node::Node() : val(nullptr), prev(nullptr), next(nullptr) {}

template <typename T>
List<T>::Node::Node(const T& _val) : val(new T(_val)), prev(nullptr), next(nullptr) {}

template <typename T>
void List<T>::Node::add(Node* new_prev, Node* new_next) {
    prev = new_prev;
    next = new_next;
    new_prev->next = this;
    new_next->prev = this;
}

template <typename T>
void List<T>::Node::remove() {
    prev->next = next;
    next->prev = prev;
}


template <typename T>
List<T>::Iterator::Iterator(List::Node* _node) : node(_node) {}

template <typename T>
T& List<T>::Iterator::operator*() {
    return *(node->val);
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    node = node->next;
    return *this;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    node = node->prev;
    return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) {
    return node == other.node;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) {
    return !(*this == other);
}