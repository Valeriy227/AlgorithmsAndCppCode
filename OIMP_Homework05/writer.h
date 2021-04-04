#include <cstdio>
#include <iostream>

class Writer {
public:
    virtual void Write(const char * data, size_t len) {
        for (size_t i = 0; i < len; ++i) {
            std::cout << data[i];
        }
        std::cout << std::endl;
    }
};