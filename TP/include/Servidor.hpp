#ifndef _SERVIDOR_
#define _SERVIDOR_

#include "CaixaEmail.hpp"

class Usuario{
    private:
        int ID;
    public:
        CaixaEmail caixa;
        Usuario(int id){this->ID = id;};
        int GetId(){return ID;};
};

class No{
    public:
        No();
        Usuario item;

    private:
        No *esq;
        No *dir;

    friend class Servidor;
};

class Servidor{
    public:
        Servidor();
        ~Servidor();
        void CadastrarUsuario(Usuario item);
        void RemoverUsuario(Usuario item);
        void EntregarEmail(Email email);
        void ConsultarEmail(int idUsuario);//caminha  acha o user e retira o ultimo da caixa de email do usuario
        void Caminha(int tipo);
        void Limpa();

    private:
        void InsereRecursivo(No* &p, Usuario item);
        void ApagaRecursivo(No* p);
        void PorNivel();
        void PreOrdem(No* p);
        void InOrdem(No* p);
        void PosOrdem(No* p);

        No *raiz;
};

#endif