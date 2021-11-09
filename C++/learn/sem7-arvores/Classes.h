#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED


using namespace std;


class Arvore{

    public:
        Node * raiz;

        Arvore(){

        }

        ~Arvore(){
            
        }

        void preOrdem () const {
            if (raiz)
                raiz->preOrdem();

            cout << endl;
        }


        void posOrdem () const {
            if (raiz)
                raiz->posOrdem();

            cout << endl;
        }
};


class Node{

    public:
        Node * filhoEsquerda;
        Node * filhoDireita;
        Aluno aluno;

        Node(){

        }


        Node(const Aluno & novoAluno){
            aluno = novoAluno;
        }


        ~Node(){
            
        }


        void preOrdem () {
            
            aluno.imprime();

            if (filhoEsquerda)
                filhoEsquerda->preOrdem();
            
            if (filhoDireita)
                filhoDireita->preOrdem();
            
        }


        void posOrdem () {
            
            if (filhoEsquerda)
                filhoEsquerda->posOrdem();
            
            if (filhoDireita)
                filhoDireita -> posOrdem();
            
            aluno.imprime();
        }

};


class Aluno{

    public:
        int chave;
        string nome;
        
        
        Aluno(int novaChave, const string & novoNome){
            chave = novaChave;
            nome = novoNome;
        }


        Aluno(){
            chave = 0;
            nome = "dummy";
        }


        ~Aluno(){

        }

        void imprime(){

            cout << "chave: " << chave << " nome: " << nome << endl;
        } 
};


#endif
