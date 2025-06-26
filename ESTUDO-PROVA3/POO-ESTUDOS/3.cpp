#include <iostream>
#include <string>

using namespace std;

struct Endereco {
    string rua;
    int numero;
};

class Pessoa {
private:
    string nome;
    int idade;
    Endereco endereco; // Composição

public:
    void setDados(string n, int i, string r, int num) {
        nome = n;
        idade = i;
        endereco.rua = r;
        endereco.numero = num;
    }

    void mostrar() {
        cout << "Nome: " << nome << " | "
             << "Idade: " << idade << " |\n"
             << "Endereco: " << endereco.rua << ", " << endereco.numero << endl;
    }
};

class GerenciarPessoa : public Pessoa {
private:
    Pessoa p; // Aqui você criou um objeto adicional (explico abaixo)

public:
    void cadastrarPessoa() {
        string nome;
        int idade;
        string rua;
        int numero;

        cout << "Digite o nome:" << endl;
        getline(cin, nome);

        cout << "Digite a idade:" << endl;
        cin >> idade;
        cin.ignore(); // <- limpa o buffer antes do próximo getline

        cout << "Digite a rua: " << endl;
        getline(cin, rua);

        cout << "Digite o numero:" << endl;
        cin >> numero;

        // Armazena os dados no objeto 'p', mas deveria usar o this:
        setDados(nome, idade, rua, numero); // ← Corrigido: usa método herdado
    }

    void mostrarPessoa() {
        mostrar(); // ← chama o método da classe base
    }
};

int main() {
    GerenciarPessoa gerenciador;

    gerenciador.cadastrarPessoa();
    gerenciador.mostrarPessoa();

    return 0;
}