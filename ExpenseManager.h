#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager {
private:
    // Tüm harcamaları "uzaktan" bu listenin içinde yöneteceğiz
    std::vector<Expense> expenses; 

public:
    // Dışarıdan çağrılacak "Remote" fonksiyonlar
    void addExpense(int id, std::string category, double amount, std::chrono::year_month_day date);
    void listAllExpenses() const;
};

#endif