#include <functional>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;

    void Insert(const std::vector<std::string>& node);

    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string> &node) const {
    const Node* cur = &root;
    for (const auto& key : node) {
        if (cur->children.count(key) == 0) {
            return false;
        }
        cur = &cur->children[key];
    }
//    if (node.empty()) {
//        return true;
//    }
//    if (root.children.count(node[0]) == 0) {
//        return false;
//    }
//    Node* current = &root.children.at(node[0]);
//    for (const auto& key : node) {
//        if (current.children.count(key) == 0) {
//            return false;
//        }
//        current = current.children[key];
//    }
//    return true;
}

void Tree::Insert(const std::vector<std::string> &node) {
    Node& current = root;
    for (const auto& key : node) {
        if (current.children.count(key) == 0) {
            current.children[key] = Node();
        }
        current = current.children[key];
    }
}

void Del(Node& node) {
    for (auto& [key, val] : node.children) {
        Del(val);
    }
    node.children.clear();
}

void Tree::Delete(const std::vector<std::string> &node) {
    Node& prev = root;
    Node& current = root;
    for (const auto& key : node) {
        if (current.children.count(key) == 0) {
            current.children[key] = Node();
        }
        prev = current;
        current = current.children[key];
    }
    Del(current);
    if (!node.empty()) {
        prev.children.erase(node.back());
    }
}