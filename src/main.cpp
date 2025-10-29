#include "Store.h"
#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;
void menu() {
    cout << "-------------------------\n";
    cout << "| 0. Exit               |\n";
    cout << "| 1. Import             |\n";
    cout << "| 2. Sell               |\n";
    cout << "| 3. Show statictics    |\n";
    cout << "| 4. Print categories   |\n";
    cout << "| 5. Add new category   |\n";
    cout << "| 6. Print products     |\n";
    cout << "| 7. Add new product    |\n";
    cout << "-------------------------\n";

}

int main() {
    Store x;
    int option;
    int exit;
    do {
        exit = 0;
        menu();
        cout << "Please enter your option: ";
        cin >> option;
        switch(option) {
            case 0: cout << "Exited!\n"; exit = 1; break;
            case 1: x.import(); break;
            case 2: x.sell(); break;
            case 3: x.showStatictics(); break;
            case 4: x.printCategories(); break;
            case 5: x.addNewCategory(); break;
            case 6: x.printProducts(); break;
            case 7: x.addNewProduct(); break;

        }
    } while(!exit);
}