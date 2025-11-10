#include "Category.h"
#include "Brand.h"
#include "Store.h"
#include "Product.h"
#include "Item.h"
#include "string_util.h"
#include "file_util.h"
#include "menu.h"
#include "LinkList.h"

#include <iostream>
#include <vector>
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;

void Store::import() {
    int n;
    cout << "Enter the number of products you want to import (enter 0 to escape): ";
    cin >> n;
    cin.ignore();

    if (n == 0) {
        cout << "Escaped!\n";
        return;
    }

    vector<Item> items;
    items.reserve(n); 

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";

        string name, ID, brand;
        int costPrice, quant;

        cout << "Enter the product name (enter q to skip): ";
        getline(cin, name);
        if (name == "q") {
            cout << "Skipped!\n";
            continue;
        }

        cout << "Enter the product ID (enter q to skip): ";
        getline(cin, ID);
        if (ID == "q") {
            cout << "Skipped!\n";
            continue;
        }

        if (existedName(name) && !matchedNameID(name, ID)) {
            i--;
            cout << "This ID does not match with product name. Please try again\n";
            continue;
        }

        cout << "Enter the product's brand (enter q to skip): ";
        getline(cin, brand);
        if (brand == "q") {
            cout << "Skipped!\n";
            continue;
        }

        cout << "Enter the cost price: ";
        cin >> costPrice;
        if (costPrice < 0) {
            cout << "Invalid cost price! Skipped!\n";
            cin.ignore();
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quant;
        cin.ignore();
        if (quant <= 0) {
            cout << "Invalid quantity! Skipped!\n";
            continue;
        }

        // Luu san pham
        Item item;
        item.setName(capitalize(name));
        item.setID(upper(ID));
        item.setBrand(capitalize(brand));
        item.setCostPrice(costPrice);
        item.setSellPrice(0);
        item.setQuantity(quant);
        item.setCostTotal();

        items.push_back(item);
    }

    if (!items.empty()) {
        cout << "\n===IMPORT SUMARY===:\n";
        int grandTotal = 0;
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ".\n";
            items[i].printInfoAfterImport();
            grandTotal += items[i].getCostTotal();
        }
        cout << "\nGrand total: " << grandTotal << "\n";
        updateAfterImport(items);
    } else {
        cout << "No product imported.\n";
    }
}

void Store::sell() {
    int n;
    cout << "Enter the number of products you want to sell (enter 0 to escape): ";
    cin >> n;
    cin.ignore();
    if (n == 0) {
        cout << "Escaped!\n";
        return;
    }

    vector<Item> items;
    items.reserve(n);

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        string name, ID;
        int quant;

        cout << "Enter the product name (enter q to skip): ";
        getline(cin, name);
        if (name == "q") {
            cout << "Skipped!\n";
            continue;
        }

        if (!existedName(name)) {
            cout << "There is no \"" << name << "\" in store, please try again.\n";
            i--; // cho nhập lại sản phẩm này
            continue;
        }

        cout << "Enter the product ID (enter q to skip): ";
        getline(cin, ID);
        if (ID == "q") {
            cout << "Skipped!\n";
            continue;
        }

        if (!matchedNameID(name, ID)) {
            cout << "This ID \"" << ID << "\" does not match the name.\n";
            i--; // cho nhập lại sản phẩm này
            continue;
        }

        int stock = getQuantity(ID);
        cout << "Enter quantity: ";
        cin >> quant;
        cin.ignore();

        if (quant > stock) {
            cout << "There are only " << stock << " left in stock!\n";
            i--;
            continue;
        }

        if (quant <= 0) {
            cout << "Invalid quantity!\n";void updateNewProduct(Product x);
            i--;
            continue;
        }

        // tạo item và thêm vào danh sách
        Item item;
        item.setName(capitalize(name));
        item.setID(upper(ID));
        item.setQuantity(quant);
        item.setSellPrice(getSellPrice(item.getID()));
        item.setSellTotal();

        items.push_back(item);
    }

    if (!items.empty()) {
        cout << "\n=== SELL SUMMARY ===\n";
        int totalRevenue = 0;

        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ".\n";
            items[i].printInfoAfterSell();
            totalRevenue += items[i].getSellTotal();
        }

        cout << "\nGrand total: " << totalRevenue << "\n";

        updateAfterSell(items);
    } else {
        cout << "No product sold.\n";
    }
}

void Store::showStatictics() {

}

void Store::search() { 
    int option;
    int exit;
    do {
        exit = 0;
        searchMenu(); 
        cout << "Please enter your option: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 0: cout << "Exited!\n"; exit = 1; break;
            case 1: searchWithCategory(); break;
            case 2: searchWithPrice(); break;
            case 3: searchWithCategoryAndPrice(); break;
        }
    } while(!exit);
    
}

void searchWithCategory() {
    string category;
    cout << "Enter category: ";
    getline(cin, category);

    string ID = getCategoryID(category);

    ifstream in("data/productList.txt");
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string _ID, name, brand;
        getline(ss, _ID, ';');
        getline(ss, name, ';');
        getline(ss, brand, ';');

        if (_ID.size() >= 3 && _ID.substr(0, 3) == ID) {
            string sellPrice, quant;

            ifstream in1("data/item.txt");
            string line1;
            while (getline(in1, line1)) {
                stringstream ss1(line1);
                string ID1;
                getline(ss1, ID1, ';');
                if (ID1 == _ID) {
                    getline(ss1, sellPrice, ';');
                    getline(ss1, quant, ';');
                    break;
                }
            }
            in1.close();

            cout << "\nProduct name: " << name << "\n";
            cout << "Product brand: " << brand << "\n";
            cout << "Price: " << sellPrice << "\n";
            cout << "Quantity: " << quant << "\n";
        }
    }

    in.close();
}

