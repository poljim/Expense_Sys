#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <vector>
#include <string>

using namespace std;

int readIntInRange(const string& prompt, int min, int max, const string& notANumber);
double readDouble(const string& prompt, const string& notANumber);
int readInt(const string& prompt, const string& notANumber);


class ExpenseManager {
    // used vectors since time complexity for accessing elements by index is 1, whereas for lists it's n.
    // in classes, members are private as default
    vector<Expense> ExpenseVector;
    int nextId = 1;

public:
    void addExpense(const string& name, Category category, double amount, const string& date);
    void removeExpense(int targetId);

    void sortByAmount();
    void sortByCategory();
    void sortByDate();
    void sortByName();
    void sortById();

    double calculateTotal();
    vector<Expense> filterExpenses(Category targetCategory);

    void printExpenses();

    bool isEmpty() const;

    double calculateTotal() const;

    // below helper functions for testing
    int getExpenseCount() const;
    const Expense& getExpenseAt(int index) const;

};

#endif //EXPENSE_SYS_EXPENSE_MANAGER_H
