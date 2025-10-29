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
    public:
        void setID(const string &s);
        void setName(const string &s);
        void setBrand(const string &s);
        void setCostPrice(int a);
        
        void update(); 
        void printInfo();
        
};

bool existedID(const string &ID);
bool existedName(const string &name);
bool matchedNameID(const string &name, const string &ID);

#endif