#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"

class Client {
private:
    char* nume;  // Numele clientului
    Comanda comanda; //comanda clientului

public:
    // TODO: de implementat

    Client();
    Client(const char*,const Comanda &);
    Client(const Client &);

    Client& operator=(const Client &);

friend std::istream &operator>>(std::istream &in, Client &client);
    friend std::ostream &operator<<(std::ostream &out, Client &client); 

    Comanda getComanda()const;

    void setarePret(const char*,const float &);
    void setComId(const int &);

    ~Client();
};

#endif
