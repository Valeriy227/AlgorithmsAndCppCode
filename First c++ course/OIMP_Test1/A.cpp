#include <iostream>
#include <string_view>

bool NextToken(std::string_view& sv, char delimiter, std::string_view& token) {
    if (sv.empty()) {
        return false;
    }
    auto next = sv.find(delimiter);
    if (next == std::string_view::npos) {
        token = sv.substr(0, sv.size());
        sv.remove_prefix(sv.size());
        return true;
    }
    token = sv.substr(0, next);
    sv.remove_prefix(next + 1);
    return true;
}

void solve() {
    std::string_view sv = "Hello world and good bye  ";
    const char delimiter = ' ';
    std::string_view token;
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}

int main() {
    solve();
}