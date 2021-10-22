/* Aluno: Breno Vambáster Cardoso Lima */
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
using namespace std;

class Cliente
{

public:
    int CPF = 0;
    string nome = "undefined";

    Cliente(const string &newname, int newcpf)
    {
        if (newcpf == 0)
        {
            cout << "Classe:Cliente> erro: chave reservada para dummy.Escolha outra,\n";
        }
        else
        {
            nome = newname;
            CPF = newcpf;
        }
    }
    Cliente()
    {
        CPF = 0;
        nome = "dummy";
    }
    void imprime()
    {
        cout << " chave : " << CPF << " ; nome : " << nome << endl;
    }
    ~Cliente() {}
};

#endif