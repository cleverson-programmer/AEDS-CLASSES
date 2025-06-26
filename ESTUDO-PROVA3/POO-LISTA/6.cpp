//Escreva uma classe em C++ que gerencie jogos de loteria lotofacil. A classe deve permitir a
// escolha de 15 números que variam de 1 a 25. A escolha de um número deve ser feita em um
// método especializado. Caso o escolhido seja repetido, inferior a 1 ou superior a 25 seja escolhido,
// o sistema deve gerar uma exceção nesse método, que deve ser propagada e tratada no
// procedimento principal (main).

#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Exceção personalizada
class EscolhaInvalidaException : public exception {
private:
    string mensagem;
public:
    EscolhaInvalidaException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Classe da Loteria Lotofácil
class Lotofacil {
private:
    set<int> numerosEscolhidos;

public:
    void escolherNumero(int num) {
        if (num < 1 || num > 25) {
            throw EscolhaInvalidaException("Número inválido! Deve estar entre 1 e 25.");
        }
        if (numerosEscolhidos.count(num)) {
            throw EscolhaInvalidaException("Número já foi escolhido!");
        }
        if (numerosEscolhidos.size() >= 15) {
            throw EscolhaInvalidaException("Já foram escolhidos 15 números.");
        }

        numerosEscolhidos.insert(num);
        cout << "Número " << num << " escolhido com sucesso.\n";
    }

    void exibirNumeros() const {
        cout << "\n=== NÚMEROS ESCOLHIDOS ===\n";
        for (int num : numerosEscolhidos) {
            cout << num << " ";
        }
        cout << "\nTotal: " << numerosEscolhidos.size() << " números\n";
    }
};

int main() {
    Lotofacil aposta;
    int numero;

    cout << "=== SISTEMA DE APOSTA - LOTOFÁCIL ===\n";

    while (true) {
        try {
            if (cin.eof()) break;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "\nDigite um número entre 1 e 25 (ou -1 para sair): ";
            cin >> numero;

            if (numero == -1) break;

            aposta.escolherNumero(numero);

            if (cin.peek() == '\n') cin.ignore();  // limpa o buffer
        }
        catch (const EscolhaInvalidaException& e) {
            cerr << "Erro: " << e.what() << endl;
        }
        catch (...) {
            cerr << "Erro desconhecido.\n";
        }
    }

    aposta.exibirNumeros();
    cout << "\nObrigado por usar o sistema de apostas!\n";
    return 0;
}