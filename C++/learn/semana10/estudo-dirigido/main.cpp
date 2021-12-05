#include <iostream>
#include "Cliente.h"
#include "Heap.h"

using namespace std;

int main()
{
    Cliente c1(20, "c1");
    Cliente c2(80, "c2");
    Cliente c3(40, "c3");
    Cliente c4(50, "c4");
    Cliente c5(10, "c5");
    Cliente c6(25, "c6");
    Cliente c7(35, "c7");
    Cliente c8(60, "c8");
    Cliente c9(45, "c9");

    Heap h;

    h.inserir(c1);
    h.imprimir();
    cout << "----------------------------------------\n";
    cout << "\nInsere c2 a c9\n";
    h.inserir(c2);
    h.inserir(c3);
    h.inserir(c4);
    h.inserir(c5);
    h.inserir(c6);
    h.inserir(c7);
    h.inserir(c8);
    h.inserir(c9);
    cout << "Impirme tudo\n";
    h.imprimir();
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "\nRemove: \n";
    h.remover();
    cout << "\nimprime: \n";
    h.imprimir();
    cout << "\nRemove: \n";
    h.remover();
    cout << "\nRemove: \n";
    h.remover();
    cout << "\nRemove: \n";
    h.remover();
    cout << "\nimprime: \n";
    h.imprimir();
}