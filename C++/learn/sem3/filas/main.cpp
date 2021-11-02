#include <iostream>
#include "Fila.h"

using namespace std;

int main()
{

    Aluno a1, a2, a3, a4;
    Fila fila1;
    a1.nome = "Breno";
    a2.nome = "Marina";
    a3.nome = "Lucas";
    a4.nome = "Mario";
    a1.notas[0] = 10;
    a4.notas[0] = 4;
    a3.notas[0] = 5;
    a2.notas[0] = 1;
    a1.notas[1] = 1;
    a1.notas[2] = 12;
    fila1.insere(a1);
    fila1.imprime();
    cout << "------------------\n";
    fila1.insere(a2);
    fila1.imprime();
    cout << "------------------\n";
    fila1.insere(a3);
    fila1.imprime();
    cout << "------------------\n";
    fila1.insere(a4);
    fila1.imprime();
    cout << "------------------\n";
    cout << "removeu: " << fila1.remove().nome << endl;
    cout << "removeu: " << fila1.remove().nome << endl;
    fila1.imprime();
    cout << "------------------\n";
    /* cout << "nota p1 "<<a1.nome <<" e "<< a1.notas[0]<< endl; */
    /* cout << "Situacao do aluno: media"<< a1.media() <<"aprovado? "<<a1.passou() ; */
    return 0;
}