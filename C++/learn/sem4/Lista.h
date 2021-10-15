
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
    int verificaLimiteIntervalo(unsigned posicao, unsigned tamanho)
    {
        if (posicao > tamanho)
        {
            cout << "posicao > que tamanho permitido" << endl;
            return 0;
        }
        if (MAX_ALUN == tamanho)
        {
            cout << "Lista cheia" << endl;
            return 0;
        }
        return 1;
    }
    void insere(unsigned posicao, const Aluno &aluno)
    {
        if (verificaLimiteIntervalo(posicao, tamanho))
        {
            // des locandotodos Alunos de posicao em diante
            for (int i = tamanho; i > posicao; i--)
            {
                alunos[i] = alunos[i - 1];
            }

            alunos[posicao] = aluno;
            tamanho++;
        }
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