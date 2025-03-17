#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"

class Comanda {
protected:
    int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:

    Comanda();
    Comanda(const int &,const int &,const int &,const int &,const int &,const Produs*);
    Comanda(const Comanda&);

    Comanda& operator=(const Comanda&);

    friend std::istream &operator>>(std::istream &in, Comanda &comanda);
    friend std::ostream &operator<<(std::ostream &out, Comanda &comanda); 
    
    int getId()const;
int getNrProduse()const;
Produs* getProduse()const;

void setId(const int &);

    ~Comanda();
    // TODO: de implementat
};

#endif
