#include <iostream>
#include <chrono>
#include "Expense.h"
#include "ExpenseManager.h"
#include <string>

#include <stdexcept>
#include <sstream>

using namespace std;

int main() {
    ExpenseManager expenseManager;
    bool condition = true;

    // Print the main menu
    while (condition){

        // Print the menu and then get the user input safely with custom function readIntIn() function
        // Below it takes 2 parameters:
        //      1. message to be printed,
        //      2. error message if user input has some problem like being a string
        int option = readInt(
        "\n\n======== Welcome to Expense Manager! ========\n"
            "[1] View expenses\n"
            "[2] Add expense\n"
            "[3] Remove expense\n"
            "[4] Filter expenses\n"
            "[5] Calculate total expense\n"
            "[6] Sort expenses\n"
            "[0] Exit.\n"
            "   > Select an option: ",
            "Invalid input. Please enter an integer.\n");

        switch (option) {
            // View Expenses
            case 1: {
                expenseManager.printExpenses();
            } break;

            // Add Expense
            case 2: {
                string name, date;
                Category category;

                // Here, vector size is decided by user input (we are storing expense objects in a vector)
                int size = readInt("Enter the number of expenses you want to add: ", "Invalid input. Please enter an integer.\n");

                for (int i=0; i<size; i++) {
                    cout << "Enter a name for expense "<<i+1 << ": ";
                    getline(cin, name);
                    // cin>>name; <<-- We removed this because when user entered a name with spaces, cin was ignoring the later part

                    // Print the menu and then get the user input, with validation that the input is an integer in range 1-6
                    int categoryChoice = readIntInRange(
                    "1. Food\n"
                    "2. Transport\n"
                    "3. Education\n"
                    "4. Health\n"
                    "5. Hobby\n"
                    "6. Other\n"
                    "> Choose category: ",
                    1,
                    6,
                    "Invalid input. Please enter an integer.\n"
                    );
                    Category category = static_cast<Category>(categoryChoice);

                    // Take amount input
                    double amount = readDouble("Enter amount (double): ", "Invalid input. Please enter an integer.\n");

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

            // Remove expense
            case 3: {
                // Check if there is any expense object created
                if (expenseManager.isEmpty()) {
                    cout << "No expenses found.\n";
                    break;
                }
                int idToRemove = readInt("Enter ID to remove: ", "Invalid input. Please enter a number.");
                expenseManager.removeExpense(idToRemove);
            }break;


            // Filter Expenses by Category
            case 4: {
                cout << "1. Food\n"
                         << "2. Transport\n"
                         << "3. Education\n"
                         << "4. Health\n"
                         << "5. Hobby\n"
                         << "6. Other\n";
                int categoryChoice = readIntInRange("> Choose category to filter with: ", 1, 6,"error. enter an integer.");
                Category category = static_cast<Category>(categoryChoice);
                vector<Expense> filteredVector = expenseManager.filterExpenses(category);

                for (const auto &e : filteredVector) {
                    cout << e.getName() << " | "
                         << e.getAmount() << " | "
                         << e.getDate() << "\n";
                }
            } break;

            // Calculate Total
            case 5: {
                if (expenseManager.isEmpty()) {
                    cout << "No expenses found.\n";
                    break;
                }
                double total;
                total = expenseManager.calculateTotal();
            }break;

            // Sort Expenses
            case 6: {
                // Check if there is any expense object created
                if (expenseManager.isEmpty()) {
                    cout << "No expenses found.\n";
                    break;
                }

                // How does the user want to sort the list? by name, amount, category, ID or date?
                // ReadIntIn() function below takes 2 parameters:
                //      1. message to be printed,
                //      2. error message if user input has some problem like being a string
                int sortOption = readInt(
                "\n1. Sort by name \n"
                "2. By category\n"
                "3. By amount\n"
                "4. By date\n"
                "5. By ID\n"
                "6. Return back to main menu.\n"
                "Choose how you want to sort expenses: ",
                "Invalid input. Please enter an integer ID.\n");

                switch (sortOption){
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
                    case 5:{
                        expenseManager.sortById();
                        cout<<"Sorted by ID.\n";
                    }break;
                    case 6:
                        break;
                    default: {
                        // print the message below and return main menu
                        cout<<"To sort, choose a number between 1-4.\n";
                    }break;
                }
                expenseManager.printExpenses();
            }break;

            // Quit Program (main menu option 0)
            case 0: {
                condition = false;
                break;
            }

            default:
                cout << "Please enter a number between 0-6\n";

        }
    }
};
