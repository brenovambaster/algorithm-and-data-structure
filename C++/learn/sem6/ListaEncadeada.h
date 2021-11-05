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
        Nodo *prox;
        while (inicio)
        {
            prox = inicio->proximo;
            delete inicio;
            inicio = prox;
        }
    }
    void imprime() const
    {
        cout << "\n------Lista encadeada------\n";
        Nodo *novoNodo = inicio;
        while (novoNodo)
        {
            cout << novoNodo->aluno.chave << "-" << novoNodo->aluno.nome;
            novoNodo = novoNodo->proximo;
            cout << endl;
        }
        cout << "------FIM DA LISTA-------------\n";
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
            cout << "Posicao invalida\n";
            return;
        }
        for (int i = 0; i < posicao - 1; i++)
        {
            // não precisa desse if, pois já fazemso a checagem antes
            /* 
            if (!nodoAnterior->proximo)
            {
                cout << "Posicao invalida" << endl;
                return;
            } */
            nodoAnterior = nodoAnterior->proximo;
        }
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        tamanho++;
    }

    Aluno *busca(int chave)
    {
        Nodo *nodo1 = inicio;
        while (nodo1)
        {
            if (nodo1->aluno.chave == chave)
            {
                return &(nodo1->aluno);
            }
            nodo1 = nodo1->proximo;
        }
        return NULL;
    }

    void remover(int chave)
    {
        Nodo *nodoAtual = inicio;
        Nodo *prev = NULL;
        while (nodoAtual)
        {
            if (nodoAtual->aluno.chave == chave)
                break;
            prev = nodoAtual;
            nodoAtual = nodoAtual->proximo;
        }
        if (!nodoAtual)
            cout << "chave invalida";
        else
        {
            if (prev)
                prev->proximo = nodoAtual->proximo;
            else
                inicio = nodoAtual->proximo;
            delete nodoAtual;
            cout << "chave " << chave << " removida com sucesso";
        }
    }
};

#endif