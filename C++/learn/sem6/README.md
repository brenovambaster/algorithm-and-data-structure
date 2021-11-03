# Alocação Dinâmica de memória: 

Considere a estrutura Alunos: ***Aluno.h***
```c++
#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
using namespace std;

class Aluno
{

public:
    int chave;
    string nome;
    Aluno(int novaChave, const string &novoNome)
    {
        chave = novaChave;
        nome = novoNome;
    }
    Aluno()
    {
        chave = 0;
        nome = "dummy";
    }
    ~Aluno() {}
};

#endif
```
Até agora criamos objetos do tipo Aluno da forma: 
```c++ 
void foo()
{
    Aluno a1(2, "breno");
} 
```
NOTA: Quando fazemos a chamada de **foo()** é criado um **alunoFoo** com alocação
**estática de memória**. Quando executamos a função foo é criado um *stack frame na pilha de ativação e a memória para o aluno é alocada*. Este espaço de memória está alocado somente enquanto ***foo()*** está executando.
___
## Operador new
A alocação dinâmica de memória é feita no heap ao contrário da pilha (stack). Para alocarmos um aluno de forma dinâmica usamos o operador new. 
***(arquivo: main.cpp)***
```c++ 
    /* Cria um objeto do tipo aluno e retorna um ponteiro para sua posicão em memória */
    Aluno *fooDin()
    {
        Aluno *aluno1 = NULL;           // declara um ponteiro para um aluno
        aluno1 = new Aluno(4, "lucas"); //  instancia o objeto aluno1 e alocando memória
        return aluno1;                  // retorna o ponteiro;
    }
    /* O ponteiro aluno1 nos dá a posição de memória onde alocamos o novo Aluno. */
```
Dito isso, vamos fazer alguns testes no arquivo ***main.cpp***:
```c++ 
#include <iostream>
#include "Aluno.h"
using namespace std;
void foo()
{
    Aluno a1(2, "breno");
}

/* Cria um objeto do tipo aluno e retorna um ponteiro para sua posicão em memória */
Aluno *fooDin()
{
    Aluno *aluno1 = NULL;           // declara um ponteiro para um aluno
    aluno1 = new Aluno(4, "lucas"); //  instancia o objeto aluno1 e alocando memória
    return aluno1;                  // retorna o ponteiro;
}
/* O ponteiro aluno1 nos dá a posição de memória onde alocamos o novo Aluno. */
int main()
{
/* Vimos que o retorno de ***fooDin()*** é um ponteiro, logo, devemos criar um ponteiro do mesmo tipo para recebê-lo.  */
    Aluno *alunomain = NULL;
    alunomain = fooDin();
    cout << alunomain->nome;
}
```
Arquivos usados: 
* [**Aluno.h**](Aluno.h) 
* [**main.cpp**](main.cpp)
