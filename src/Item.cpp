#include "Product.h"
#include "Item.h"
#include "string_util.h"
#include <iostream>
#include <sstream> //string stream: 
#include <fstream> //file stream: 
#include <vector>
using namespace std;


bool haveSameID(Item a, Item b) {
    return (a.getID() == b.getID());
}

void subtract(Item &a, Item b) {   
    a.setQuantity(a.getQuantity() - b.getQuantity());
}

void plusInto(Item &a, Item b) {   
    a.setQuantity(a.getQuantity() + b.getQuantity());
}