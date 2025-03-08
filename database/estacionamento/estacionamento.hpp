#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

class Veiculo {
    std::string id;
    std::string tipo;
    float tempo = 0;
    float valor = 0.0;
public:
    Veiculo(std::string id, std::string tipo) : id(id), tipo(tipo) {}
    
    virtual float calcular_valor(float temp) = 0;
    virtual ~Veiculo() {}

    float get_tempo() {
        return tempo;
    }
    void set_tempo(float temp) {
        this->tempo = temp;
    }
    std::string get_id() {
        return id;
    }

    void set_id(std::string id) {
        this->id = id;
    }

    std::string get_tipo() {
        if(tipo == "bike"){
            return "Bike";
        }else if(tipo == "moto"){
            return "Moto";
        }else if(tipo == "carro"){
            return "Carro";
        }
        return "Tipo invalido";
    }

    void set_tipo(std::string tip) {
        this->tipo = tip;
    }

    void get_valor(float temp){
        if (tipo == "carro") {
            this->valor = temp/10 >= 5 ? temp/10 : 5.0;
        } else if (tipo == "moto") {
            this->valor = temp/10;
        } else if (tipo == "bike") {
            this->valor = 3;
        }
    }

    virtual std::string toString() const {
        std::stringstream ss;
        ss << std::setw(10) << std::setfill('_') << tipo << " : " 
           << std::setw(10) << std::setfill('_') << id << " : " 
           << tempo;
        return ss.str();
    }
};

class Bicicleta : public Veiculo {
    public:
        Bicicleta(std::string id) : Veiculo(id, "bike") {}
    
        float calcular_valor([[maybe_unused]] float temp) override {
            return 3.0;
        }
    };
    

class Moto : public Veiculo {
public:
    Moto(std::string id) : Veiculo(id, "moto") {}
    float calcular_valor(float temp){
        
        return temp/20;
    }
};

class Carro : public Veiculo {
public:
    Carro(std::string id) : Veiculo(id, "carro") {}
    float calcular_valor(float temp){
        return temp/10 >= 5 ? temp/10 : 5.0;
    }
};

class Estacionamento{
    std::vector<Veiculo*> veiculos;
    int hora_atual = 0;
public:

    void set_hora_atual(int hora_atual){
        this->hora_atual += hora_atual;
    }

    void estacionar(std::string tipo, std::string id) {
        Veiculo* veiculo = nullptr;
        if (tipo == "bike"){
            veiculo = new Bicicleta(id);
            veiculo->set_tempo(hora_atual);
        }else if (tipo == "moto"){ 
            veiculo = new Moto(id);
            veiculo->set_tempo(hora_atual);
        }else if (tipo == "carro"){
            veiculo = new Carro(id);
            veiculo->set_tempo(hora_atual);
        }
        if (veiculo) {
            veiculo->set_tempo(hora_atual);
            veiculos.push_back(veiculo);
        }
    }

    void pagar(std::string id) {
        auto it = std::find_if(veiculos.begin(), veiculos.end(),
                               [&](Veiculo* v) { return v->get_id() == id; });
    
        if (it != veiculos.end()) {
            Veiculo* veiculo = *it;
    
            
            std::cout << veiculo->get_tipo() << " chegou " <<(int)veiculo->get_tempo()
                      << " saiu "  << hora_atual
                      << ". Pagar R$ " << std::fixed << std::setprecision(2)
                      << veiculo->calcular_valor(hora_atual-(int)veiculo->get_tempo()) << std::endl;
    
            
            veiculos.erase(it); 
            delete veiculo;     
    
            return;
        }
    
        std::cout << "Veiculo nao encontrado" << std::endl;
    }
    

    std::string to_string(){
        std::stringstream ss;
        for (auto& veiculo : veiculos) {
            ss << std::setw(10) << std::setfill('_') << veiculo->get_tipo() << " : "
               << std::setw(10) << std::setfill('_') << veiculo->get_id() << " : "
               << veiculo->get_tempo() << std::endl;
        }
        ss << "Hora atual: " << hora_atual;
        return ss.str();
    }
};