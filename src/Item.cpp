#include "Product.h"
#include "Item.h"
#include <iostream>
using namespace std;

void Item::enterInfo() {
    Product::enterInfo();
    cout << "Enter price: ";
    cin >>  this->price;
    cout << "Enter warranty: ";
    cin >> this->warranty;
    cout << "Enter discount: ";
    cin >> this->discount;
    cout << "Enter quantity: ";
    cin >>  this->quantity;
}

void Item::printInfo() {
    Product::printInfo();
    cout << "Price: " << this->price << "\n";
    cout << "Quantity: " << this->quantity << "\n";
    cout << "Warranty: " << this->warranty << "\n";
    cout << "Discount: " << this->discount << "\n";
}
