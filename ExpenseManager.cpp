#include "ExpenseManager.h"
#include "Expense.h" //include only header files, not cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    sort(ExpenseVector.begin(), ExpenseVector.end(),
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

			// we are using our string caster method to be able to compare categories alphabetically
			// (because in the enum list categories are not in alphabetical order)
            return categoryToString(a.getCategory()) < categoryToString(b.getCategory());
        });
}


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





