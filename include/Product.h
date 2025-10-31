#ifndef PRODUCT_H
#define PRODUCT_H

#include "Category.h"
#include <string.h>
#include <iostream>
using namespace std;

class Product{
    protected: 
        string productID;
        string productName;
        string productBrand;
        int costPrice;
        int costTotal;
    public:
        void setID(const string &s) {this->productID = s;}
        string getID() {return this->productID;}

        void setName(const string &s) {this->productName = s;}
        string getName() {return this->productName;}

        void setBrand(const string &s) {this->productBrand = s;}
        string getBrand() {return this->productBrand;}

        void setCostPrice(int a) {this->costPrice = a;}
        int getCostPrice() {return this->costPrice;}
        
        void printInfo();
        
};


#endif