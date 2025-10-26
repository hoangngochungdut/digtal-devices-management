#include "Store.h"
#include <iostream>
#include <cctype> //c character type: toupper()
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;

void Store::import() {
    int n, count = 0;
    cout << "Enter the number of products you want to import (enter 0 to escape): ";
    cin >> n;
    if (n == 0) cout << "Escaped!\n";
    cin.ignore();
    while(n) {
        cout << ++count << ".\n";
        cout << "Enter the product";
    }

    
}

void Store::sell() {

}

void Store::showStatictics() {

}

string upper(string s) {
    string temp = s;
    for (char &c : temp) c = toupper(c);
    return temp;
}

string capitalize(string s) {
    if(s.empty()) return s;
    string temp = s;
    for (char &c: temp) c = tolower(c);
    temp[0] = toupper(temp[0]);
    return temp;
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
        bool isDuplicate;


        cout << "Enter product name (enter q to skip): ";
        getline(cin, name);
        if (name == "q") {
            n--;
            count++;
            cout << "Skipped!\n";
            continue;
        }
        ifstream in;
        in.open("data/productList.txt", ios::in);

        isDuplicate = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(name) == upper(_name)) {
                cout << "This product name already existed, please try again!\n";
                isDuplicate = true;
                in.close();
            }
        in.close();
        
        if (!isDuplicate) {
            cout << "Enter product ID (enter q to skip): ";
            getline(cin, ID);
            if (ID == "q") {
                n--;
                count++;
                cout << "Skipped!\n";
                continue;
            }

            isDuplicate = false;
            in.open("data/productList.txt", ios::in);
            while(getline(in, line)) {
                stringstream ss(line);
                string __ID;
                getline(ss, _ID, ';');
                getline(ss, _name, ';');
                if (upper(ID) == upper(_ID)) {
                    cout << "This ID already existed, please try again!\n";
                    isDuplicate = true;
                    in.close();
                    }
                
                }
            in.close();

            if (!isDuplicate) {
                cout << "Enter the product's brand: ";
                getline(cin, brand);
                ofstream out;
                out.open("data/productList.txt", ios::app);
                out << ID << ";" << capitalize(name) << ";" << capitalize(brand) << "\n";
                cout << "Added succesfully!\n";
                n--;
                count++;
                out.close();
                }
            }

        
        }
    }
}



