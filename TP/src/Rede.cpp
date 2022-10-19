#include "../include/Rede.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

Rede::Rede(){
    this->servidor = new Servidor();
}

Rede::~Rede(){
    delete this->servidor;
}

void Rede::ReceberMensagens(std::string nome_arquivo){
    std::ifstream file;
    std::string requisicao, linha;
    int id, pri;

    // abrir o arquivo de entrada
    file.open(nome_arquivo);
    erroAssert(file, "Não é possivel abrir arquivo de entrada!");

    while (getline(file, linha))
    {
        std::istringstream iss(linha);
        
        if (!(iss >> requisicao))
            break; //erro em ler a linha

        if(requisicao == "CADASTRA"){
            iss >> id;
            servidor->CadastrarUsuario(id);
        } 
        else if(requisicao == "REMOVE"){
            iss >> id;
            servidor->RemoverUsuario(id);
        } 
        else if(requisicao == "ENTREGA"){
            std::string msg, buffer;

            iss >> id >> pri >> buffer;

            while (buffer != "FIM")
            {   
                msg.append(buffer);
                msg.push_back(' ');
                iss >> buffer;
            }
            servidor->EntregarEmail(id, pri, msg);
        } 
        else if(requisicao == "CONSULTA"){
            iss >> id;
            servidor->ConsultarEmail(id);
        }
    }

    file.close();
}