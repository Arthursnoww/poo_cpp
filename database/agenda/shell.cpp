#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "agenda.hpp"
using namespace std;

template <typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string sep = " ") {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : sep);
        ss << func(*it);
    }
    return ss.str();
}

pair<string, string> decodeFone(string fone) {
    stringstream ss(fone);
    string id, number;
    getline(ss, id, ':');
    getline(ss, number);
    return {id, number};
}

int main() {
    Agenda agenda;
    Contato contato("fulano");
    Fone fone("oi", "1234");
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        } else if(cmd == "add") {//name id:fone id:fone ...
            string name;
            ss >> name;
            vector<Fone> fones;
            string token;
            while(ss >> token) {
                 auto [id, number] = decodeFone(token);
                 fones.push_back(Fone(id, number));
            }
            agenda.add_contato(name, fones);
        } else if(cmd == "show") {
            std::cout << agenda.toString() << std::endl;
        } else if(cmd == "rmFone") {//id index
            string name;
            int index;
            ss >> name >> index;
            agenda.rm_fone(name, index);
        } else if(cmd == "rm") {//id
            string name;
            ss >> name;
            agenda.rm_contato(name);
        } else if(cmd == "tfav") {//id 1 ou 0
            string name;
            ss >> name;
            agenda.fav(name);
        } else if(cmd == "favs") {
            std::cout << agenda.favs() << std::endl;
        } else if(cmd == "search") {
            std::string pattern;
            ss >> pattern;
            agenda.pesquisa(pattern);
        } else{
            cout << "fail: comando invalido" << endl;
        }
    }
}
