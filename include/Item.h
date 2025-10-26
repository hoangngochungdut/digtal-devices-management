#ifndef ITEM_H
#define ITEM_H
#include "Product.h"

class Item: public Product{
    int price;
    int warranty;
    int discount;
    int quantity;
    public: 
        void enterInfo();
        void printInfo();
};
#endif