#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <iomanip>
#include <memory>

class Item{
    std::string label;
    int volume = 0;
public:
    Item(std::string label, int volume) : label(label), volume(volume) {}

    int get_volume() const {
        return volume;
    }

    std::string get_label() const {
        return label;
    }

    void set_volume(int volume) {
        this->volume = volume;
    }

    void set_label(std::string label) {
        this->label = label;
    }



    std::string to_string() const {
        std::stringstream ss;
        ss << label << ":" << volume;
        return ss.str();
    }
};


class Moeda{
    std::string label;
    float valor = 0;
    int vol = 0;
    

public:
    Moeda(std::string label, float valor, int vol) : label(label), valor(valor), vol(vol) {}

    const static Moeda C10;
    const static Moeda C25;
    const static Moeda C50;
    const static Moeda C100;

    float get_valor() const {
        return valor;
    }   

    int get_vol() const {
        return vol;
    }

    std::string tostring() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << valor << ":" << vol;
        return ss.str();
    }
};

const Moeda Moeda::C10 {"C10", 0.10, 1};
const Moeda Moeda::C25 {"C25", 0.25, 2};
const Moeda Moeda::C50 {"C50", 0.50, 3};
const Moeda Moeda::C100 {"C100", 1.00, 4};


class Porco{
    int volumemax;
    std::vector<Moeda> moedas;
    std::vector<Item> itens;
    bool quebrado = false;
    float valor = 0;
    int volume = 0;

public:
    Porco(int volumemax) : volumemax(volumemax) {}

    /*float get_volume() const {
        float volume = 0;
        for (auto& item : itens) {
            volume += item.get_volume();
        }
        return volume;
    }*/

    /*int get_value() const {
        float volume = 0;
        for (auto& item : itens) {
            volume += item.get_volume();
        }
        return volume;
    }*/

    void add_moeda(std::string value) {
        if(quebrado){
            std::cout << "fail: the pig is broken" << std::endl;
            return;
        }
        if (volume + volume > volumemax) {
            std::cout << "fail: the pig is full" << std::endl;
            return;
        }
        if (value == "10") {
            moedas.push_back(Moeda::C10);
            valor += 0.10;
            volume += 1;
        } else if (value == "25") {
            moedas.push_back(Moeda::C25);
            valor += 0.25;
            volume += 2;
        } else if (value == "50") {
            moedas.push_back(Moeda::C50);
            valor += 0.50;
            volume += 3;
        } else if (value == "100") {
            moedas.push_back(Moeda::C100);
            valor += 1.00;
            volume += 4;
        } else {
            return;
        }
        return;
    }


    void add_item(Item item) {
        if(quebrado){
            std::cout << "fail: the pig is broken" << std::endl;
            return;
        }
        if (volume + item.get_volume() > volumemax) {
            std::cout << "fail: the pig is full" << std::endl;
            return;
        }
        
        itens.push_back(item);
        volume += item.get_volume();
    }

    std::vector<Moeda> extract_coins() {
        if(quebrado == false){
            std::cout << "fail: you must break the pig first" << std::endl;
            std::cout << "[]" << std::endl;
            return {};
        }
        std::vector<Moeda> retiradas = moedas;
        moedas.clear();
        valor = 0;
        std::cout << "[";
        for (size_t i = 0; i < retiradas.size(); i++) {
            std::cout << retiradas[i].tostring();
            if (i < retiradas.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
            volume = 0;
        return retiradas;
    }

    std::vector<Item> extract_items() {
        if(quebrado == false){
            std::cout << "fail: you must break the pig first" << std::endl;
            std::cout << "[]" << std::endl;
            return {};
        }
        std::vector<Item> retiradas = itens;
        itens.clear();
        std::cout << "[";
        for (size_t i = 0; i < retiradas.size(); i++) {
            std::cout << retiradas[i].to_string();
            if (i < retiradas.size() - 1) { 
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        volume = 0;
        return retiradas;
    }
    


    bool is_quebrado() const {
        return quebrado;
    }

    void quebrar() {
        quebrado = true;
        volume = 0;
    }

    std::string to_string() const {
        std::ostringstream ss;

        ss << "state=" << (quebrado ? "broken" : "intact")
        << " : coins=[";
        
        for (size_t i = 0; i < moedas.size(); i++) {
            if (i > 0) ss << ", ";  
            ss << moedas[i].tostring();
        }

        ss << "] : items=[";

        for (size_t i = 0; i < itens.size(); i++) {
            if (i > 0) ss << ", ";  
            ss << itens[i].to_string();
        }

        
        ss << "] : value=" << std::fixed << std::setprecision(2) << valor
        << " : volume=" << volume << "/" << volumemax;

        return ss.str();
    }
    

    

    
};