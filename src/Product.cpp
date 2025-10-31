#include "Product.h"
#include "string_util.h"
#include <iostream>
#include <cctype> //c character type: toupper()
#include <sstream> //string stream: 
#include <fstream> //file stream: 

using namespace std;

void Product::printInfo() {
    cout << "Product ID: " << this->productID << "\n";
    cout << "Product name: " << this->productName << "\n";
    cout << "Product brand: " << this->productBrand << "\n";
}

