#include <iostream>
#include "Aluno.h"
#include "Nodo.h"
#include "ListaEncadeada.h"
using namespace std;

int main()
{
    Aluno *aluno_procucarado;
    Aluno a(1, "breno");
    Aluno b(2, "luc");
    Aluno c(4, "livia");
    ListaEncadeada lista;
    lista.insere(0, a);
    lista.insere(1, b);
    lista.insere(2, c);
    lista.imprime();
    aluno_procucarado = lista.busca(5);
    if (aluno_procucarado)
    {
        cout << "Aluno procurado encontrado:  nome:" << aluno_procucarado->nome << " chave: " << aluno_procucarado->chave;
    }
    else
    {
        cout << "Aluno procurado não foi encontrado\n";
    }
    lista.remover(1);
    lista.imprime();
}