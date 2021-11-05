# 3 Lista encadeada
TODO: 
- [x] Criação de lista vazia
- [x] inserção de novo nó em uma posição especíca
- [x] busca de um nó pela sua chave
- [x] remoção de um nó pela sua chave
- [x] desalocar memória 
  
Cada *nodo* tem um ponteiro que aponta para o *nodo* seguinte. **O último Nodo não aponta
para Nodo algum, sendo assim tem o ponteiro definido como NULL**. Nestas
representações vamos, por simplicidade, mostrar apenas as chaves do Aluno
contido em cada *nodo*.

<center>
<img src="https://www.ime.usp.br/~pf/algoritmos/aulas/img/linked-list.jpg" alt="Girl in a jacket" width="70%" height="70%">

<img src="https://www.ime.usp.br/~pf/algoritmos/aulas/png-from-tex/lista.png" alt="Girl in a jacket" width="70%" height="70%">
</center>





# 3.1 Nodo:
Cada *nodo* na nossa lista encadeada tem dois atributos
- Aluno
- ponteiro para próximo *nodo*

Desta forma, é conveniente criarmos uma classe que encapsula os *nodos* desta lista encadeada

**Classe Nodo.h:**
```c++
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
```

**Classe Aluno:**
```c++
#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#define TOTAL_NOTAS 3
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
# 3.1.2 Inserção
Nossa inserção recebe uma posição e um Aluno e coloca o Aluno na posição dada.

Imagine que queremos inserir um novo Aluno com chave 4 na posição 3 da
Figura 2. Isso o coloca entre o Nodo 1 e 9. Temos que denir o campo prox
deste novo Nodo para apontar para o Nodo 9 e modicar o campo prox do Nodo
1 para apontar para o novo Nodo.
    
    7-> 5-> 1-> 9-> 8


**Classe ListaEncadeada**
```c++
#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "Aluno.h"
#include "Nodo.h"

using namespace std;

class ListaEncadeada
{

public:
    Nodo *inicio;
    int tamanho = 0;
    ListaEncadeada()
    {
        inicio = NULL;
        tamanho = 0;
    }
    ~ListaEncadeada()
    {
        /* temos que desalocar explicitamente toda memória que alocamos no heap. */
    }
    void imprime() const
    {
        Nodo *novoNodo = inicio;
        while (novoNodo)
        {
            cout << novoNodo->aluno.chave << "-" << novoNodo->aluno.nome << "";
            novoNodo = novoNodo->proximo;
            cout << endl;
        }
        cout << endl;
    }
    void insere(int posicao, const Aluno &aluno)
    {
        /* implementar método */
    }
};
#endif
```

**Método inserir. ListaEncadeada::insere()**
```c++ 
void insere(int posicao, const Aluno &aluno)
    {
        Nodo *novoNodo = new Nodo(aluno);
        Nodo *nodoAnterior = inicio;
        if (posicao == 0)
        {
            novoNodo->proximo = inicio;
            inicio = novoNodo;
            tamanho++;
            return;
        }
        if (posicao > tamanho)
        {
            cout << "Posicao invalida";
            return;
        }
        for (int i = 0; i < posicao - 1; i++)
        {
            if (!nodoAnterior->proximo)
            {
                cout << "Posicao invalida" << endl;
                return;
            }
            nodoAnterior = nodoAnterior->proximo;
        }
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        tamanho++;
    }
```
**Remover nodo**
```c++
void remover(int chave)
    {
        Nodo *nodoAtual = inicio;
        Nodo *prev = NULL;
        while (nodoAtual)
        {
            if (nodoAtual->aluno.chave == chave)
                break;
            prev = nodoAtual;
            nodoAtual = nodoAtual->proximo;
        }
        if (!nodoAtual)
            cout << "chave invalida";
        else
        {
            if (prev)
                prev->proximo = nodoAtual->proximo;
            else
                inicio = nodoAtual->proximo;
            delete nodoAtual;
            cout << "chave " << chave << " removida com sucesso";
        }
    }
```
**Destrutor ListaEncadeada**
```c++
~ListaEncadeada()
    {
        Nodo *prox;
        while (inicio)
        {
            prox = inicio->proximo;
            delete inicio;
            inicio = prox;
        }
    }
```

***Arquivos complestos  usados neste tópico:*** 

[ListaEncadeada.h](ListaEncadeada.h)  
[main.cpp](main_encadeada.cpp)  
[Nodo.h](Nodo.h) 

***Créditos das imagens:***
[1 e 2 ](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)
