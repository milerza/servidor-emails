
#include "Servidor.hpp"

int main(){
    Email * email_teste1 = new Email();
    email_teste1->ContaID = 20;
    email_teste1->mensagem = "Oi 1 FIM";
    email_teste1->prioridade = 1;

    Servidor servidor;
    Usuario * usuario1 = new Usuario(60);
    Usuario * usuario2 = new Usuario(30);
    Usuario * usuario3 = new Usuario(20);
    Usuario * usuario4 = new Usuario(40);
    Usuario * usuario5 = new Usuario(70);
    Usuario * usuario6 = new Usuario(80);
    Usuario * usuario7 = new Usuario(75);

    servidor.CadastrarUsuario(usuario1);
    servidor.CadastrarUsuario(usuario2);
    servidor.CadastrarUsuario(usuario3);
    servidor.CadastrarUsuario(usuario4);
    servidor.CadastrarUsuario(usuario5);
    servidor.CadastrarUsuario(usuario6);
    servidor.CadastrarUsuario(usuario7);
    servidor.EntregarEmail(*email_teste1);
    servidor.RemoverUsuario(60);

    return 0;
}