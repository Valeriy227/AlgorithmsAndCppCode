#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
private:
    std::unordered_map<Key, Value> data;

public:
    KeyValueStorage();

    void insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void remove(const Key& key) {
        data.erase(key);
    }

    bool find(const Key& key, Value * const value = nullptr) const;
};


template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value* const value) const {
    auto it = data.find(key);
    if (it != data.end()) {
        if (value != nullptr)
            *value = it->second;
        return true;
    }
    return false;
}
