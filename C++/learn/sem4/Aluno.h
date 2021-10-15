#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

using namespace std;

class Aluno
{

public:
    unsigned chave;
    string nome;

    /* construtor */
    Aluno(unsigned novaChave, const string &novoNome)
    {
        chave = novaChave;
        nome = novoNome;
    }

    /* construtor que designa um aluno que ainda nao foi inicializado */
    Aluno()
    {
        chave = 0;
        nome = "dummy";
    }

    /* destrutor */
    ~Aluno() {}

    void imprime()
    {

        cout << " chave : " << chave << " ; nome : " << nome << endl;
    }
};

#endif