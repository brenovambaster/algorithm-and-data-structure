#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX_ALUNOS 4
#include "Aluno.h"
using namespace std;
class Pilha
{
public:
    Aluno alunos[MAX_ALUNOS];
    unsigned topo = 0;
    Pilha()
    {
        topo = 0;
    }
    bool Vazia()
    {
        return topo ? 1 : 0;
    }
    void Push(const Aluno &aluno)
    {
        alunos[topo] = aluno;
        topo++;
    }
    void imprime()
    {
        for (unsigned i = 0; i < topo; i++)
        {
            alunos[i].imprime();
        }
    }
    Aluno pop()
    {
        topo--;
        return alunos[topo];
    }
    ~Pilha() {}
};
#endif