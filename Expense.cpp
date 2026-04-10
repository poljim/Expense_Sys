#include "Expense.h"
using namespace std;

Expense::Expense(int id, const string& name, const string& category, double amount, const string& date) {
    // For string, vector, large objects, we usually prefer const T& because it avoids unnecessary copying.
    this->id = id;
    this->name = name;
    this->category = category;
    this->amount = amount;
    this->date = date;
    // can use this too> (): id(id), category(category), amount(amount), date(date)

}

// The reason they are all constants is getters should not modify values
int Expense::getID() const {
    return id;
}

string Expense::getName() const {
    return name;
}

string Expense::getCategory() const {
    return category;
}

double Expense::getAmount() const {
    return amount;
}

string Expense::getDate() const {
    return date;
}
// Setter for updating values
void Expense::setID(int newID) {
    id = newID;
}
