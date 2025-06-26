#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

//CORRETO É USAR COMPOSIÇÃO NO EX ABAIXO. PORÉM ESTAMOS USANDO HERANÇA PARA FINS DIDÁTICOS.
// Herança (é-um): Não faz sentido porque um gerenciador não é um produto

// Composição (tem-um): Faz sentido porque um gerenciador tem produtos

using namespace std;

class Produto {
protected:
// Atributos protected - só podem ser acessados pelos métodos da classe ou quem herda
    string nome;
    float preco;
    int id;
    int quantidade;

public:
    // Construtor - inicializa os atributos com valores padrão ou fornecidos
    Produto(string n = "", float p = 0.0f, int i = 0, int q = 0)
        : nome(n), preco(p), id(i), quantidade(q) {}

    // Métodos SETTERS - permitem modificar os atributos privados
    // Métodos GETTERS - permitem acessar os atributos privados
    void setNome(string n) { nome = n; }
    string getNome() const { return nome; }

    void setPreco(float p) { preco = p; }
    float getPreco() const { return preco; }

    void setId(int i) { id = i; }
    int getId() const { return id; }

    void setQuantidade(int q) { quantidade = q; }
    int getQuantidade() const { return quantidade; }

    //Atualiza apenas um elemento
    void atualizarQuantidade() {
        int novaQuantidade;
        cout << "Digite a nova quantidade: ";
        cin >> novaQuantidade;
        quantidade = novaQuantidade;    //Atribui diretamente
    }

    // Exibe produto
    void exibir() const {
        cout << nome << " | " << fixed << setprecision(2)
             << preco << " | " << id << " | " << quantidade << endl;
    }
};

// Cada objeto da classe GerenciadorProdutos **é** um Produto
class GerenciadorProdutos : public Produto {
private:
    vector<GerenciadorProdutos> produtos;

public:
    void cadastrarProdutos() {
        int n;
        cout << "Digite a quantidade de produtos a ser cadastrado: ";
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < n; i++) {
            GerenciadorProdutos p;
            string nome;
            int id;
            float preco;
            int quantidade;

            cout << "Digite o nome do produto: ";
            getline(cin, nome);
            p.setNome(nome);

            cout << "Digite o id do produto: ";
            cin >> id;
            p.setId(id);

            cout << "Digite o preço: ";
            cin >> preco;
            p.setPreco(preco);

            cout << "Digite a quantidade: ";
            cin >> quantidade;
            p.setQuantidade(quantidade);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            produtos.push_back(p);
        }
    }

    //Gerencia a atualização de um produto dentro de um vetor
    void atualizarEstoque() {
        char att;
        cout << "Deseja atualizar o estoque: (S/N): ";
        cin >> att;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(att) == 's') {
            int idBusca;
            cout << "Digite o id do produto: ";
            cin >> idBusca;

            for (int i = 0; i < produtos.size(); i++) {
                if (produtos[i].getId() == idBusca) {
                    produtos[i].atualizarQuantidade(); //Chama o metodo de produto
                    cout << "Nova quantidade:\n";
                    produtos[i].exibir();
                    break;
                }
            }
        }
    }

    void executar() {
        cadastrarProdutos();
        atualizarEstoque();
    }
};

int main() {
    GerenciadorProdutos gerenciador;
    gerenciador.executar();
    return 0;
}

//VERSÃO CORRETA, DEVE USAR COMPOSIÇÃO NESSE CASO, MAS ESTAMOS USANDDO HERANÇA PARA FINS DIDÁTICOS

// using namespace std;

// class Produto {
// private:
//     string nome;
//     float preco;
//     int id;
//     int quantidade;

// public:
//     // Construtor
//     Produto(string n = "", float p = 0.0f, int i = 0, int q = 0) 
//         : nome(n), preco(p), id(i), quantidade(q) {}

//     // Métodos para acesso aos atributos (encapsulamento)
//     void setNome(string n) { nome = n; }
//     string getNome() const { return nome; }

//     void setPreco(float p) { preco = p; }
//     float getPreco() const { return preco; }

//     void setId(int i) { id = i; }
//     int getId() const { return id; }

//     void setQuantidade(int q) { quantidade = q; }
//     int getQuantidade() const { return quantidade; }

//     // Método para atualizar estoque
//     void atualizarEstoque() {
//         int novaQuantidade;
//         cout << "Digite a nova quantidade: ";
//         cin >> novaQuantidade;
//         quantidade = novaQuantidade;
//     }

//     // Método para exibir informações do produto
//     void exibir() const {
//         cout << nome << " | " << fixed << setprecision(2) 
//              << preco << " | " << id << " | " << quantidade << endl;
//     }
// };

// class GerenciadorProdutos {
// private:
//     vector<Produto> produtos;

// public:
//     void cadastrarProdutos() {
//         int n;
//         cout << "Digite a quantidade de produtos a ser cadastrado: ";
//         cin >> n;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');

//         for(int i = 0; i < n; i++) {
//             Produto p;
//             string nome;
//             int id;
//             float preco;
//             int quantidade;

//             cout << "Digite o nome do produto: ";
//             getline(cin, nome);
//             p.setNome(nome);

//             cout << "Digite o id do produto: ";
//             cin >> id;
//             p.setId(id);

//             cout << "Digite o preço: ";
//             cin >> preco;
//             p.setPreco(preco);

//             cout << "Digite a quantidade: ";
//             cin >> quantidade;
//             p.setQuantidade(quantidade);
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');

//             produtos.push_back(p);
//         }
//     }

//     void atualizarEstoque() {
//         char att;
//         cout << "Deseja atualizar o estoque: (S/N): ";
//         cin >> att;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');

//         if(tolower(att) == 's') {
//             int id;
//             cout << "Digite o id do produto: ";
//             cin >> id;

//             for(auto& produto : produtos) {
//                 if(produto.getId() == id) {
//                     produto.atualizarEstoque();
//                     cout << "Nova quantidade:\n";
//                     produto.exibir();
//                     break;
//                 }
//             }
//         }
//     }

//     void executar() {
//         cadastrarProdutos();
//         atualizarEstoque();
//     }
// };

// int main() {
//     GerenciadorProdutos gerenciador;
//     gerenciador.executar();
//     return 0;
// }