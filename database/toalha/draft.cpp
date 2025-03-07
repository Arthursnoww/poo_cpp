#include <iostream>
#include <sstream>

class Toalha {
private:
    std::string cor;
    char tam;
    int umi;

public:
    Toalha(std::string corr, char tamm, int umm=0) : cor(corr), tam(tamm), umi(umm) {}

    
    int get_max(){
        if (tam == 'P'){
            return 10;
        }if (tam == 'M'){
            return 20;
        }if (tam == 'G'){
            return 30;
        } return 0;  
    }

    void enxugar(int quantidade) {
        int maxUmidade = get_max();
        if (umi + quantidade > maxUmidade) {
            std::cout << "toalha encharcada" << std::endl;
            umi = maxUmidade;  
        } else {
            umi += quantidade;
        }
    }

    void torcer(){
        umi = 0;
    }

    /*void esta_seca(){
        if(umi == 0){
            std::cout << "true" << std::endl;
        }else{
            std::cout << "false" << std::endl;
        }
    }*/

    bool esta_seca(){
        return umi == 0;
    }

    std::string mostrar(){
        std::stringstream ss;
        ss << cor << " " << tam << " " << umi;
        return ss.str();
    }

    void mostrar_teste(){
        std::cout << mostrar() << std::endl;
    }


};

int main() {
    Toalha toalha("Azul", 'P');

    toalha.mostrar_teste();  
    toalha.enxugar(5);
    toalha.mostrar_teste();  
    std::cout << std::boolalpha << toalha.esta_seca() << std::endl; 
    toalha.enxugar(5);
    toalha.mostrar_teste();  
    toalha.enxugar(5);  
    toalha.mostrar_teste();  
    toalha.torcer();
    toalha.mostrar_teste();  

    std::cout << std::endl;
    
    Toalha toalha2("Verde", 'G');

    std::cout << std::boolalpha << toalha2.esta_seca() << std::endl;
    toalha2.enxugar(30); 
    toalha2.mostrar_teste(); 
    std::cout << std::boolalpha << toalha2.esta_seca() << std::endl;
    toalha2.enxugar(1); 
    
}
