#include "string_util.h"
#include <cctype> //c character type: toupper()
string upper(string s) {
    string temp = s;
    for (char &c : temp) c = toupper(c);
    return temp;
}

string capitalize(string s) {
    if(s.empty()) return s;
    string temp = s;
    for (char &c: temp) c = tolower(c);
    temp[0] = toupper(temp[0]);
    return temp;
}
