#include "Product.h"
#include <iostream>
#include <cctype> //c character type: toupper()
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;

void Product::enterInfo() {
    cout << "Enter product ID: ";
    cin >> this->productID;
    cout << "Enter product name: ";
    cin >> this->productName;
    cout << "Enter product brand: ";
    cin >> this->productBrand;
}

void Product::printInfo() {
    cout << "Product ID: " << this->productID << "\n";
    cout << "Product name: " << this->productName << "\n";
    cout << "Enter product brand: " << this->productBrand << "\n";
}


