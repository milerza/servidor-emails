#ifndef _SERVIDOR_
#define _SERVIDOR_

#include "CaixaEmail.hpp"

class Usuario{
    public:
        int ID;
        CaixaEmail * caixa;
        Usuario(int id);
        ~Usuario();
        int GetId(){return ID;};

        
        
};

class No{
    public:
        No();
        Usuario * item;

    private:
        No *esq;
        No *dir;

    friend class Servidor;
};

class Servidor{
    public:
        Servidor();
        ~Servidor();
        void CadastrarUsuario(Usuario * item);
        void RemoverUsuario(int id);
        void EntregarEmail(Email email);
        void ConsultarEmail(int idUsuario);
        void Limpa();

    private:
        void InsereRecursivo(No* &p, Usuario * item);
        No * BuscarUsuario(No* &p, int id);
        No * Remover(No* &raiz, int id);
        void ApagaRecursivo(No* p);

        No *raiz;
};

#endif