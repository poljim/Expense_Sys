#include <cassert>
#include <iostream>
#include <stdexcept>
#include "ExpenseManager.h"

using namespace std;

void testAddExpense() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Coffee");
    assert(manager.getExpenseAt(0).getCategory() == Category::Food);
    assert(manager.getExpenseAt(0).getAmount() == 50.0);
    assert(manager.getExpenseAt(0).getDate() == "2026-04-11");
    assert(manager.getExpenseAt(0).getID() == 1);
}

void testRemoveExpense() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");
    manager.addExpense("Taxi", Category::Transport, 100.0, "2026-04-10");

    manager.removeExpense(1);

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Taxi");
    assert(manager.getExpenseAt(0).getID() == 2);
}

void testSortByAmount() {
    ExpenseManager manager;
    manager.addExpense("Taxi", Category::Transport, 100.0, "2026-04-10");
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");
    manager.addExpense("Book", Category::Education, 75.0, "2026-04-09");

    manager.sortByAmount();

    assert(manager.getExpenseAt(0).getAmount() == 50.0);
    assert(manager.getExpenseAt(1).getAmount() == 75.0);
    assert(manager.getExpenseAt(2).getAmount() == 100.0);
}

void testSortByName() {
    ExpenseManager manager;
    manager.addExpense("Taxi", Category::Transport, 100.0, "2026-04-10");
    manager.addExpense("Book", Category::Education, 75.0, "2026-04-09");
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");

    manager.sortByName();

    assert(manager.getExpenseAt(0).getName() == "Book");
    assert(manager.getExpenseAt(1).getName() == "Coffee");
    assert(manager.getExpenseAt(2).getName() == "Taxi");
}

void testSortByCategory() {
    ExpenseManager manager;
    manager.addExpense("Taxi", Category::Transport, 100.0, "2026-04-10");
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");
    manager.addExpense("Book", Category::Education, 75.0, "2026-04-09");

    manager.sortByCategory();

    assert(manager.getExpenseAt(0).getCategory() == Category::Education);
    assert(manager.getExpenseAt(1).getCategory() == Category::Food);
    assert(manager.getExpenseAt(2).getCategory() == Category::Transport);
}

void testSortByDate() {
    ExpenseManager manager;
    manager.addExpense("Taxi", Category::Transport, 100.0, "2026-04-10");
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");
    manager.addExpense("Book", Category::Education, 75.0, "2026-04-09");

    manager.sortByDate();

    assert(manager.getExpenseAt(0).getDate() == "2026-04-09");
    assert(manager.getExpenseAt(1).getDate() == "2026-04-10");
    assert(manager.getExpenseAt(2).getDate() == "2026-04-11");
}

// edge case tests

void testEmptyManager() {
    ExpenseManager manager;
    assert(manager.getExpenseCount() == 0);
}

void testRemoveNonExistingId() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");

    manager.removeExpense(99);

    assert(manager.getExpenseCount() == 1);
    assert(manager.getExpenseAt(0).getName() == "Coffee");
}

void testDuplicateRecords() {
    ExpenseManager manager;
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");
    manager.addExpense("Coffee", Category::Food, 50.0, "2026-04-11");

    assert(manager.getExpenseCount() == 2);
    assert(manager.getExpenseAt(0).getID() != manager.getExpenseAt(1).getID());
}

void testEmptyNameThrows() {
    ExpenseManager manager;
    bool thrown = false;

    try {
        manager.addExpense("", Category::Food, 50.0, "2026-04-11");
    } catch (const invalid_argument&) {
        thrown = true;
    }

    assert(thrown);
}

void testNegativeAmountThrows() {
    ExpenseManager manager;
    bool thrown = false;

    try {
        manager.addExpense("Coffee", Category::Food, -5.0, "2026-04-11");
    } catch (const invalid_argument&) {
        thrown = true;
    }

    assert(thrown);
}

void testInvalidDateThrows() {
    ExpenseManager manager;
    bool thrown = false;

    try {
        manager.addExpense("Coffee", Category::Food, 50.0, "11-04-2026");
    } catch (const invalid_argument&) {
        thrown = true;
    }

    assert(thrown);
}

int main() {
    testAddExpense();
    testRemoveExpense();
    testSortByAmount();
    testSortByName();
    testSortByCategory();
    testSortByDate();

    testDuplicateRecords();
    testRemoveNonExistingId();
    testEmptyManager();
    testEmptyNameThrows();
    testNegativeAmountThrows();
    testInvalidDateThrows();

    cout << "All tests passed.\n";
    return 0;
}