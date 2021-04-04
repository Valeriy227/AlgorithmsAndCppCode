#include "writer.h"

class BufferedWriter: public Writer {
private:
    char* out;
    size_t reminder;
    size_t bufferSize;
    void check() {
        if (reminder == 0) {
            Writer::Write(out, bufferSize);
            reminder = bufferSize;
        }
    }

public:
    BufferedWriter(size_t _bufferSize) : reminder(_bufferSize), bufferSize(_bufferSize) {
        out = new char[bufferSize];
    }
    void Write(const char* data, size_t len) override {
        this->check();
        for (size_t i = 0; i < len; ++i) {
            out[bufferSize - reminder] = data[i];
            --reminder;
            this->check();
        }
    }
    ~BufferedWriter() {
        if (reminder < bufferSize) {
            Writer::Write(out, bufferSize - reminder);
        }
        delete[] out;
    }
};