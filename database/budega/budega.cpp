#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <sstream>

class Pessoa{
    public:
    std::string nome;

    Pessoa (std::string nome = ""): nome(nome) {};

    std::string get_nome(){
        return this->nome;
    }

    void set_nome(std::string name){
        this->nome = name;
    }


};

class Budega{
    std::vector<std::shared_ptr<Pessoa>> caixa;
    std::list<std::shared_ptr<Pessoa>> espera;

    public:
    Budega(int n_cxs){
        for(int i = 0; i < n_cxs; i++){
            this->caixa.push_back(nullptr);
        }
    }

    void chegar(std::shared_ptr<Pessoa> pessoa){
        this->espera.push_back(pessoa);
    }

    void chamar(int i){
        if (espera.empty()) {  
            std::cout << "fail: sem clientes" << std::endl;
            return;
        }
        if(caixa[i] != nullptr){
            std::cout << "fail: caixa ocupado" << std::endl;
            return;
        }
        this->caixa[i] =  espera.front();
        this->espera.pop_front();


    }

    std::shared_ptr<Pessoa> finalizar(int i) {
        if (i < 0 || i >= static_cast<int>(caixa.size())) {
            std::cout << "fail: caixa inexistente" << std::endl;
            return nullptr;
        }if (caixa[i] == nullptr) {
            std::cout << "fail: caixa vazio" << std::endl;
            return nullptr;
        }

        auto aux = caixa[i];
        caixa[i] = nullptr;
        return aux;
    }

    std::string str() {
        std::ostringstream ss;
        ss << "Caixas: [";
        for (size_t i = 0; i < caixa.size(); ++i) {
            if (caixa[i] == nullptr) {
                ss << "-----";
            } else {
                ss << caixa[i]->get_nome();
            }
            if (i < caixa.size() - 1) { 
                ss << ", ";
            }
        }
        ss << "]\n";
        ss << "Espera: [";
        for (auto it = espera.begin(); it != espera.end(); ++it) {
            ss << (*it)->get_nome();
            if (std::next(it) != espera.end()) { 
                ss << ", ";
            }
        }
        ss << "]\n";
        return ss.str();
    }
};

    


/*int main(){
    Budega budega(3);

    std::cout << budega.str();

}*/