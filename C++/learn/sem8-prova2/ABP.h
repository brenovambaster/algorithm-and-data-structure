#ifndef ABP_H_INCLUDED
#define ABP_H_INCLUDED

#include "Nodo.h"
using namespace std;

class ABP
{
public:
    Nodo *raiz = NULL;
    ABP() {}
    void insere(const Aluno &aluno)
    {
        Nodo *novoNodo = new Nodo(aluno);
        Nodo *nodoAtual = raiz;
        if (!raiz)
        {
            raiz = novoNodo;
            raiz->pai = NULL;
            return;
        }
        while (true)
        {
            if (aluno.chave > nodoAtual->aluno.chave) // ir para direita. (aluno > nodo-atual)
            {
                if (nodoAtual->filhoDireita)
                { // ainda não chegamos
                    nodoAtual = nodoAtual->filhoDireita;
                }
                else
                { // caso seja null, será uma folha. Aí podemos iserir novo nodo
                    nodoAtual->filhoDireita = novoNodo;
                    novoNodo->pai = nodoAtual;
                    return;
                }
            }
            else // esquerda do nodo atual
            {
                if (nodoAtual->filhoEsquerda) // ainda nao chegamos
                    nodoAtual = nodoAtual->filhoEsquerda;
                else
                { //chegamos na  folha
                    nodoAtual->filhoEsquerda = novoNodo;
                    novoNodo->pai = nodoAtual;
                    return;
                }
            }
        }
    }
    Nodo *buscaNod(int chave)
    {
        Nodo *nodoAtual = raiz;
        while (nodoAtual)
        {
            if (nodoAtual->aluno.chave == chave)
            {
                return nodoAtual;
            }
            else if (nodoAtual->aluno.chave < chave)
            {
                nodoAtual = nodoAtual->filhoDireita;
            }
            else
            {
                nodoAtual = nodoAtual->filhoEsquerda;
            }
        }
        return NULL;
    }
    void imprimeAncestrais(Nodo *nodo)
    {
        // Apenas imprimir o pai do pai até chegar na raiz;
        while (nodo)
        {
            cout << endl;
            nodo->aluno.imprime();
            nodo = nodo->pai;
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
    ~ABP()
    {
        if (raiz)
        {
            apaga(raiz);
        }
    }
};

#endif