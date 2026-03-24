/*
 * ============================================================
 *  heritage_visibilite.cpp
 *  Démonstration complète des 3 modes d'héritage en C++
 *  Compile : g++ -std=c++17 heritage_visibilite.cpp -o demo
 * ============================================================
 */

#include <iostream>
#include <string>

// ============================================================
//  CLASSE DE BASE
// ============================================================
class Base {
public:
    int pub;        // accessible partout

protected:
    int prot;       // accessible dans Base et ses dérivées

private:
    int priv;       // accessible UNIQUEMENT dans Base

public:
    Base(int a, int b, int c) : pub(a), prot(b), priv(c) {}

    void afficher_base() const {
        // Ici on est DANS Base → les 3 membres sont accessibles
        std::cout << "  [Base] pub="  << pub
                  << "  prot=" << prot
                  << "  priv=" << priv << "\n";
    }

    // Accesseur public pour exposer priv à l'extérieur
    int get_priv() const { return priv; }
};

// ============================================================
//  1) HÉRITAGE PUBLIC  (: public Base)
//     pub   → public     (identique)
//     prot  → protected  (identique)
//     priv  → inaccessible depuis Derive, mais toujours présent
// ============================================================
class DerivePublic : public Base {
public:
    DerivePublic(int a, int b, int c) : Base(a, b, c) {}

    void acceder() const {
        std::cout << "  [DerivePublic::acceder]\n";
        std::cout << "    pub  accessible : " << pub  << "\n";   // OK public
        std::cout << "    prot accessible : " << prot << "\n";   // OK protected
        // priv inaccessible directement → on passe par get_priv()
        std::cout << "    priv via getter : " << get_priv() << "\n";
        // std::cout << priv; // ❌ erreur de compilation
    }
};

// ============================================================
//  2) HÉRITAGE PROTECTED  (: protected Base)
//     pub   → protected  (abaissé)
//     prot  → protected  (identique)
//     priv  → inaccessible depuis Derive
// ============================================================
class DeriveProtected : protected Base {
public:
    DeriveProtected(int a, int b, int c) : Base(a, b, c) {}

    void acceder() const {
        std::cout << "  [DeriveProtected::acceder]\n";
        std::cout << "    pub  accessible : " << pub  << "\n";   // OK (est devenu protected)
        std::cout << "    prot accessible : " << prot << "\n";   // OK protected
        std::cout << "    priv via getter : " << get_priv() << "\n";
        // std::cout << priv; // ❌ erreur de compilation
    }

    // Expose une valeur au monde extérieur via wrapper
    int lire_pub() const { return pub; }
};

// Sous-classe de DeriveProtected :
// pub et prot de Base sont ici protected → encore accessibles
class SousDeriveProtected : public DeriveProtected {
public:
    SousDeriveProtected(int a, int b, int c) : DeriveProtected(a, b, c) {}

    void acceder() const {
        std::cout << "  [SousDeriveProtected::acceder]\n";
        std::cout << "    pub  encore accessible : " << pub  << "\n"; // OK (protected hérité)
        std::cout << "    prot encore accessible : " << prot << "\n"; // OK protected
    }
};

// ============================================================
//  3) HÉRITAGE PRIVATE  (: private Base)
//     pub   → private  (abaissé au max)
//     prot  → private  (abaissé)
//     priv  → inaccessible depuis Derive
// ============================================================
class DerivePrivate : private Base {
public:
    DerivePrivate(int a, int b, int c) : Base(a, b, c) {}

    void acceder() const {
        std::cout << "  [DerivePrivate::acceder]\n";
        std::cout << "    pub  accessible : " << pub  << "\n";   // OK (est devenu private)
        std::cout << "    prot accessible : " << prot << "\n";   // OK (est devenu private)
        std::cout << "    priv via getter : " << get_priv() << "\n";
        // std::cout << priv; // ❌ erreur de compilation
    }

    // Wrapper nécessaire pour exposer quoi que ce soit
    int lire_pub() const { return pub; }
};

// Tentative de sous-dérivation depuis DerivePrivate :
// pub et prot de Base sont ICI private → inaccessibles dans SousDerivePrivate
class SousDerivePrivate : public DerivePrivate {
public:
    SousDerivePrivate(int a, int b, int c) : DerivePrivate(a, b, c) {}

