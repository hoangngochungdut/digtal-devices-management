#ifndef PRODUCT_H
#define PRODUCT_H

#include "Category.h"
#include <string.h>
#include <iostream>
using namespace std;

class Product: public Category{
    protected: 
        string productID;
        string productName;
        string productBrand;
        int costPrice;
        int costTotal;
    public:
        void setProductID(const string &s) {this->productID = s;}
        void setProductBrand(const string &s) {this->productBrand = s;}
        void setProductName(const string &s) {this->productName = s;}
        void setCostPrice(int a) {this->costPrice = a;}

        string getProductID() {return this->productID;}
        string getProductName() {return this->productName;}
        string getProductBrand() {return this->productBrand;}
        int getCostPrice() {return this->costPrice;}
        
        void show() {
            cout << getProductID() << " - " << getProductName() << "\n";
        }
        
};


#endif