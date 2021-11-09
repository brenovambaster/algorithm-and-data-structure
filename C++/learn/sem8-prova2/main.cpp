#include <iostream>
#include "Aluno.h"
#include "ABP.h"
#include "Nodo.h"
using namespace std;
int main()
{
    Aluno a1(1, "a1");
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

    ABP abp;
    abp.insere(a8);
    abp.insere(a5);
    abp.insere(a3);
    abp.insere(a12);
    abp.insere(a9);
    abp.insere(a4);
    abp.insere(a11);
    abp.insere(a2);
    abp.insere(a6);
    abp.insere(a10);
    abp.insere(a1);
    abp.insere(a7);

    cout << "\nImprime pre ordem: \n";
    abp.preOrdem();
    cout << "\nImprime Ancestrais de 10: \n";
    abp.imprimeAncestrais(abp.buscaNod(10));
    cout << "\nImprime ancestrais de 1 \n";
    abp.imprimeAncestrais(abp.buscaNod(1));
    cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

    cout << "\nRotaciona a direita: \n";
    abp.rotacionaDireita();

    cout << "\nImprime pre ordem: \n";
    abp.preOrdem();
    cout << "\nImprime Ancestrais de 10: \n";
    abp.imprimeAncestrais(abp.buscaNod(10));
    cout << "\n Imprime ancestrais de 1 \n";
    abp.imprimeAncestrais(abp.buscaNod(1));

    cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

    cout << "\n Rotaciona esquerda 2x\n";
    abp.rotacionaEsquerda();
    abp.rotacionaEsquerda();
    cout << "\nImprime pre ordem \n";
    abp.preOrdem();
    cout << "\nImprime ancestrais 10 \n";
    abp.imprimeAncestrais(abp.buscaNod(10));
    cout << "\nImprime ancestrais 1 \n";
    abp.imprimeAncestrais(abp.buscaNod(1));

    return 0;

    /* cout << "PESQUISA:\n";
    cout << abp.buscaNod(14);
    cout << "ANCESTRAIS:\n";
    abp.imprimeAncestrais(abp.buscaNod(10));
 */
    /* abp.preOrdem();
    abp.posOrdem(); */
}