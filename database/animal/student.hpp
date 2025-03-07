#pragma once
#include "fn.hpp"

struct Animal{
    std::string especie;
    std::string barulho;
    int idade;

    Animal(std::string especie = "", std::string barulho = ""){
        this->especie = especie;
        this->barulho = barulho;
        this->idade = 0;
    }


    std::string makenoise(){
        if(this->idade == 0){
            return "---";
        }else if(this->idade == 4){
            return "RIP";
        }else{
            return barulho;
        }
        
    }

    void old(int nivel){
        idade += nivel;
        if(this->idade >= 4){
            this->idade = 4;
            std::cout << "warning: " << especie << " morreu" << std::endl;
        }
    }

    std::string str(){
        return especie + ":" + std::to_string(idade) + ":" + barulho;
    }

};


struct Student {
    Animal animal;
    Student(std::string especie = "", std::string barulho = "") {
        animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        animal.old(nivel);
    }

    void noise() {
        
        std::cout << animal.makenoise() << std::endl;
    }

    void show() {
        std::cout << animal.str() << std::endl;
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