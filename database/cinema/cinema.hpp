#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

class Cliente{
public:
    std::string id = "";
    int fone = 0;
    Cliente() : id(""), fone(0) {}  

    std::string get_id() const{
        return id;
    }
    int get_fone() const{
        return fone;
    }

    void set_id(std::string id){
        this->id = id;
    }

    void set_fone(int fone){
        this->fone = fone;
    }

    std::string toString() const {
        return id + ":" + std::to_string(fone);
    }
};

class Sala{
private:
    std::vector<Cliente> cadeiras;
    
    bool search(std::string name){
        for(auto& cliente : cadeiras){
            if(cliente.get_id() == name){
                return true;
            }
        }
        return false;      
    }

    bool is_index(int index){
        if(index < 0 || index >= (int) cadeiras.size()){
            return false;
        }
        return true;
    }
public:
    Sala(int qtd){
        for(int i = 0; i < qtd; i++){
            cadeiras.push_back(Cliente());
        }
    }

    void reserve(std::string name, int fone, int index){
        if(search(name) != true ){
            if(is_index(index)){
                if(cadeiras[index].get_id().empty()){
                    cadeiras[index].set_id(name);
                    cadeiras[index].set_fone(fone);
                
                }else{
                    std::cout << "fail: cadeira ja esta ocupada" << std::endl;
                }
            }else{
                std::cout << "fail: cadeira nao existe" << std::endl;
            }
        }else{
            std::cout << "fail: cliente ja esta no cinema" << std::endl;
        }
    }

    void cancelar(std::string id){
        for(auto& cliente : cadeiras){
            if(cliente.get_id() == id){
                cliente.set_id("");
                cliente.set_fone(0);
                return;
            }
        }
        std::cout << "fail: cliente nao esta no cinema" << std::endl;
    }

    std::vector<Cliente> get_cadeiras(){
        return cadeiras;
    }

    std::string toString() const {
        std::ostringstream ss;
        ss << "[";

        for (size_t i = 0; i < cadeiras.size(); i++) {
            if (cadeiras[i].get_id().empty()) {  
                ss << "-";
            } else {
                ss << cadeiras[i].toString();  
            }
            
            if (i < cadeiras.size() - 1) {
                ss << " ";
            }
        }

        ss << "]";
        return ss.str();
    }




};