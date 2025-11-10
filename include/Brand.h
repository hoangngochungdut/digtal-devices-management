#ifndef BRAND_H
#define BRAND_H
#include <string>
using namespace std;
class Brand{
    
    string brandID;
    string brandName;
    public:
        string getBrandID() {return brandID;};
        string getBrandName() {return brandName;};

        void setBrandID(const string &ID) {this->brandID = ID;}
        void setBrandName(const string &name) {this->brandName = name;}
        
        void show() {
            cout << getBrandID() << " - " << getBrandName() << "\n";
        }
};

#endif