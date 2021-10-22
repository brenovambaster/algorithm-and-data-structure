/* Aluno: Breno Vambáster Cardoso Lima */
#include <iostream>
#include "Cliente.h"
#include "Lista.h"

using namespace std;

int main()
{
    Cliente c1("a", 1);
    Cliente c2("b", 2);
    Cliente c3("c", 3);
    Cliente c4("d", 4);
    Cliente c5("e", 5);
    Cliente c6("f", 6);
    Cliente c7("g", 7);
    Cliente c8("h", 8);
    Cliente c9("i", 9);
    Lista ls1;
    Lista ls2;
    ls1.insere(c2);
    ls1.imprime();

    ls1.insere(c5);
    ls1.imprime();

    ls1.insere(c9);
    ls1.imprime();

    ls1.insere(c7);
    ls1.imprime();

    ls1.insere(c6);
    cout << "\t\t ##Lista 1##\n";
    ls1.imprime();
    cout << "---------------------------------------------------\n";
    cout << "\t\t -- Pesquisas--  \n";
    ls1.procura(2).imprime();
    ls1.procura(9).imprime();
    ls1.procura(5).imprime();
    ls1.procura(1).imprime();
    ls1.procura(8).imprime();
    ls1.procura(4).imprime();
    cout << "---------------------------------------------------\n";

    ls2.insere(c1);
    ls2.insere(c3);
    ls2.insere(c8);
    ls2.insere(c4);
    cout << "\t\t ##Lista 2##\n";
    ls2.imprime();
    cout << "---------------------------------------------------\n";
    ls1.junta(ls1, ls2);
    cout << "-----------MERGE LISTA 1 <-2 ----------------------\n";
    ls1.imprime();
}