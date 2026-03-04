#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <list>

class ExpenseManager {

};

void addExpense(int id, std::string category, double amount, std::chrono::year_month_day date) {
    //add instance of a class to a list?

    std::list<Expense> expense = new Expense(id, std::move(category), std::move(amount), date);


    // we can use linked lists and each element becomes an object.
    // to go through the elements we need nested loops, one for object attributes, and one for list elements
    // not sure if it is good as other options since the complexity becomes n^2. but at least we are familiar with it

    //though correct implementation of this would be with vectors

}


#endif //EXPENSE_SYS_EXPENSE_MANAGER_H