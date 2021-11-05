#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Aluno.h"

using namespace std;

class Nodo
{
private:
    /* data */
public:
    Nodo *proximo;
    Aluno aluno;
    Nodo(){
        proximo= NULL;
    }
    Nodo(const Aluno &novoAluno){
        proximo = NULL;
        aluno = novoAluno;
    }
    ~Nodo(){}
};



#endif
