#include "../headers/Mystring.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

int Mystring::getlength() const {
    return m_length;
}

Mystring::Mystring() {
    m_length = 0;
    m_ptr = strdup("");
}

Mystring::Mystring(char *c) {
    m_length = strlen(c);
    m_ptr = strdup(c);
}

Mystring::Mystring(const Mystring &s) {
    m_length = s.m_length;
    m_ptr = strdup(s.m_ptr);
}

Mystring::~Mystring() {
    free(m_ptr);
}

Mystring Mystring::operator+(const Mystring &s) const {
    char *newPtr = new char[m_length + s.m_length + 1];
    strcpy(newPtr, m_ptr);
    strcat(newPtr, s.m_ptr);

    Mystring resultas(newPtr);
    delete[] newPtr;
    return resultas;
}

Mystring &Mystring::operator=(const Mystring &s) {
    if (this != &s) {
        free(m_ptr);
        m_ptr = strdup(s.m_ptr);
    }
    return *this;
}

int Mystring::operator==(const Mystring &s) const {
    if (m_length != s.m_length) {return 0;}
    if (strcmp(m_ptr, s.m_ptr) == 0) {return 1;}//egaux
}

char &Mystring::operator[](int n) const {
    return m_ptr[n];
}

void Mystring::print() const {
    std::cout << m_ptr << std::endl;
    // pas besoin d'une boucle
    // for (int i = 0; i < m_length; i++) {
    //     std::cout << m_ptr[i];
    // }
    // std::cout << std::endl;
}


