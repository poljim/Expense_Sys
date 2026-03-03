//
// Created by chö on 3.03.2026.
//

#ifndef EXPENSE_SYS_EXPENSE_H
#define EXPENSE_SYS_EXPENSE_H


#include <string>
#include <chrono>


class Expense {
private:
    //int id;
    std::string category;
    double amount;
    std::chrono::year_month_day date;

public:
    Expense(std::string category, double amount, std::chrono::year_month_day date);
    //Expense(int id, const std::string& desc,
    //const std::string& cat, double amt);
    //int getID() const;
    std::string getCategory() const;
    double getAmount() const;
    std::chrono::year_month_day getDate() const;

    //setters for updating values
    void setID(int newID);

};

#endif //EXPENSE_SYS_EXPENSE_H