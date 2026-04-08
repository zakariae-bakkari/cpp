//
// Created by admin on 01-Apr-26.
//

#ifndef CPP_MYSTRING_H
#define CPP_MYSTRING_H

class Mystring {
private:
    int m_length;

    char *m_ptr;

public:
    Mystring();

    Mystring(char *c);

    Mystring(const Mystring &s);

    ~Mystring();

    Mystring &operator=(const Mystring &s);

    int operator==(const Mystring &s) const;

    Mystring operator+(const Mystring &s) const;

    char &operator[](int n) const;

    void print() const;

    int getlength() const;
};
#endif //CPP_MYSTRING_H
