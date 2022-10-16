
#include "Servidor.hpp"

int main(){
    Email * email_teste1 = new Email();
    email_teste1->ContaID = 10;
    email_teste1->mensagem = "Oi 1 FIM";
    email_teste1->prioridade = 1;

    Servidor servidor;
    Usuario * usuario = new Usuario(20);

    servidor.CadastrarUsuario(usuario);

    return 0;
}