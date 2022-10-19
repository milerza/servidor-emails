#ifndef _REDE_
#define _REDE_

#include "Servidor.hpp"
#include <string>

class Rede{
    public:
        Rede();
        ~Rede();
        void ReceberMensagens(std::string nome_arquivo);

    private:
        Servidor * servidor;
};

#endif