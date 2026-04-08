#include "headers/Mystring.h"
#include <cstring>
#include <iostream>
#include <ostream>

int main() {
    char *str = strdup("exemple");
    Mystring string(str);
    Mystring string2(strdup("test"));
    int len = string.getlength();
    std::cout << len << std::endl;
    std::cout << "string=";
    string.print();
    std::cout << "string2=";
    string2.print();

    Mystring conc = string + string2;
    if (string == conc) {
        std::cout << "egaux" << std::endl;
    }else {
        std::cout << "different" << std::endl;
    }
    string2=string;
    std::cout << "string2=";
    string2.print();

    std::cout << "string2[2]=" << string2[2] << std::endl;

}
