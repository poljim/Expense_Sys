#include <iostream>
#include "Expense.h"
#include "ExpenseManager.h"

int main() {
    std::cout << "Expense System'e Hos Geldin!\n";

    // Önce Manager nesnemizi yaratıyoruz
    ExpenseManager manager;

    // C++20'ye uygun tarih oluşturma (Yıl, Ay, Gün)
    std::chrono::year_month_day myDate = std::chrono::year(2026) / 3 / 15;

    // Manager üzerinden fonksiyonumuzu çağırarak harcamayı sisteme ekliyoruz
    manager.addExpense(1, "Market", 450.50, myDate);

    return 0;
}