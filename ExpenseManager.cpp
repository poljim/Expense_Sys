#include "ExpenseManager.h"
#include "Expense.cpp"
#include <iostream>
#include <vector>

using namespace std;

// used vectors since time complexity for accessing elements with index in is 1, whereas in lists it's n.
vector<Expense> ExpenseVector;

void addExpense(int id, string category, double amount, string date) {
    //does the user quit if it presses 0?

    // std::string, std::chrono
    //int size = ExpenseVector.size();
    int size;
    cout<<"Enter how many expenses will you add: "; //??? how to do this more properly, return menu everytime?
    cin >> size;
    for (int i=0; i<size; i++) {
        Expense tempExp;
        cout << "enter category for expense"<< i+1 <<": ";
        cin>>category;
        cout << "enter amount for expense"<< i+1 <<": ";
        cin>>amount;
        cout << "enter date for expense"<< i+1 <<": ";
        cin>>date;


        Expense Expense = new Expense expense1, expense2, expense3;
        expense1.addExpense(2,"some category", 100, chrono::year{2010}/10/01); //std::chrono
    }
}