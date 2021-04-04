#include <iostream>
#include <stack>
#include <string>

class Serializer {
public:
    virtual void BeginArray() {}
    virtual void AddArrayItem(const std::string &) {}
    virtual void EndArray() {}
    virtual ~Serializer() {}
};

class JsonSerializer: public Serializer {
private:
    std::stack<bool> need_comma;

public:
    JsonSerializer() {
        need_comma.push(false);
    }
    void BeginArray() override {
        if (need_comma.top()) {
            std::cout << ",";
        } else {
            need_comma.top() = true;
        }
        std::cout << "[";
        need_comma.push(false);
    }
    void AddArrayItem(const std::string &str) override {
        if (need_comma.top()) {
            std::cout << ",";
        } else {
            need_comma.top() = true;
        }
        std::cout << '"' << str << '"';
    }
    void EndArray() override {
        std::cout << "]";
        need_comma.pop();
    }
    ~JsonSerializer() override {
        while (!need_comma.empty()) {
            need_comma.pop();
        }
    }
};