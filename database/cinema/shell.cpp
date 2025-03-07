#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include "cinema.hpp"
using namespace std;

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

int main() {
    Sala sala(0);

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;    
        } else if (cmd == "show") {
            std::cout << sala.toString() << std::endl;

        } else if (cmd == "init") {
            int qtd;
            ss >> qtd;
            sala = Sala(qtd);
        
        } else if (cmd == "reserve") {
            string id, phone;
            int index;
            ss >> id >> phone >> index;
            sala.reserve(id, stoi(phone), index);
        } else if (cmd == "cancel") {
            string id;
            ss >> id;
            sala.cancelar(id);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
