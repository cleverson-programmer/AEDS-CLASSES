// Crie uma struct Produto com os campos nome (até 30 caracteres) e preco (float). 
// Permita que o usuário cadastre produtos até desejar parar. 

#include <iostream>      // Biblioteca para entrada/saída padrão (cout, cin)
#include <vector>        // Biblioteca para usar o container vector (array dinâmico)
#include <string>        // Biblioteca para usar a classe string
#include <iomanip>       // Biblioteca para formatação de saída (setprecision, fixed)
#include <cctype>        // Biblioteca para funções de caracteres (tolower)

using namespace std;     // Permite usar elementos da std sem prefixo (std::)

// Struct Produto - representa um produto com nome e preço
struct Produto {
    string nome;        // Nome do produto (string substitui char[30] do C)
    float preco;        // Preço do produto

    // Construtor da struct (inicializa os membros)
    // O construtor está na struct porque em C++ tanto structs quanto classes podem ter construtores
    // A diferença é que struct tem membros públicos por padrão, classe tem privados


    // Possui parâmetros com valores padrão (n = "", p = 0.0f), permitindo criar objetos sem fornecer valores
    // const std::string& n: Recebe uma referência constante a uma string (explico detalhes abaixo)

    // : nome(n), preco(p): Lista de inicialização - inicializa os membros diretamente (mais eficiente que atribuir depois)

    // {}: Corpo vazio pois toda a inicialização é feita na lista de inicialização
    Produto(const string& n = "", float p = 0.0f) : nome(n), preco(p) {}
};

// Classe para gerenciar o cadastro de produtos
class CadastroProdutos {
private:
    vector<Produto> produtos;  // Armazena os produtos (substitui o array dinâmico do C)

public:
    // Construtor da classe (opcional neste caso, pois o vector já se inicializa)

    // = default indica que queremos o construtor padrão gerado pelo compilador
    // É usado quando não precisamos de nenhuma inicialização especial
    // Neste caso, o std::vector<Produto> já se inicializa automaticamente (vazio)
    // Alternativa seria escrever CadastroProdutos() {} (construtor vazio), mas = default é mais explícito
    CadastroProdutos() = default;  // Usa o construtor padrão do compilador

    // Método para adicionar um novo produto ao vetor
    // const: Indica que o objeto não será modificado (apenas leitura)
    // Produto&: É uma referência (não uma cópia) ao objeto Produto
    void adicionarProduto(const Produto& produto) { 
        produtos.push_back(produto);  // Adiciona no final do vetor
    }

    // Método para ler produtos do usuário
    void lerProdutos() {
        char continuar;
        
        do {
            Produto p;  // Cria um produto temporário
            string nome;
            float preco;

            // Interface com o usuário
            //endl: manipulador de fluxo de saída, insere o \n e descarrega (flush) o buffer de saída
            cout << "Produto " << produtos.size() + 1 << endl;
            
            // Lê o nome do produto
            cout << "Nome: ";
            getline(cin, nome);  // Lê toda a linha (permite espaços)
            p.nome = nome;        // Atribui ao produto

            // Lê o preço do produto
            cout << "Preço: ";
            cin >> preco;
            p.preco = preco;

            // Adiciona o produto ao vetor
            adicionarProduto(p);

            // Pergunta se deseja continuar
            cout << "Deseja adicionar outro produto? (s/n): ";
            cin >> continuar;
            cin.ignore();  // Limpa o buffer do teclado (remove o '\n' deixado pelo cin)
        } while (tolower(continuar) == 's');  // Continua enquanto usuário digitar 's'
    }

    // Método para exibir todos os produtos
    void mostrarProdutos() const {
        cout << "\nLista de Produtos:\n";
        // Percorre todos os produtos usando índice (estilo C)
        for (size_t i = 0; i < produtos.size(); i++) {
            // Formata a saída com 2 casas decimais
            cout << "Produto: " << produtos[i].nome 
                 << " - Preço: R$ " << fixed << setprecision(2) 
                 << produtos[i].preco << endl;
        }
    }
};

int main() {
    // Cria um objeto da classe CadastroProdutos
    CadastroProdutos cadastro;
    
    // Chama os métodos para ler e mostrar produtos
    cadastro.lerProdutos();
    cadastro.mostrarProdutos();

    return 0;  // Encerra o programa
}

//MESMA VERSÃO SEM USAR O using namespace std

// // Struct Produto - representa um produto com nome e preço
// struct Produto {
//     std::string nome;        // std::string em vez de string
//     float preco;

//     // Construtor da struct
//     Produto(const std::string& n = "", float p = 0.0f) : nome(n), preco(p) {}
// };

// // Classe para gerenciar o cadastro de produtos
// class CadastroProdutos {
// private:
//     std::vector<Produto> produtos;  // std::vector em vez de vector

// public:
//     // Construtor da classe
//     CadastroProdutos() = default;

//     // Método para adicionar um novo produto ao vetor
//     void adicionarProduto(const Produto& produto) {
//         produtos.push_back(produto);
//     }

//     // Método para ler produtos do usuário
//     void lerProdutos() {
//         char continuar;
        
//         do {
//             Produto p;
//             std::string nome;
//             float preco;

//             std::cout << "Produto " << produtos.size() + 1 << std::endl;
            
//             std::cout << "Nome: ";
//             std::getline(std::cin, nome);
//             p.nome = nome;

//             std::cout << "Preço: ";
//             std::cin >> preco;
//             p.preco = preco;

//             adicionarProduto(p);

//             std::cout << "Deseja adicionar outro produto? (s/n): ";
//             std::cin >> continuar;
//             std::cin.ignore();
//         } while (std::tolower(continuar) == 's');
//     }

//     // Método para exibir todos os produtos
//     void mostrarProdutos() const {
//         std::cout << "\nLista de Produtos:\n";
//         for (size_t i = 0; i < produtos.size(); i++) {
//             std::cout << "Produto: " << produtos[i].nome 
//                       << " - Preço: R$ " << std::fixed << std::setprecision(2) 
//                       << produtos[i].preco << std::endl;
//         }
//     }
// };

// int main() {
//     CadastroProdutos cadastro;
    
//     cadastro.lerProdutos();
//     cadastro.mostrarProdutos();

//     return 0;
// }