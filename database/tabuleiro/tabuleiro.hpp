#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


class Jogador {
private:
    int num {0};
    int pos {0};
    bool livre {false};

public:
    Jogador(int num) : num(num), pos(0), livre(true) {}

    int get_num() const {
        return num;
    }

    int get_pos() const {
        return pos;
    }

    void set_pos(int pos) {
        this->pos = pos;
    }


    bool livre_() {
        return livre;
    }

    void set_livre(bool livre) {
        this->livre = livre;
    }

    std::string toString(int tam) const {
        std::string result(tam, '.');
        if (pos > 0 && pos <= tam) {
            result[pos - 1] = std::to_string(num)[0];
        }
        return result;
    }
};

class Tabuleiro {
private:
    std::vector<int> armadilha;
    std::vector<Jogador> jogador;
    bool andar {false};
    int tam {0};
    int vez {0};

public:
    Tabuleiro (int njogador, int ntam) : andar(true), tam(ntam) {
        for (int i = 1; i <= njogador; i++) {
            jogador.push_back(i);
        }
    }

    
    void add_arma(int pos) {
        if (pos >= 0 && pos <= tam) {
            armadilha.push_back(pos);
        }
    }

    void dado(int value) {
        if (!andar) {
            std::cout << "game is over\n";
            return;
        }


        Jogador& Jogador = jogador[vez];
        if (Jogador.livre_() == true) {
            Jogador.set_pos(Jogador.get_pos() + value);
            if (Jogador.get_pos() > tam) {
                std::cout << "player" << jogador[vez].get_num() << " ganhou" << "\n";
                andar = false;
                return;
            }else{
                std::cout << "player" << jogador[vez].get_num() << " andou para " << Jogador.get_pos() << "\n";
                if(std::find(armadilha.begin(), armadilha.end(), Jogador.get_pos()) != armadilha.end()) {
                    std::cout << "player" << jogador[vez].get_num() << " caiu em uma armadilha" << "\n";
                    Jogador.set_livre(false);
                }
            }
            vez = (vez + 1) % jogador.size();
        } else{
            if(value % 2 == 0) {
                Jogador.set_livre(true);
                std::cout << "player" << jogador[vez].get_num() << " se libertou" << "\n";
            } else {
                std::cout << "player" << jogador[vez].get_num() << " continua preso" << "\n";
            }
            vez = (vez + 1) % jogador.size();
        }
            
        
    }

    std::string str() const {
        std::ostringstream ss;

        for (const auto& Jogador : jogador) {
            ss << "player" << Jogador.get_num() << ": " ;
            for(int i = 0; i <= tam; i++) {
                if (i == Jogador.get_pos()) {
                    ss << Jogador.get_num();
                } else if (i == tam && Jogador.get_pos() >= tam) {
                    ss << Jogador.get_num();
                } else {
                    ss << ".";
                }
            }
            ss << "\n";
        }

        ss << "traps__: ";
        for (int i = 0; i <= tam; i++) {
            ss << (std::find(armadilha.begin(), armadilha.end(), i) != armadilha.end() ? "x" : ".");
        }

    
        return ss.str();
    }

    
};

