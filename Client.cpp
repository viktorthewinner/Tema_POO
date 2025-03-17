#include "Client.h"

//implementare clasa Client

Client::Client() : comanda()
{
    this->nume=nullptr;
}

Client::Client(const char* nume, const Comanda &comanda)
{
    if(this->nume != nullptr)
        delete[] this->nume; // Corrected: delete this object's nume, not the parameter nume

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->comanda = comanda;
}


Client::Client(const Client &client)
{
    if(this->nume!=nullptr)
        delete[] nume;

    this->nume=new char[strlen(client.nume)+1];
    strcpy(this->nume,client.nume);

    this->comanda=client.comanda;
}

Client& Client::operator=(const Client &other)
{
    if(this==&other)
        return *this;

    if(this->nume!=nullptr)
        delete[] nume;

    this->nume=new char[strlen(other.nume)+1];
    strcpy(this->nume,other.nume);

    this->comanda=other.comanda;

return *this;
}

 std::istream &operator>>(std::istream &in, Client &client)
 {
    char v[60];
    char x[5];
    in.getline(x,5);

    ///citeste o linie, se opreste cand se termina linia
    ///daca e mai lunga linia atunci la 60 de caractere
    in.getline(v,60);

    if(client.nume!=nullptr)
        delete[] client.nume;
    
    client.nume=new char[strlen(v)+1];
    strcpy(client.nume,v);

    in>>client.comanda;

    return in;
 }


 std::ostream &operator<<(std::ostream &out, Client &client)
 {
        out<<"Nume: "<<client.nume<<std::endl;
        out<<"Comanda ID: "<<client.comanda.getId()<<std::endl;
        out<<client.comanda;

        return out;
 } 
    
Comanda Client::getComanda()const
{
    return comanda;
}

void Client::setarePret(const char* denumire, const float& pret)
{
    Produs* produse=comanda.getProduse();
    int nrProduse=comanda.getNrProduse();

    for(int i=0;i<nrProduse;i++)
    {
        if(strcmp(produse[i].getDenumire(),denumire)==0)
        {
            produse[i].setPret(pret);
        }
    }
}

void Client::setComId(const int &id)
{
    comanda.setId(id);
}


Client::~Client()
{
    if(nume != nullptr) {
        delete[] nume;
        nume = nullptr; // Optional: set to nullptr to prevent dangling pointer
    }
}
