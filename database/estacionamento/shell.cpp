#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "estacionamento.hpp"

using namespace std;

int main() {
    Estacionamento estacionamento;
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            std::cout << estacionamento.to_string() << std::endl;
        } else if (cmd == "estacionar") {
            string tipo, id;
            ss >> tipo >> id;
            estacionamento.estacionar(tipo, id);
        } else if (cmd == "tempo") {
            float tempo {};
            ss >> tempo;
            estacionamento.set_hora_atual(tempo);
        } else if (cmd == "pagar") {
            string id;
            ss >> id;
            estacionamento.pagar(id);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
