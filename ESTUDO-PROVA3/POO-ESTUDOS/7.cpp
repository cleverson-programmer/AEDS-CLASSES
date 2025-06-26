// Crie uma classe base Funcionario com os atributos protegidos: nome, cargo e salário. Implemente métodos virtuais para calcular o bônus anual (salário * 0.10).
// Crie classes derivadas Gerente e Desenvolvedor, sobrescrevendo o método de bônus: gerente recebe 20% e desenvolvedor 15%.
// Permita cadastrar funcionários e exibir todos com seu bônus usando polimorfismo.


//TRABALHANDO USANDO POLIMORFISMO COM PONTEIROS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <memory>
#include <memory>

using namespace std;

class Funcionario {
protected:
    string _nome;
    string _cargo;
    float _salario;

public:
    Funcionario(string n, string c, float s) : _nome(n), _cargo(c), _salario(s) {}

    void setNome(string n) { _nome = n; }
    void setCargo(string c) { _cargo = c; }
    void setSalario(float s) { _salario = s; }

    string getNome() const { return _nome; }
    string getCargo() const { return _cargo; }
    float getSalario() const { return _salario; }

    virtual float bonus() const {
        return _salario * 0.10f;
    }

    virtual void exibir() const {
        cout << "Nome: " << _nome
             << " | Cargo: " << _cargo
             << " | Salário: R$" << fixed << setprecision(2) << _salario
             << " | Bônus: R$" << fixed << setprecision(2) << bonus()
             << endl;
    }

    virtual ~Funcionario() {}
};

class Gerente : public Funcionario {
public:
    Gerente(string n, float s) : Funcionario(n, "Gerente", s) {}

    float bonus() const override {
        return getSalario() * 0.20f;
    }
};

class Desenvolvedor : public Funcionario {
public:
    Desenvolvedor(string n, float s) : Funcionario(n, "Desenvolvedor", s) {}

    float bonus() const override {
        return getSalario() * 0.15f;
    }
};

class GerenciarFuncionarios {
private:
// unique_ptr<T> é um ponteiro inteligente que gera um objeto dinâmico (com new) e garante que ele será destruído automaticamente quando não for mais usado.
// Ele é "único" porque não pode ser copiado, apenas movido.
// Garante que não haverá vazamento de memória (memory leak), porque o objeto que ele aponta será destruído automaticamente quando sair do escopo.
//Por que usar unique_ptr<Funcionario> aqui?
// Porque você está usando polimorfismo (armazenando objetos do tipo Gerente e Desenvolvedor no mesmo vetor), e isso exige ponteiros.
// Como vector<Funcionario> não pode conter objetos derivados diretamente (por causa do slicing), você precisa de vector<ponteiros>. Com unique_ptr, você faz isso com segurança e modernidade, sem precisar gerenciar new/delete manualmente.
    vector<unique_ptr<Funcionario>> _funcionarios;

public:
    void cadastrarFuncionarios() {
        while (true) {
            string nome, cargo;
            float salario;
            int tipo;

            cout << "\n=== Cadastro de Funcionário ===\n";
            cout << "Nome: ";
            getline(cin, nome);

            cout << "Tipo de funcionário (1-Gerente / 2-Desenvolvedor / 0-Sair): ";
            cin >> tipo;
            if (tipo == 0) break;

            cout << "Salário: R$";
            cin >> salario;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // make_unique<T>(args...) é uma função utilitária que:
            // Cria um novo objeto do tipo T com os argumentos args.
            // Retorna um unique_ptr<T> que já aponta para esse objeto.
            if (tipo == 1) {
                _funcionarios.push_back(make_unique<Gerente>(nome, salario));
            } else if (tipo == 2) {
                _funcionarios.push_back(make_unique<Desenvolvedor>(nome, salario));
            } else {
                cout << "Tipo inválido!\n";
            }
        }
    }

    void exibirFuncionarios() const {
        cout << "\n=== Funcionários Cadastrados ===\n";
        for (size_t i = 0; i < _funcionarios.size(); ++i) {
            _funcionarios[i]->exibir();
        }
    }
};

int main() {
    GerenciarFuncionarios funcionarios;
    funcionarios.cadastrarFuncionarios();
    funcionarios.exibirFuncionarios();

    return 0;
}