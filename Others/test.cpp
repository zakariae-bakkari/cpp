//
// Created by admin on 31-Dec-25.
//

#include <iostream>
#include "h1.h"
#include "h2.h"

using namespace h2;
using namespace std;
int g() {
    cout << f() << endl;
    return 5+ h1::f();
}

int main() {
    cout << g() << endl;
    return 0;
}