#include "../include/Servidor.hpp"
#include <iostream>

Usuario::Usuario(int id){
    this->ID = id;
    this->caixa = new CaixaEmail();
}

Usuario::~Usuario(){
    delete caixa;
}

No::No(){
    this->esq = nullptr;
    this->dir = nullptr;
}

Servidor::Servidor(){
    this->raiz = nullptr;
}

Servidor::~Servidor(){
    Limpa();
}

void Servidor::CadastrarUsuario(int id){
    Usuario * item = new Usuario(id);
    InsereRecursivo(raiz,item);
}

void Servidor::RemoverUsuario(int id){
    Remover(raiz, id);
}

void Servidor::EntregarEmail(int id, int pri, std::string msg){
    Email email = Email(id,pri,msg);
    
    No * usuario;
    try{
        usuario = this->BuscarUsuario(raiz, email.ContaID);
        usuario->item->caixa->InserePrioritario(email);
    } catch(int id){
        std::cout << "ERRO: CONTA "<< id << " NAO EXISTE" << std::endl;
    }
}

void Servidor::ConsultarEmail(int idUsuario){
    No * usuario;
    try{
        usuario = this->BuscarUsuario(raiz, idUsuario);
        usuario->item->caixa->Desenfileira();
    } catch(int id){
        std::cout << "ERRO: CONTA ID "<< id << " NAO EXISTE" << std::endl;
    } catch(char const* erro){
        std::cout << "CONSULTA ID: "<< idUsuario << " CAIXA DE ENTRADA VAZIA" << std::endl;
    }
    
}

void Servidor::InsereRecursivo(No* &p, Usuario * item){
    if(p == nullptr){
        p = new No();
        p->item = item;
        std::cout << "OK: CONTA "<< p->item->ID << " CADASTRADA" << std::endl;
    }
    else{
        if(item->ID < p->item->ID)
            InsereRecursivo(p->esq, item);
        else if(item->ID > p->item->ID){
            InsereRecursivo(p->dir, item);
        } else{
            std::cout << "ERRO: CONTA "<< p->item->ID << " JA EXISTENTE" << std::endl;
        }
    }
}

No * Servidor::BuscarUsuario(No* &p, int id){
    if(p == nullptr){
        throw id;
    }
    if(p->item->ID == id){
        return p;
    } 
    else{
        if(id < p->item->ID)
           return BuscarUsuario(p->esq, id);
        else
           return BuscarUsuario(p->dir, id);
    }
}

No * Servidor::Remover(No* &p, int id) {
    if(p == nullptr){
        std::cout << "ERRO: CONTA "<< id << " NAO EXISTE" << std::endl;
        return nullptr;
    } else { // procura o nó a remover
        if(p->item->ID == id) {
            // remove nós folhas (nós sem filhos)
            if(p->esq == nullptr && p->dir == nullptr) {
                delete p;
                std::cout << "OK: CONTA "<< id <<" REMOVIDA"<<std::endl;
                return nullptr;
            }
            else{
                // remover nós que possuem 2 filhos
                if(p->esq != nullptr && p->dir != nullptr){
                    No *aux = p->esq;
                    Usuario *atual = p->item;

                    while(aux->dir != nullptr)
                        aux = aux->dir;

                    p->item = aux->item;
                    aux->item = atual;
                    p->esq = Remover(p->esq, id);
                    return p;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    No *aux;
                    if(p->esq != nullptr)
                        aux = p->esq;
                    else
                        aux = p->dir;
                    delete p;
                    std::cout << "OK: CONTA "<< id <<" REMOVIDA" <<std::endl;
                    return aux;
                }
            }
        } else {
            if(id < p->item->ID )
                p->esq = Remover(p->esq, id);
            else
                p->dir = Remover(p->dir, id);
            return p;
        }
    }
}

void Servidor::ApagaRecursivo(No *p){
    if(p!=nullptr){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void Servidor::Limpa(){
    ApagaRecursivo(raiz);
    raiz = nullptr;
}