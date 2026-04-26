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
## Quick Run (Windows)
If the project has already been built, you can run:

```bash
.\cmake-build-default\Expense_Sys.exe
```

For running tests:

```bash
.\cmake-build-default\Expense_Tests.exe
```


## Other Options than Quick Run
## Option A: Build and Run in VSCode
### Prerequisites
Install the following before opening the project:
- **Visual Studio Code**
- **C++ compiler**
  - Windows: MinGW-w64 or MSYS2 `g++`
  - macOS: Xcode Command Line Tools
  - Linux: `g++`
- **CMake**
- VS Code extensions:
  - **C/C++** by Microsoft
  - **CMake Tools** by Microsoft

### 1 - Configure the project in VS Code
1. Press `Ctrl+Shift+P`.
2. Run **CMake: Select a Kit**.
3. Choose your installed compiler.
4. Run **CMake: Configure**.

### 2 - Build the application in VS Code
1. Press `Ctrl+Shift+P`.
2. Run **CMake: Build**.

This builds the main executable:
- `Expense_Sys.exe` on Windows
- `Expense_Sys` on macOS/Linux

### Run the main application
Open the VS Code terminal and run:

**Windows**
```bash
.\build\Expense_Sys.exe
```

**macOS/Linux**
```bash
./build/Expense_Sys
```

Depending on the selected CMake generator, the executable may also be placed in a folder such as `cmake-build-debug` or `cmake-build-default`.

### Build and run the tests
Build the test target:
```bash
cmake --build build --target Expense_Tests
```

Run the tests from the VS Code terminal.
**Windows**
```bash
.\build\Expense_Tests.exe
```

**macOS/Linux**
```bash
./build/Expense_Tests
```

**CMake version note:** The current `CMakeLists.txt` uses version **4.1**:


## Option B: Build with CMake
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This creates two targets:
- `Expense_Sys` for the interactive application
- `Expense_Tests` for the test suite

## Option C: Compile directly with g++
```bash
g++ -std=c++20 main.cpp Expense.cpp ExpenseManager.cpp -o Expense_Sys
g++ -std=c++20 tests.cpp Expense.cpp ExpenseManager.cpp -o Expense_Tests
```
### Running the Program
Run the main application:
```bash
./Expense_Sys
```

Run the tests:
```bash
./Expense_Tests
```

