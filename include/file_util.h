#ifndef FILE_UTIL_H
#define FILE_UTIL_H
#include "Category.h"
#include "Brand.h"
#include "Product.h"
#include "Item.h"
#include "LinkList.h"

//chua sua lai
int getQuantity(const string &ID);
void updateAfterSell(vector <Item> &x);
void updateAfterImport(vector <Item> &x);
bool existedID(const string &ID);
bool existedName(const string &name);
bool matchedNameID(const string &name, const string &ID);
void updateNewProduct(Product x);
int getSellPrice(const string &ID);
string getCategoryID(const string &category);

bool existedCategoryID(const string &ID);
bool existedCategoryName(const string &name);
void updateCategoryList(const LinkList<Category>& categories);

bool existedBrandID(const string &ID);
bool existedBrandName(const string &name);
void updateBrandList(const LinkList<Brand>& brands);

bool existedProductID(const string &ID);
bool existedProductName(const string &name);
void updateProductList(const LinkList<Product>& products);

#endif