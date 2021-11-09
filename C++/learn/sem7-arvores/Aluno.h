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
    void imprime() const
    {
        cout << "nome: " << nome << " chave:" << chave;
    }
    ~Aluno() {}
};

#endif