#include <iostream>

#include "Aluno.h"
#include "Lista.h"

using namespace std;

int main()
{
    Aluno aluno1(42, "Btrn");
    Aluno aluno2(40, "lucas");
    Aluno aluno3(39, "Maria");
    Aluno aluno4(391, "asdwq");
    Lista lista1;

    lista1.insere(0, aluno1);
    lista1.insere(1, aluno2);
    lista1.insere(2, aluno3);
    lista1.insere(1, aluno4);
    lista1.imprime();
    lista1.deletar(40);
    lista1.imprime();
    cout
        << "\nindice: " << lista1.busca(40) << endl;

    return 0;
}
