#include "ExpenseManager.h"


double ExpenseManager::calculateTotal() const {
    double total = 0.0;

    
    for (size_t i = 0; i < ExpenseVector.size(); i++) {
    
        total += ExpenseVector[i].getAmount(); 
    }

    return total;
}
