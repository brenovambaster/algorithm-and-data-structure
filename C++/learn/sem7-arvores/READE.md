## 3 Representação de Árvores Binárias em Memória
## 3.2 Para apenas dois filhos
```c++
class Nodo
{

public:
    Nodo * filhoEsquerda;
    Nodo * filhoDireita;
    Aluno aluno;
    Nodo()
    {
        // o pe r ac oe s a serem f e i t a s
    }
    Nodo(const Aluno &novoAluno)
    {
        aluno = novoAluno;
    }
    ~Nodo() {}
};

```

### 3.2.1 Percurso em Pré-ordem
Vamos iniciar invocando o método pela classe Arvore
