#ifndef ITEM_H
#define ITEM_H
#include "Product.h"

class Item: public Product{
    int sellPrice;
    int quantity;
    int total;
    public: 
        void setQuantity(int a);
        void setSellPrice(int a);
        void setTotal();

        int getTotal() {
            return this->total;
        }
        bool getSellPrice();
        void printInfo();
};

int getQuantity(const string &ID);

#endif