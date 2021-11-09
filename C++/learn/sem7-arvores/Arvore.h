#ifndef LISTANODO_H_INCLUDED
#define LISTANODO_H_INCLUDED

#include "Nodo.h"
using namespace std;

class Arvore
{

public:
    Nodo *raiz;
    Arvore() {}
    void preOrdem()
    {
        if (raiz)
        {
            raiz->preOrdem(); // invoca o método da classe superior (Nodo::preOrdem)
            cout << endl;
        }
    }
    ~Arvore() {}
};

#endif