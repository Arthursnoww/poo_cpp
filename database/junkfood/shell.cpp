#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <memory>
#include "junk.hpp"

using namespace std;

template<typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim);
        ss << func(*it);
    }
    return ss.str();
}


int main() {
    Maquina maquina(10);

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        try {
            if (cmd == "show") {
                cout << maquina.str() << '\n';
            } else if (cmd == "init") {
                int n_espirais {};
                ss >> n_espirais;
                maquina = Maquina(n_espirais);
            } else if (cmd == "limpar") {
                int indice {};
                ss >> indice;
                maquina.limpar(indice);
            } else if (cmd == "dinheiro") {
                int value {};
                ss >> value;
                maquina.inserir_money(value);
            } else if (cmd == "comprar") {
                int index {};
                ss >> index;
                maquina.comprar(index);
            } else if (cmd == "set") {
                int index {};
                string name;
                int qtd {};
                double price {};
                ss >> index >> name >> qtd >> price;
                maquina.set_produto(index, name, qtd, price);
            } else if (cmd == "troco") {
                auto troco = maquina.troco();
                cout << "voce recebeu " 
                     << fixed << setprecision(2) << troco
                     << " RS" << '\n';
            } else if (cmd == "end") {
                break;
            } else {
                cout << "comando invalido" << endl;
            }
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    return 0;
}
