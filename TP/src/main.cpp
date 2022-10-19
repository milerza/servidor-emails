
#include "Rede.hpp"

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char const *argv[]){
    
    Rede * rede = new Rede();
    std::string arquivo_entrada = "input2.txt";
    std::string arquivo_saida;

    // check arguments
    for (int i = 0; i < argc; i++)
    {
        if (std::string(argv[i]) == "-i") //ler o arquivo
        {
            arquivo_entrada = std::string(argv[i+1]);
        }
    }

    rede->ReceberMensagens(arquivo_entrada);

    // asserts de arquivos de entrada
    erroAssert(arquivo_entrada != "", "Erro no input!");

    return 0;
}