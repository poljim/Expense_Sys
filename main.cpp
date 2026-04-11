case 4: {
    if (expenseManager.isEmpty()) {
        cout << "No expenses found to filter.\n";
        break;
    }

    string searchCategory;
    cout << "Enter the category you want to filter by: ";
    // Önceki cin'den kalan newline karakterini temizlemek için
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, searchCategory);

    expenseManager.filterByCategory(searchCategory);
    break;
}
