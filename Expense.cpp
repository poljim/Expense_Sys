#include "Expense.h"
#include <stdexcept>

using namespace std;

Expense::Expense(int id, const string& name, Category category, double amount, const string& date) {
    // For string we used const T& because it avoids unnecessary copying.
    if (name.empty()) {
        throw invalid_argument("Name cannot be empty.\n");
    }
    if (amount < 0) {
        throw invalid_argument("Amount cannot be less than 0.\n");
    }
    if (date.size() != 10 || date[4]!= '-' || date[7]!='-') {
        throw invalid_argument("Date must be in YYYY-MM-DD format.\n");
    }
    if (date[5]>2 || date[5]==1 && date[6]>2 || date[8]>3 || date[8]==3 && date[9]>1 || date[1]>0 || date[0]>2 || date[0]<1 || date[2]>2 ||date[2]==2 && date[3]>6) {
        throw invalid_argument("Date must be in YYYY-MM-DD format.\n");
    }
    // if (category.empty()) {
    //     throw invalid_argument("Category cannot be empty.\n");
    // }

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

// The reason they are all chosen constants is getters should not modify values
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
    id = newID;
}


