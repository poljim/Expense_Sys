#ifndef EXPENSE_SYS_EXPENSE_H
#define EXPENSE_SYS_EXPENSE_H

#include <string>
#include <chrono>
using namespace std;

// Expense categories
enum class Category {
    Food =1,
    Transport,
    Education,
    Health,
    Hobby,
    Other,
};

string categoryToString(Category category); // for printing\comparing purposes

class Expense {
    int id;
    Category category;
    string name, date;
    double amount;

public:
    Expense(int id, const string& name, Category category, double amount, const string& date);
    // we use '&' for strings because that way it is less costly to copy
    int getID() const;
    string getName() const;
    Category getCategory() const;
    double getAmount() const;
    string getDate() const;

    //setters for updating values
    void setID(int newID);


};

#endif //EXPENSE_SYS_EXPENSE_H