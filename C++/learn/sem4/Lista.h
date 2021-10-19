
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
            // deslocando todos Alunos de posicao em diante -- direita -> esquerda é melhor
            for (int i = tamanho; i > posicao; i--)
            {
                alunos[i] = alunos[i - 1];
            }

            alunos[posicao] = aluno;
            tamanho++;
        }
    }

    /*  retorna -1 caso nao encontre */
    int busca(unsigned chave)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (alunos[i].chave == chave)
            {
                return i;
            }
        }
        cout << " Chave nao encontrada: erro:";
        return -1;
    }
    int deletar(unsigned chave)
    {
        int posicao = busca(chave);
        if (posicao >= 0)
        {
            tamanho--;
            for (unsigned i = posicao; i < tamanho; i++)
            {
                alunos[i] = alunos[i + 1];
            }
            cout << "Removido com sucesso.Chave removida:" << chave << endl;
            return 1;
        }
        else
        {
            cout << "Chave do Aluno nao encontrado\n";
            return -1;
        }
    }
    ~Lista(){};
};
#endif