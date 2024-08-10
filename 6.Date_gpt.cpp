#include <iostream>
#include <iomanip>
#include <stdexcept>

class Date {
public:
    // 构造函数，初始化日期并验证合法性
    Date(int year, int month, int day) : year(year), month(month), day(day) {
        if (!is_valid_date(year, month, day)) {
            throw std::invalid_argument("Invalid date");
        }
    }

    // 获取年、月、日
    int get_year() const { return year; }
    int get_month() const { return month; }
    int get_day() const { return day; }

    // 计算下一天的Date对象
    Date next_day() const {
        // 计算下一天的日期
        int new_year = year;
        int new_month = month;
        int new_day = day + 1;

        // 处理日期溢出
        if (new_day > days_in_month(new_month, new_year)) {
            new_day = 1;
            new_month++;
            if (new_month > 12) {
                new_month = 1;
                new_year++;
            }
        }

        return Date(new_year, new_month, new_day);
    }

    // 计算当前日期与指定日期之间的差值（以天为单位）
    int difference(const Date& other) const {
        int days1 = to_days_since_epoch();
        int days2 = other.to_days_since_epoch();
        return days1 - days2;
    }

    // 格式化输出日期
    void print() const {
        std::cout << std::setfill('0') << std::setw(4) << year << '-'
                  << std::setw(2) << month << '-'
                  << std::setw(2) << day << std::endl;
    }

private:
    int year, month, day;

    // 判断日期是否合法
    bool is_valid_date(int year, int month, int day) const {
        if (month < 1 || month > 12 || day < 1 || day > days_in_month(month, year)) {
            return false;
        }
        return true;
    }

    // 获取指定月份的天数
    int days_in_month(int month, int year) const {
        static const int days_in_month_non_leap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        static const int days_in_month_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (is_leap_year(year)) {
            return days_in_month_leap[month - 1];
        } else {
            return days_in_month_non_leap[month - 1];
        }
    }

    // 判断是否是闰年
    bool is_leap_year(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 计算从公元元年到当前日期的天数
    int to_days_since_epoch() const {
        int days = 0;
        for (int y = 0; y < year; ++y) {
            days += is_leap_year(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            days += days_in_month(m, year);
        }
        days += day - 1;
        return days;
    }
};

int main() {
    try {
        Date d1(2024, 8, 8);
        d1.print();

        Date d2 = d1.next_day();
        d2.print();

        int diff = d1.difference(d2);
        std::cout << "Difference: " << diff << " days" << std::endl;

        Date d3(2023, 8, 8);
        int diff2 = d1.difference(d3);
        std::cout << "Difference with 2023-08-08: " << diff2 << " days" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
