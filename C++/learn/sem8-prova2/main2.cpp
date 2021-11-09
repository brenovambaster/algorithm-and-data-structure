#include <iostream>
#include "Aluno.h"
#include "ABP.h"
#include "Nodo.h"
using namespace std;

int main()
{

    Aluno a1(1, "al");
    Aluno a2(2, "a2");
    Aluno a3(3, "a3");
    Aluno a4(4, "a4");
    Aluno a5(5, "a5");
    Aluno a6(6, "a6");
    Aluno a7(7, "a7");
    Aluno a8(8, "a8");
    Aluno a9(9, "a9");
    Aluno a10(10, "a10");
    Aluno a11(11, "a11");
    Aluno a12(12, "a12");

    ABP tree;

    tree.insere(a8);
    tree.insere(a5);
    tree.insere(a3);
    tree.insere(a12);
    tree.insere(a9);
    tree.insere(a4);
    tree.insere(a11);
    tree.insere(a2);
    tree.insere(a6);
    tree.insere(a10);
    tree.insere(a1);
    tree.insere(a7);
    cout << "\nPre ordem\n";
    tree.preOrdem();
    cout << "\nImprime Ancestrais 10\n";
    tree.imprimeAncestrais(tree.buscaNod(10));
    cout << "\nImprime Ancestrais 1\n";
    tree.imprimeAncestrais(tree.buscaNod(1));

    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "\nRotaciona direita\n";
    tree.rotacionaDireita();
    tree.preOrdem();
    cout << "\nImprime Ancestrais 10\n";
    tree.imprimeAncestrais(tree.buscaNod(10));
    cout << "\nImprime Ancestrais 1\n";
    tree.imprimeAncestrais(tree.buscaNod(1));

    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "\nROTaciona esq 2x\n";
    tree.rotacionaEsquerda();
    tree.rotacionaEsquerda();

    tree.preOrdem();

    cout << "\nImprime Ancestrais 10\n";
    tree.imprimeAncestrais(tree.buscaNod(10));
    cout << "\nImprime Ancestrais 1\n";
    tree.imprimeAncestrais(tree.buscaNod(1));

    return 0;
}