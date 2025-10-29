#include "Product.h"
#include "Item.h"
#include "string_util.h"
#include <iostream>
#include <sstream> //string stream: 
#include <fstream> //file stream: 
using namespace std;


void Item::setSellPrice(int a) {
    this->sellPrice = a; 
}

void Item::setQuantity(int a) {
    this->quantity = a;
}

void Item::setTotal() {
    this->total = this->sellPrice * this->quantity;
}

void Item::printInfo() {
    Product::printInfo();
    cout << "Price: " << this->sellPrice << "\n";
    cout << "Quantity: " << this->quantity << "\n";
    cout << "Total: " << this->sellPrice * this->quantity << "\n";
}

int getQuantity(const string &ID) {
    if (ID == "") return -1;

    ifstream in("data/item.txt");

    string line, quant;
    while (getline(in, line)) {
        stringstream ss(line);
        string _ID, sellPrice;
        getline(ss, _ID, ';');
        getline(ss, sellPrice, ';');
        getline(ss, quant, ';');

        if (upper(ID) == upper(_ID)) {
            in.close();
            return stoi(quant);
        
        }
    }
    in.close();
    return -1;
}

bool Item::getSellPrice() {
    if (this->productID == "") return false;

    ifstream in("data/item.txt");

    string line, sellPrice;
    while (getline(in, line)) {
        stringstream ss(line);
        string _ID;
        getline(ss, _ID, ';');
        getline(ss, sellPrice, ';');

        if (upper(this->productID) == upper(_ID)) {
            in.close();
            this->sellPrice = stoi(sellPrice);
            return true;
        }
    }
    in.close();
    return false;
}