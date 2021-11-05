# Alocação Dinâmica de memória: 
 **Próximo tópico:>>** [**3 Lista encadeada**](lista_encadeada.md)  
 
 
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
    Aluno *aluno1 = NULL;           // cria um ponteiro para um aluno
    aluno1 = new Aluno(4, "lucas"); //  instancia o objeto aluno1
    return aluno1;                  // retorna o ponteiro;
}

int main()
{
    Aluno *alunomain = NULL;
    alunomain = fooDin();
    if (!alunomain) // caso falhe a alocação, aluno1 será = NULL
    {
        cout << "Erro:falta de memoria" << endl;
    }
    else
    {
        cout << alunomain->nome;
    }
}
```

Ao usar o operador **`new`**, retorna `NULL` caso não seja mais possível alocar mais memória, logo é uma boa prática testar
se a alocação foi concluída com sucesso. 
```c++
    Aluno ∗ aluno1 = NULL;
    aluno1 = new Aluno ( ) ;
    if (!aluno1 )
        cout<<"Erro:falta de memoria"<<endl;
```
___

## Operador delete
A memória disponibilizada para os objetos e variáveis alocados de forma estática
é automaticamente liberada no momento que o método retorna, *pois sua stack
frame é destruída neste momento*. **A memória alocada para os objetos e variáveis
alocada dinamicamente precisa ser explicitamente liberada**. Para isso usamos o
operador **delete**.

```c++
int main()
{
    Aluno *alunomain = NULL;
    alunomain = fooDin();
    if (!alunomain) // caso falhe a alocação, aluno1 será = NULL
    {
        cout << "Erro:falta de memoria" << endl;
    }
    else
    {
        cout << alunomain->nome;
    }
    delete alunomain;
    cout <<"\n Depois de deletado aparece lixo : "<< alunomain->nome;
}
```
```diff 
+ Nota: Note que ao deletarm, estamos liberando a memória que foi utilizada para aluno. 
! O operador delete imediatamente invoca o destrutor da classe. Esse fato será útil na nossa lista encadeada que veremos à seguir neste estudo.

```

### Arquivos usados: 

* [**Aluno.h**](Aluno.h) 
* [**main.cpp**](main.cpp)
* **Continuação:>>** [**Lista encadeada**](lista_encadeada.md)
