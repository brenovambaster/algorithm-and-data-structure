#include <iostream>

#include "Aluno.h"
#include "Lista.h"

using namespace std;

int main()
{
    Aluno aluno1(42, "Btrn");
    Aluno aluno2(40, "lucas");
    Aluno aluno3(39, "Maria");
    Lista lista1;
    lista1.insere(0,aluno1);
    lista1.insere(1,aluno2);
    lista1.insere(0,aluno3);
    lista1.imprime();

    return 0;
}