void searchWithPrice() {
    int price;
    cout << "Enter price: ";
    cin >> price;
    
}

void searchWithCategoryAndPrice() {

}


void Store::printCategories() {
    ifstream in;
    in.open("data/categoryList.txt", ios::in);
    string line;
    LinkList<Category> categories;
    while(getline(in, line)) {
        stringstream ss(line);
        string ID, name;
        getline(ss, ID, ';');
        getline(ss, name);

        Category category;
        category.setCategoryID(ID);
        category.setCategoryName(name);
        categories.add(category);
    }
    in.close();

    if(!categories.isEmpty()) categories.display();
    else cout << "Empty list!\n";
}

void Store::addNewCategory() {
    int n;
    cout << "Enter the number of categories you want to add (enter 0 to esc e): ";
    cin >> n;
    cin.ignore();
    if (n == 0) cout << "Escaped!\n";

    //nhap thong tin
    int count = 0;
    LinkList<Category> categories;
    while(n) {
        cout << "Category " << count + 1 << ":\n";
        string ID, name;
        cout << "Enter category ID: ";
        getline(cin, ID);
        cout << "Enter category name: "; 
        getline(cin, name);
        if (!existedCategoryID(ID) && !existedCategoryName(name)) {
            Category category;
            category.setCategoryID(ID);
            category.setCategoryName(name);

            categories.add(category);
            n--;
            count++; 
        } else cout << "This ID or name is already existed, Please try again!\n";
    }

    //xuat thong tin ra file
    updateCategoryList(categories);
}

void Store::categoryOptions() { 
    int option;
    int exit;
    do {
        exit = 0;
        categoryOptionMenu();
        cout << "Please enter your option: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 0: cout << "Exited!\n"; exit = 1; break;
            case 1: addNewCategory(); break;
            case 2: printCategories(); break;
        }
    } while(!exit);
}

void Store::printBrands() {
    ifstream in;
    in.open("data/brandList.txt", ios::in);
    string line;
    LinkList<Brand> brands;
    while(getline(in, line)) {
        stringstream ss(line);
        string ID, name;
        getline(ss, ID, ';');
        getline(ss, name);

        Brand brand;
        brand.setBrandID(ID);
        brand.setBrandName(name);
        brands.add(brand);
    }
    in.close();

    if(!brands.isEmpty()) brands.display();
    else cout << "Empty list!\n";
}

void Store::addNewBrand() {
    int n;
    cout << "Enter the number of brands you want to add (enter 0 to esc e): ";
    cin >> n;
    cin.ignore();
    if (n == 0) cout << "Escaped!\n";

    //nhap thong tin
    int count = 0;
    LinkList<Brand> brands;
    while(n) {
        cout << "Brand " << count + 1 << ":\n";
        string ID, name;
        cout << "Enter brand ID: ";
        getline(cin, ID);
        cout << "Enter brand name: "; 
        getline(cin, name);
        if (!existedBrandID(ID) && !existedBrandName(name)) {
            Brand brand;
            brand.setBrandID(ID);
            brand.setBrandName(name);

            brands.add(brand);
            n--;
            count++; 
        } else cout << "This ID or name is already existed, Please try again!\n";
    }
 
    //xuat thong tin ra file
    updateBrandList(brands);
}

void Store::brandOptions() {
    int option;
    int exit;
    do {
        exit = 0;
        brandOptionMenu();
        cout << "Please enter your option: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 0: cout << "Exited!\n"; exit = 1; break;
            case 1: addNewBrand(); break;
            case 2: printBrands(); break;
        }
    } while(!exit); 
}

void Store::printProducts() {
    ifstream in;
    in.open("data/productList.txt", ios::in);
    string line;
    LinkList<Product> products;
    while(getline(in, line)) {
        stringstream ss(line);
        string ID, name;
        getline(ss, ID, ';');
        getline(ss, name);

        Product product;
        product.setProductID(ID);
        product.setProductName(name);
        products.add(product);
    }
    in.close();

    if(!products.isEmpty()) products.display();
    else cout << "Empty list!\n";
}

void Store::addNewProduct() {
    int n;
    cout << "Enter the number of brands you want to add (enter 0 to esc e): ";
    cin >> n;
    cin.ignore();
    if (n == 0) cout << "Escaped!\n";

    //nhap thong tin
    int count = 0;
    LinkList<Brand> brands;
    while(n) {
        cout << "Brand " << count + 1 << ":\n";
        string ID, name;
        cout << "Enter brand ID: ";
        getline(cin, ID);
        cout << "Enter brand name: "; 
        getline(cin, name);
        if (!existedBrandID(ID) && !existedBrandName(name)) {
            Brand brand;
            brand.setBrandID(ID);
            brand.setBrandName(name);

            brands.add(brand);
            n--;
            count++; 
        } else cout << "This ID or name is already existed, Please try again!\n";
    }
 
    //xuat thong tin ra file
    updateBrandList(brands);
}

void Store::productOptions() {
    int option;
    int exit;
    do {
        exit = 0;
        productOptionMenu();
        cout << "Please enter your option: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 0: cout << "Exited!\n"; exit = 1; break;
            case 1: addNewProduct(); break;
            case 2: printProducts(); break;
        }
    } while(!exit); 
}

