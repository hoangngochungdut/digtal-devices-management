#include "Store.h"
#include "Item.h"
#include "menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    Store x;
    int option;
    int exit;
    do {
        exit = 0;
        mainMenu();
        cout << "Please enter your option: ";
        cin >> option;
        cin.ignore();
        switch(option) {
            case 0: {
                cout << "Exited!\n"; 
                exit = 1; break;
            }
            case 1: {
                x.import();break;
            }
            case 2: {
                x.sell(); break;
            }
            case 3: {
                x.showStatictics(); break;
            }
            case 4: {
                x.categoryOptions(); break;
            }
            case 5: {
                x.brandOptions(); break;
            }
            case 6: {
                x.printProducts();break;
            }
            case 7: {
                x.search(); break;
            }
        }
    } while(!exit);
}