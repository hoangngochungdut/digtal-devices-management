#ifndef ITEM_H
#define ITEM_H
#include "Product.h"
#include <vector>

class Item: public Product{
    int sellPrice;
    int quantity;
    int sellTotal; 
    public:
        void setQuantity(int a) {this->quantity = a;}
        void setSellPrice(int a) {this->sellPrice = a;}
        void setSellTotal() {this->sellTotal = this->sellPrice * this->quantity;}
        void setCostTotal() {this->costTotal = this->costPrice * this->quantity;}

        int getQuantity() {return this->quantity;}
        int getSellPrice() {return this->sellPrice;}
        int getSellTotal() {return this->sellTotal;}
        int getCostTotal() {return this->costTotal;}

    void printInfoAfterSell() {
        Product::printInfo();
        cout << "Price: " << this->sellPrice << "\n";
        cout << "Quantity: " << this->quantity << "\n";
        cout << "Total: " << this->getSellTotal()<< "\n";
    }

    void printInfoAfterImport() {
        Product::printInfo();
        cout << "Price: " << this->costPrice << "\n";
        cout << "Quantity: " << this->quantity << "\n";
        cout << "Total: " << this->getCostTotal()<< "\n";
    }

};

bool haveSameID(Item a, Item b);
void subtract(Item &a, Item b);
void plusInto(Item &a, Item b);

#endif