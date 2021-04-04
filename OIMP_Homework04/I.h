#include <vector>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;

public:
    Table(size_t n, size_t m) {
        data.resize(n);
        for (auto& row : data) {
            row.resize(m);
        }
    }

    std::vector<T>& operator[](size_t i) {
        return data[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        return data[i];
    }

    void resize(size_t n, size_t m) {
        data.resize(n);
        for (auto& row : data) {
            row.resize(m);
        }
    }

    std::pair<size_t, size_t> size()  const {
        if (data.size() == 0) {
            return {0, 0};
        }
        return {data.size(), data.back().size()};
    }
};