#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class Date :
    public Object
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(string);
	Date(const Date&);
	~Date() { };

	bool isVisok();
	bool isBefore(const Date&);
	bool isAfter(const Date&);
	bool isNow(const Date&);

	void setYear(unsigned int y) { year = y; };
	void setMonth(unsigned int m) { month = m; };
	void setDay(unsigned int d) { day = d; };

	unsigned int getYear() const { return year; };
	unsigned int getMonth() const { return month; };
	unsigned int getDay() const { return day; };

	Date operator=(Date t);

	friend istream& operator >> (istream& in, Date& r);
	friend ostream& operator << (ostream& out, const Date& r);

	operator string () const;

	Date& operator ++();
	Date& operator --();
	Date operator ++(int);
	Date operator --(int);
};

