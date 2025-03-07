#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "fn.hpp"

class Grafite{
    private:
    float calibre;
    std::string dureza;
    int tam;

    public:
    Grafite(float tt, std::string hh, int ss): calibre(tt), dureza(hh), tam(ss) {}

    float get_calibre(){
        return calibre;
    }

    std::string get_dureza(){
        return dureza;
    }

    int get_tam(){
        return tam;
    }

    void set_tam(int ss){
        tam = ss;
    }

    int usage_per(){
        if(this->dureza == "HB"){
            return 1;
        }else if(this->dureza == "2B"){
            return 2;
        }else if(this->dureza == "4B"){
            return 4;
        }else if(this->dureza == "6B"){
            return 6;
        }   
        return 0;
    }

    std::string str() const{
        return fn::format("{}:{}:{}", this->calibre, this->dureza, this->tam);
    }
};
std::ostream& operator<<(std::ostream &os, const Grafite& garfite) {
    return os << garfite.str();
}

class Lapiseira{
    private:
    float calibre_p {0};
    std::shared_ptr<Grafite> grafite {nullptr};

    public:
    Lapiseira(float tt): calibre_p(tt) {}

    bool has_grafite(){
        if(this->grafite == nullptr){
        return false;
        }else{
        return true;
        }
    }
    void insert_grafite(std::shared_ptr<Grafite> gft){
        if(this->grafite != nullptr){
            fn::write("fail: ja existe grafite");
            return;
        }
        if(gft->get_calibre() != calibre_p){
            fn::write("fail: calibre incompativel");
            return;
        }
        this->grafite = gft;
        
    }void remove(){
        if(has_grafite() == true){
            this->grafite = nullptr;
        }
    }
    void write(){
        if(this->grafite == nullptr){
            fn::write("fail: nao existe grafite");
            return;
        }if(this->grafite->get_tam() <= 10){
            fn::write("fail: tamanho insuficiente");
            return;
        }if(this->grafite->get_tam() < this->grafite->usage_per()+10){
            fn::write("fail: folha incompleta");
            grafite->set_tam(10); 
            return;
        }
        grafite->set_tam(grafite->get_tam() - this->grafite->usage_per());

    }

    std::string str() const{
        if(this->grafite == nullptr){
            return fn::format("calibre: {}, grafite: {}", this->calibre_p, this->grafite);

        }
        return fn::format("calibre: {}, grafite: [{}]", this->calibre_p, this->grafite);
    }

};
std::ostream& operator<<(std::ostream &os, const Lapiseira& lapiseira) {
    return os << lapiseira.str();
};



class Student {
private:
    Lapiseira lapiseira;
public:
    Student(float calibreness = 1):lapiseira(calibreness) {};
    
    void insert(double calibre, std::string dureza, int tam) {
        auto grt = std::make_shared<Grafite>(calibre, dureza, tam);
        lapiseira.insert_grafite(grt);
    }

    void remove() {
        lapiseira.remove();
    }

    void writePage() {
        lapiseira.write();
    }

    void show() {
        fn::write(lapiseira.str());
    }
};
