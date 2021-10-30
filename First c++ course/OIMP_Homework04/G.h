#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

class Date {
private:
    int day, month, year;
    inline static std::vector<int> DAYS_PER_MONTH =
            { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool is_leap(int year) {
        if (year % 400 == 0) {
            return true;
        }
        if (year % 100 == 0) {
            return false;
        }
        return (year % 4 == 0);
    }

    int get_days_per_month(int _month, int _year) {
        if (_month == 2) {
            if (is_leap(_year)) {
                return 29;
            }
            return 28;
        }
        return DAYS_PER_MONTH[_month - 1];
    }

    bool check_date(int _day, int _month, int _year) {
        if (_day <= 0 || _month <= 0 || _year <= 0) {
            return false;
        }
        return _day <= get_days_per_month(_month, _year);
    }

public:
    Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {
        if (!check_date(day, month, year)) {
            throw std::invalid_argument("error");
        }
    }

    int GetDay() const {
        return day;
    }

    int GetMonth() const {
        return month;
    }

    int GetYear() const {
        return year;
    }

    Date& operator++() {
        ++day;
        if (day > get_days_per_month(month, year)) {
            day = 1;
            ++month;
        }
        if (month > 12) {
            month = 1;
            ++year;
        }
        return *this;
    }

    Date& operator--() {
        --day;
        if (day == 0) {
            --month;
            if (month == 0) {
                month = 12;
                --year;
            }
            day = get_days_per_month(month, year);
        }
        return *this;
    }

    Date operator+(int cnt) {
        Date res(*this);
        while (cnt > 0) {
            --cnt;
            ++res;
        }
        return res;
    }

    Date operator-(int cnt) {
        Date res(*this);
        while (cnt > 0) {
            --cnt;
            --res;
        }
        return res;
    }

    bool operator!=(const Date& other) {
        return !(day == other.day && month == other.month && year == other.year);
    }

    bool operator<(const Date& other) {
        return std::tie(year, month, day) < std::tie(other.year, other.month, other.day);
    }

    int operator-(Date other) {
        int cnt = 0;
        while (*this < other) {
            --other;
            --cnt;
        }
        while (other < *this) {
            ++other;
            ++cnt;
        }
        return cnt;
    }
};