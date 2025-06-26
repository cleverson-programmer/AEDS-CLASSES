// 3. Crie uma classe para representar uma conta corrente, com métodos para depositar uma
// quantia, sacar uma quantia e obter o saldo. Para cada saque será debitada também uma taxa de
// operação equivalente à 0.5% do valor sacado. Crie, em seguida, uma subclasse (herdada) da classe
// anterior para representar uma conta corrente de um cliente especial. Clientes especiais pagam
// taxas de operação de apenas 0.1% do valor sacado.
// Utilize os conceitos de classe, atributos, métodos, encapsulamento (get/set), método construtor e
// herança. Crie um main com menu, que após o usuário definir o tipo de conta (comum ou especial),
// permitirá ao usuário depositar, sacar e mostrar saldo da conta instanciada

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <memory>
#include <limits>
#include <exception>

using namespace std;

// Exceção personalizada
class OperacaoInvalidaException : public exception {
private:
    string mensagem;
public:
    OperacaoInvalidaException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Conta Corrente Base
class ContaCorrente {
protected:
    string _nome;
    float _saldo;
    float taxaOp = 0.005f;

public:
    ContaCorrente(string nome, float saldo = 0.0f) {
        if (nome.empty()) throw OperacaoInvalidaException("Nome do cliente não pode estar vazio.");
        if (saldo < 0) throw OperacaoInvalidaException("Saldo inicial não pode ser negativo.");
        _nome = nome;
        _saldo = saldo;
    }

    virtual ~ContaCorrente() {}

    void setNome(string nome) { _nome = nome; }
    void setSaldo(float saldo) { _saldo = saldo; }

    string getNome() const { return _nome; }
    float getSaldo() const { return _saldo; }

    void depositar(float valor) {
        if (valor <= 0) throw OperacaoInvalidaException("Valor de depósito deve ser positivo.");
        _saldo += valor;
        cout << "Depósito de R$ " << fixed << setprecision(2) << valor << " realizado com sucesso.\n";
    }

    virtual void sacar(float valor) {
        if (valor <= 0) throw OperacaoInvalidaException("Valor de saque deve ser positivo.");
        float taxa = valor * taxaOp;
        float total = valor + taxa;
        if (_saldo < total) throw OperacaoInvalidaException("Saldo insuficiente para saque com taxa.");
        _saldo -= total;
        cout << "Saque de R$ " << fixed << setprecision(2) << valor << " realizado.\n";
        cout << "Taxa de operação: R$ " << taxa << "\n";
    }

    virtual void mostrarDados() const {
        cout << "\nCONTA CORRENTE:\nCLIENTE: " << _nome
             << " | Saldo: R$ " << fixed << setprecision(2) << _saldo << endl;
    }
};

// Conta Especial Derivada
class ContaEspecial : public ContaCorrente {
private:
    float taxaOpEspecial = 0.001f;

public:
    ContaEspecial(string nome, float saldo = 0.0f)
        : ContaCorrente(nome, saldo) {}

    void sacar(float valor) override {
        if (valor <= 0) throw OperacaoInvalidaException("Valor de saque deve ser positivo.");
        float taxa = valor * taxaOpEspecial;
        float total = valor + taxa;
        if (_saldo < total) throw OperacaoInvalidaException("Saldo insuficiente para saque com taxa especial.");
        _saldo -= total;
        cout << "Saque de R$ " << fixed << setprecision(2) << valor << " realizado.\n";
        cout << "Taxa de operação: R$ " << taxa << "\n";
    }

    void mostrarDados() const override {
        cout << "\nCONTA ESPECIAL\nCLIENTE: " << _nome
             << " | Saldo: R$ " << fixed << setprecision(2) << _saldo << endl;
    }
};

// Funções utilitárias
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void exibirMenu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Cadastrar nova conta\n";
    cout << "2. Depositar\n";
    cout << "3. Sacar\n";
    cout << "4. Ver saldo\n";
    cout << "5. Listar todas as contas\n";
    cout << "6. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    vector<unique_ptr<ContaCorrente>> contas;
    int opcao;
    int contaAtual = -1;

