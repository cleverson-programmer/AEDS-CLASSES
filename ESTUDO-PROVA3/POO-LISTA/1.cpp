// Escreva um programa para cadastrar clientes de uma loja. As informações necessárias são:
// nome, data de nascimento, endereço e telefone. Devem ser usada classes para a construção deste
// cadastro.
// Utilize os conceitos de classe, atributos e método construtor. Crie o main, que declara um vetor de
// clientes e que permite ao usuário adicionar os clientes nesse vetor. O tamanho do vetor deverá
// ser definido pelo usuário.
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // tolower
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

class Cliente {
private:
    string _nome;
    string _endereco;
    string _telefone;
    string _dataNascimento;

public:
    Cliente(string nome, string endereco, string telefone, string dataNascimento) :
        _nome(nome), _endereco(endereco), _telefone(telefone), _dataNascimento(dataNascimento) {}

    string getNome() const { return _nome; }
    string getEndereco() const { return _endereco; }
    string getTelefone() const { return _telefone; }
    string getDataNascimento() const { return _dataNascimento; }

    void setNome(string nome) { _nome = nome; }
    void setEndereco(string endereco) { _endereco = endereco; }
    void setTelefone(string telefone) { _telefone = telefone; }
    void setDataNascimento(string data) { _dataNascimento = data; }

    void exibir() const {
        cout << "\nNome: " << _nome
             << "\nEndereço: " << _endereco
             << "\nTelefone: " << _telefone
             << "\nData Nascimento: " << _dataNascimento << endl;
    }
};

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função para ler entrada com validação e exceção
string lerEntrada(const string& prompt) {
    string entrada;
    cout << prompt;
    getline(cin, entrada);
    if (entrada.empty()) {
        throw EntradaInvalidaException("Erro: O campo não pode estar vazio.");
    }
    return entrada;
}

int main() {
    vector<Cliente> clientes;
    char continuar;

    do {
        try {
            string nome = lerEntrada("\nDigite o nome: ");
            string endereco = lerEntrada("Digite o endereço: ");
            string telefone = lerEntrada("Digite o telefone: ");
            string nascimento = lerEntrada("Digite a data de nascimento (formato DD/MM/AAAA): ");

            clientes.emplace_back(nome, endereco, telefone, nascimento);

        } catch (const EntradaInvalidaException& e) {
            cerr << e.what() << endl;
            cout << "Por favor, tente novamente." << endl;
            continue; // Volta ao início do loop
        }

        cout << "\nDeseja cadastrar outro cliente? (S/N): ";
        cin >> continuar;
        limparBuffer();

    } while (tolower(continuar) == 's');

    cout << "\n=== CLIENTES CADASTRADOS ===" << endl;
    for (const auto& cliente : clientes) {
        cliente.exibir();
        cout << "-----------------------------" << endl;
    }

    return 0;
}