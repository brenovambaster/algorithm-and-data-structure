#include <iostream>

#include "Pilha.h"

using namespace std;

int main()
{

    Aluno a1, a2;
    Pilha pilha1;
    a1.nome = "Breno";
    a2.nome = "Marina";
    a1.notas[0] = 10;
    a2.notas[0] = 1;
    a1.notas[1] = 1;
    a1.notas[2] = 12;
    pilha1.Push(a1);
    pilha1.Push(a2);
    pilha1.imprime();
    /* cout << "nota p1 "<<a1.nome <<" e "<< a1.notas[0]<< endl; */
    /* cout << "Situacao do aluno: media"<< a1.media() <<"aprovado? "<<a1.passou() ; */
    return 0;
}
