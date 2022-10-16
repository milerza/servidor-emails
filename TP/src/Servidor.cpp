#include "Servidor.hpp"

No::No(){
    esq = nullptr;
    dir = nullptr;
}

Servidor::Servidor(){
    raiz = nullptr;
}

Servidor::~Servidor(){
    Limpa();
}

void Servidor::CadastrarUsuario(Email item){
    InsereRecursivo(raiz,item);
}
void Servidor::InsereRecursivo(No* &p, Email item){
    if(p == nullptr){
        p = new No();
        p->item = item;
    }
    else{
        if(item.ID() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
    else
        InsereRecursivo(p->dir, item);
    }
}