#include "Store.h"
#include "Product.h"
#include "Item.h"
#include "string_util.h"
#include "file_util.h"

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

        if (!matchedNameID(name, ID)) {
            i--;
            cout << "This ID already existed. Please try again\n";
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
    
}

void Store::searchWithCategory() {
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

        // kiểm tra ID có trùng 3 ký tự đầu không
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
                    break; // tìm thấy rồi thì dừng
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

    

void searcWithPrice() {

}

void searcWithCategoryAndPrice() {

}


void Store::printCategories() {
    ifstream in;
    in.open("data/categoryList.txt", ios::in);
    string line;
    int count = 1;
    while(getline(in, line)) {
        stringstream ss(line);
        string ID, name;

        getline(ss, ID, ';');
        getline(ss, name, ';');
        cout << count << ". " << name << "\n";
        count++;
    }
    in.close();
}

void Store::addNewCategory() {
    int n, count = 1;
    cout << "Enter the number of categories you want to add (enter 0 to escape): ";
    cin >> n;
    if (n == 0) cout << "Escaped!\n";
    cin.ignore();
    while(n) {
        ifstream in;
        in.open("data/categoryList.txt", ios::in);
        cout << count << ".\n";
        string name, ID;
        cout << "Enter category name (enter q to skip): ";
        getline(cin, name);
        if (name == "q") {
            n--;
            count++;
            cout << "Skipped!\n";
            continue;
        }
        cout << "Enter category ID (enter q to skip): ";
        getline(cin, ID);
        if (ID == "q") {
            n--;
            count++;
            cout << "Skipped!\n";
            continue;
        }
        
        bool isDuplicate = false;
        string line;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(ID) == upper(_ID) || upper(name) == upper(_name)) {
                cout << "This category name or ID already existed, please try again!\n";
                isDuplicate = true;
                break;
            }
        }
        in.close();

        if (!isDuplicate) {
            ofstream out;
            out.open("data/categoryList.txt", ios::app);
            out << ID << ";" << capitalize(name) << "\n";
            cout << "Added succesfully!\n";
            n--;
            count++;
            out.close();
        }
    }
}

void Store::printProducts() {
    ifstream in;
    in.open("data/productList.txt", ios::in);
    string line;
    int count = 1;
    while(getline(in, line)) {
        stringstream ss(line);
        string ID, name, brand;

        getline(ss, ID, ';');
        getline(ss, name, ';');
        getline(ss, brand, ';');
        cout << count << ". " << name << ", " << brand << "\n";
        count++;
    }
    in.close();
}

void Store::addNewProduct() {
    int n, count = 1;
    cout << "Enter the number of products you want to add (enter 0 to escape): ";
    cin >> n;
    if (n == 0) cout << "Escaped!\n";
    cin.ignore();

    while(n) {
        cout << count << ".\n";
        string name, ID, brand, line;
        int costPrice;

        cout << "Enter product name (enter q to skip): ";
        getline(cin, name);
        if (name == "q") {
            n--;
            count++;
            cout << "Skipped!\n";
            continue;
        }

        if (!existedName(name)) {

            cout << "Enter product ID (enter q to skip): ";
            getline(cin, ID);
            
            if (ID == "q") {
                n--;
                count++;
                cout << "Skipped!\n";
                continue;
            }

            if (!existedID(ID)) {
                cout << "Enter the product's brand: ";
                getline(cin, brand);

                cout << "Enter cost price: ";
                cin >> costPrice;
                cin.ignore();
                Product x;
                x.setName(name);
                x.setID(ID);
                x.setBrand(brand);
                x.setCostPrice(costPrice);

                updateNewProduct(x);
                cout << "Added succesfully!\n";
                n--;
                count++;
                
                }
            }

        
        }
    
}


