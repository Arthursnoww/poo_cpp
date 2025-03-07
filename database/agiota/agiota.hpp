#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>

enum Label {
    GIVE, TAKE, PLUS
};

std::ostream& operator<<(std::ostream& os, Label label) {
    switch (label) {
        case GIVE: os << "give"; break;
        case TAKE: os << "take"; break;
        case PLUS: os << "plus"; break;
    }
    return os;
}


class Operation {
    int id;
    std::string name;
    int value;
    Label label;
public:
    Operation(int id, std::string name, int value,Label label) : id(id), name(name), value(value), label(label) {}
    
    int get_id() const {
        return id;
    }

    std::string get_name() const {
        return name;
    }

    int get_value() const {
        return value;
    }

    Label get_label() const {
        return label;
    }

   
    std::string to_string() const {
        std::string label_str;
        
        
        if (label == GIVE)
            label_str = "give";
        else if (label == TAKE)
            label_str = "take";
        else
            label_str = "plus"; 

        return "id:" + std::to_string(id) + " " + label_str + ":" + name + " " + std::to_string(value);
    }

    
};

class Cliente{
    std::string name;
    int limite;
    std::list<std::shared_ptr<Operation>> operations;
    int saldo = 0;
public:

    Cliente(std::string name, int limite) : name(name), limite(limite) {}

    std::string get_name() const {
        return name;
    }
    int get_saldo() const {
        return saldo;
    }
    void set_saldo(int ss) {
        this->saldo = saldo+ss;
    }

    int get_limite() const {
        return limite;
    }
    std::list<std::shared_ptr<Operation>> get_operations() const {
        return operations;
    }

    void add_operation(std::shared_ptr<Operation> op) {
        operations.push_back(op);
        if (op->get_label() == GIVE) saldo += op->get_value();
        else if (op->get_label() == TAKE) saldo -= op->get_value();
    }

    std::string to_string() const {
        return name + " " + std::to_string(saldo) + "/" + std::to_string(limite);
    }
};

class Agiota {
    std::list <Cliente> clientes_vivos;
    std::list <Cliente> clientes_mortos;
    std::list<std::shared_ptr<Operation>> op_vivos;
    std::list<std::shared_ptr<Operation>> op_mortos;
    int next_id = 0;

    int buscarCliente(std::string nome) {
        int index = 0;
        for (auto it = clientes_vivos.begin(); it != clientes_vivos.end(); ++it, ++index) {
            if (it->get_name() == nome) {
                return index;  
            }
        }
        return -1;  
    }

    void add_operation(Cliente& cliente, Label label, int valor) {
        std::shared_ptr<Operation> op = std::make_shared<Operation>(next_id++, cliente.get_name(), valor, label);
        op_vivos.push_back(op);
        cliente.add_operation(op);
    }


public:
    Cliente* getCliente(std::string nome) {
        auto it = std::find_if(clientes_vivos.begin(), clientes_vivos.end(),
            [&](const Cliente& c) { return c.get_name() == nome; });

        if (it == clientes_vivos.end()) {
            std::cout << "fail: cliente nao existe" << std::endl;
            return nullptr;
        }
        return &(*it);  
    }


    void add_cliente(std::string name, int limite) {
        if(buscarCliente(name) != -1) {
            std::cout << "fail: cliente ja existe" << std::endl;
            return;
        }
        clientes_vivos.emplace_back(Cliente(name, limite));
        clientes_vivos.sort([](const Cliente& a, const Cliente& b) { return a.get_name() < b.get_name(); });
    }

    void emprestar(std::string nome, int valor){
        Cliente* cliente = getCliente(nome);
        
        if (!cliente) { 
            return;
        }

        if(cliente->get_saldo() + valor <= cliente->get_limite()) {
            add_operation(*cliente, GIVE, valor);
        } else {
            std::cout << "fail: limite excedido" << std::endl;
        }
    }

    void pagar(std::string nome, int valor) {
        Cliente* cliente = getCliente(nome);
        
        if (!cliente) { 
            return;
        }

        if(cliente->get_saldo() - valor >= 0) {
            add_operation(*cliente, TAKE, valor);
        } else {
            std::cout << "fail: pagamento excede saldo" << std::endl;
        }
    }

    void pesquisar(std::string nome) {
        Cliente* cliente = getCliente(nome);
        
        if (!cliente) { 
            return;
        }

        std::cout << cliente->to_string() << std::endl;
        for (auto& op : cliente->get_operations()) {
            std::cout << op->to_string() << std::endl;
        }
    }

    void matar(std::string nome) {
        auto it = std::find_if(clientes_vivos.begin(), clientes_vivos.end(),
            [&](const Cliente& c) { return c.get_name() == nome; });

        if (it == clientes_vivos.end()) { 
            std::cout << "fail: cliente nao existe" << std::endl;
            return;
        }

        clientes_mortos.push_back(*it);
        
        std::list<std::shared_ptr<Operation>> ops_para_mover = it->get_operations();
        
        clientes_vivos.erase(it);

        for (auto& op : ops_para_mover) {
            op_mortos.push_back(op);
        }
        op_vivos.remove_if([&](const std::shared_ptr<Operation>& o) {
            return std::any_of(ops_para_mover.begin(), ops_para_mover.end(),
            [&](const std::shared_ptr<Operation>& op_cliente) {
                return o->get_id() == op_cliente->get_id();
            });
        });
    }

    void plus() {
        std::vector<std::string> para_matar; 

        for (auto& c : clientes_vivos) {
            int valor = (c.get_saldo() + 9) / 10; 
            
            add_operation(c, PLUS, valor);
            
            c.set_saldo(valor); 
            
            if (c.get_saldo() > c.get_limite()) {
                para_matar.push_back(c.get_name());
            }
        }

        
        for (const auto& nome : para_matar) {
            matar(nome);
        }
    }

 
   
    std::string to_string() {
        std::stringstream ss;
        for (auto& c : clientes_vivos) ss << ":) " << c.to_string() << '\n';
        for (auto& o : op_vivos) ss << "+ " << o->to_string() << '\n';
        for (auto& c : clientes_mortos) ss << ":( " << c.to_string() << '\n';
        for (auto& o : op_mortos) ss << "- " << o->to_string() << '\n';
        auto out = ss.str();
        if (!out.empty()) out.pop_back();
        return out;
    }



    
};

    