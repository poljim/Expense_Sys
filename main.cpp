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
        cout<<   "\n1. Add expense\n"
            <<   "2. Remove expense\n"
            <<   "3. Filter expenses \n"
            <<   "4. Calculate total expense \n"
            <<   "5. Sort expenses\n"
            <<   "0. Exit.\n" // We can add extra functions later
            <<   "Welcome to Expense Manager! Please choose choose the action you want to take: ";

        int option;
        cin>> option;
        switch (option) {
            case 1: {
                int id;
                string category, date;
                double amount;

                int size; // how many expenses will be entered
                cout<<"Enter the number of expenses you want to add: "; //??? how to do this more properly, return menu everytime?

                //int size = ExpenseVector.size();
                cin >> size;
                for (int i=0; i<size; i++) {
                    id = i+1;
                    cout << "enter category: "<< i+1 <<": ";
                    cin>>category;
                    cout << "enter amount: "<< i+1 <<": ";
                    cin>>amount;
                    cout << "enter expense date: "<< i+1 <<": ";
                    cin>>date;

                    // We are creating the objects here
                    expenseManager.addExpense(id, category, amount, date);
                    //expense{i}.addExpense(2,"some category", 100, chrono::year{2010}/10/01); //std::chrono
                }
            }break;

            
                case 2: {
                int idToRemove;
                cout << "Enter the ID of the expense you want to remove: \n\n";
                cin >> idToRemove;

                expenseManager.removeExpense(idToRemove);
                
            }break;

                // case 3:
                //     filterExpense();
                // case 4:
                //     calExpense();
                //     break;
                // case 5:
                //     // how does the user want to sort the list? by save time, category or date?
                //     sortExpense();
                //     break;
            
            case 0: {
                condition = false;
                break;
            }
            default:
                cout << "Please enter a number between 0-5\n";
        
        }
    }
};
