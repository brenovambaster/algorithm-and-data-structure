
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

    void insere(unsigned posicao, Aluno &aluno)
    {
        if (posicao > tamanho)
        {
            cout << "posicao > que tamanho permitido" << endl;
        }
        if (MAX_ALUN == tamanho)
        {
            cout << "Lista cheia" << endl;
        }
        // de sl oc a n d o t o d o s Alunos de p o s i c a o em d i a n t e
        for (int i = tamanho; i > posicao; i--)
        {
            alunos[i] = alunos[i - 1];
        }
        alunos[posicao] = aluno;
        tamanho++;
    }
    ~Lista(){};
};
#endif