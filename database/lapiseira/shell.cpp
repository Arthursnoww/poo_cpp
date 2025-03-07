#include <iostream>
#include <list>
#include <sstream>
#include <memory>
#include "lapiseira.hpp"
using namespace std;

// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "");
        ss << f(*it);
    }
    return ss.str();
}

int main() {
    Lapiseira lapiseira(0.5);

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;  
        }
        else if (cmd == "show") { 
            fn::write(lapiseira.str());
        } 
        else if (cmd == "init") { 
            float calibre;
            ss >> calibre;
            lapiseira = Lapiseira(calibre);
        } 
        else if (cmd == "insert") { 
            float calibre;
            string dureza;
            int tamanho;
            ss >> calibre >> dureza >> tamanho;
            lapiseira.insert_grafite(std::make_shared<Grafite>(calibre, dureza, tamanho));
        } 
        else if (cmd == "remove") { 
            lapiseira.remove();
        } 
        else if (cmd == "pull") { 
            lapiseira.pull();
        } 
        else if (cmd == "write") { 
            lapiseira.write();
        } 
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