    void acceder() const {
        std::cout << "  [SousDerivePrivate::acceder]\n";
        // std::cout << pub;  // ❌ 'pub' est private dans DerivePrivate
        // std::cout << prot; // ❌ 'prot' est private dans DerivePrivate
        // std::cout << priv; // ❌ 'priv' est private dans Base, et inaccessible dans DerivePrivate
        // Seuls les wrappers publics de DerivePrivate sont utilisables
        std::cout << "    pub via wrapper : " << lire_pub() << "\n"; // OK via wrapper public
    }
};

// ============================================================
//  ACCÈS DEPUIS L'EXTÉRIEUR (hors hiérarchie)
// ============================================================
void tester_acces_externe() {
    std::cout << "\n===== ACCÈS DEPUIS L'EXTÉRIEUR =====\n";

    Base b(10, 20, 30);
    std::cout << "[Base] b.pub = " << b.pub << "\n";          // OK public
    // std::cout << b.prot; // ❌ protected inaccessible
    // std::cout << b.priv; // ❌ private inaccessible
    std::cout << "[Base] b.get_priv() = " << b.get_priv() << "\n"; // OK via getter

    DerivePublic dp(1, 2, 3);
    std::cout << "\n[DerivePublic] dp.pub = " << dp.pub << "\n";    // OK : pub est encore public
    // std::cout << dp.prot; // ❌ protected depuis l'extérieur
    // std::cout << dp.priv; // ❌ inaccessible

    DeriveProtected dprot(4, 5, 6);
    // std::cout << dprot.pub; // ❌ pub est devenu protected → inaccessible depuis l'extérieur
    std::cout << "\n[DeriveProtected] dprot.lire_pub() = " << dprot.lire_pub() << "\n"; // OK via wrapper

    DerivePrivate dpriv(7, 8, 9);
    // std::cout << dpriv.pub; // ❌ pub est devenu private → inaccessible
    std::cout << "\n[DerivePrivate] dpriv.lire_pub() = " << dpriv.lire_pub() << "\n"; // OK via wrapper
}

// ============================================================
//  POLYMORPHISME — fonctionne uniquement avec : public
// ============================================================
void polymorphisme(Base* ptr) {
    ptr->afficher_base();
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "╔══════════════════════════════════════════════╗\n";
    std::cout << "║   Démonstration héritage C++ — visibilité   ║\n";
    std::cout << "╚══════════════════════════════════════════════╝\n";

    // --- Accès depuis les méthodes internes ---
    std::cout << "\n===== ACCÈS INTERNE (méthodes de la dérivée) =====\n";

    std::cout << "\n-- : public Base --\n";
    DerivePublic dp(1, 2, 3);
    dp.acceder();

    std::cout << "\n-- : protected Base --\n";
    DeriveProtected dprot(4, 5, 6);
    dprot.acceder();

    std::cout << "\n-- sous-classe de DeriveProtected --\n";
    SousDeriveProtected sdp(7, 8, 9);
    sdp.acceder();  // pub/prot encore accessibles (ils sont protected)

    std::cout << "\n-- : private Base --\n";
    DerivePrivate dpriv(10, 11, 12);
    dpriv.acceder();

    std::cout << "\n-- sous-classe de DerivePrivate --\n";
    SousDerivePrivate sdpriv(13, 14, 15);
    sdpriv.acceder();  // pub/prot inaccessibles, seul le wrapper fonctionne

    // --- Accès depuis l'extérieur ---
    tester_acces_externe();

    // --- Polymorphisme ---
    std::cout << "\n===== POLYMORPHISME (Base*) =====\n";
    DerivePublic dp2(100, 200, 300);
    polymorphisme(&dp2);   // ✅ OK : public → IS-A relation préservée

    // DeriveProtected dprot2(1,2,3);
    // polymorphisme(&dprot2); // ❌ : protected casse la relation IS-A vers l'extérieur

    // DerivePrivate dpriv2(1,2,3);
    // polymorphisme(&dpriv2); // ❌ : private casse la relation IS-A vers l'extérieur

    std::cout << "\n===== RÉSUMÉ =====\n";
    std::cout << "  : public    → IS-A, polymorphisme OK, interface publique préservée\n";
    std::cout << "  : protected → interface cachée à l'extérieur, sous-héritage encore possible\n";
    std::cout << "  : private   → implémentation privée, bloque tout sous-héritage ultérieur\n";

    return 0;
}