    do {
        exibirMenu();
        cin >> opcao;
        limparBuffer();

        try {
            switch(opcao) {
                case 1: { // Cadastrar
                    string nome;
                    int tipoConta;
                    float saldoInicial;

                    cout << "\nDigite o nome do cliente: ";
                    getline(cin, nome);

                    cout << "Selecione o tipo de conta:\n";
                    cout << "1. Conta Comum\n";
                    cout << "2. Conta Especial\n";
                    cout << "Opção: ";
                    cin >> tipoConta;
                    limparBuffer();

                    cout << "Digite o saldo inicial (ou 0 para nenhum): ";
                    cin >> saldoInicial;
                    limparBuffer();

                    if (tipoConta == 1)
                        contas.emplace_back(make_unique<ContaCorrente>(nome, saldoInicial));
                    else if (tipoConta == 2)
                        contas.emplace_back(make_unique<ContaEspecial>(nome, saldoInicial));
                    else
                        throw OperacaoInvalidaException("Tipo de conta inválido.");

                    contaAtual = contas.size() - 1;
                    cout << "Conta cadastrada com sucesso!\n";
                    break;
                }
                case 2: { // Depositar
                    if (contas.empty()) throw OperacaoInvalidaException("Nenhuma conta cadastrada.");
                    if (contaAtual == -1) throw OperacaoInvalidaException("Nenhuma conta selecionada.");

                    float valor;
                    cout << "Digite o valor para depósito: R$ ";
                    cin >> valor;
                    limparBuffer();

                    contas[contaAtual]->depositar(valor);
                    break;
                }
                case 3: { // Sacar
                    if (contas.empty()) throw OperacaoInvalidaException("Nenhuma conta cadastrada.");
                    if (contaAtual == -1) throw OperacaoInvalidaException("Nenhuma conta selecionada.");

                    float valor;
                    cout << "Digite o valor para saque: R$ ";
                    cin >> valor;
                    limparBuffer();

                    contas[contaAtual]->sacar(valor);
                    break;
                }
                case 4: { // Ver saldo
                    if (contas.empty()) throw OperacaoInvalidaException("Nenhuma conta cadastrada.");
                    if (contaAtual == -1) throw OperacaoInvalidaException("Nenhuma conta selecionada.");

                    contas[contaAtual]->mostrarDados();
                    break;
                }
                case 5: { // Listar todas
                    if (contas.empty()) throw OperacaoInvalidaException("Nenhuma conta cadastrada.");

                    cout << "\n=== LISTA DE CONTAS ===\n";
                    for (size_t i = 0; i < contas.size(); ++i) {
                        cout << "Conta #" << i + 1 << ":\n";
                        contas[i]->mostrarDados();
                        if (static_cast<int>(i) == contaAtual)
                            cout << " (CONTA SELECIONADA)\n";
                        cout << "-----------------------\n";
                    }

                    if (contaAtual == -1) {
                        cout << "Selecione uma conta para operar (digite o número da conta): ";
                        int selecao;
                        cin >> selecao;
                        limparBuffer();

                        if (selecao >= 1 && selecao <= static_cast<int>(contas.size())) {
                            contaAtual = selecao - 1;
                            cout << "Conta #" << selecao << " selecionada.\n";
                        } else {
                            throw OperacaoInvalidaException("Número da conta inválido.");
                        }
                    }
                    break;
                }
                case 6:
                    cout << "Encerrando programa...\n";
                    break;
                default:
                    throw OperacaoInvalidaException("Opção inválida. Tente novamente.");
            }
        } catch (const OperacaoInvalidaException& e) {
            cerr << "Erro: " << e.what() << endl;
        }
    } while (opcao != 6);

    return 0;
}