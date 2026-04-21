#include "ExpenseManager.h"
#include "Expense.h" //include only header files, no cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort()
#include <limits> // for numeric_limits

using namespace std;



// Calculate total expense
double ExpenseManager::calculateTotal() {
    double total = 0.0;

    for (const auto & i : ExpenseVector) {
        total += i.getAmount();
    }
    cout << "\nTotal expense is: " << total << "\n";

    return total;
}

// Filter expenses
vector<Expense> ExpenseManager::filterExpenses(Category targetCategory) {
    vector<Expense> filteredVector;
    for (const auto & i : ExpenseVector) {
        if (i.getCategory()==targetCategory) {
            filteredVector.push_back(i);
        }
    }
    return filteredVector;
}

// Remove Expense
void ExpenseManager::removeExpense(int targetId) {
    // Vektörün içinde dolaşmak için bir iterator (it) kullanıyoruz

    for (auto it = ExpenseVector.begin(); it != ExpenseVector.end(); ++it) {
        // Eğer harcamanın ID'si eşleşirse:
        if (it->getID() == targetId) {
            ExpenseVector.erase(it); // Vektörden sil
            cout << "ID'si " << targetId << " olan harcama basariyla silindi.\n";
            return; // Silme işlemi tamamlandı, fonksiyondan çık
        }
    }
    cout << "ID not found.\n";
}

// Print Expenses
void ExpenseManager::printExpenses(){
    if (ExpenseVector.empty()) {
        cout << "No expenses found.\n";
        return;
    }
    cout << "\nID\tName\tCategory\tAmount\tDate\n";
    cout << "----------------------------------------\n";

    for (const auto& expense : ExpenseVector) {
        cout << expense.getID() << '\t'
            << expense.getName() << '\t'
            << categoryToString(expense.getCategory()) << '\t'
            << expense.getAmount() << '\t'
            << expense.getDate() << '\n';
        cout << "----------------------------------------\n";
    }
}

// Add Expense
void ExpenseManager::addExpense(const string& name, Category category, double amount, const string& date) {
    ExpenseVector.emplace_back(nextId, name, category, amount, date);
    nextId++;
}


// Sort Functions
void ExpenseManager::sortByAmount() {
    sort(ExpenseVector.begin(), ExpenseVector.end(), // We use C's own sort function, which compares elements one by one and updates position if specified condition is true
        [](const Expense& a, const Expense& b) {
            return a.getAmount() < b.getAmount();
        });
}
void ExpenseManager::sortByName() {
    sort(ExpenseVector.begin(), ExpenseVector.end(),
        [](const Expense& a, const Expense& b) {
            return a.getName() < b.getName();
        });
}
void ExpenseManager::sortByDate() {
    sort(ExpenseVector.begin(), ExpenseVector.end(),
        [](const Expense& a, const Expense& b) {
            return a.getDate() < b.getDate();
        });
}
void ExpenseManager::sortByCategory() {
    sort(ExpenseVector.begin(), ExpenseVector.end(),
        [](const Expense& a, const Expense& b) {

			// We are using our string caster method to be able to compare categories alphabetically
			// (Because in the enum, categories are not in alphabetical order)
            return categoryToString(a.getCategory()) < categoryToString(b.getCategory());
        });
}
void ExpenseManager::sortById(){
    sort(ExpenseVector.begin(), ExpenseVector.end(),
        [](const Expense& a, const Expense& b){
            return a.getID() < b.getID();
        });
}

// This function is useful in the main where we have to ask for user input first, to be able to run the target function.
// (Normally this control is in the target function but asking for input would add unnecessary steps for the user.)
bool ExpenseManager::isEmpty() const{
    return ExpenseVector.empty();
}

// Helper functions for testing
int ExpenseManager::getExpenseCount() const {
    return ExpenseVector.size();
}
const Expense &ExpenseManager::getExpenseAt(int index) const {
    return ExpenseVector.at(index);
}


// these two functions are for a tidier main.cpp
double readDouble(const string& prompt, const string& notANumber) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << notANumber;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // check positivity
        if (value<0){
            cout << "\nInvalid input. The number should be positive.";
            continue;
        }

        return value;
    }
}

int readInt(const string& prompt, const string& notANumber) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << notANumber;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // check positivity
        if (value<0){
            cout << "\nInvalid input. The number should be positive.";
            continue;
        }

        return value;
    }
}



// There are many user inputs which requires error prevention in the main function.
// Instead of writing the code below again and again, we created a function to be reused.
// This change helps to avoid redundancy and also makes the project easier to build upon.
// For example, if another menu was to be added later, this function could be used instead of recreating or copying the already existing logic.
int readIntInRange(const string& prompt, int min, int max, const string& notANumber) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << notANumber; // Here we used a variable to print out instead of a certain string, for future development
            // This way the program outputs can be configured and be less repetitive for the user
            // Though it is not the best way to implement this logic
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (value < min || value > max) {
            cout << "\nInvalid input. Please enter a number between "
                 << min << " and " << max << ".\n";
            continue;
        }
        return value;
    }
}