#include <iostream>
#include "Aluno.h"
using namespace std;
void foo()
{
    Aluno a1(2, "breno");
}

/* Cria um objeto do tipo aluno e retorna um ponteiro para sua posicão em memória */
Aluno *fooDin()
{
    Aluno *aluno1 = NULL;           // cria um ponteiro para um aluno
    aluno1 = new Aluno(4, "lucas"); //  instancia o objeto aluno1
    return aluno1;                  // retorna o ponteiro;
}

int main()
{
    Aluno *alunomain = NULL;
    alunomain = fooDin();
    if (!alunomain) // caso falhe a alocação, aluno1 será = NULL
    {
        cout << "Erro:falta de memoria" << endl;
    }
    else
    {
        cout << alunomain->nome;
    }
    delete alunomain;
    cout <<"\n Depois de deletado aparece lixo : "<< alunomain->nome;
}