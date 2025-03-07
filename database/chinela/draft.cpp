#include <iostream>

class Chinela{
    private:
    int tam;

    public:

    Chinela() : tam(0){}

    void set_tam(int t){
        if(t >= 20 && t <= 50 && t % 2 == 0){
            tam  = t;
            std::cout << tam << std::endl;
        }else{
            std::cout << "valor invalido" << std::endl;
        }
    }

    int get_tam(){
        return tam;
    }

    /*void value_valid(){
        while(get_tam() == 0){
            //std::cout << "Digite o tamanho:" << std::endl;
            //std::cin >> tam_input;
    
            set_tam(tam_input);
        }
    } */

};

int main() {
    Chinela chinela;

    while(chinela.get_tam() == 0){
        int tam_input;
        std::cout << "Digite o tamanho:" << std::endl;
        std::cin >> tam_input;
        chinela.set_tam(tam_input);
    }

}


