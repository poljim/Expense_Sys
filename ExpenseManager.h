#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;

class ExpenseManager {
    // used vectors since time complexity for accessing elements by index is 1, whereas for lists it's n.
    vector<Expense> ExpenseVector;
    int nextId = 1;

public:
    void addExpense(const string& name, Category category, double amount, const string& date);
    void removeExpense(int targetId);

    void sortByAmount();
    void sortByCategory();
    void sortByDate();
    void sortByName();

    void printExpenses();

    bool isEmpty() const;


    // below helper functions for testing
    int getExpenseCount() const;
    const Expense& getExpenseAt(int index) const;

};

#endif //EXPENSE_SYS_EXPENSE_MANAGER_H