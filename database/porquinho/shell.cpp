#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <iomanip>
#include <memory>
#include "porquinho.hpp"
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ", string prefix = "[", string suffix = "]") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return prefix + ss.str() + suffix;
}

int main() {
    Porco porco(0);
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int volumeMax;
            ss >> volumeMax;
            porco = Porco(volumeMax);
        } else if (cmd == "show") {
            std::cout << porco.to_string() << std::endl;
        } else if (cmd == "break") {
            porco.quebrar();
        } else if (cmd == "addCoin") {
            string label;
            ss >> label;
            porco.add_moeda(label);
        } else if (cmd == "addItem") {
            string label;
            int volume;
            ss >> label >> volume;
            porco.add_item(Item(label, volume));
        } else if (cmd == "extractItems") {
            porco.extract_items();
        } else if (cmd == "extractCoins") {
            porco.extract_coins();
        } else {
            cout << "fail: invalid command\n";
        }
    }
}
