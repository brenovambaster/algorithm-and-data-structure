#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "Aluno.h"
#include "Nodo.h"

using namespace std;

class ListaEncadeada
{

public:
    Nodo *inicio;
    int tamanho = 0;
    ListaEncadeada()
    {
        inicio = NULL;
        tamanho = 0;
    }
    ~ListaEncadeada()
    {
        /* temos que desalocar explicitamente toda memória que alocamos no heap. */
    }
    void imprime() const
    {
        Nodo *novoNodo = inicio;
        while (novoNodo)
        {
            cout << novoNodo->aluno.chave << "-" << novoNodo->aluno.nome << ",";
            novoNodo = novoNodo->proximo;
        }
        cout << endl;
    }
    void insere(int posicao, const Aluno &aluno)
    {
        Nodo *novoNodo = new Nodo(aluno);
        Nodo *nodoAnterior = inicio;
        if (posicao == 0)
        {
            novoNodo->proximo = inicio;
            inicio = novoNodo;
            tamanho++;
            return;
        }
        if (posicao > tamanho)
        {
            cout << "Posicao invalida";
            return;
        }
        for (int i = 0; i < posicao - 1; i++)
        {
            if (!nodoAnterior->proximo)
            {
                cout << "Posicao invalida" << endl;
                return;
            }
            nodoAnterior = nodoAnterior->proximo;
        }
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        tamanho++;
    }
};

#endif