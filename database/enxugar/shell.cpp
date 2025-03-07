#include <iostream>
#include <sstream>
using namespace std;

class Toalha {
private:
    std::string cor;
    char tam;
    int umi;

public:
    Toalha(std::string corr, char tamm, int umm = 0) : cor(corr), tam(tamm), umi(umm) {}

    int get_max() {
        if (tam == 'P') {
            return 10;
        }
        if (tam == 'M') {
            return 20;
        }
        if (tam == 'G') {
            return 30;
        }
        return 0;
    }

    void enxugar(int quantidade) {
        int maxUmidade = get_max();
        if (this->umi + quantidade >= maxUmidade) {
            std::cout << "toalha encharcada" << std::endl;
            umi = maxUmidade;
        } else {
            
            umi += quantidade;
        }
    }

    void torcer() {
        umi = 0;
    }

    bool esta_seca() {
        return umi == 0;
    }

    std::string mostrar() {
        std::stringstream ss;
        ss << "Cor: " << cor << ", Tamanho: " << tam << ", Umidade: " << umi;
        return ss.str();
    }
};

int main() {
    Toalha toalha("Azul", 'P');

    while (true) {
        string line, cmd;
        getline(cin, line);
        stringstream par(line);
        par >> cmd;

        if (cmd == "mostrar") { 
            cout << "$mostrar" << endl;
            cout << toalha.mostrar() << endl;
        } 
        else if (cmd == "criar") { 
            string cor; 
            char tamanho;
            par >> cor >> tamanho;
            toalha = Toalha(cor, tamanho);
            cout << "$criar " << cor << " " << tamanho << endl;
        } 
        else if (cmd == "enxugar") { 
            int umidade {};
            par >> umidade;
            cout << "$enxugar " << umidade << endl;
            toalha.enxugar(umidade);
        } 
        else if (cmd == "torcer") { 
            cout << "$torcer" << endl;
            toalha.torcer();
        } 
        else if (cmd == "seca") { 
            cout << "$seca" << endl;
            if (toalha.esta_seca()) {
                cout << "sim" << endl;
            } else {
                cout << "nao" << endl;
            }
        } 
        else if (cmd == "end") {
            cout << "$end" << endl;
            break;
        } 
        else {
            cout << "fail: comando invalido" << endl;
        }
    }

    return 0;
}
