// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include "Expense.h"
//
//
// using namespace std;
//
// class ExpenseManager {
// private:
//     vector<Expense> expenses;  // Vector to hold the expenses
//
// public:
//     // Add an expense
//     void addEx(double amount) {
//         expenses.push_back(amount);
//     }
//
//     // Remove an expense (example: remove the last one)
//     void removeEx() {
//         if (!expenses.empty()) {
//             expenses.pop_back();
//         } else {
//             cout << "No expenses to remove.\n";
//         }
//     }
//
//     // Filter expenses (e.g., remove expenses below a threshold)
//     void filterEx(double threshold) {
//         expenses.erase(remove_if(expenses.begin(), expenses.end(),
//                                  [threshold](double expense) { return expense < threshold; }),
//                        expenses.end());
//     }
//
//     // Calculate total expense
//     double calEx() const {
//         double total = 0;
//         for (double expense : expenses) {
//             total += expense;
//         }
//         return total;
//     }
//
//     // Sort expenses
//     void sortEx() {
//         sort(expenses.begin(), expenses.end());
//     }
//
//     // Print all expenses (for display)
//     void printEx() const {
//         std::cout << "\nAll items:\n";
//         for (const auto& item : items) {
//             std::cout << item.name << " - " << item.value << "\n";
//         }
//
//
//         for (double expense : expenses) {
//             cout << expense << " ";
//         }
//         cout << endl;
//     }
// };
//
// int main() {
//     ExpenseManager em;
//     bool condition = true;
//
//     while (condition) {
//         cout << "Please choose one of the options below:\n"
//              << "1. Add expense\n"
//              << "2. Remove expense\n"
//              << "3. Filter expenses\n"
//              << "4. Calculate total expense\n"
//              << "5. Sort expenses\n"
//              << "0. Exit\n";
//
//         int option;
//         cin >> option;
//
//         switch (option) {
//             case 1: {
//                 double amount;
//                 cout << "Enter the expense amount: ";
//                 cin >> amount;
//                 em.addEx(amount);
//                 break;
//             }
//             case 2:
//                 em.removeEx();
//                 break;
//             case 3: {
//                 double threshold;
//                 cout << "Enter the threshold: ";
//                 cin >> threshold;
//                 em.filterEx(threshold);
//                 break;
//             }
//             case 4:
//                 cout << "Total expense: " << em.calEx() << endl;
//                 break;
//             case 5:
//                 em.sortEx();
//                 cout << "Sorted expenses: ";
//                 em.printEx();
//                 break;
//             case 0:
//                 condition = false;
//                 break;
//             default:
//                 cout << "Please enter a valid option between 0-5.\n";
//         }
//     }
//
//     return 0;
// }