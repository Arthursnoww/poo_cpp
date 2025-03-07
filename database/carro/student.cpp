#include "fn.hpp"


struct Carro{
    int pass;
    int passmax;
    int gas;
    int gasmax;
    int km;

    Carro(){
        this->pass = 0;
        this->passmax = 2;
        this->gas = 0;
        this->gasmax = 100;
        this->km = 0;
    }

    void enter(){
        if(this->pass < this->passmax){
            this->pass++;
        }else{
            std::cout << "fail: limite de pessoas atingido" << std::endl;
        }
    }
    void leave(){
        if(this->pass > 0){
            this->pass--;
        }else{
            std::cout << "fail: nao ha ninguem no carro" << std::endl;
        }
    }
    void fuel_qtd(int qtd){
        if(this->gas+ qtd <= this->gasmax){
            this->gas = this->gas + qtd;
        } else{
            this->gas = this->gasmax;
        }
    }
    void drive_dist(int qtd){
        if(this->pass > 0){
            if(this->gas > 0){
                if(this->gas > qtd){
                    this->gas = this->gas - qtd;
                    this->km = this->km + qtd;
                }else{
                    this->km += this->gas;
                    std::cout << "fail: tanque vazio apos andar " << this->gas << " km" << std::endl;
                    this->gas = 0;
                } 
                
            
            }else{
            std::cout << "fail: tanque vazio" << std::endl;
        }
        }else{
            std::cout << "fail: nao ha ninguem no carro" << std::endl;
        }
    }
    std::string str(){
        return fn::format("pass: {}, gas: {}, km: {}", this->pass, this->gas, this->km);
    };
    

};

struct Student {
    Carro carro;

    Student() {};

    void enter() {
        carro.enter();
    }
    void leave() {
        carro.leave();
    }
    void fuel(int qtd) {
        carro.fuel_qtd(qtd);
        (void) qtd;
    }
    void drive(int qtd) {
        carro.drive_dist(qtd);
        (void) qtd;
    }
    void show() {
        std::cout << carro.str() << std::endl;
    }
};

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};
