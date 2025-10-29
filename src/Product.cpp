#include "Product.h"
#include "string_util.h"
#include <iostream>
#include <cctype> //c character type: toupper()
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;
void Product::setID(const string &s){
    this->productID = s;
}

void Product::setName(const string &s) {
    this->productName = s;
}

void Product::setBrand(const string &s) {
    this->productBrand = s;
}

void Product::setCostPrice(int a) {
    this->costPrice = a;
}

void Product::update() {
    ofstream out;
    out.open("data/productList.txt", ios::app);
    out << this->productID << ";" << this->productName << ";" << this->productBrand << "\n";
    out.close();
}


void Product::printInfo() {
    cout << "Product ID: " << this->productID << "\n";
    cout << "Product name: " << this->productName << "\n";
    cout << "Product brand: " << this->productBrand << "\n";
}

bool existedID(const string &ID) {
        ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool existed = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _ID;
            getline(ss, _ID, ';');
            if (upper(ID) == upper(_ID)) {
                existed = true;
                in.close();
            }
        }
        in.close();
        return existed;
}

bool existedName(const string &name) {
        ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool existed = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(name) == upper(_name)) {
                existed = true;
                in.close();
            }
        }
        in.close();
        return existed;
}

bool matchedNameID(const string &name, const string &ID) {
    ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool matched = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(name) == upper(_name) && upper(ID) == upper(_ID)) {
                matched = true;
                in.close();
            }
        }
        in.close();
        return matched;
}