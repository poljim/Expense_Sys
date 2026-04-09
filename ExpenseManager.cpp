#include "ExpenseManager.h"
#include "Expense.h" //include only header files, not cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

    vector<Expense> ExpenseVector;
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
}

    void addExpense(int id, const string& category, double amount, const string& date) {
        //does the user quit if it presses 0?
		ExpenseVector.push_back(Expense(id, category, amount, date));
    }










