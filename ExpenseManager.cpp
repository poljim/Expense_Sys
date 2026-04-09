#include "ExpenseManager.h"
#include "Expense.h" //include only header files, not cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

    vector<Expense> ExpenseVector;

    void addExpense(int id, const string& category, double amount, const string& date) {
        //does the user quit if it presses 0?
		ExpenseVector.push_back(Expense(id, category, amount, date));
    }










