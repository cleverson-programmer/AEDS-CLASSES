// Desenvolva um sistema de comparação de preços de alimentos. Na primeira fase do seu
// software, gostaria de criar uma classe que contenha o nome da loja, telefone e preço de um
// alimento. Em seguida, irá cadastrar um total de 10 registros e exibir estatísticas desses itens, de
// modo que possa verificar o melhor preço (menor valor), o preço médio e o preço máximo. Crie
// classes e exiba as informações desejadas.
// Utilize os conceitos de classe, atributos, métodos, método construtor. Proteja o acesso aos dados
// implementando encapsulamento por meio de métodos get e set. Crie o main, que declara um vetor
// de alimentos e que permite ao usuário adicionar nesse vetor informações das lojas e preço.

#include <iostream>
#include <iomanip>  // fixed e setprecision(2)
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include <exception>

using namespace std;

// Classe de exceção
class EntradaInvalidaException : public exception {
private:
    string mensagem;
public:
    EntradaInvalidaException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class Loja {
private:
    string _nome;
    string _telefone;
    float _preco;
public:
    Loja(string nome, string telefone, float preco) :
        _nome(nome), _telefone(telefone), _preco(preco) {}

    void setDados(string nome, string telefone, float preco) {
        _nome = nome;
        _telefone = telefone;
        _preco = preco;
    }

    string getNome() const { return _nome; }
    string getTelefone() const { return _telefone; }
    float getPreco() const { return _preco; }
};

class GerenciarLojas {
private:
    vector<Loja> lojas;

    // Função para entrada com validação
    string lerString(const string& prompt) {
        string entrada;
        cout << prompt;
        getline(cin, entrada);
        if (entrada.empty()) {
            throw EntradaInvalidaException("Erro: Campo de texto vazio.");
        }
        return entrada;
    }

    float lerPreco(const string& prompt) {
        float preco;
        cout << prompt;
        if (!(cin >> preco)) {
            cin.clear(); // limpa erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw EntradaInvalidaException("Erro: Valor de preço inválido. Deve ser numérico.");
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (preco <= 0) {
            throw EntradaInvalidaException("Erro: O preço deve ser maior que zero.");
        }
        return preco;
    }

public:
    void cadastrarLojas() {
        string nome;
        string telefone;
        float preco;

        for (int i = 0; i < 10; ) {
            try {
                cout << "\nCadastro da Loja " << i + 1 << "/10" << endl;

                nome = lerString("Digite o nome da loja: ");
                telefone = lerString("Digite o telefone: ");
                preco = lerPreco("Digite o preço: ");

                lojas.emplace_back(nome, telefone, preco);
                i++; // só incrementa se tudo der certo
            } catch (const EntradaInvalidaException& e) {
                cerr << e.what() << " Tente novamente." << endl;
            }
        }
    }

    void exibir(string nome, float preco) {
        cout << "Nome: " << nome << " | Preço: R$ " << fixed << setprecision(2) << preco << endl;
    }

    void menorPreco() {
        if (lojas.empty()) return;

        float menor = lojas[0].getPreco();
        string nome = lojas[0].getNome();

        for (const auto& loja : lojas) {
            if (loja.getPreco() < menor) {
                menor = loja.getPreco();
                nome = loja.getNome();
            }
        }

        cout << "\nMENOR PREÇO:" << endl;
        exibir(nome, menor);
    }

    float mediaPreco() {
        if (lojas.empty()) return 0.0f;

        float soma = 0;
        for (const auto& loja : lojas) {
            soma += loja.getPreco();
        }
        return soma / lojas.size();
    }

    void maiorPreco() {
        if (lojas.empty()) return;

        float maior = lojas[0].getPreco();
        string nome = lojas[0].getNome();

        for (const auto& loja : lojas) {
            if (loja.getPreco() > maior) {
                maior = loja.getPreco();
                nome = loja.getNome();
            }
        }

        cout << "\nMAIOR PREÇO:" << endl;
        exibir(nome, maior);
    }
};

int main() {
    GerenciarLojas gerenciador;

    cout << "=== SISTEMA DE COMPARAÇÃO DE PREÇOS ===" << endl;
    gerenciador.cadastrarLojas();

    cout << "\n=== RESULTADOS ===" << endl;
    gerenciador.maiorPreco();
    gerenciador.menorPreco();

    cout << "\nMédia de preços: R$ " << fixed << setprecision(2) << gerenciador.mediaPreco() << endl;

    return 0;
}