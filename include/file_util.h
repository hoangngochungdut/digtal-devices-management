#ifndef FILE_UTIL_H
#define FILE_UTIL_H
#include "Product.h"
#include "Item.h"

int getQuantity(const string &ID);
void updateAfterSell(vector <Item> &x);
void updateAfterImport(vector <Item> &x);
bool existedID(const string &ID);
bool existedName(const string &name);
bool matchedNameID(const string &name, const string &ID);
void updateNewProduct(Product x);
int getSellPrice(const string &ID);\
string getCategoryID(const string &category);

#endif