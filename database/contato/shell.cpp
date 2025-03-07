#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "contato.hpp"

using namespace std;

template <class CONTAINER, class FUNC>
string map_join(const CONTAINER &cont, FUNC func, string sep = " ")
{
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
        ss << (it == cont.begin() ? "" : sep) << func(*it);
    }
    return ss.str();
}
int main()
{
    Contato contato("david");
    while (true)
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            string name;
            ss >> name;
            contato = Contato(name);



        }
        else if (cmd == "add")
        {
            string id, number;
            ss >> id >> number;
            contato.add_fone(id, number);
        }
        else if (cmd == "rm")
        {
            int index{};
            ss >> index;
            contato.rm_fone(index);
        }
        else if (cmd == "tfav"){
            contato.add_fav();
        }
        else if (cmd == "showfav"){
            std::cout << contato.toString() << std::endl;
        }
        else if (cmd == "show"){
            std::cout << contato.toString() << std::endl;
        
        }
        else
        {
            cout << "fail: comando invalido" << endl;
        }
    }
}
