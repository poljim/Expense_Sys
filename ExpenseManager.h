#ifndef EXPENSE_SYS_EXPENSE_MANAGER_H
#define EXPENSE_SYS_EXPENSE_MANAGER_H
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;

class ExpenseManager {
public:
    // used vectors since time complexity for accessing elements by index is 1, whereas for lists it's n.
    vector<Expense> ExpenseVector;

    // tüm özellikleri aynı olan iki harcamaya izin olacak mı? (kabul etmemek daha kolay çünkü
    // aynı harcamalar olduğunda remove expense'te hangisini silmek istediğini nasıl bileceğiz?
    // id ile ulaşmak kolay olabilir ama kullanıcı id mi seçecek, id sıra mı olacak?)

    void addExpense(int id, const string& category, double amount, const string& date) {
        ExpenseVector.emplace_back(id, category, amount, date);
        // emplace_back "Constructs a new object directly at the end of a container."

        // though correct implementation of this would be with vectors

    }
    void removeExpense(int targetId);
};

#endif //EXPENSE_SYS_EXPENSE_MANAGER_H