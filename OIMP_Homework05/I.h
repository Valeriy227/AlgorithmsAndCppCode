#include <iostream>
#include <vector>

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sz = data.size();
    out.write(reinterpret_cast<char*>(&sz), sizeof(sz));
    for (auto elem : data)
        out.write(reinterpret_cast<char*>(&elem), sizeof(elem));
}

void Model::load(std::istream& in) {
    size_t sz = 0;
    in.read(reinterpret_cast<char*>(&sz), sizeof(sz));
    data.resize(sz);
    for (size_t i = 0; i != sz; ++i)
        in.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));
}