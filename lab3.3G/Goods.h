#pragma once
#include "Date.h"

using namespace std;

class Goods :
	public Date
{
	Date dateNad;
	Date dateOform;
	string name;
	int cost;
	int amount;
	int nomer;
public:
	Goods();
	Goods(Date, Date, string, int, int, int);
	Goods(Goods&);
	~Goods() { };

	Date getDateNad() const { return dateNad; };
	Date getDateOform() const { return dateOform; };
	string getName() const { return name; };
	int getCost() const { return cost; };
	int getAmount() const { return amount; };
	int getNomer() const { return nomer; };

	void setDateNad(const Date&);
	void setDateOform(const Date&);
	void setName(const string&);
	void setCost(int);
	void setAmount(int);
	void setNomer(int);

	int calc();

	Goods operator=(Goods t);

	friend istream& operator >> (istream& in, Goods& r);
	friend ostream& operator << (ostream& out, const Goods& r);

	operator string () const;

	Goods& operator ++();
	Goods& operator --();
	Goods operator ++(int);
	Goods operator --(int);
};
