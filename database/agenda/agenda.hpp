
#include <algorithm>

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

    std::string getId() const{
        return id;
    }

    std::string getNumber() const{
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

    std::string get_name() const{
        return name;
    }

    std::vector<Fone> get_fones() const{
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

    bool is_fav() const {
        return fav;
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

class Agenda{
    std::vector<Contato> contatos;
public:
    Agenda() {}

    std::vector<Contato> get_contatos(){
        return contatos;
    }

    void add_contato(std::string nome, std::vector<Fone> fone) {
        auto it = std::lower_bound(contatos.begin(), contatos.end(), nome, 
            [](const Contato& c, const std::string& n) { return c.get_name() < n; });

        if (it != contatos.end() && it->get_name() == nome) {
            for(auto& f : fone){
                it->add_fone(f.getId(), f.getNumber());
            }
            return;
        }

        Contato novoContato(nome);
        for (auto& f : fone) {
            novoContato.add_fone(f.getId(), f.getNumber());
        }
        contatos.insert(it, std::move(novoContato));
    }

    void rm_fone(std::string nome, int index){
        auto it = std::lower_bound(contatos.begin(), contatos.end(), nome, 
            [](const Contato& c, const std::string& n) { return c.get_name() < n; });

        if (it != contatos.end() && it->get_name() == nome) {
            it->rm_fone(index);
            return;
        }
        std::cout << "fail: contato nao encontrado" << std::endl;
    }

    void rm_contato(std::string nome){
        auto it = std::lower_bound(contatos.begin(), contatos.end(), nome, 
            [](const Contato& c, const std::string& n) { return c.get_name() < n; });

        if (it != contatos.end() && it->get_name() == nome) {
            contatos.erase(it);
            return;
        }
        std::cout << "fail: contato nao encontrado" << std::endl;
    }

    void pesquisa(std::string pattern){
        std::vector<Contato> resultado;
        for(auto& c : contatos){
            if(c.get_name().find(pattern) != std::string::npos){
                resultado.push_back(c);
            }
            for(auto& f : c.get_fones()){
                if(f.getNumber().find(pattern) != std::string::npos){
                    resultado.push_back(c);
                }
            }
        }
        for(auto& c : resultado){
            std::cout << c.toString() << std::endl;
        }
    }

    void fav(std::string nome){
        auto it = std::lower_bound(contatos.begin(), contatos.end(), nome, 
            [](const Contato& c, const std::string& n) { return c.get_name() < n; });
        
        if (it != contatos.end() && it->get_name() == nome) {

            it->add_fav();
            return;
        }
        std::cout << "fail: contato nao encontrado" << std::endl;
    }


    std::string favs(){
        bool encontrou = false;
        std::stringstream ss;
        

        for (auto& c : contatos) {
            if (c.is_fav()) {  
                if(encontrou){
                    ss << "\n";
                }
                ss << c.toString();
                encontrou = true;
            }
        }

        if (ss.str().empty()) {
            return "fail: nenhum contato favorito";
        }

        return ss.str();
    }

    std::string toString(){
        std::stringstream ss;
        for (size_t i = 0; i < contatos.size(); i++) {
            ss << contatos[i].toString();
            if (i < contatos.size() - 1) {  
                ss << "\n";
            }
        }
        return ss.str();
    }

};