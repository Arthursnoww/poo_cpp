#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <sstream>

class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string iid, std::string nnumber) : id(iid), number(nnumber) {}

    bool is_valid(){
        std::string valid = "0123456789().";
        for(auto c : number)
            if(valid.find(c) == std::string::npos)
                return false;
        return true;
    }

    std::string getId(){
        return id;
    }

    std::string getNumber(){
        return number;
    }

    std::string toString(){
        return id + ":" + number;
    }
};

class Contato{
    std::string name;
    std::vector<Fone> fones;
    bool fav = false;
public:
    Contato(std::string nome) : name(nome) {}

    std::string get_name(){
        return name;
    }

    std::vector<Fone> get_fones(){
        return fones;
    }

    void set_name(std::string nome){
        name = nome;
    }

    void add_fone(std::string id, std::string number){
        auto fone = Fone(id, number);
        if(fone.is_valid()){
            fones.push_back(fone);
            return;
        }else{
            std::cout << "fail: invalid number" << std::endl;
            return;
        }
        fones.push_back(fone);
    }

    void add_fav(){
        fav = !fav;
    }

    void rm_fone(int index){
        if(index < 0 || index >= (int) fones.size()){
            std::cout << "fail: indice invalido" << std::endl;
            return;
        }
        fones.erase(fones.begin() + index);
    }

    std::string toString(){
        std::stringstream ss;
        ss << (fav ? "@ " : "- ") << name << " [";
        for (size_t i = 0; i < fones.size(); i++) {
            ss << fones[i].toString();
            if (i < fones.size() - 1) {  
                ss << ", ";
            }
        }
        ss << "]";
        return ss.str();
    }
};