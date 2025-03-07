#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "draft.cpp" 

int main() {
    Notebook notebook;

    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        std::cout << "$" << line << std::endl;

        if (command == "end") {
            break;

        } else if (command == "show") {
            notebook.mostrar();

        } else if (command == "turn_on") {
            notebook.set_note();

        } else if (command == "turn_off") {
            notebook.desligar_note();

        } else if (command == "use") {
            int time;
            ss >> time;
            notebook.usar(time);

        } else if (command == "set_battery") {
            int capacity;
            ss >> capacity;
            auto battery = std::make_shared<Bateria>(capacity);
            notebook.set_bateria(battery);

        } else if (command == "rm_battery") {
            notebook.remove_bateria();

        } else if (command == "set_charger") {
            int power;
            ss >> power;
            auto charger = std::make_shared<Carregador>(power);
            notebook.set_carregador(charger);

        } else if (command == "rm_charger") {
            notebook.remove_carregador();

        } else {
            std::cout << "fail: comando inválido" << std::endl;
        }
    }

    return 0;
}
