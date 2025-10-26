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
    public:
        void enterInfo();
        void printInfo();
        
};
#endif