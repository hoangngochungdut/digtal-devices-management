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
       
        void printCategories();
        void addNewCategory();
        void categoryOptions();

        void printBrands();
        void addNewBrand();
        void brandOptions();

        void printProducts();
        void addNewProduct();
        void productOptions();
        
};

void searchWithCategory();
void searchWithPrice();
void searchWithCategoryAndPrice();
#endif