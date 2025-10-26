#ifndef CATEGORY_H
#define CATEGORY_H

#include <string.h>
#include <iostream>
using namespace std;

class Category {
    string categoryID;
    string categoryName;
    public:
        virtual ~Category () = 0; 
};
#endif