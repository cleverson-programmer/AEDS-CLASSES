// Sistema Bancário (Sobrecarga de Construtor, Alocação Dinâmica)
// Enunciado:
// Crie a classe ContaBancaria com os atributos: número da conta, nome do titular e saldo.
// Implemente sobrecarga de construtores para permitir diferentes formas de criação de uma conta.
// Crie dinamicamente um vetor de contas, permita cadastrar e buscar por número da conta.
// Trate exceções se o saldo for negativo ao criar a conta.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>
#include <stdexcept>

using namespace std;

class ContaBancaria{
    private:
        string _nomeTitular;
        int _numeroConta;
        float _saldo;

        string _nomeInfantil;
        int _cnpj;
    public:
        //Construtor padrão;
        ContaBancaria() : _nomeTitular(""), _numeroConta(0), _saldo(0.0) {}

        //Construtor Completo:
        ContaBancaria(string _nT, int _nC, float _s){
            if( _s < 0 ) throw invalid_argument("Saldo inválido!");
            _nomeTitular = _nT;
            _numeroConta = _nC;
            _saldo = _s;
        }

        //Construtor Conta Infantil:
        ContaBancaria(string _nI, string _nT, int _nC){
            if( _nT == _nI ) throw invalid_argument("Nomes iguais!");

            _nomeInfantil = _nI;
            _nomeTitular = _nT;
            _numeroConta = _nC;
            _saldo = 50.00;
        }

        //Construtor Conta PJ:
        ContaBancaria(string _nT, bool isEmpresa, int _cnpj, int _nC, float _s){
            _nomeTitular = _nT;
            this->_cnpj = _cnpj;
            _numeroConta = _nC;
            _saldo = isEmpresa ? _s + 1000.00 : 0.00;
        }

        int getNumeroConta() const {
            return _numeroConta;
        }

        string getTitularConta() const {
            return _nomeTitular;
        }

        void setSaldo(float _s){
            if( _s < 0.00 ) throw invalid_argument("Saldo inválido");
        }

        int getSaldo() const {
            return _saldo;
        }

        void exibirConta(){
            cout << "\nNome titular: " << _nomeTitular
            << "\nNúmero da conta: " << _numeroConta
            << "\nSaldo: " << fixed << setprecision(2) << _saldo;
        }
};

class GerenciadorContas{
    private:
        vector<unique_ptr<ContaBancaria>> contas;

    public:
        void cadastrarContas(){
            int tipo, numeroConta, cnpj;
            float saldo;
            string nomeTitular, nomeInfantil;

            cout << "Tipos de contas: \n";
            cout << "1. Conta Comum\n";
            cout << "2. Conta Infantil\n";
            cout << "3. Conta Empresarial\n";
            cout << "Escolha o tipo: ";
            cin >> tipo;
            cin.ignore();

            cout << "Número da conta: \n";
            cin >> numeroConta;
            cin.ignore();

            cout << "Nome do titular: ";
            getline(cin, nomeTitular);

            try{
                switch(tipo){
                    case 1:
                        cout << "Saldo inicial: ";
                        cin >> saldo;
                        contas.push_back(make_unique<ContaBancaria>(nomeTitular, numeroConta, saldo));
                        break;
                    case 2:
                        cout << "Digite o nome da criança";
                        getline(cin, nomeInfantil);
                        contas.push_back(make_unique<ContaBancaria>(nomeInfantil, nomeTitular, numeroConta));
                        break;
                    case 3:
                        cout << "Digite o CNPJ: ";
                        cin >> cnpj;
                        cout << "Saldo inicial: ";
                        cin >> saldo;
                        contas.push_back(make_unique<ContaBancaria>(nomeTitular, true, cnpj, numeroConta, saldo));
                        break;
                    default:
                        cout << "Tipo inválido";
                }
            } catch( const invalid_argument& error){
                cout << "Erro ao criar conta: " << error.what() << endl;
            }
        }

        void buscarConta() {
            int numeroConta;
            cout << "\nDigite o número da conta para buscar: ";
            cin >> numeroConta;

            bool encontrada = false;
            for (int i = 0; i < contas.size(); i++) {
                if(contas[i]->getNumeroConta() == numeroConta){
                    encontrada = true;
                    contas[i]->exibirConta();
                }
            }

            if(!encontrada){
                throw invalid_argument("Conta não encontrada!");
            }
        }
    
    private:
        void exibirTodasContas(){
            for(int i = 0; i < contas.size(); i++){
                 cout << "\nNome titular: " << contas[i]->getTitularConta()
                << "\nNúmero da conta: " << contas[i]->getNumeroConta();
            }
        }

    public:
        void getExibirTodasContas() {
            exibirTodasContas();
        }
};

int main(){
    GerenciadorContas gerente;

    gerente.cadastrarContas();
    gerente.buscarConta();
    gerente.getExibirTodasContas();

    return 0;
}