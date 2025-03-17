#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>

class Produs {
    const int id;           // Cod unic al produsului
    char *denumire;      // Denumirea produsului (șir de caractere)
    float pret;             // Prețul produsului
    int cantitate;          // Cantitatea pe stoc a produsului

public:
    Produs();
    Produs(const int & id,const char* denumire, const int & cantitate, const float & pret);
    Produs(const Produs &produs);

    Produs& operator=(const Produs &);
    Produs& operator--(int);


///fiind friend programul are "incredere"
    friend std::istream &operator>>(std::istream &in, Produs &produs);
    friend std::ostream &operator<<(std::ostream &out, Produs &produs);

    void setDenumire(const char*);
    void setCantitate(const int &);
    void setPret(const float &);

    int getCantitate() const;
    char* getDenumire() const;
    float getPret() const;

    ~Produs();
    // TODO: de implementat
};

#endif
