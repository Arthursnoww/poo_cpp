#include <iostream>
#include <memory>
#include <sstream>
#include <list>
#include "pula.cpp"
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

    Pulapula pula;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            cout << pula.str() << endl;
        } else if (cmd == "arrive") {
            string name;
            int age;
            ss >> name >> age;
            auto child = std::make_shared<Muleke>(age, name);
            pula.fila(child);

        } else if (cmd == "enter") {
            pula.enter();
        } else if (cmd == "leave") {
            pula.leave();
        } else if (cmd == "remove") {
            string name;
            ss >> name;
            pula.remove(name);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
