#include <iostream>
#include <fstream>
#include "Comanda.h"
#include "Client.h"
#include "Produs.h"

int main(int argc, char *argv[])
{

    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    /// if pt fisier
    std::ifstream in_client(argv[2]);
    if (in_client.is_open() == false)
    {
        return 1;
    }

    std::ifstream in_produse(argv[1]);
    if (in_produse.is_open() == false)
    {
        return 1;
    }

    std::ofstream out_client("output_comenzi.txt");
    if (out_client.is_open() == false)
    {
        return 1;
    }

    std::ofstream out_produse("output_stoc_ramas.txt");
    if (out_produse.is_open() == false)
    {
        return 1;
    }

    /// citire comenzi
    int o = 0;
    in_client >> o;
    Client c[150];

    if (in_client.eof())
    {
        out_client << "Nu exista clienti in magazin.";
        o = 0;
    }

    for (int i = 0; i < o; i++)
    {
        in_client >> c[i];
        /// sa setez id pt comanda
        c[i].setComId(i);
    }

    /// citire stoc
    int k;
    in_produse >> k;
    Produs v[150];

    if (in_produse.eof())
    {
        k = 0;
    }
    out_produse << "Stoc ramas";

    for (int i = 0; i < k; i++)
    {
        in_produse >> v[i];
    }

    for (int i = 0; i < o; i++)
    {
        Comanda com = c[i].getComanda();
        Produs *pro = com.getProduse();

        for (int j = 0; j < com.getNrProduse(); j++)
        {
            bool ok = false;

            for (int l = 0; l < k && ok == false; l++)
            {
                if (strcmp(pro[j].getDenumire(), v[l].getDenumire()) == 0)
                {
                    /// setam pretul
                    c[i].setarePret(pro[j].getDenumire(), v[l].getPret());

                    for (int z = 0; z < pro[j].getCantitate(); z++)
                        v[l]--;

                    ok = true;
                }
            }
        }
    }

    if (0 < o)
    {
        out_client << c[0];
    }

    for (int i = 1; i < o; i++)
    {
        out_client << std::endl
                   << std::endl;
        out_client << c[i];
    }

    for (int i = 0; i < k; i++)
    {
        out_produse << std::endl;
        out_produse << i << ". " << v[i];
    }

    // TODO: nu scrieti cod functional aici, implementati clasele sau functii care sa rezolve
    //  pastrati main-ul cat mai curat si simplu de inteles

    in_client.close();
    in_produse.close();
    out_client.close();
    out_produse.close();
    return 0;
}