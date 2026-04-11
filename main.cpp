#include <iostream>
#include <chrono>
#include "Expense.h"
#include "ExpenseManager.h"
#include <limits>
#include <string>

using namespace std;

int main() {
    ExpenseManager expenseManager;
    bool condition = true;

    // Print the main menu
    while (condition){
        cout <<"\n\n======== Welcome to Expense Manager! ========\n"
             << "[1] View expenses\n"
             << "[2] Add expense\n"
             << "[3] Remove expense\n"
             << "[4] Filter expenses\n"
             << "[5] Calculate total expense\n"
             << "[6] Sort expenses\n"
             << "[0] Exit.\n";
        int option = readIntInRange("   > Select an option: ", 0, 6);
        switch (option) {
            case 1: {
                expenseManager.printExpenses();
            } break;

            case 2: {
                string name, date;
                Category category;
                double amount;

                int size; // number of loops
                cout<<"Enter the number of expenses you want to add: "; //??? how to do this more properly, return menu everytime?
                cin >> size;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for (int i=0; i<size; i++) {
                    cout << "Enter a name for expense "<<i+1 << ": ";
                    getline(cin, name);
                    // cin>>name; <<-- we removed this because when user entered a name with spaces, cin was ignoring the later part

                    cout << "1. Food\n"
                         << "2. Transport\n"
                         << "3. Education\n"
                         << "4. Health\n"
                         << "5. Hobby\n"
                         << "6. Other\n";
                    int categoryChoice = readIntInRange("> Choose category: ", 1, 6);
                    Category category = static_cast<Category>(categoryChoice);

                    cout << "Enter amount (double): ";
                    cin>>amount;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter date (YYYY-MM-DD): ";
                    getline(cin, date);
                    try {
                        // We are creating the objects here
                        expenseManager.addExpense(name, category, amount, date);
                        cout<<"Expense "<< i+1  <<" has been added successfully!\n\n"<<endl;
                    }catch(const invalid_argument& error) {
                        cout<<"Error: "<<error.what()<<'\n'; // '\n' instead of "\n" because new line is a character
                        i--;
                        continue;
                    }
                }
                expenseManager.printExpenses();
            }break;

            case 3: {
                if (expenseManager.isEmpty()) {
                    cout << "No expenses found.\n";
                    break;
                }

                int idToRemove;
                cout << "Enter the ID of the expense you want to remove: ";
                cin >> idToRemove;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Invalid input. Please enter an integer ID.\n";
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (idToRemove<=0) {
                    cout<<"ID must be a positive integer.\n";
                    break;
                }

                expenseManager.removeExpense(idToRemove);
            }break;

                // case 4:
                //     filterExpense();


                // case 5:
                //     calcExpense();
                //     break;

            case 6: {
                // return to the main menu if the vector is empty.
                if (expenseManager.isEmpty()) {
                    cout << "No expenses found.\n";
                    break;
                }

                // how does the user want to sort the list? by name, amount, category or date?
                cout<<   "\n1. Sort by name \n"
                     <<   "2. By category\n"
                     <<   "3. By amount\n"
                     <<   "4. By date\n"
                     <<   "5. Return back to main menu.\n";

                int sortOption = readIntInRange("Choose how you want to sort expenses: ", 1, 5);
                switch (sortOption) {
                    case 1: {
                        expenseManager.sortByName();
                        cout<<"Sorted by Name.\n";
                    }break;
                    case 2: {
                        expenseManager.sortByCategory();
                        cout<<"Sorted by Category.\n";
                    }break;
                    case 3: {
                        expenseManager.sortByAmount();
                        cout<<"Sorted by Amount.\n";
                    }break;
                    case 4: {
                        expenseManager.sortByDate();
                        cout<<"Sorted by Date.\n";
                    }break;
                    case 5:
                        break;
                    default: {
                        cout<<"To sort, choose a number between 1-4.\n";
                    }break;
                }
                expenseManager.printExpenses();
            }break;

            case 0: {
                condition = false;
                break;
            }
            default:
                cout << "Please enter a number between 0-6\n";

        }
    }
};
