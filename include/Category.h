#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <iostream>
using namespace std;

class Category {
    string categoryID;
    string categoryName;
    public:
        void setCategoryID(const string& ID) {this->categoryID = ID;}
        void setCategoryName(const string& name) {this->categoryName = name;}

        string getCategoryID() {return this->categoryID;}
        string getCategoryName() {return this->categoryName;}

        void show() {
            cout << getCategoryID() << " - " << getCategoryName() << "\n";
        }
};
#endif