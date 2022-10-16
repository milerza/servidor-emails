#include "CaixaEmail.hpp"
#include <iostream>

using namespace std;

CaixaEmail::CaixaEmail() {
    tamanho = 0;
    frente = new TipoCelula();
    tras = frente;
}

CaixaEmail::~CaixaEmail(){
    Limpa();
    delete frente;
}

TipoCelula::TipoCelula(){
    prox = nullptr;
}

Email CaixaEmail::Desenfileira(){
    TipoCelula *p;
    Email aux;
    if (tamanho == 0)
        throw "Fila está vazia!";

    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;

    delete p;
    tamanho--;

    return aux;
}

void CaixaEmail::Limpa(){
    TipoCelula *p;
    p = frente->prox;

    while(p!=NULL){
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }

    tamanho = 0;
    tras = frente;
}

void CaixaEmail::InserePrioritario(Email item) {
    TipoCelula *p, *nova;
    p = Posiciona(item.prioridade); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    std::cout << item.mensagem <<std::endl;
    
    if(nova->prox == NULL)
        tras = nova;
};

TipoCelula* CaixaEmail::Posiciona(int prioridade){
   
    TipoCelula *p; 
    p = frente;

    for(int i = 1; i<tamanho; i++){
        if(prioridade > p->prox->item.prioridade)
            return p;
        p = p->prox;
        
    }
    // vai para a próxima
    if(tamanho > 0)
        p = p->prox;

    return p;
}