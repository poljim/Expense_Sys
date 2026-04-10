#include <iostream>
#include <chrono>
#include "Expense.h"
#include "ExpenseManager.h"

using namespace std;

int main() {
    ExpenseManager expenseManager;
    bool condition = true;

    // Print the menu
    while (condition){
        cout << "\n1. View expenses\n"
             << "2. Add expense\n"
             << "3. Remove expense\n"
             << "4. Filter expenses\n"
             << "5. Calculate total expense\n"
             << "6. Sort expenses\n"
             << "0. Exit.\n"
             << "Welcome to Expense Manager! Please choose the action you want to take: ";

        int option;     // for the main menu
        int sortOption; // for the sort function's menu

        cin>> option;
        switch (option) {
            case 1: {
                expenseManager.printExpenses();
            }
            case 2: {
                string name, category, date;
                double amount;

                int size; // number of loops
                cout<<"Enter the number of expenses you want to add: "; //??? how to do this more properly, return menu everytime?

                //int size = ExpenseVector.size();
                cin >> size;
                for (int i=0; i<size; i++) {
                    cout << "Enter a name for the expense: ";
                    cin>>name;
                    cout << "Enter category: ";
                    cin>>category;
                    cout << "Enter amount (double): ";
                    cin>>amount;
                    cout << "Enter date (YYYY-MM-DD): ";
                    cin>>date;

                    // We are creating the objects here
                    expenseManager.addExpense(name, category, amount, date);
                    cout<<"Expense"<< i+1  <<"has been added successfully!\n"<<endl;
                }
                expenseManager.printExpenses();
            }break;

            case 3: {
            int idToRemove;
            cout << "Enter the ID of the expense you want to remove: \n\n";
            cin >> idToRemove;
            expenseManager.removeExpense(idToRemove);
            }break;

            // case 4:
            //     filterExpense();


            // case 5:
            //     calcExpense();
            //     break;

            case 6:
                // how does the user want to sort the list? by name, amount, category or date?
                cout<<   "\n1. Sort by category \n"
                     <<   "2. By amount\n"
                     <<   "3. By name\n"
                     <<   "4. By date\n"
                     <<   "How do you wish to sort the list: ";
                cin >> sortOption;
                switch (sortOption) {
                    case 1: {
                        expenseManager.sortByCategory();
                        cout<<"Sorted by Category.\n";
                    }break;
                    case 2: {
                        expenseManager.sortByAmount();
                        cout<<"Sorted by Amount.\n";
                    }break;
                    case 3: {
                        expenseManager.sortByName();
                        cout<<"Sorted by Name.\n";
                    }break;
                    case 4: {
                        expenseManager.sortByDate();
                        cout<<"Sorted by Date.\n";
                    }break;
                    default: {
                        cout<<"To sort, enter a number between 0-4.\n";
                    }break;
                }
                expenseManager.printExpenses();
                break;
            
            case 0: {
                condition = false;
                break;
            }
            default:
                cout << "Please enter a number between 0-5\n";
        
        }
    }
};
