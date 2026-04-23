# Team Members

| Number       | Name                  | Created Function      |
|--------------|-----------------------|-----------------------|
| 240 201 426  | Ömer Balkanoğlu       | Remove Expense        |
| 240 201 427  | Yusuf Alper Açıkbaş   | Calculate Total       |
| 240 201 418  | Alperen Baysal        | Filter Expenses       |
| 250 201 019  | Süeda Nalan Tahtacı   | Add and Sort Expenses |



# Expense Management System

A simple console-based expense tracker program written in C++. It allows users to add, view, remove, filter, sort expenses and calculate the total expense from a menu based interface.

## Features

- Add one or more expenses
- View saved expenses
- Remove an expense by its ID
- Filter expenses by category
- Calculate total expense
- Sort expenses by:
  - Name
  - Category
  - Amount
  - Date
  - ID
- Basic validation of user input
- Unit tests for core functions and edge cases

## Project Structure

- `main.cpp` - menu system and user interaction
- `Expense.h` / `.cpp` - Expense class and category-to-string conversion
- `ExpenseManager.h` / `.cpp` - expense management logic
- `tests.cpp` - unit tests
- `CMakeLists.txt` - build configuration


## Build Instructions

### Option 1: Build with CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This creates two targets:

- `Expense_Sys` for the interactive application
- `Expense_Tests` for the test suite

### Option 2: Compile directly with g++

```bash
g++ -std=c++20 main.cpp Expense.cpp ExpenseManager.cpp -o Expense_Sys
g++ -std=c++20 tests.cpp Expense.cpp ExpenseManager.cpp -o Expense_Tests
```

## Running the Program

Run the main application:

```bash
./Expense_Sys
```

Run the tests:

```bash
./Expense_Tests
```
