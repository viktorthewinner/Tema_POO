#include "Produs.h"

/// tipul datei; numele clasei :: numele functiei si parametrii (amprenta)

/// acolo unde am const, initializarea lui se face declarand-ul
Produs::Produs() : id(0)
{
    /// id nu merge pt ca e de tip const => initializat la declarare
    this->cantitate = 0;
    denumire = nullptr;
    this->pret = 0;
}

Produs::Produs(const int &id, const char *denumire, const int &cantitate, const float &pret) : id(id)
{
    if (this->denumire != nullptr)
        delete[] this->denumire;

    this->denumire = new char[strlen(denumire) + 1];  // Corrected: +1 outside of strlen
    strcpy(this->denumire, denumire);

    this->cantitate = cantitate;
    this->pret = pret;
}


Produs::Produs(const Produs &produs) : id(produs.id) // id must be initialized with the copy's id
{
    if (this->denumire != nullptr)
        delete[] this->denumire;

    this->denumire = new char[strlen(produs.denumire) + 1]; // Corrected: strlen(produs.denumire) + 1
    strcpy(this->denumire, produs.denumire);

    this->cantitate = produs.cantitate;
    this->pret = produs.pret;
}


Produs &Produs::operator=(const Produs &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (this->denumire != nullptr)
    {
        delete[] this->denumire;
    }

    this->pret = other.pret;
    this->cantitate = other.cantitate;

    this->denumire = new char[strlen(other.denumire) + 1];
    strcpy(this->denumire, other.denumire);

    return *this;
}

Produs& Produs::operator--(int)
{
    this->cantitate--;

    return *this;
}

std::istream &operator>>(std::istream &in, Produs &produs)
{
    char w[50];
    in >> w;

    delete[] produs.denumire; /// ma asigur ca e curat
    produs.denumire = new char[strlen(w) + 1];
    strcpy(produs.denumire, w);

    in >> produs.pret >> produs.cantitate;

    return in;
}

std::ostream &operator<<(std::ostream &out, Produs &produs)
{
    out << produs.denumire << ": " << produs.cantitate << ", Pret: " << produs.pret;

    return out;
}

void Produs::setDenumire(const char *denumire)
{
    if (this->denumire != nullptr)
        delete[] this->denumire;

    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}

void Produs::setCantitate(const int &cantitate)
{
    this->cantitate=cantitate;
}

void Produs::setPret(const float &pret)
{
    this->pret=pret;
}

int Produs::getCantitate()const
{
    return cantitate;
}


char* Produs::getDenumire()const
{
    return denumire;
}

float Produs::getPret()const
{
    return pret;
}

Produs::~Produs()
{
    if (denumire != nullptr)
        delete[] denumire;
}
// implementare clasa Produs