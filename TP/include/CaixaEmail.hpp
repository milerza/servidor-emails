#ifndef _CAIXA_EMAIL_
#define _CAIXA_EMAIL_

#include <string>

extern "C" {
    #include "msgassert.h" 
}

class Email{
    public:
        Email();
        Email(int id, int pri, std::string msg);
        int ContaID;
        int prioridade;
        std::string mensagem;
};

class TipoCelula{
    public:
        TipoCelula();
        TipoCelula *prox;
        Email item;  

    friend class FilaEncadeada;
};

class CaixaEmail{
    public:
        CaixaEmail();
        ~CaixaEmail();
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        Email Desenfileira();
        void Limpa();
        void InserePrioritario(Email item);
        
    protected:
        int tamanho;

    private:
        TipoCelula* Posiciona(int prioridade);
        TipoCelula* frente;
        TipoCelula* tras;
};

#endif