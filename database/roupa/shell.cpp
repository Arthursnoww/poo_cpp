#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class Roupa{
    private:
    std::string tam;

    public:
    Roupa(std::string tamm = ""): tam(tamm){}

    void get_tam(){
        std::cout << "size: "<< "(" << tam << ")" << std::endl;
    }

    void set_tam(std::string tt){
        if(tt == "PP"){
            tam = tt;
        }
        else if(tt == "P"){
             tam = tt;
        }
        else if(tt == "M"){
            tam = tt;
        }
        else if(tt == "G"){
             tam = tt;
        }
        else if(tt == "GG"){
             tam = tt;
        }
        else if(tt == "XG"){
             tam = tt;
        }else{
            cout << "fail: Valor inválido, tente PP, P, M, G, GG ou XG" << endl;
        }
    } 
};

int main() {
    Roupa roupa("");

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        
        stringstream ss(line);
        ss >> cmd;

        if (cmd == "size") { 
            string size;
            ss >> size;
            roupa.set_tam(size);
        } 
        else if (cmd == "show") {
            roupa.get_tam();
        } 
        else if (cmd == "end") {
            break;
        } 
        else {
            cout << "fail: Comando inválido" << endl;
        }
    }
}
