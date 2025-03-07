#include <sstream>
#include <iostream>
#include "agiota.hpp"
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return ss.str();
}

int main() {
    Agiota agiota;
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        }
        else if(cmd == "addCli") {
            string name;
            int limite {};
            ss >> name >> limite;
            agiota.add_cliente(name, limite);
        }
        else if(cmd == "show") {
            std::cout << agiota.to_string() << std::endl;
        }
        else if(cmd == "showCli") {
            string name;
            ss >> name;
            agiota.pesquisar(name);

        }
        else if(cmd == "kill") {
            string name;
            ss >> name;
            agiota.matar(name);
        }
        else if(cmd == "give") {
            string name;
            int value;
            ss >> name >> value;
            agiota.emprestar(name, value);
        }
        else if(cmd == "take") {
            string name;
            int value;
            ss >> name >> value;
            agiota.pagar(name, value);
        }
        else if(cmd == "plus") {
            agiota.plus();
        }
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
