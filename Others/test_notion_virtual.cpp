#include <iostream>

class animal {
public:
    virtual void parler() const {
        std::cout << "Je suis un animal" << std::endl;
    }

    virtual void manger() const = 0;/// pure virtual -> class abstrait

    virtual ~animal() {} // bonne pratique
};

class chien : public animal {
public:
    void parler() const override {
        animal::parler(); // Appel de la version de la classe de base
        std::cout << "Je suis un chien" << std::endl;
    }

    void manger() const override {
        std::cout << "Le chien mange de la viande" << std::endl;
    }
};

int main() {
    animal* a = new chien();  // polymorphisme réel

    a->parler();  // "Je suis un chien"
    a->manger();  // "Le chien mange de la viande"

    delete a;
    return 0;
}