#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount,
        int sleepTime, bool throwLast) {
    Result res;
    for (int i = 0; i <= retryCount; ++i) {
        try {
            res = func();
        } catch (Exception exc) {
            if (i == retryCount) {
                if (throwLast) {
                    throw exc;
                }
                return {};
            }
            Sleep(sleepTime);
            continue;
        }
        return res;
    }
}