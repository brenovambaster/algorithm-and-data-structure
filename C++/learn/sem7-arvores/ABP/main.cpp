#include <iostream>
#include "Aluno.h"
#include "Arvore.h"
#include "ListaNodo.h"
#include "Nodo.h"
using namespace std;
int main()
{
    Aluno a(1, "a");
    Aluno b(2, "b");
    Aluno c(3, "c");
    Aluno d(4, "d");
    Aluno e(5, "e");

    Arvore av1;
    av1.insere(a);
    av1.insere(c);
    av1.insere(b);
    av1.insere(e);
    av1.insere(d);
    av1.preOrdem();
    av1.posOrdem();
}