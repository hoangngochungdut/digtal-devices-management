#ifndef ITEM_H
#define ITEM_H
#include "Product.h"
#include <vector>

class Item: public Product{
    int sellPrice;
    int quantity;
    int sellTotal;
    public:
        void setQuantity(int a) {
            this->quantity = a; 
        }

        int getQuantity() {
            return this->quantity;
        }

        void setSellPrice(int a) {
            this->sellPrice = a;
        }

        int getSellPrice() {
            return this->sellPrice;
        }
       
        void setSellTotal() {
            this->sellTotal = this->sellPrice * this->quantity;
        }

        int getSellTotal() {
            return this->sellTotal;
        }
//
        void setCostTotal() {
            this->costTotal = this->costPrice * this->quantity;
        }

        int getCostTotal() {
            return this->costTotal;
        }

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