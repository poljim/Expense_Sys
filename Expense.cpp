#include "Expense.h"
#include <stdexcept>

using namespace std;

Expense::Expense(int id, const string& name, Category category, double amount, const string& date) {
    // For strings, we used const and & because that way we avoid unnecessary copying.

    if (name.empty()) {
        throw invalid_argument("Name cannot be empty.\n");
    }
    if (amount < 0) {
        throw invalid_argument("Amount cannot be less than 0.\n");
    }
    if (date.size() != 10 || date[4]!= '-' || date[7]!='-') {
        throw invalid_argument("Date must be in YYYY-MM-DD format.\n");
    }
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    // if (date[0]>2 || date[0]<1 || date[1]>0 || month < 1 || month > 12 || day < 1 || day > 31) {
    //     throw invalid_argument("Date must be in YYYY-MM-DD format.\n");
    // } //this is not valid because it compares string with numbers. (since we accept the date from the user input as a string)
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw invalid_argument("Date must be in YYYY-MM-DD format.\n");
    }

    this->id = id;
    this->name = name;
    this->category = category;
    this->amount = amount;
    this->date = date;

}

string categoryToString(Category category) {
    switch (category) {
        case Category::Food: return "Food";
        case Category::Transport: return "Transport";
        case Category::Education: return "Education";
        case Category::Health: return "Health";
        case Category::Hobby: return "Hobby";
        case Category::Other: return "Other";
        default: return "Unknown";
    }
}

// The reason they are all chosen constants is getters not modifying values
int Expense::getID() const {
    return id;
}

string Expense::getName() const {
    return name;
}

Category Expense::getCategory() const {
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
    id = newID; // We use newID to keep track of the object id's accurately, even when add function is called more than 1 time.
    // The use of the variable can be seen in addExpense() function in ExpenseManager.cpp
}


