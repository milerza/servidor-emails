
#include "Servidor.hpp"

#include <sstream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[]){
    
    std::ifstream infile("thefile.txt");
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { break; } // error

        // process pair (a,b)
    }


    return 0;
}