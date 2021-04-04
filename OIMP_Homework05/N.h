#include "classifiers.h"
#include <memory>
#include <string>

class CombinedClassifier {
public:
    CombinedClassifier(const std::string& _forFast,
            const std::string& _forMain) : forFast(_forFast), forMain(_forMain) {
        fastClassifier = std::make_unique<FastClassifier>(FastClassifier(forFast));
    }
    double classify(const string& str) {
        double res = 0;
        try {
            res = fastClassifier->classify(str);
        } catch (TooHardObjectException& exc) {
            if (mainClassifier == nullptr) {
                mainClassifier = std::make_unique<MainClassifier>(MainClassifier(forMain));
            }
            res = mainClassifier->classify(str);
        } catch (...) {}
        return res;
    }

private:
    string forFast;
    string forMain;
    std::unique_ptr<FastClassifier> fastClassifier;
    std::unique_ptr<MainClassifier> mainClassifier;
};