#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

class Produto{
    private:
        std::string nome;
        float preco;
        int qtd;
    public:
    Produto(std::string nome, float preco, int qtd): nome(nome), preco(preco), qtd(qtd){}

    std::string get_nome(){
        return this->nome;
    }

    float get_preco(){
        return this->preco;
    }

    int get_qtd(){
        return this->qtd;
    }

    void set_nome(std::string nome){
        this->nome = nome;
    }

    void set_preco(float preco){
        this->preco = preco;
    }
    void set_qtd(int qtd){
        this->qtd = qtd;
    }

    string str() {

        stringstream ss;
        ss << "[" 
           << setw(8) << setfill(' ') << nome 
           << " : " << qtd << " U : " 
           << fixed << setprecision(2) << preco
           << " RS]";
        return ss.str();
    }
};

class Maquina{
    private:
        std::vector<Produto> produtos;
        float saldo;
        float lucro;
        //int cpd;
    public:

    Maquina(int n_espirais) {
        produtos = vector<Produto>(n_espirais, 
                   Produto("empty", 0, 0));
        saldo = 0;
        lucro = 0;
    }


    void set_produto(int indice, string nome, int qnt, double preco) {
        if (indice < 0 || indice >= (int) produtos.size()) {
            std::cout << "fail: indice nao existe" << '\n';
            return;
        }
        produtos[indice] = Produto(nome, preco, qnt);
    }

    /*void limpar(int indice) {
        if (indice < 0 || indice >= (int) produtos.size()) {
            std::cout << "fail: indice nao existe" << '\n';
            return;
        }
        produtos[indice] = Produto("empty", 0, 0);
    }*/

    void limpar(int indice) {
        if (indice < 0 || indice >= (int) produtos.size()) {
            cout << "fail: indice nao existe" << '\n';
            return;
        }
        produtos[indice] = Produto("empty", 0, 0);
    }

    void inserir_money(float value) {
        this->saldo += value;
    }

    float troco() {
        float troco = saldo;
        saldo = 0;
        return troco;
    }

    void comprar(int indice) {
        if (indice < 0 || indice >= (int) produtos.size()) {
            cout << "fail: indice nao existe" << '\n';
            return;
        }
        Produto& produto = produtos[indice];
        if (produto.get_qtd() == 0) {
            cout << "fail: espiral sem produtos" << '\n';
            return;
        }
        if (saldo < produto.get_preco()) {
            cout << "fail: saldo insuficiente" << '\n';
            return;
        }
        saldo -= produto.get_preco();
        produto.set_qtd(produto.get_qtd() - 1);
        lucro += produto.get_preco();
        cout << "voce comprou um " << produto.get_nome() << '\n';
    }

    std::string str(){
        std::stringstream ss;
        ss << "saldo: " << std::fixed << std::setprecision(2) << saldo << std::endl;
        for (size_t i = 0; i < produtos.size(); i++) {
            ss << i << " " << produtos[i].str() << std::endl;
        }
        std::string saida = ss.str();
        saida.pop_back();
        return saida;
    }
    

};

