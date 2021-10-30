#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, size_t> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        if (data[id] > 0) {
            --data[id];
        }
    }

    size_t getNumberOf(int id) const {
        if (data.count(id) == 0) {
            return 0;
        }
        return data.at(id);
    }
};