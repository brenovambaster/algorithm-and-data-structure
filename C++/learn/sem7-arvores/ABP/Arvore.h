#ifndef LISTANODO_H_INCLUDED
#define LISTANODO_H_INCLUDED

#include "Nodo.h"
using namespace std;

class Arvore
{

public:
    Nodo *raiz = NULL;
    Arvore() {}
    void insere(const Aluno &aluno)
    {
        Nodo *novoNodo = new Nodo(aluno);
        Nodo *nodoAtual = raiz;
        if (!raiz)
        {
            raiz = novoNodo;
            return;
        }
        while (true)
        {
            if (nodoAtual->aluno.chave < aluno.chave) // ir para direita. (aluno > nodo-atual)
            {
                if (nodoAtual->filhoDireita) // ainda não chegamos
                    nodoAtual = nodoAtual->filhoDireita;
                else
                { // caso seja null, será uma folha. Aí podemos iserir novo nodo
                    nodoAtual->filhoDireita = novoNodo;
                    return;
                }
            }
            else
            { // esquerda do nodo atual

                if (nodoAtual->filhoEsquerda) // ainda nao chegamos
                    nodoAtual = nodoAtual->filhoEsquerda;
                else
                { //chegamos na  folha
                    nodoAtual->filhoEsquerda = novoNodo;
                    return;
                }
            }
        }
    }
    void preOrdem()
    {
        if (raiz)
        {
            raiz->preOrdem(); // invoca o método da classe superior (Nodo::preOrdem)
            cout << endl;
        }
    }
    void posOrdem() const
    {
        if (raiz)
            raiz->posOrdem();

        cout << endl;
    }
    void apaga(Nodo *nodePtr)
    {
        if (nodePtr->filhoEsquerda)
            apaga(nodePtr->filhoEsquerda);
        if (nodePtr->filhoDireita)
            apaga(nodePtr->filhoDireita);
        delete nodePtr;
    }
    ~Arvore()
    {
        if (raiz)
        {
            apaga(raiz);
        }
    }
};

#endif