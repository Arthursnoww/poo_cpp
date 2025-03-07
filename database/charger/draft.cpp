#include <iostream>
#include <string>
#include <memory>

class Bateria {
private:
    int carga {0};
    int capacidade {0};

public:
    Bateria(int btr) : carga(btr), capacidade(btr) {}

    int get_capacidade() const {
        return capacidade;
    }

    int get_carga() const {
        return carga;
    }

    void set_carga(int qtd) {
        carga = carga + qtd; 
        if(this->carga > this->capacidade){
            carga = capacidade;
        }
    }
    void consumir(int qtd) {
        if (carga >= qtd) {
            carga -= qtd;
        } else {
            carga = 0;
        }
    }

    void mostrar() {
        std::cout << "Bateria: (" << carga << "/" << capacidade << ")" << std::endl;
    }
};

class Carregador {
private:
    int potencia {0};

public:
    Carregador(int p) : potencia(p) {}

    int get_potencia() const {
        return potencia;
    }

    void mostrar() const {
        std::cout << "Carregador: (Potência " << potencia << ")" << std::endl;
    }
};

class Notebook {
private:
    bool ligado {false};
    std::shared_ptr<Bateria> bateria {nullptr};
    std::shared_ptr<Carregador> carregador {nullptr};
    int time {0};

public:
    void set_bateria(std::shared_ptr<Bateria> b) {
        this->bateria = b;
    }

    void set_carregador(std::shared_ptr<Carregador> c) {
        if(this->carregador != nullptr){
            std::cout << "fail: carregador já conectado" << std::endl;
            return;
        }
        this->carregador = c;
    }

    void remove_carregador() {
        if (this->carregador == nullptr) {
            std::cout << "fail: Sem carregador" << std::endl;
            return;
        }
        
        std::cout << "Removido " << this->carregador->get_potencia()<< "W" << std::endl;
        this->carregador = nullptr;
        this->ligado = false;
    }

    void mostrar(){
        if(this->ligado == false && this->carregador == nullptr && this->bateria == nullptr ){
            std::cout << "Notebook: desligado" << std::endl;
            return;
        }if(this->ligado == false && this->carregador != nullptr){
            std::cout << "Notebook: desligado, Carregador "<< this->carregador->get_potencia() << "W" << std::endl;
            return;
        }if(this->ligado == true && this->carregador != nullptr && this->bateria == nullptr){
            std::cout << "Notebook: ligado por " << this->time << " min, Carregador "<< this->carregador->get_potencia() << "W" << std::endl;
            return;
        }if(this->ligado == false && this->bateria != nullptr){
            std::cout << "Notebook: desligado, " << "Bateria " << this->bateria->get_carga() << "/" << this->bateria->get_capacidade()  << std::endl;
            return;
        }if(this->ligado == true && this->bateria != nullptr && this->carregador == nullptr){
            std::cout << "Notebook: ligado por " << this->time << " min, Bateria " << this->bateria->get_carga() << "/" << this->bateria->get_capacidade()  << std::endl;
            return;
        }if(this->ligado == true && this->bateria != nullptr && this->carregador != nullptr){
            std::cout << "Notebook: ligado por " << this->time << " min, Carregador "<< this->carregador->get_potencia() << "W," 
            <<" Bateria " << this->bateria->get_carga() << "/" << this->bateria->get_capacidade()  << std::endl;
        }if(this->ligado == true && this->bateria == nullptr && this->carregador != nullptr){
            std::cout << "Notebook: ligado por " << this->time << " min, Carregador "<< this->carregador->get_potencia() << "W" 
            << std::endl;
        }
    }

    void set_note() {
         if(this->carregador == nullptr && this->bateria == nullptr ){
            std::cout << "fail: não foi possível ligar" << std::endl;
            return;
        }
        this->ligado = true;
    }

    void desligar_note() {
        if (this->ligado == false) {
            std::cout << "notebook ja está desligado" << std::endl;
            return;
        }
        this->ligado = false;
        
    }

    void usar(int time) {
        if (this->ligado == false) {
            std::cout << "fail: desligado" << std::endl;
            return;
        }
        if(this->bateria != nullptr && this->carregador == nullptr ){
            this->bateria->consumir(time);
            if(this->bateria->get_carga() == 0){
                std::cout << "fail: descarregou" << std::endl;
                this->ligado = false;
                return;
            }
            
        }
        if(this->bateria != nullptr && this->carregador != nullptr ){

            this->bateria->set_carga(time * this->carregador->get_potencia() );
            
        }
        this->time += time;

 
        }

    void remove_bateria() {
        if (this->bateria == nullptr ) {
            std::cout << "fail: Sem bateria" << std::endl;
            return;
        }if(this->carregador != nullptr && this->bateria != nullptr){
            std::cout << "Removido " << this->bateria->get_carga() << "/" << this->bateria->get_capacidade()  << std::endl;
            this->bateria = nullptr;
            this->ligado = true;
            return;
        }
        std::cout << "Removido " << this->bateria->get_carga() << "/" << this->bateria->get_capacidade()  << std::endl;
        this->bateria = nullptr;
        ligado = false;
        

    }
};

/*class Student {
private:
    Notebook notebook;
public:
    Student(int cpt, int pot) {
        auto btr = std::make_shared<Bateria>(cpt);
        auto carregador = std::make_shared<Carregador>(pot);
        notebook.set_bateria(btr);
        notebook.set_carregador(carregador);

    }

    void charge() {
        auto carregador = std::make_shared<Carregador>(5);
        notebook.set_carregador(carregador);


    }

    void ligar() {
        notebook.set_note();
    }

    void mostrar() {
        notebook.mostrar();
    }

    void desligar() {
        notebook.desligar_note();
    }

    void bateria() {
        auto btr = std::make_shared<Bateria>(50);
        notebook.set_bateria(btr);
    }

};*/