#ifndef EXPENSE_SYS_EXPENSE_H
#define EXPENSE_SYS_EXPENSE_H

#include <string>
#include <chrono>
using namespace std;

class Expense {
private:
    int id;
    string category;
    double amount;
    string date;

public:
    Expense(int id, const string& category, double amount, const string& date); // we use & because that way it is less costy to copy strings

    //Expense(int id, const std::string& desc,
    //const std::string& cat, double amt);
    int getID() const;
    string getCategory() const;
    double getAmount() const;
    string getDate() const;

    //setters for updating values
    void setID(int newID);

};

#endif //EXPENSE_SYS_EXPENSE_H