#ifndef EXPENSE_SYS_EXPENSE_H
#define EXPENSE_SYS_EXPENSE_H

#include <string>
#include <chrono>
using namespace std;

class Expense {
    int id;
    string category, name, date;
    double amount;

public:
    Expense(int id, const string& name, const string& category, double amount, const string& date); // we use & because that way it is less costy to copy strings
    int getID() const;
    string getName() const;
    string getCategory() const;
    double getAmount() const;
    string getDate() const;

    //setters for updating values
    void setID(int newID);

};

#endif //EXPENSE_SYS_EXPENSE_H