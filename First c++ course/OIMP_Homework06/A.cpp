//#include <algorithm>
//#include <string>
//#include <string_view>
//#include <tuple>
//#include <unordered_map>
//#include <vector>
//
//struct Star {
//    std::string name;
//    uint64_t age;
//};
//
//struct MyStar {
//    std::string_view name;
//    uint64_t age;
//    MyStar() = default;
//    MyStar(const std::string_view& _name, uint64_t _age) : name(_name), age(_age) {}
//    bool operator<(const MyStar& other) {
//        return std::tie(age, name) < std::tie(other.age, other.name);
//    }
//    void swap(MyStar& other) {
//        std::swap(name, other.name);
//        std::swap(age, other.age);
//    }
//};
//
//void swap(MyStar& a, MyStar& b) {
//    a.swap(b);
//}
//
//std::string findStar(const std::vector<Star>& stars) {
//    std::unordered_map<std::string_view, uint64_t> ages;
//    for (const auto& star : stars) {
//        auto& age = ages[star.name];
//        age = std::max(age, star.age);
//    }
//    std::vector<MyStar> unique_stars(ages.size());
//    size_t cur_ind = 0;
//    for (const auto& star : ages) {
//        unique_stars[cur_ind] = {star.first, star.second};
//        cur_ind += 1;
//    }
//    std::nth_element(unique_stars.begin(), unique_stars.begin() + unique_stars.size() / 2,
//            unique_stars.end());
//    MyStar res = unique_stars[unique_stars.size() / 2];
//    for (const auto& star : unique_stars) {
//        if (star.age == res.age && star.name < res.name) {
//            res = star;
//        }
//    }
//    return std::string(res.name);
//}
//
//#include <iostream>
//using namespace std;
//
//int main() {
//
//    vector<Star> v = {{"A", 4}, {"B", 8}, {"C", 8}, {"A", 3}, {"A", 10}};
//    cout << findStar(v);
//}