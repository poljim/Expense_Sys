cmake_minimum_required(VERSION 4.1)
project(Expense_Sys)

set(CMAKE_CXX_STANDARD 20)

add_executable(Expense_Sys main.cpp
        Expense.cpp
        ExpenseManager.cpp
        ExpenseManager.h
        deneme.cpp
        deneme.h)
