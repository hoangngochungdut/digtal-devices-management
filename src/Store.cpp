#include "Store.h"
#include "Product.h"
#include "Item.h"
#include "string_util.h"

#include <iostream>
#include <vector>
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;

void Store::import() {

}

void Store::sell() {
    int n, count = 0;
    cout << "Enter the number of products you want to sell (enter 0 to escape): ";
    cin >> n;
    if (n == 0) {
        cout << "Escaped!\n";
        return;
    }
    cin.ignore();
    vector <Item> items(n);
    int N = n;
    
    //Nhap thong tin
    while(n) {
        string name, ID;
        int quant;
        cout << count + 1 << ".\n";

        bool exitName = false;
        do {
            cout << "Enter the product name (enter q to skip): ";
            getline(cin, name);

            if (name == "q") {
                n--;
                count++;
                exitName = true;
                cout << "Skipped!\n";
                continue;
            }

            if(!existedName(name)) cout << "There is no \"" << name << "\" in store, please try a new name.\n";
            else {
                
                bool exitID = false;
                do {
                    cout << "Enter the product ID (enter q to skip): ";
                    getline(cin, ID);

                    if (ID == "q") {
                    n--;
                    count++;
                    exitID = true;
                    cout << "Skipped!\n";
                    continue;
                    }
                    
                    if(!matchedNameID(name, ID)) cout << "There is no product has ID: " << ID << ", please try a new ID.\n";
                    else {
                    int _quant = getQuantity(ID), quant = 0;
                    
                    bool exitQuant = false;
                    do {
                        cout << "Enter quantity: ";
                        cin >> quant;
                        cin.ignore();

                        if (quant > _quant) cout << "There are only " << _quant << " left!\n";
                        else if (quant <= 0) cout << "Invalid quantity!\n";
                        else {
                            items[count].setName(capitalize(name));
                            items[count].setID(upper(ID));
                            items[count].setQuantity(quant);
                            items[count].getSellPrice();
                            items[count].setTotal();

                            n--;
                            count++;

                            exitQuant = true;
                            exitID = true;
                            exitName = true;
                        }
                    } while(!exitQuant);

                    }
                } while(!exitID);
            }

        } while(!exitName);
    }

    if(count) {
        cout << "\n";

        //Tong hop
        int S = 0;
        for (int i = 0; i < N; i++) {
            cout << i + 1 << ".\n";
            items[i].printInfo();
            S+= items[i].getTotal();
        }
        cout << "\nGrand total: " << S << "\n"; 
    }


}

// void Store::sell() {
//     int n, count = 1;
//     cout << "Enter the number of products you want to sell (enter 0 to escape): ";
//     cin >> n;
//     if (n == 0) cout << "Escaped!\n";
//     cin.ignore();
//     vector <Item> items(n);
//     while(n) {
//         string name, ID;
//         int quant;
//         cout << count << ".\n";

//         do {
//             cout << "Enter the product name (enter q to skip): ";
//             getline(cin, name);

//             if (name == "q") {
//                 n--;
//                 count++;
//                 cout << "Skipped!\n";
//                 continue;
//             }
            
//             if(existedName(name)) {
//                 cout << "Enter the product ID (enter q to skip): ";
//                 getline(cin, ID);

//                 if (ID == "q") {
//                 n--;
//                 count++;
//                 cout << "Skipped!\n";
//                 continue;
//                 }
    
//                 if(matchedNameID(name, ID)) {
//                     int quant = getQuantity(ID);
//                     if (!quant) {
//                         cout << "This product is out of store!\n";
//                         n--;
//                         count++;
//                         continue;
//                     }
//                     int _quant = 0;
//                     do {
//                         cout << "Enter quantity: ";
//                         cin >> _quant;
//                         cin.ignore();
//                         if (_quant > quant) cout << "There is only " << quant << " left!\n";
//                     } while(_quant > quant);
//                 } else cout << "There is no product has ID: " << ID << ", please try a new ID.\n";
//             } else cout << "There is no \"" << name << "\" in store, please try a new name.\n";
//         } while(true);
//     }   
// }

void Store::showStatictics() {

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

                x.update();
                cout << "Added succesfully!\n";
                n--;
                count++;
                
                }
            }

        
        }
    
}



