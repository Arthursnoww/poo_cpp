#include <iostream>

class Roupa{
    private:
    std::string tam;

    public:

    Roupa() : tam(" "){}

    void set_tam(std::string tam_input){
        if(tam_input == "PP"){
            tam  = tam_input;
            std::cout << "Tamanho:"  << tam << std::endl;
        }else if(tam_input == "P"){
            tam  = tam_input;
            std::cout << "Tamanho:" << tam << std::endl;
        }else if(tam_input == "M"){
            tam  = tam_input;
            std::cout << "Tamanho:" << tam << std::endl;
        }else if(tam_input == "G"){
            tam  = tam_input;
            std::cout << "Tamanho:" << tam << std::endl;
        }else if(tam_input == "GG"){
            tam  = tam_input;
            std::cout << "Tamanho:" << tam << std::endl;
        }else if(tam_input == "XG"){
            tam  = tam_input;
            std::cout << "Tamanho:" << tam << std::endl;
        }else{
            std::cout << "valor invalido" << std::endl;
        }
    }

    std::string get_tam(){
        return tam;
    }
};

int main() {
    Roupa roupa;

    while(roupa.get_tam() == " "){
        std::string tam_input;
        std::cout << "Digite o tamanho:" << std::endl;
        std::getline(std::cin, tam_input);
        roupa.set_tam(tam_input);
    }

}


