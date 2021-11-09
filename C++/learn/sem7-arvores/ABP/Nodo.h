#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Aluno.h"
#include "ListaNodo.h"

using namespace std;

class Nodo
{

public:
    Nodo *filhoEsquerda = NULL;
    Nodo *filhoDireita = NULL;
    Aluno aluno;
    Nodo()
    {
    }
    Nodo(const Aluno &novoAluno)
    {
        aluno = novoAluno;
    }
    void preOrdem() const
    {
        aluno.imprime();
        cout << endl;
        if (filhoEsquerda)
            filhoEsquerda->preOrdem();
        if (filhoDireita)
            filhoDireita->preOrdem();
    }
    void posOrdem()
    {

        if (filhoEsquerda)
            filhoEsquerda->posOrdem();

        if (filhoDireita)
            filhoDireita->posOrdem();

        aluno.imprime();
        cout << endl;
    }

    ~Nodo() {}
};

#endif
