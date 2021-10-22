/* Aluno: Breno Vambáster Cardoso Lima */
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX_CLIENTE 20
using namespace std;

#include "Cliente.h"
#include <string>

class Lista
{
public:
    Cliente clientes[MAX_CLIENTE];
    unsigned tamanho;

    Lista()
    {
        tamanho = 0;
    }

    int insere(const Cliente &cliente)
    {
        unsigned melhor_posi = melhor_posicao(cliente.CPF);
        int existe_cpf_cadastrado = busca_binaria(cliente.CPF, 0, tamanho, 0);
        existe_cpf_cadastrado == -1 ? existe_cpf_cadastrado = 0 : existe_cpf_cadastrado = 1;

        if (cliente.CPF == 0)
        {
            cout << "Classe: Lista: erro> Chave 0 está reservada. Ela nao pode ser usada\n";
            return 0;
        }

        if (verifica_intervalo(melhor_posi, tamanho) && !existe_cpf_cadastrado)
        {
            for (unsigned i = tamanho; i > melhor_posi; i--)
            {
                clientes[i] = clientes[i - 1];
            }
            clientes[melhor_posi] = cliente;
            tamanho++;
            return 1;
        }
        else
        {
            cout << "Insersao na  falhou. Já existe o cpf: " << cliente.CPF << endl;
            cliente.~Cliente();
            return 0;
        }
    }
    /* Verifica se a lista não está cheia e se a posição que deseja inserir é válida  */
    int verifica_intervalo(unsigned posicao, unsigned tamanho)
    {
        if (posicao > tamanho)
        {
            cout << "posicao > que tamanho permitido" << endl;
            return 0;
        }
        if (MAX_CLIENTE == tamanho)
        {
            cout << "Lista cheia" << endl;
            return 0;
        }
        return 1;
    }
    /* 
     Caso 'querMelhorPosicao' seja TRUE, retornará a melhor posicao para inseir determinado CPF.
     Caso seja FALSE, retornará:  [-1 para CPF não encontrado ] OU o [índice  do array] em que se encontra o cliente procurado.  
    */
    int busca_binaria(int cpf, int inicio, int fim, bool querMelhorPoiscao)
    {
        int meio = (inicio + fim) / 2;
        if (fim - inicio <= 0)
        {
            return querMelhorPoiscao ? fim : -1;
        }
        if (clientes[meio].CPF == cpf)
            return meio;
        else if (clientes[meio].CPF < cpf)
        {
            return busca_binaria(cpf, meio + 1, fim, querMelhorPoiscao);
        }
        else
        {
            return busca_binaria(cpf, inicio, meio, querMelhorPoiscao);
        }
    }

    /* Faz merge dos elementos entre duas listas ( lista1 <-- lista2 )*/
    int junta(Lista &list1, const Lista &lista2)
    {
        int tamanhoDasListas = lista2.tamanho + tamanho;
        if (tamanho == 0 || lista2.tamanho == 0)
        {
            cout << "Alguma das Listas está vazia. Não há com o que juntar";
            return 0;
        }
        if (tamanhoDasListas > MAX_CLIENTE)
        {
            cout << "O tamanho das duas listas é superior ao máximo permitido [" << MAX_CLIENTE << "]\n";
            return 0;
        }
        else
        {
            for (unsigned i = 0; i < lista2.tamanho; i++)
            {
                list1.insere(lista2.clientes[i]);
            }
        }
    }

    /* Procura por determinado cliente usando o CPF */
    Cliente procura(unsigned cpf)
    {
        int resul = busca_binaria(cpf, 0, tamanho, 0);
        if (resul == -1)
        {
            Cliente vazio;
            return vazio;
        }
        return clientes[resul];
    }

    /* Retornará um número positivo contendo a melhor posicao para que seja inserido */
    int melhor_posicao(int cpf)
    {
        return busca_binaria(cpf, 0, tamanho, 1);
    }
    void imprime()
    {
        for (int i = 0; i < tamanho; i++)
        {
            cout << "indice: " << i;
            clientes[i].imprime();
        }
        cout << "\n";
    }
    ~Lista()
    {
    }
};

#endif
