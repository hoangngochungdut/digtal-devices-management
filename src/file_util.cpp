#include "file_util.h"
#include "string_util.h"
#include <iostream>
#include <cctype> //c character type: toupper()
#include <sstream> //string stream: 
#include <fstream> //file stream: 

bool existedID(const string &ID) {
        ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool existed = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _ID;
            getline(ss, _ID, ';');
            if (upper(ID) == upper(_ID)) {
                existed = true;
                in.close();
            }
        }
        in.close();
        return existed;
}

bool existedName(const string &name) {
        ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool existed = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(name) == upper(_name)) {
                existed = true;
                in.close();
            }
        }
        in.close();
        return existed;
}

bool matchedNameID(const string &name, const string &ID) {
    ifstream in;
        in.open("data/productList.txt", ios::in);

        string line;
        bool matched = false;
        while(getline(in, line)) {
            stringstream ss(line);
            string _name, _ID;
            getline(ss, _ID, ';');
            getline(ss, _name, ';');
            if (upper(name) == upper(_name) && upper(ID) == upper(_ID)) {
                matched = true;
                in.close();
            }
        }
        in.close();
        return matched;
}

void updateNewProduct(Product x) {
    ofstream out;
    out.open("data/productList.txt", ios::app);
    out << x.getID() << ";" << x.getName() << ";" << x.getBrand() << "\n";
    out.close();
}

int getQuantity(const string &ID) {
    if (ID == "") return -1;

    ifstream in("data/item.txt");

    string line, quant;
    while (getline(in, line)) {
        stringstream ss(line);
        string _ID, sellPrice;
        getline(ss, _ID, ';');
        getline(ss, sellPrice, ';');
        getline(ss, quant, ';');

        if (upper(ID) == upper(_ID)) {
            in.close();
            return stoi(quant);
        
        }
    }
    in.close();
    return -1;
}

int getSellPrice(const string &ID) {
    if (ID == "") return false;

    ifstream in("data/item.txt");

    string line, sellPrice;
    while (getline(in, line)) {
        stringstream ss(line);
        string _ID;
        getline(ss, _ID, ';');
        getline(ss, sellPrice, ';');

        if (upper(ID) == upper(_ID)) {
            in.close();
            return stoi(sellPrice);
        }
    }
    in.close();
    return -1;
}

void updateAfterSell(vector <Item> &x) {
    int n = 0;
    ifstream in("data/item.txt");
    string line;
    vector <string> lines;
   
    while (getline(in, line)) {
        lines.push_back(line);
        n++;
    }   
    in.close();

    //load trong file
    vector <Item> items(n);
    for (int i = 0; i < n; i++) {
        stringstream ss(lines[i]);
        string ID, sellPrice, quant;
        getline(ss, ID, ';');
        getline(ss, sellPrice, ';');
        getline(ss, quant, ';');

        items[i].setID(ID);
        items[i].setSellPrice(stoi(sellPrice));
        items[i].setQuantity(stoi(quant));
    }

    //cap nhat
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < n; j++) {
            if(haveSameID(x[i], items[j])) {
                subtract(items[j], x[i]);
            }
        }
    }

    // ghi lai vao file
    ofstream out("data/item.txt");
    for (int i = 0; i < n; i++) {
        out << items[i].getID() << ';'
            << items[i].getSellPrice() << ';'
            << items[i].getQuantity() << '\n';
    }
    out.close();

}

