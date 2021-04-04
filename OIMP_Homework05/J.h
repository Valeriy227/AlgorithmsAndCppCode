#include <cstddef>
#include <sstream>

class RangeError {
};

size_t CountValues(const char* data, size_t size) {
    char for_len[sizeof(size_t)];
    size_t len = 0;
    size_t cnt = 0;
    for (size_t i = 0; i < size;) {
        if (i + sizeof(len) > size) {
            throw RangeError();
        }
        for (size_t j = 0; j < sizeof(len); ++j) {
            for_len[j] = data[i + j];
        }
        std::stringstream ss(for_len);
        ss.read(reinterpret_cast<char*>(&len), sizeof(len));
        i += sizeof(len);
        if (i + len * sizeof(char) > size) {
            throw RangeError();
        }
        i += len * sizeof(char);
        cnt += 1;
    }
    return cnt;
}