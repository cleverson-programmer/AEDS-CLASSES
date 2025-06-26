// Sistema de Estoque com Manipulação de String e Herança
// Enunciado:
// Crie uma classe ItemEstoque com código, descrição e quantidade.
// Derive as classes Eletronico e Alimento, cada uma com um campo adicional (voltagem e validade).
// Implemente um método virtual exibirDetalhes() e sobrescreva nas classes derivadas.
// Use manipulação de string para formatar a descrição.
// Crie um menu para cadastro e exibição.

#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

class ItemEstoque {
public:
    int codigo;
    int quantidade;
    string descricao;

    ItemEstoque(int c, int q, string desc)
        : codigo(c), quantidade(q), descricao(desc) {}

    virtual void exibirDetalhes() const {
        cout << "\nCódigo: " << codigo
             << "\nQuantidade: " << quantidade
             << "\nDescrição: " << descricao << endl;
    }

    //Destrutor da classe para evitar vazamento de memoria
    //Essencial quando se usa herança com polimorfismo usando ponteiros para a classe base
    //Permite usar o unique_ptr e o make_unique corretamente na instancia da classe base e das classes filhas
    virtual ~ItemEstoque() {}
};

class Eletronico : public ItemEstoque {
public:
    int voltagem;

    Eletronico(int c, int q, string desc, int v)
        : ItemEstoque(c, q, desc), voltagem(v) {}

    void exibirDetalhes() const override {
        cout << "\n[ELETRÔNICO]"
             << "\nCódigo: " << codigo
             << "\nQuantidade: " << quantidade
             << "\nDescrição: " << descricao
             << "\nVoltagem: " << voltagem << "V" << endl;
    }
};

class Alimento : public ItemEstoque {
public:
    string validade;

    Alimento(int c, int q, string desc, string val)
        : ItemEstoque(c, q, desc), validade(val) {}

    void exibirDetalhes() const override {
        cout << "\n[ALIMENTO]"
             << "\nCódigo: " << codigo
             << "\nQuantidade: " << quantidade
             << "\nDescrição: " << descricao
             << "\nValidade: " << validade << endl;
    }
};

void menu() {
    cout << "\n=== MENU ESTOQUE ===";
    cout << "\n1. Cadastrar Eletrônico";
    cout << "\n2. Cadastrar Alimento";
    cout << "\n3. Exibir Estoque";
    cout << "\n0. Sair";
    cout << "\nEscolha: ";
}

int main() {
    vector<unique_ptr<ItemEstoque>> estoque;
    int opcao;

    do {
        menu();
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            int cod, qtd, volt;
            string desc;

            cout << "Código: ";
            cin >> cod;
            cout << "Quantidade: ";
            cin >> qtd;
            cin.ignore();
            cout << "Descrição: ";
            getline(cin, desc);
            cout << "Voltagem (ex: 110): ";
            cin >> volt;

            estoque.push_back(make_unique<Eletronico>(cod, qtd, desc, volt));
            cout << "Eletrônico cadastrado com sucesso!\n";

        } else if (opcao == 2) {
            int cod, qtd;
            string desc, val;

            cout << "Código: ";
            cin >> cod;
            cout << "Quantidade: ";
            cin >> qtd;
            cin.ignore();
            cout << "Descrição: ";
            getline(cin, desc);
            cout << "Validade (ex: 10/2025): ";
            getline(cin, val);

            estoque.push_back(make_unique<Alimento>(cod, qtd, desc, val));
            cout << "Alimento cadastrado com sucesso!\n";

        } else if (opcao == 3) {
            cout << "\n--- Itens no Estoque ---\n";
            for (const auto& item : estoque) {
                item->exibirDetalhes();
            }

        } else if (opcao != 0) {
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    cout << "Programa finalizado.\n";
    return 0;
}
