#include <iostream>
#include "fn.hpp"

class Pessoa{
    private:
    std::string name;
    int money;

    public:
    Pessoa(std::string nome = " ", int dinheiro = 0): name(nome), money(dinheiro) {}

    std::string str(){
        return fn::format("{}:{}", name, money);
    }

    std::string get_name(){
        return this->name;
    }

    int get_money(){
        return this->money;
    }

    void set_money(int valor){
        money += valor;
    }

};

class Moto{
    private:
    int value{0};
    std::shared_ptr<Pessoa> motorista {nullptr};
    std::shared_ptr<Pessoa> passageiro {nullptr};

    public:
    Moto() {}

    std::string str(){
        if(motorista == nullptr && passageiro == nullptr){
            return fn::format("Cost: {}, Driver: None, Passenger: None", value);
        }
        if(motorista == nullptr){
            return fn::format("Cost: {}, Driver: None, Passenger: {}", value, passageiro->str());
            
        }
        if(passageiro == nullptr){
            return fn::format("Cost: {}, Driver: {}, Passenger: None", value, motorista->str());
        }
        return fn::format("Cost: {}, Driver: {}, Passenger: {}", value, motorista->str(), passageiro->str());
    }
    void set_motorista(std::shared_ptr<Pessoa> motoqueiro){
        if(motorista == nullptr){
            motorista = motoqueiro;
        }
    }
    void set_passageiro(std::shared_ptr<Pessoa> cliente){
        if(passageiro == nullptr){
            passageiro = cliente;
        }
    }
    void corrida(int valor){
        value += valor;
    }

    void finalizar(){
        if(passageiro != nullptr){
            if(value > passageiro->get_money()){
                fn::write("fail: Passenger does not have enough money");
                fn::print("{}:0 leave\n", passageiro->get_name());
                motorista->set_money(value);
                value = 0;
                passageiro = nullptr;
                return;
            }
            fn::print("{}:{} leave\n", passageiro->get_name(), value);
            motorista->set_money(value);
            value = 0;
            passageiro = nullptr;
            return;
        }
    }


};




class Adapter {
    Moto moto;
public:
    void setDriver(std::string name, int money) {
        (void) name;
        (void) money;
        auto person = std::make_shared<Pessoa>(name, money);
        moto.set_motorista(person);
    }
    void setPass(std::string name, int money) {
        (void) name;
        (void) money;
        auto person = std::make_shared<Pessoa>(name, money);
        moto.set_passageiro(person);
    }
    void drive(int distance) {
        (void) distance;
        moto.corrida(distance);
    }
    void leavePass() {
        moto.finalizar();
    }
    void show() {
        std::cout << moto.str() << '\n';
    }
};

int main() {
    Adapter adp;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")       { break;                                  }
        else if (args[0] == "setDriver") { adp.setDriver(args[1], +args[2]);       }
        else if (args[0] == "setPass")   { adp.setPass(args[1], +args[2]);         }
        else if (args[0] == "drive")     { adp.drive(+args[1]);                    }
        else if (args[0] == "leavePass") { adp.leavePass();                        }
        else if (args[0] == "show")      { adp.show();                             }
        else                             { fn::write("fail: command not found\n"); }
    }
}