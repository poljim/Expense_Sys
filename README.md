# Expense Management System

A simple console-based expense tracker program written in C++. It allows users to add, remove, filter, sort, view expenses and calculate the total expense.
Prepared by:
  - 240 201 426 Ömer Balkanoğlu
  - 240 201 427 Yusuf Alper Açıkbaş
  - 240 201 418 Alperen Baysal 
  - 250 201 019 Süeda Nalan Tahtacı 


## Features

- Add new expenses
- View saved expenses
- Remove an expense by its ID
- Filter expenses by category
- Calculate total expense
- Sort expenses by:
  - ID
  - name
  - category
  - amount
  - date
- Basic validation of user input
- Unit tests for core functions

## Project Structure

- `main.cpp` - menu system and user interaction
- `Expense.h` / `Expense.cpp` - `Expense` class and category-to-string conversion
- `ExpenseManager.h` / `ExpenseManager.cpp` - expense management logic
- `tests.cpp` - unit tests
- `CMakeLists.txt` - build configuration

## Requirements

- A C++20 compatible compiler
- CMake
- Windows if you want to run a provided `.exe` directly

## Running the Program

### Option 1: Run a provided executable on Windows

If a precompiled `.exe` is included, you may be able to run it directly by double-clicking it.

Note: if the executable was built with MinGW, Windows may also require runtime DLL files such as `libstdc++-6.dll` and `libgcc_s_seh-1.dll` in the same folder. If these are missing, build the project from source using the instructions below.

### Option 2: Build from source

Use CMake or an IDE such as CLion to build the project from the provided source files.

#### Build with CLion

1. Open the project folder in CLion.
2. Let CLion load the CMake project.
3. Select the target you want to run:
  - `Expense_Sys` for the main program
  - `Expense_Tests` for the tests
4. Click **Run**.

#### Build from the terminal

Open a terminal in the project folder and run:

```bash
mkdir build
cd build
cmake ..
cmake --build .
