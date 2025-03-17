#include "Comanda.h"

Comanda::Comanda()
{
    this->id = 0;
    this->zi = 0;
    this->luna = 0;
    this->an = 0;
    this->nrProduse = 0;
    this->produse = nullptr;
}

Comanda::Comanda(const int &id, const int &zi, const int &luna, const int &an, const int &nrProduse, const Produs *produse)
{
    this->id = id;
    this->zi = zi;
    this->luna = luna;
    this->an = an;
    this->nrProduse = nrProduse;

    this->produse = new Produs[nrProduse];
    for (int i = 0; i < nrProduse; i++)
        this->produse[i] = produse[i];

    /// vedem ce punem
}

Comanda::Comanda(const Comanda &comanda)
{
    this->id = comanda.id;
    this->zi = comanda.zi;
    this->luna = comanda.luna;
    this->an = comanda.an;
    this->nrProduse = comanda.nrProduse;

    this->produse = new Produs[comanda.nrProduse];
    for (int i = 0; i < comanda.nrProduse; i++)
        this->produse[i] = comanda.produse[i];
}


Comanda &Comanda::operator=(const Comanda &other)
{
    if (this == &other)
        return *this;

    if (this->produse != nullptr) {
        delete[] this->produse;
        this->produse = nullptr;
    }

    this->id = other.id;
    this->zi = other.zi;
    this->luna = other.luna;
    this->an = other.an;
    this->nrProduse = other.nrProduse;

    this->produse = new Produs[other.nrProduse];
    for (int i = 0; i < other.nrProduse; i++)
        this->produse[i] = other.produse[i];

    return *this;
}


std::istream &operator>>(std::istream &in, Comanda &comanda)
{
    in >> comanda.zi >> comanda.luna >> comanda.an >> comanda.nrProduse;

    if (comanda.produse != nullptr)
        delete[] comanda.produse;

    comanda.produse = new Produs[comanda.nrProduse];
    for (int i = 0; i < comanda.nrProduse; i++)
    {        
        char v[50];
        in>>v;
        comanda.produse[i].setDenumire(v);
        
        int a;
        in>>a;
        comanda.produse[i].setCantitate(a);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, Comanda &comanda)
{
    out<<"Data comenzii: "<<comanda.zi<<"/"<<comanda.luna<<"/"<<comanda.an<<std::endl;
    out<<"Produse comandate:"<<std::endl;
    float total=0;
    for (int i = 0; i < comanda.nrProduse; i++)
    {
        out<<comanda.produse[i].getCantitate()<<" X ";
        out<<comanda.produse[i].getDenumire()<<" (";
        out<<comanda.produse[i].getPret()<<")"<<std::endl;
        total=total+comanda.produse[i].getCantitate()*comanda.produse[i].getPret();
    }
    out<<"Total comanda: "<<total<<" RON";

    return out;
}

int Comanda::getId() const
{
    return id;
}

int Comanda::getNrProduse()const
{
    return nrProduse;
}

Produs* Comanda::getProduse() const
{
    return nrProduse > 0 ? produse : nullptr; // Return nullptr if no products are available
}

void Comanda::setId(const int &id)
{
    this->id=id;
}

Comanda::~Comanda()
{
    if (produse != nullptr)
    {
        delete[] produse;
        produse = nullptr; // Optional: prevent dangling pointer
    }
}

// implementare clasa Comanda