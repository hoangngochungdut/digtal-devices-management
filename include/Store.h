#ifndef STORE_H
#define STORE_H
#include "Category.h"
#include "Product.h"
#include "Item.h"

class Store{

    public:
        void import();
        void sell();
        void showStatictics();
        void search();
        void searchWithCategory();

        void printCategories();
        void addNewCategory();
        
        void printProducts();
        void addNewProduct();
        
};
#endif