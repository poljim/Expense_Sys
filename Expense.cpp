#include "Expense.h"
using namespace std;

Expense::Expense(int id, const string category, double amount, string date) {
    this->id = id;
    this->category = category;
    this->amount = amount;
    this->date = date;
    // can use this instead, after()
    //: id(id), category(category), amount(amount), date(date)
}

//int Expense::getID() {return this->id = id;} // böyle niye olmuyo? (constu çıkardıktan sonra)

// getter should not modify the value, that's why all of them are constant
int Expense::getID() const {}

std::string Expense::getCategory() const {return category;}

double Expense::getAmount() const { return  amount;}

string Expense::getDate() const { return date;}

//setters for updating values
void Expense::setID(int newID){id = newID;}
