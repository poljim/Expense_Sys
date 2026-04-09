#include "Expense.h"
using namespace std;

Expense::Expense(int id, const string& category, double amount, string& date) {
    // For string, vector, large objects, we usually prefer const T& because it avoids unnecessary copying.

    this->id = id;
    this->category = category;
    this->amount = amount;
    this->date = date;
    // can use this one too, (): id(id), category(category), amount(amount), date(date)
}

// The reason they are all constants is getters should not modify values
int Expense::getID() const { return this->id; }

string Expense::getCategory() const {return this->category; }

double Expense::getAmount() const { return this->amount; }

string Expense::getDate() const { return this->date; }

// Setter for updating values
void Expense::setID(int newID){id = newID;}
