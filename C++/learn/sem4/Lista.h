
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX_ALUN 100

#include "Aluno.h"

using namespace std;
class Lista
{
public:
    Aluno alunos[MAX_ALUN];
    unsigned tamanho;

    Lista()
    {
        tamanho = 0;
    }

    void imprime()
    {
        for (int i = 0; i < tamanho; i++)
        {
            alunos[i].imprime(); // estamos invocando o método imprime da classe aluno
        }
    }
    void verificaLimiteIntervalo(unsigned posicao, unsigned tamanho)
    {
        if (posicao > tamanho)
        {
            cout << "posicao > que tamanho permitido" << endl;
            return;
        }
        if (MAX_ALUN == tamanho)
        {
            cout << "Lista cheia" << endl;
            return;
        }
    }
    void insere(unsigned posicao, Aluno &aluno)
    {
        verificaLimiteIntervalo(posicao, tamanho);
        // de sl oc a n d o t o d o s Alunos de p o s i c a o em d i a n t e
        for (int i = tamanho; i > posicao; i--)
        {
            alunos[i] = alunos[i - 1];
        }
        alunos[posicao] = aluno;
        tamanho++;
    }
    
    int busca(unsigned chave)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (alunos[i].chave == chave)
            {
                return i;
            }
        }
        return -1;
    }
    ~Lista(){};
};
#endif