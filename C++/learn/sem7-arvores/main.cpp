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

    Nodo n1(a);
    Nodo n2(b);
    Nodo n3(c);
    Nodo n4(d);
    Nodo n5(e);
}