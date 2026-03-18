//
// Created by admin on 17-Feb-26.
//
class A {
public:
    int value;
    A() : value(10){};
};

class B : public A {
};

class C : public A {
};

class D : public B, public C {
};

int main() {
    D obj;

    obj.value = 5;   // ❌ ERREUR DE COMPILATION
    return 0;
}