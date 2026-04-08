#include <iostream>
#include "Expense.h"
#include <chrono>
#include "ExpenseManager.h"
#include <list>

using namespace std;

int main() {
    // print the menu
    bool condition = true;
    while (condition){
        cout<<   "1. Add expense\n"
            <<   "2. Remove expense\n"
            <<   "3. Filter expenses \n"
            <<   "4. Calculate total expense \n"
            <<   "5. Sort expenses\n"
            <<   "0. Exit.\n" //we can add extra functions later
            <<   "Welcome to Expense Manager! Please choose choose the action you want to take: ";

        int option;
        cin>> option;
        switch (option) {

            case 1:
                // we are creating the objects here
                addEx();
                break;
            case 2:
                removeEx();
                break;
            case 3:
                filterEx();
            case 4:
                calEx();
                break;
            case 5:
                // how does the user want to sort the list?
                sortEx();
                break;
            case 0:
                condition = false;
            default:
                cout << "pls enter a number between 0-5";

        }
    }

    // expense objects should be collected into a list or a vector
    Expense Expense = new Expense expense1, expense2, expense3;
    expense1.addExpense(2,"some category", 100, chrono::year{2010}/10/01); //std::chrono

    return 0;
}