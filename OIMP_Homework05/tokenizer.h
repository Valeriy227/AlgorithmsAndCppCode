#include <string>

class CallbackBase {
public:
    virtual void OnToken(const char * token, size_t length) = 0;
    virtual ~CallbackBase() {}
};

class Tokenizer {
public:
    void Tokenize(const std::string& text, CallbackBase* callback) const {}
};