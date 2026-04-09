#include "ExpenseManager.h"
#include "Expense.h" //include only header files, not cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExpenseManager {
public:
    // used vectors since time complexity for accessing elements by index is 1, whereas for lists it's n.
    vector<Expense> ExpenseVector;

    void addExpense(int id, string category, double amount, string date) {
        //does the user quit if it presses 0?

        // std::string, std::chrono
        //int size = ExpenseVector.size();
        int size;
        cout<<"Enter how many expenses you will add: "; //??? how to do this more properly, return menu everytime?
        cin >> size;
        for (int i=0; i<size; i++) {
            Expense tempExpense;
            id = i+1;
            cout << "enter category for expense"<< i+1 <<": ";
            cin>>category;
            cout << "enter amount for expense"<< i+1 <<": ";
            cin>>amount;
            cout << "enter date for expense"<< i+1 <<": ";
            cin>>date;

            expense{i}.addExpense(2,"some category", 100, chrono::year{2010}/10/01); //std::chrono
        }
    }
};