#include "CaixaEmail.hpp"

TipoCelula::TipoCelula(){}

void CaixaEmail::Enfileira(Email item){
    TipoCelula *nova;
    nova = new TipoCelula();
    tras->prox = nova;
    tras = nova;
    tamanho++;
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