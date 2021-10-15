#include <iostream>

#include "Aluno.h"

using namespace std ;

int main ( ) {

    Aluno a1 ;
    a1.nome= 'Breno';
    a1.notas[0]=10;
    a1.notas[1]=1;
    a1.notas[2]=12;
    cout << "nota p1 "<<a1.nome <<" e "<< a1.notas[0]<< endl;
    cout << "Situacao do aluno: media"<< a1.media() <<"aprovado? "<<a1.passou() ;
    return 0 ;
 }