void updateAfterImport(vector <Item> &x) {
    int n = 0;
    ifstream in("data/item.txt");
    string line;
    vector <string> lines;
   
    while (getline(in, line)) {
        lines.push_back(line);
        n++;
    }   
    in.close();

    //load trong file
    vector <Item> items(n);
    for (int i = 0; i < n; i++) {
        stringstream ss(lines[i]);
        string ID, sellPrice, quant;
        getline(ss, ID, ';');
        getline(ss, sellPrice, ';');
        getline(ss, quant, ';');

        items[i].setID(ID);
        items[i].setSellPrice(stoi(sellPrice));
        items[i].setQuantity(stoi(quant));
    }

    vector<bool> isNew(x.size(), false);

    //cap nhat
    for (int i = 0; i < x.size(); i++) {
    bool found = false;
    for (int j = 0; j < n; j++) {
        if(haveSameID(x[i], items[j])) {
            plusInto(items[j], x[i]);
            found = true;
            break; // không cần kiểm tra tiếp
        }
    }
    isNew[i] = !found;
    }
    
    // ghi lai vao file
    ofstream out("data/item.txt");
    for (int i = 0; i < n; i++) {
        out << items[i].getID() << ';'
            << items[i].getSellPrice() << ';'
            << items[i].getQuantity() << '\n';
    }
    out.close();

    ofstream out2("data/item.txt", ios::app);
    for (int i = 0; i < x.size(); i++) {
        if(isNew[i]) {
            updateNewProduct(x[i]);
            out2 << x[i].getID() << ';'
            << x[i].getSellPrice() << ';'
            << x[i].getQuantity() << '\n';
        }
    }
    
    out2.close();
}

string getCategoryID(const string &category) {
    ifstream in;
    in.open("data/categoryList.txt");

    string line;
    while(getline(in, line)) {
    stringstream ss(line);
    string _ID, _category;
    getline(ss, _ID, ';');
    getline(ss, _category, ';');
    if (upper(category) == upper(_category)) {
        in.close();
        return _ID;     
        }
    }
    in.close();
    return "";
}


bool existedCategoryID(const string &ID) {
    ifstream in;
    in.open("data/categoryList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID;
        getline(ss, _ID, ';');
        if (upper(ID) == upper(_ID)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;
}

bool existedCategoryName(const string &name) {
    ifstream in;
    in.open("data/categoryList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID, _name;
        getline(ss, _ID, ';');
        if (upper(name) == upper(_name)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;   
}

void updateCategoryList(const LinkList<Category>& categories) {
    ofstream out;
    out.open("data/categoryList.txt", ios::app);
    Node<Category>* temp = categories.getHead();
    while(temp != nullptr) {
        out << (temp->data).getCategoryID() << ";" << (temp->data).getCategoryName() << "\n";
        temp = temp->next;
    }
    out.close();
}

bool existedBrandID(const string &ID) {
    ifstream in;
    in.open("data/brandList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID;
        getline(ss, _ID, ';');
        if (upper(ID) == upper(_ID)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;
}

bool existedBrandName(const string &name) {
    ifstream in;
    in.open("data/brandList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID, _name;
        getline(ss, _ID, ';');
        if (upper(name) == upper(_name)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;
}

void updateBrandList(const LinkList< Brand>& brands) {
    ofstream out;
    out.open("data/brandList.txt", ios::app);
    Node<Brand>* temp = brands.getHead();
    while(temp != nullptr) {
        out << (temp->data).getBrandID() << ";" << (temp->data).getBrandName() << "\n";
        temp = temp->next;
    }
    out.close();
}

bool existedProductID(const string &ID) {
    ifstream in;
    in.open("data/productList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID;
        getline(ss, _ID, ';');
        if (upper(ID) == upper(_ID)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;
}

bool existedProductName(const string &name) {
    ifstream in;
    in.open("data/productList.txt");
    string line;
    while(getline(in, line)) {
        stringstream ss(line);
        string _ID, _name;
        getline(ss, _ID, ';');
        if (upper(name) == upper(_name)) {
            in.close();
            return true;
        }    
    }
    in.close();
    return false;
}

void updateProductList(const LinkList<Product>& products) {
    ofstream out;
    out.open("data/productList.txt", ios::app);
    Node<Product>* temp = products.getHead();
    while(temp != nullptr) {
        out << (temp->data).getProductID() << ";" << (temp->data).geProductName() << "\n";
        temp = temp->next;
    }
    out.close();
}