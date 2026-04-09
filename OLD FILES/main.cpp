#include <iostream>
#include "Expense.h"
#include <chrono>
#include "ExpenseManager.h"
#include <list>

using namespace std;

int main() {
    ExpenseManager expenseManager;
    bool condition = true;

    // Print the menu
    while (condition){
        cout<<   "1. Add expense\n"
            <<   "2. Remove expense\n"
            <<   "3. Filter expenses \n"
            <<   "4. Calculate total expense \n"
            <<   "5. Sort expenses\n"
            <<   "0. Exit.\n" // We can add extra functions later
            <<   "Welcome to Expense Manager! Please choose choose the action you want to take: ";

        int option;
        cin>> option;
        switch (option) {

            case 1:
                // We are creating the objects here
                expenseManager.addExpense();
                break;
            case 2:
                removeExpense();
                break;
            case 3:
                filterExpense();
            case 4:
                calExpense();
                break;
            case 5:
                // how does the user want to sort the list? by save time, category or date?
                sortExpense();
                break;
            case 0:
                condition = false;
            default:
                cout << "pls enter a number between 0-5";

        }
    }
    return 0;
}