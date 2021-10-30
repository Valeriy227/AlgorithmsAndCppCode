#include <stdexcept>
#include <tuple>
#include <vector>

class Date {
private:
    int days;
    inline static std::vector<int> DAYS_PER_MONTH =
            { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool is_leap(int year) const {
        if (year % 400 == 0) {
            return true;
        }
        if (year % 100 == 0) {
            return false;
        }
        return (year % 4 == 0);
    }

    int get_days_per_month(int _month, int _year) const {
        if (_month == 2) {
            if (is_leap(_year)) {
                return 29;
            }
            return 28;
        }
        return DAYS_PER_MONTH[_month - 1];
    }

    bool check_date(int _day, int _month, int _year) const {
        if (_day <= 0 || _month <= 0 || _year <= 0) {
            return false;
        }
        return _day <= get_days_per_month(_month, _year);
    }

    int get_days(int day, int month, int year) const {
        int cnt = 0;
        for (int i = 1970; i < year; ++i) {
            if (is_leap(i)) {
                cnt += 366;
            } else {
                cnt += 365;
            }
        }
        for (int i = 1; i < month; ++i) {
            cnt += get_days_per_month(i, year);
        }
        cnt += day;
        return cnt;
    }

    std::tuple<int, int, int> get_date(int days) const {
        int day, month, year;
        for (int i = 1970; i <= 2099; ++i) {
            int decr = 365;
            if (is_leap(i)) {
                decr = 366;
            }
            if (days > decr) {
                days -= decr;
            } else {
                year = i;
                break;
            }
        }
        for (int i = 1; i <= 13; ++i) {
            int decr = get_days_per_month(i, year);
            if (days > decr) {
                days -= decr;
            } else {
                month = i;
                break;
            }
        }
        day = days;
        return {day, month, year};
    }

public:
    Date(int _day, int _month, int _year) {
        if (!check_date(_day, _month, _year)) {
            throw std::invalid_argument("error");
        }
        days = get_days(_day, _month, _year);
    }

    int GetDay() const {
        auto [day, month, year] = get_date(days);
        return day;
    }

    int GetMonth() const {
        auto [day, month, year] = get_date(days);
        return month;
    }

    int GetYear() const {
        auto [day, month, year] = get_date(days);
        return year;
    }

    Date& operator++() {
        ++days;
        return *this;
    }

    Date& operator--() {
        --days;
        return *this;
    }

    Date operator+(int cnt) {
        Date res(*this);
        res.days += cnt;
        return res;
    }

    Date operator-(int cnt) {
        Date res(*this);
        res.days -= cnt;
        return res;
    }

    int operator-(Date other) {
        return days - other.days;
    }
};