#pragma once
#include "fn.hpp"

struct Calculator{
    int battery;
    int batterymax;
    float display;

    Calculator(int btmax){
        battery = 0;
        batterymax = btmax;
        display = 0.00;
    }

    std::string str() const {
    // a biblioteca auxiliar de formatação permite formatar como o format do python
    return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }


    void charge(int value){
        battery += value;
        if(battery > batterymax){
            battery = batterymax;
        }
    }

    void somar(int a, int b){
        if(battery > 0){
            display = a + b;
            battery--;
        }else{
            std::cout << "fail: bateria insuficiente" << std::endl;
        }
    }
    void div(int num, int den){
        if(battery > 0){
            if(den == 0){
                std::cout << "fail: divisao por zero" << std::endl;
                battery--;
            }else{
                display = static_cast<float>(num) / den;
                battery--;
            }
        }else{
            std::cout << "fail: bateria insuficiente" << std::endl;
        }

    }

};

class Student {

    Calculator c;
public:
    Student() :
        c(0){
    }
    void show() {
        std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        c = Calculator(batteryMax);
        //(void) batteryMax;
    }
    void charge(int value) {
        c.charge(value);
        // // ACT!
        // // (void) value;
    }
    void sum(int a, int b) {
        c.somar(a, b);
        // // ACT!
        // // (void) a;
        // // (void) b;
    }
    void div(int num, int den) {
        c.div(num, den);
        // // ACT!
        // // (void) num;
        // // (void) den;
    }
};
