//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <tuple>
//#include <unordered_map>
//#include <vector>
//
//struct Student {
//    int score;
//    int year, month, day;
//    std::string last_name, name;
//    std::vector<int> preferences;
//};
//
//struct University {
//    std::string name;
//    int max_cnt;
//    std::vector<Student> students;
//};
//
//void distribute() {
//    int n;
//    std::cin >> n;
//    std::unordered_map<std::string, int> ind;
//    std::vector<University> universities(n);
//    for (int i = 0; i < n; ++i) {
//        std::cin >> universities[i].name >> universities[i].max_cnt;
//        ind[universities[i].name] = i;
//    }
//    int m;
//    std::cin >> m;
//    std::vector<Student> students(m);
//    for (auto& student : students) {
//        std::cin >> student.name >> student.last_name >> student.day >>
//        student.month >> student.year >> student.score;
//        int k;
//        std::cin >> k;
//        student.preferences.resize(k);
//        for (int i = 0; i < k; ++i) {
//            std::string univer;
//            std::cin >> univer;
//            student.preferences[i] = ind[univer];
//        }
//    }
//    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
//        return tie(a.score, b.year, b.month, b.day, b.last_name, b.name) >
//        tie(b.score, a.year, a.month, a.day, a.last_name, a.name);
//    });
//    for (const auto& student : students) {
//        for (int i : student.preferences) {
//            if (universities[i].students.size() < universities[i].max_cnt) {
//                universities[i].students.push_back(student);
//                break;
//            }
//        }
//    }
//    sort(universities.begin(), universities.end(), [](const auto& a, const auto& b) {
//        return a.name < b.name;
//    });
//    for (auto& university : universities) {
//        sort(university.students.begin(), university.students.end(),
//                [](const Student& a, const Student& b) {
//            return tie(a.last_name, a.name, a.year, a.month, a.day) <
//            tie(b.last_name, b.name, b.year, b.month, b.day);
//        });
//        std::cout << university.name;
//        for (const auto& student : university.students) {
//            std::cout << '\t' << student.name << " " << student.last_name;
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    distribute();
//}