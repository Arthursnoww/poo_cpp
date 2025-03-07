#include <iostream>
#include <list>
#include <memory>
#include <string>


class Pessoa{
    public:
    std::string nome {nullptr};
    Pessoa (std::string nome):nome(nome) {}

};

int main() {
    auto a = std::make_shared<Pessoa> ("fulano");
    std::list<std::shared_ptr<Pessoa>> lista;

    lista.push_back(a);
    lista.push_back(std::make_shared<Pessoa> ("emanuela"));
    lista.push_front(std::make_shared<Pessoa> ("arthur"));
    lista.push_front(std::make_shared<Pessoa> ("marcos"));
    lista.push_front(std::make_shared<Pessoa> ("paulo"));
    auto b = lista.front();

    std::cout << a->nome << std::endl;
    std::cout << lista.front()->nome << std::endl;

    /*auto it = lista.begin();
    auto elem = *it;
    std::cout << elem->nome << std::endl;*/

    std ::cout << (**lista.begin()).nome <<std::endl;

    /*auto it = lista.begin();
    it++;
    std::cout << (*it)->nome <<std::endl;*/
    
    for(auto it =lista.begin(); it != lista.end(); it++){
        auto elem = *it;
        std::cout << elem->nome << std::endl;
    }

    /*for(auto it =std::next(lista.begin(), 2); it != lista.end(); it++){
        auto elem = *it;
        std::cout << elem->nome << std::endl;
    }*/

   for(auto it =lista.begin(); it != lista.end(); it++){
        auto elem = *it;
        if(elem->nome == "arthur"){
            lista.erase(it);
            break;
        }
        
    }

    for(auto it =lista.begin(); it != lista.end(); it++){
        auto elem = *it;
        std::cout << elem->nome << std::endl;
    }
   

    std::cout << "qxcode\n";


}


