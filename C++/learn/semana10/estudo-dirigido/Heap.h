#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define MAX_CLI 20
using namespace std;
#include "Cliente.h"
#include <algorithm>
class Heap
{
public:
    Cliente fila_cli[MAX_CLI + 1]; // posicao 0 não será usada
    int total_cli = 0;

    Heap()
    {
    }
    void subir(int i)
    {
        int j;
        j = i / 2;
        if (j >= 1)
        {
            if (fila_cli[i].CPF > fila_cli[j].CPF)
            {
                swap(fila_cli[i], fila_cli[j]);
                subir(j);
            }
        }
    }
    void descer(int i)
    {
        int j;
        j = 2 * i;
        if (j <= total_cli)
        {
            if (j < total_cli)
            {
                if (fila_cli[j + 1].CPF > fila_cli[j].CPF)
                {
                    j++;
                }
            }
            if (fila_cli[i].CPF < fila_cli[j].CPF)
            {
                swap(fila_cli[i], fila_cli[j]);
                descer(j);
            }
        }
    }
    void inserir(const Cliente &cliente)
    {
        fila_cli[total_cli + 1] = cliente;
        total_cli++;
        subir(total_cli);
    }
    Cliente seleciona()
    {
        return fila_cli[1];
    }
    void remover()
    {
        fila_cli[1] = fila_cli[total_cli];
        total_cli--;
        descer(1);
    }
    void imprimir()
    {
        for (int i = 1; i <= total_cli; i++)
        {
            fila_cli[i].imprime();
        }
    }
};
#endif