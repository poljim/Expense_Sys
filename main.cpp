#include <iostream>
#include "Expense.h"
#include <chrono>
#include "ExpenseManager.h"

int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    Expense someInstance(2,"some category", 100, std::chrono::year{2010}/10/01);

    return 0;
}