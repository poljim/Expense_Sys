#include <cassert>
#include <iostream>
#include <stdexcept>
#include "Expense.h"
#include "ExpenseManager.h"

using namespace std;

void testAddExpense() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2011-11-11");

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Coffee");
    assert(manager.getExpenseAt(0).getCategory() == Category::Food);
    assert(manager.getExpenseAt(0).getAmount() == 50.0);
    assert(manager.getExpenseAt(0).getDate() == "2011-11-11");
    assert(manager.getExpenseAt(0).getID() == 1);

    manager.addExpense("Lego", Category::Hobby, 20.0, "2012-12-22");

    assert(manager.getExpenseCount() == 2);
    assert(manager.getExpenseAt(1).getName() == "Lego");
    assert(manager.getExpenseAt(1).getCategory() == Category::Hobby);
    assert(manager.getExpenseAt(1).getAmount() == 20.0);
    assert(manager.getExpenseAt(1).getDate() == "2012-12-22");
    assert(manager.getExpenseAt(1).getID() == 2);
}

void testRemoveExpense() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2011-11-11");
    manager.addExpense("Taxi", Category::Transport, 100.0, "2011-11-10");

    manager.removeExpense(1);

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Taxi");
    assert(manager.getExpenseAt(0).getID() == 2);
}

void testSortByAmount() {
    ExpenseManager manager;
    manager.addExpense("B", Category::Food, 100.0, "2011-11-11");
    manager.addExpense("B", Category::Food, 50.0, "2011-11-11");
    manager.addExpense("B", Category::Food, 75.0, "2011-11-11");

    manager.sortByAmount();

    assert(manager.getExpenseAt(0).getAmount() == 50.0);
    assert(manager.getExpenseAt(1).getAmount() == 75.0);
    assert(manager.getExpenseAt(2).getAmount() == 100.0);
}

void testSortByName() {
    ExpenseManager manager;
    manager.addExpense("B", Category::Food, 100.0, "2011-11-11");
    manager.addExpense("A", Category::Food, 100.0, "2011-11-11");
    manager.addExpense("C", Category::Food, 100.0, "2011-11-11");

    manager.sortByName();

    assert(manager.getExpenseAt(0).getName() == "A");
    assert(manager.getExpenseAt(1).getName() == "B");
    assert(manager.getExpenseAt(2).getName() == "C");
}

void testSortByCategory() {
    ExpenseManager manager;
    manager.addExpense("Book", Category::Transport, 100.0, "2011-11-11");
    manager.addExpense("Book", Category::Food, 100.0, "2011-11-11");
    manager.addExpense("Book", Category::Education, 100.0, "2011-11-11");

    manager.sortByCategory();

    assert(manager.getExpenseAt(0).getCategory() == Category::Education);
    assert(manager.getExpenseAt(1).getCategory() == Category::Food);
    assert(manager.getExpenseAt(2).getCategory() == Category::Transport);
}

void testSortByDate() {
    ExpenseManager manager;
    manager.addExpense("Taxi", Category::Transport, 100.0, "2011-04-11");
    manager.addExpense("Taxi", Category::Transport, 100.0, "2010-04-10");
    manager.addExpense("Taxi", Category::Transport, 100.0, "2009-04-09");
    manager.sortByDate();

    assert(manager.getExpenseAt(0).getDate() == "2009-04-09");
    assert(manager.getExpenseAt(1).getDate() == "2010-04-10");
    assert(manager.getExpenseAt(2).getDate() == "2011-04-11");
}

void testSortByID() {
    ExpenseManager manager;
    manager.addExpense("A", Category::Food, 100.0, "2011-04-11"); // ID 1
    manager.addExpense("A", Category::Food, 100.0, "2010-04-10"); // ID 2
    manager.addExpense("A", Category::Food, 100.0, "2009-04-09"); // ID 3

    manager.sortByDate(); // shuffle
    manager.sortById();   // test target

    assert(manager.getExpenseAt(0).getID() == 1);
    assert(manager.getExpenseAt(1).getID() == 2);
    assert(manager.getExpenseAt(2).getID() == 3);
}


//=========================     edge case tests     =========================
void testEmptyManager() {
    ExpenseManager manager;
    assert(manager.isEmpty());
}

void testRemoveNonExistingId() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2011-11-11");

    manager.removeExpense(99);

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Coffee");
}

void testDuplicateRecords() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2011-11-11");
    manager.addExpense("Coffee", Category::Food, 50.0, "2011-11-11");

    assert(manager.getExpenseCount() == 2);
    assert(manager.getExpenseAt(0).getID() != manager.getExpenseAt(1).getID());
}

void testNegativeAmountThrows() {
    ExpenseManager manager;
    bool thrown = false;

    try {
        manager.addExpense("Coffee", Category::Food, -5.0, "2011-11-11");
    } catch (const invalid_argument&) {
        thrown = true;
    }
    try {
        manager.addExpense("Coffee", Category::Food, -5.0, "2011-11-11");
    } catch (const invalid_argument&) {
        thrown = true;
    }

    assert(thrown);
}

void testInvalidDateThrows() {
    ExpenseManager manager;

    bool thrown1 = false;
    try {
        manager.addExpense("X", Category::Food, 50.0, "11-11-2011");
    } catch (const invalid_argument&) {
        thrown1 = true;
    }
    assert(thrown1);

    bool thrown2 = false;
    try {
        manager.addExpense("X", Category::Food, 50.0, "2000.01.01");
    } catch (const invalid_argument&) {
        thrown2 = true;
    }
    assert(thrown2);

    bool thrown3 = false;
    try {
        manager.addExpense("X", Category::Food, 50.0, "2025-13-01");
    } catch (const invalid_argument&) {
        thrown3 = true;
    }
    assert(thrown3);

    bool thrown5 = false;
    try {
        manager.addExpense("X", Category::Food, 50.0, "2025-02-99");
    } catch (const invalid_argument&) {
        thrown5 = true;
    }
    assert(thrown5);
}

int main() {
    testAddExpense();
    testRemoveExpense();
    testSortByAmount();
    testSortByName();
    testSortByCategory();
    testSortByDate();
    testSortByID();

    testEmptyManager();
    testDuplicateRecords();
    testRemoveNonExistingId();
    testNegativeAmountThrows();
    testInvalidDateThrows();

    cout << "All tests passed.\n";
    return 0;
}