#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>

class Date {
private:
    int daysSinceEpoch;

    void checkValidDate() const {
        if (daysSinceEpoch < 0) {
            throw std::invalid_argument("Date cannot be before 01.01.1970");
        }
    }

    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static int daysInMonth(int year, int month) {
        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear(year) && month == 2) {
            return 29;
        }
        return daysInMonth[month - 1];
    }


public:
    // ������������
    Date() : daysSinceEpoch(0) {}
    Date(int days) : daysSinceEpoch(days) {
        checkValidDate();
    }

    // ����� ������ �� �����
   void print() const {
        int year = 1970;
        int days = daysSinceEpoch;
        while (days >= 365) {
            if (isLeapYear(year)) {
                if (days >= 366) {
                    days -= 366;
                    year++;
                }
                else {
                    break;
                }
            }
            else {
                days -= 365;
                year++;
            }
        }
        int month = 1;
        while (days >= daysInMonth(year, month)) {
            days -= daysInMonth(year, month);
            month++;
        }
        std::cout << year << "-" << month << "-" << (days + 1) << std::endl;
    }

    // �������� �������������� ���������
    Date operator+(int days) const {
        return Date(daysSinceEpoch + days);
    }
    Date operator-(int days) const {
        int newDays = daysSinceEpoch - days;
        checkValidDate();
        return Date(newDays);
    }

    // ���������� � �����������
    Date& operator+=(int days) {
        daysSinceEpoch += days;
        return *this;
    }
    Date& operator-=(int days) {
        daysSinceEpoch -= days;
        checkValidDate();
        return *this;
    }

    // ������� ���������
    Date& operator++() {
        ++daysSinceEpoch;
        return *this;
    }
    Date operator++(int) {
        Date temp = *this;
        ++daysSinceEpoch;
        return temp;
    }
    Date& operator--() {
        --daysSinceEpoch;
        checkValidDate();
        return *this;
    }
    Date operator--(int) {
        Date temp = *this;
        --daysSinceEpoch;
        checkValidDate();
        return temp;
    }

    // ���������� ���������
    bool operator<(const Date& other) const {
        return daysSinceEpoch < other.daysSinceEpoch;
    }
    bool operator>(const Date& other) const {
        return daysSinceEpoch > other.daysSinceEpoch;
    }
    bool operator==(const Date& other) const {
        return daysSinceEpoch == other.daysSinceEpoch;
    }
    bool operator!=(const Date& other) const {
        return daysSinceEpoch != other.daysSinceEpoch;
    }

    // ��������� �������������� ����
    explicit operator int() const {
        return daysSinceEpoch;
    }
};

#endif 
