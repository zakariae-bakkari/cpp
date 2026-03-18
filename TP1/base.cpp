//
// Created by admin on 11-Feb-26.
//

#include "base.h"
#include <iostream>
using namespace std;
base::base(int db):m_b(db) {
    cout << "constructor" << endl;
    cout << "classe de base " << endl;
    cout << "valeur : " << m_b << endl;
}
base::~base() {
    cout << "destructor" << endl;
    cout << "classe de base " << endl;
}

derive::derive(int db, int dd):base(db), m_d(dd) {
    cout << "constructor" << endl;
    cout << "classe derive " << endl;
    cout << "valeur : " << m_d << endl;
}
derive::~derive() {
    cout << "destructor" << endl;
    cout << "classe derive " << endl;
}

