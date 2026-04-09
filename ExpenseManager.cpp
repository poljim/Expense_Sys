#include "ExpenseManager.h"
#include <iostream>

void ExpenseManager::addExpense(int id, std::string category, double amount, std::chrono::year_month_day date) {
    // Yeni bir harcama oluşturup listeye ekliyoruz
    Expense newExp(id, category, amount, date);
    expenses.push_back(newExp);
    std::cout << "Sistem: Harcama basariyla kaydedildi.\n";
}

void ExpenseManager::listAllExpenses() const {
    std::cout << "--- Kayitli Harcamalar ---\n";
    for (const auto& e : expenses) {
        std::cout << "ID: " << e.getID() << " | Kategori: " << e.getCategory() 
                  << " | Miktar: " << e.getAmount() << "\n";
    }
}