#include "Date.h"
#include <sstream>

using namespace std;

Date::Date() {
    setYear(0);
    setMonth(0);
    setDay(0);
}

Date::Date(unsigned int y, unsigned int m, unsigned int d) {
    year = y;
    month = m;
    day = d;
}

Date::Date(string dateStr) {
    sscanf_s(dateStr.c_str(), "%d.%d.%d", &year, &month, &day);
}

Date::Date(const Date& other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

bool Date::isVisok() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isBefore(const Date& other) {
    if (year < other.year)
        return true;
    else if (year == other.year && month < other.month)
        return true;
    else if (year == other.year && month == other.month && day < other.day)
        return true;
    return false;
}

bool Date::isAfter(const Date& other) {
    if (year > other.year)
        return true;
    else if (year == other.year && month > other.month)
        return true;
    else if (year == other.year && month == other.month && day > other.day)
        return true;
    return false;
}

bool Date::isNow(const Date& other) {
    return year == other.year && month == other.month && day == other.day;
}

Date::operator string () const {
    stringstream ss;
    ss << year << "." << month << "." << day << endl;
    return ss.str();
}

Date Date::operator=(Date t) {
    year = t.year;
    month = t.month;
    day = t.day;
    return *this;
}

istream& operator >> (istream& in, Date& r) {
    std::cout << "Enter year, month and day: ";
    in >> r.year >> r.month >> r.day;
    return in;
}

ostream& operator << (ostream& out, const Date& r) {
    out << string(r);
    return out;
}


Date& Date::operator ++() {
    year++;
    return *this;
}

Date& Date::operator --() {
    year--;
    return *this;
}

Date Date::operator ++(int) {
    Date n(*this);
    month++;
    return n;
}

Date Date::operator --(int) {
    Date n(*this);
    month--;
    return n;
}