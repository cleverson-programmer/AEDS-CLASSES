// Cadastro de pessoa com encapsulamento
//Criar uma classe com atributos privados e métodos públicos.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Pessoa{
    private:
        string nome;
        int idade;
    public:
        void setNome(string n){ nome = n; }
        void setIdade(int i) { idade = i; }

        string getNome() const { return nome; }
        int getIdade() const { return idade; }

};

class GerenciarPessoa : public Pessoa{

    protected:
        Pessoa p;
    public:

        void cadastrarPessoa(){
            string n;
            int i;

            cout << "Digite o nome: ";
            getline(cin, n);
            p.setNome(n);

            cout << "Digite a idade: ";
            cin >> i;
            p.setIdade(i);
        }

        void exibir(){
            cout << p.getNome() << " | " << p.getIdade() << endl;
        }
};

int main(){
    GerenciarPessoa gerenciador;
    gerenciador.cadastrarPessoa();
    gerenciador.exibir();

    return 0;
}