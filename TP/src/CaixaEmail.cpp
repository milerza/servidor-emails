#include "CaixaEmail.hpp"
#include <iostream>

using namespace std;

TipoCelula::TipoCelula(){
    prox = nullptr;// tenho que dazer algo em relacao ao contrutpr da caixa de email
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
    p = Posiciona(item.prioridade,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    
    if(nova->prox == NULL)
        tras = nova;
};

TipoCelula* CaixaEmail::Posiciona(int prioridade, bool antes=false){
   
    TipoCelula *p; 
    p = frente;

    for(int i = 1; i<tamanho; i++){
        if(prioridade > p->item.prioridade){
            break;
        }
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
        p = p->prox;

    return p;
}