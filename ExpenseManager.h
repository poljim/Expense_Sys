#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <list>

class ExpenseManager {
    std::list<Expense> Expenses;

public:

    // tüm özellikleri aynı olan iki harcamaya izin olacak mı? (kabul etmemek daha kolay çünkü
    // aynı harcamalar olduğunda remove expense'te hangisini silmek istediğini nasıl bileceğiz?
    // id ile ulaşmak kolay olabilir ama kullanıcı id mi seçecek, id sıra mı olacak?)

    void addExpense(int id, std::string category, double amount, std::chrono::year_month_day date) {
        Expenses.emplace_back(id, category, amount, date);
        // emplace_back "Constructs a new object directly at the end of a container."

        // we can use linked lists and each element becomes an object.
        // to go through the elements we need nested loops, one for object attributes, and one for list elements
        // not sure if it is good as other options since the complexity becomes n^2. but at least we are familiar with it

        // though correct implementation of this would be with vectors

    }
};

#endif //EXPENSE_SYS_EXPENSE_MANAGER_H