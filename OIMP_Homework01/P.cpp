//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <tuple>
//#include <vector>
//
//using namespace std;
//
//struct Student {
//    string name, surname;
//    int day, month, year;
//    Student() {
//        day = month = year = 0;
//    }
//    string toString() const {
//        return name + " " + surname + " " + to_string(day) + "." +
//        to_string(month) + "." + to_string(year);
//    }
//};
//
//bool compare_by_name(const Student& a, const Student& b) {
//    return tie(a.surname, a.name, a.year, a.month, a.day) <
//           tie(b.surname, b.name, b.year, b.month, b.day);
//}
//
//bool compare_by_date(const Student& a, const Student& b) {
//    return tie(a.year, a.month, a.day, a.surname, a.name) <
//           tie(b.year, b.month, b.day, b.surname, b.name);
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<Student> students(n);
//    for (auto& student : students) {
//        cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
//    }
//
//    string key;
//    cin >> key;
//    if (key == "name") {
//        sort(students.begin(), students.end(), compare_by_name);
//    } else {
//        sort(students.begin(), students.end(), compare_by_date);
//    }
//
//    for (const auto& student : students) {
//        cout << student.toString() << endl;
//    }
//}