#include "ExpenseManager.h"

double ExpenseManager::calculateTotal() {
    double total = 0.0;

    for (int i = 0; i < currentSize; i++) {
        total += expenses[i].getAmount(); 
    }

    return total;
}
