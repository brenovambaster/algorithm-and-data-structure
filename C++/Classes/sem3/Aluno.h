#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#define TOTAL_NOTAS 3
using namespace std;

class Aluno
{
public:
    string nome;
    int notas[TOTAL_NOTAS];
    double media()
    {
        int total = 0;
        for (unsigned u = 0; u < TOTAL_NOTAS; u++)
        {
            total += notas[u];
        }
        return total / (double)TOTAL_NOTAS;
    }
    bool passou()
    {
        return media() >= 60;
    }
};

#endif
