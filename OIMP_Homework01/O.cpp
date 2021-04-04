//#include <cctype>
//#include <string>
//#include <vector>
//
//bool contains(const std::vector<char>& vowels, char letter) {
//    if (isupper(letter)) {
//        letter = static_cast<char>(letter - 'A' + 'a');
//    }
//    for (const auto& vowel : vowels) {
//        if (vowel == letter) {
//            return true;
//        }
//    }
//    return false;
//}
//
//std::pair<size_t, size_t> FindVowels(const std::string& text, size_t pos) {
//    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
//    while (pos < text.length() && !contains(vowels, text[pos])) {
//        pos++;
//    }
//    size_t start = pos;
//    if (start >= text.size()) {
//        return {-1, 0};
//    }
//    while (pos < text.length() && contains(vowels, text[pos])) {
//        pos++;
//    }
//    size_t count = pos - start;
//    return {start, count};
//}