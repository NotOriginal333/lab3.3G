#include "Goods.h"

#include <iostream>

Goods::Goods() {
    name = "";
    cost = 0;
    amount = 0;
    nomer = 0;
}

Goods::Goods(Goods& t) {
    dateNad = t.dateNad;
    dateOform = t.dateOform;
    name = t.name;
    cost = t.cost;
    amount = t.amount;
    nomer = t.nomer;
}

Goods::Goods(Date nad, Date oform, std::string n, int c, int a, int nom) {
    dateNad = nad;
    dateOform = oform;
    name = n;
    cost = c;
    amount = a;
    nomer = nom;
}

void Goods::setDateNad(const Date& t) {
    dateNad.setYear(t.getYear());
    dateNad.setMonth(t.getMonth());
    dateNad.setDay(t.getDay());
}

void Goods::setDateOform(const Date& t) {
    dateOform.setYear(t.getYear());
    dateOform.setMonth(t.getMonth());
    dateOform.setDay(t.getDay());
}

void Goods::setName(const std::string& n) {
    name = n;
}

void Goods::setCost(int c) {
    cost = c;
}

void Goods::setAmount(int a) {
    amount = a;
}

void Goods::setNomer(int nom) {
    nomer = nom;
}

int Goods::calc() {
    return cost * amount;
}

Goods::operator string () const {
    return "Name: " + name + ", Cost: " + std::to_string(cost) + ", Amount: " + std::to_string(amount) +
        ", Nomer: " + std::to_string(nomer);
}

Goods Goods::operator=(Goods t) {
    dateNad = t.dateNad;
    dateOform = t.dateOform;
    name = t.name;
    cost = t.cost;
    amount = t.amount;
    nomer = t.nomer;
    return *this;
}

istream& operator >> (istream& in, Goods& r) {
    std::cout << "Enter name: ";
    in >> r.name;
    std::cout << "Enter cost: ";
    in >> r.cost;
    std::cout << "Enter amount: ";
    in >> r.amount;
    std::cout << "Enter nomer: ";
    in >> r.nomer;
    std::cout << "Enter dateNad: ";
    in >> r.dateNad;
    std::cout << "Enter dateOform: ";
    in >> r.dateOform;
    return in;
}

ostream& operator << (ostream& out, const Goods& r) {
    out << string(r);
    return out;
}

Goods& Goods::operator ++() {
    cost++;
    return *this;
}

Goods& Goods::operator --() {
    cost--;
    return *this;
}

Goods Goods::operator ++(int) {
    Goods n(*this);
    amount++;
    return n;
}

Goods Goods::operator --(int) {
    Goods n(*this);
    amount--;
    return n;
}