#include <iostream>
#include "Expense.h"
#include <chrono>
#include "ExpenseManager.h"
#include "ExpenseManager.cpp"
#include <list>
#include "Expense.h"

int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    Expense new_expense;
    new_expense.addExpense(2,"some category", 100, std::chrono::year{2010}/10/01);

    return 0;
}