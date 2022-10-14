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
        CaixaEmail() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        void Enfileira(Email item);
        Email Desenfileira();
        void Limpa();

    protected:
        int tamanho;

    private:
        TipoCelula* frente;
        TipoCelula* tras;
};

#endif