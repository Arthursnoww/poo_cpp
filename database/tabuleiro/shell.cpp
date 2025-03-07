#include <iostream>
#include <vector>
#include <sstream>
#include "tabuleiro.hpp"
using namespace std;

int main() {
    Tabuleiro tabuleiro(0, 0);
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int nPlayers, size;
            ss >> nPlayers >> size;
            tabuleiro = Tabuleiro(nPlayers, size);
        } else if (cmd == "addTrap") {
            int pos;
            ss >> pos;
            tabuleiro.add_arma(pos);
        } else if (cmd == "roll") {
            int value;
            ss >> value;
            tabuleiro.dado(value);
        } else if (cmd == "show") {
            std::cout << tabuleiro.str() << std::endl;
        } else {
            cout << "fail: command not found" << endl;
        }

    }
}
