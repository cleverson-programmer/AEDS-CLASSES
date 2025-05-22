#include <iostream>   // Para entrada e saída padrão
#include <vector>     // Para vetor dinâmico
#include <string>     // Para manipulação de strings
#include <iomanip>    // Para setprecision

using namespace std;

// Estrutura que representa um produto
struct Produto {
    string nome;
    float preco;
};

int main() {
    vector<Produto> produtos; // Vetor dinâmico de produtos
    char continuar;

    do {
        Produto p; // Novo produto a ser cadastrado

        cout << "Produto " << produtos.size() + 1 << endl;

        cin.ignore(); // Limpa o buffer antes de ler o nome
        cout << "Nome: ";
        getline(cin, p.nome); // Lê o nome do produto (com espaços)

        cout << "Preço: ";
        cin >> p.preco; // Lê o preço

        produtos.push_back(p); // Adiciona o produto ao vetor

        cout << "Deseja adicionar outro produto? (s/n): ";
        cin >> continuar; // Lê a resposta do usuário

    } while (continuar == 's' || continuar == 'S'); // Repete enquanto o usuário quiser

    // Exibe todos os produtos cadastrados
    cout << "\nLista de Produtos:\n";
    for (const auto& produto : produtos) {
        cout << "Produto: " << produto.nome << " - Preço: R$ "
             << fixed << setprecision(2) << produto.preco << endl;
    }

    return 0;
}

// Produto 1
// Nome: Refrigerante Laranja
// Preço: 5.50
// Deseja adicionar outro produto? (s/n): s
// Produto 2
// Nome: Salgadinho de Queijo
// Preço: 3.75
// Deseja adicionar outro produto? (s/n): s
// Produto 3
// Nome: Chocolate Amargo 70%
// Preço: 7.90
// Deseja adicionar outro produto? (s/n): n

// Lista de Produtos:
// Produto: Refrigerante Laranja - Preço: R$ 5.50
// Produto: Salgadinho de Queijo - Preço: R$ 3.75
// Produto: Chocolate Amargo 70% - Preço: R$ 7.90