#ifndef _CAIXA_EMAIL_
#define _CAIXA_EMAIL_

#include <string>

class Email{
    public:
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
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        Email Desenfileira();
        void Limpa();
        void InserePrioritario(Email item);
        
    protected:
        int tamanho;

    private:
        TipoCelula* Posiciona(int prioridade, bool antes);
        TipoCelula* frente;
        TipoCelula* tras;
};

#endif