#include <stdexcept>
#include <optional>
#include <unordered_map>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value) {
        if (key1.has_value()) {

        } else if (key2.has_value()) {

        } else {
            throw std::invalid_argument("error");
        }
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key) {
        if (map.fi)
    }
    const Value& GetByPrimaryKey(const Key1& key) const;

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key);
    const Value& GetBySecondaryKey(const Key2& key) const;

    std::unordered_map<Key1, Value> map;
};