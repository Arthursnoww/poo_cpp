#pragma once
#include <iostream>
#include <memory>
#include "fn.hpp"

class Pessoa{
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade): nome(nome), idade(idade) {}

    std::string get_nome(){
        return this->nome;
    }

    int get_idade(){
        return this->idade;
    }

    std::string str() const{
        return fn::format("{}:{}", nome, idade);
    }
};

std::ostream& operator<<(std::ostream &os, const Pessoa& pessoa) {
    return os << pessoa.str();
}

class Moto{
    int potencia {0};
    int tempo {0};
    std::shared_ptr<Pessoa> pessoa {nullptr};

public:
    Moto(int potencia): potencia(potencia){}

    void insert_person(std::shared_ptr<Pessoa> pessoa){
        if(this->pessoa == nullptr){
            this->pessoa = pessoa;
        }else if(this->pessoa != nullptr){
            fn::write("fail: busy motorcycle");
        }
    }

    std::shared_ptr<Pessoa> remove(){
        if(this->pessoa == nullptr){
           fn::write("fail: empty motorcycle");
           return nullptr;
        }
        auto backup = this ->pessoa;
        this->pessoa = nullptr;
        return backup;
    }

    void buy_time(int time){
        this->tempo += time;
    }

    void drive(int time){
        if(this->tempo == 0){
            fn::write("fail: buy time first");
            return;
        }
        if(this->pessoa == nullptr){
            fn::write("fail: empty motorcycle");
            return;
        }if(this->pessoa->get_idade() > 10){
            fn::write ("fail: too old to drive");
            return;
        }if(this->tempo < time){
            fn::print("fail: time finished after {} minutes\n", this->tempo);
            this->tempo = 0;
            return;
        }
        this->tempo -= time;
    }
    std::string honk() const{
        auto saida = "P"s;
        for(int i = 0; i < (int) this->potencia; i++){
            saida += 'e';
        }
        return saida + 'm';
    }
    std::string str() const{
        std::string nome ("empty");
        if(this->pessoa != nullptr){
            nome = this->pessoa->str();
        }
        return fn::format("power:{}, time:{}, person:({})", this->potencia, this->tempo, nome);

    }
};

std::ostream& operator<<(std::ostream &os, const Moto& moto) {
    return os << moto.str();
}

class Student {
    Moto moto;
public:

    Student(int power = 1):moto(power) {
    }

    void enter(std::string name, int age) {
        auto person = std::make_shared<Pessoa>(name, age);
        moto.insert_person(person);
        (void) name;
        (void) age;
    }

    void leave() {
        auto person = moto.remove();
        fn::write(person == nullptr ? "---" : person->str());
    }

    void honk() const {
        fn::write(moto.honk());
    }

    void buy(int time) {
        moto.buy_time(time);
        
    }

    void drive(int time) {
        moto.drive(time);
    }

    void show() const {
        fn::write(moto.str());
    }
};