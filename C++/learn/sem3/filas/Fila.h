#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define MAX_ALUNOS 4
#include "Aluno.h"
using namespace std;
class Fila
{

public:
    int topo, base, tamanho;
    Aluno alunos[MAX_ALUNOS];

    Fila(/* args */)
    {
        base = topo = MAX_ALUNOS - 1;
        tamanho = 0;
    }
    bool vazia()
    {
        return tamanho == 0;
    }
    void insere(const Aluno &aluno)
    {
        if (tamanho == MAX_ALUNOS)
        {
            cout << "Erro. Fila esta cheia \n";
            return;
        }
        tamanho++;
        topo++;
        topo = topo % MAX_ALUNOS;
        cout << "topo: " << topo << " base: " << base << endl;
        alunos[topo] = aluno;
    }
    Aluno remove()
    {
        if (vazia())
        {
            cout << "Fila está vazia\n";
            return Aluno();
        }
        tamanho--;
        base++;
        cout << "remover: topo: " << topo << "base:" << base << endl;
        base = base % MAX_ALUNOS;
        return alunos[base];
    }
    void imprime()
    {
        for (unsigned i = 0; i < MAX_ALUNOS; i++)
        {
            //cout << "base:" << base << "tam:" << tamanho << "topo:" << topo << endl;
            alunos[i].imprime();
        }
    }
    ~Fila() {}
};
#endif