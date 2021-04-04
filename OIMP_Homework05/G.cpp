//#include <iostream>
//#include <string>
//#include "tokenizer.h"
//
//class MyCallbackBase: public CallbackBase {
//private:
//    size_t TokensCnt = 0;
//    size_t MaxLength = 0;
//
//public:
//    size_t GetTokensCnt() const {
//        return TokensCnt;
//    }
//    size_t GetMaxLength() const {
//        return MaxLength;
//    }
//    void OnToken(const char *token, size_t length) override {
//        ++TokensCnt;
//        MaxLength = std::max(MaxLength, length);
//    }
//    ~MyCallbackBase() override {}
//};
//
//int main() {
//    std::string str;
//    std::getline(std::cin, str);
//    Tokenizer tokenizer;
//    MyCallbackBase callbackBase;
//    tokenizer.Tokenize(str, &callbackBase);
//    std::cout << callbackBase.GetTokensCnt() << " " << callbackBase.GetMaxLength() << std::endl;
//}