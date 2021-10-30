#include <cstdio>

class List {
private:
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;

        Node();
        explicit Node(int _val);
        void add(Node* new_prev, Node* new_next);
        void remove();
    };

    class Iterator {
    public:
        explicit Iterator(Node* _node);
        int operator*();
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
    void push_back(int elem);
    void push_front(int elem);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator end() const;
};

List::List() : first(new Node()), last(new Node()), list_size(0) {
    first->next = last;
    last->prev = first;
}

List::~List() {
    while (list_size > 0) {
        pop_back();
    }
    delete first;
    delete last;
}

List& List::operator=(const List& other) {
    while (list_size > 0) {
        pop_back();
    }
    for (auto it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
    return *this;
}

void List::pop_back() {
    auto back = last->prev;
    back->remove();
    delete back;
    list_size -= 1;
}

void List::pop_front() {
    auto front = first->next;
    front->remove();
    delete front;
    list_size -= 1;
}

void List::push_back(int elem) {
    auto new_back = new Node(elem);
    new_back->add(last->prev, last);
    list_size += 1;
}

void List::push_front(int elem) {
    auto new_front = new Node(elem);
    new_front->add(first, first->next);
    list_size += 1;
}

size_t List::size() const {
    return list_size;
}

List::Iterator List::begin() const {
    return Iterator(first->next);
}

List::Iterator List::end() const {
    return Iterator(last);
}


List::Node::Node() : val(0), prev(nullptr), next(nullptr) {}

List::Node::Node(int _val) : val(_val), prev(nullptr), next(nullptr) {}

void List::Node::add(Node* new_prev, Node* new_next) {
    prev = new_prev;
    next = new_next;
    new_prev->next = this;
    new_next->prev = this;
}

void List::Node::remove() {
    prev->next = next;
    next->prev = prev;
}


List::Iterator::Iterator(List::Node* _node) : node(_node) {}

int List::Iterator::operator*() {
    return node->val;
}

List::Iterator& List::Iterator::operator++() {
    node = node->next;
    return *this;
}

List::Iterator & List::Iterator::operator--() {
    node = node->prev;
    return *this;
}

bool List::Iterator::operator==(const Iterator& other) {
    return node == other.node;
}

bool List::Iterator::operator!=(const Iterator& other) {
    return !(*this == other);
}