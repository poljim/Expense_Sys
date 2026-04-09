#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;

class ExpenseManager {
    vector<Expense> Expenses;

public:
    // tüm özellikleri aynı olan iki harcamaya izin olacak mı? (kabul etmemek daha kolay çünkü
    // aynı harcamalar olduğunda remove expense'te hangisini silmek istediğini nasıl bileceğiz?
    // id ile ulaşmak kolay olabilir ama kullanıcı id mi seçecek, id sıra mı olacak?)

    void addExpense(int id, string category, double amount, string date) {
        Expenses.emplace_back(id, category, amount, date);
        // emplace_back "Constructs a new object directly at the end of a container."

        // though correct implementation of this would be with vectors

    }
};

#endif //EXPENSE_SYS_EXPENSE_MANAGER_H