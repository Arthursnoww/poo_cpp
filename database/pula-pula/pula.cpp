#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>


class Muleke{
    private:
    int idade;
    std::string nome;

    public:

    Muleke(int id, std::string nn): idade(id), nome(nn) {}

    int get_idade(){
        return this->idade;
    }

    std::string get_nome(){
        return this->nome;
    }

    void set_idade(int idade){
        this->idade = idade;
    }

    void set_name(std::string nome){
        this->nome = nome;
    }

    std::string str() {
        std::ostringstream ss;
        ss << this->nome << ":" << this->idade;
        return ss.str();
    }


};

class Pulapula{
    private:
    std::list<std::shared_ptr<Muleke>> pulando;
    std::list<std::shared_ptr<Muleke>> espera;

    public:

    void fila(std::shared_ptr<Muleke> pitoco){
        this->espera.push_back(pitoco);
    }

    void enter(){
        this->pulando.push_front(this->espera.front());
        this->espera.erase(espera.begin());
    }

    void leave() {
        if (pulando.empty()) {
            //std::cout << "fail: nao ha ninguem no pula-pula" << std::endl;
            return;
        }
        this->espera.push_back(std::move(this->pulando.back()));
        this->pulando.pop_back();
    }

    std::shared_ptr<Muleke> remove(std::string nome) {
        for (auto it = pulando.begin(); it != pulando.end(); ++it) {
            auto elem = *it;
            if (elem->get_nome() == nome) {
                pulando.erase(it); 
                return elem;       
            }
        }
        for (auto it = espera.begin(); it != espera.end(); ++it) {
            auto elem = *it;
            if (elem->get_nome() == nome) {
                espera.erase(it); 
                return elem;      
            }
        }

   
    std::cout << "fail: " << nome << " nao esta no pula-pula" << std::endl;
    return nullptr; 
}



    std::string str() const {

        std::ostringstream ss;
        ss << "[";
        for (auto it = espera.rbegin(); it != espera.rend(); ++it) { // rbegin e rend para inverter a ordem
            ss << (*it)->get_nome() << ":" << (*it)->get_idade();
            if (std::next(it) != espera.rend()) { // Verifica se não é o último elemento
            ss << ", ";
            }
        }
        ss << "] => [";
        // Adiciona as crianças no pula-pula
        for (auto it = pulando.begin(); it != pulando.end(); ++it) {
            ss << (*it)->get_nome() << ":" << (*it)->get_idade();
            if (std::next(it) != pulando.end()) { // Verifica se não é o último elemento
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }





};



