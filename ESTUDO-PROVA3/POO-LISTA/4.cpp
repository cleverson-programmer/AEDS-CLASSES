// Crie um programa para gerenciar uma loja de animais de estimação. A loja vende cachorros e
// gatos. Cada animal possui um nome, raça, idade e preço. Faça um CRUD utilizando métodos setter
// e getters.
// Utilize os conceitos de classe, atributos, métodos, encapsulamento (get/set), método construtor e
// relacionamento de classes com cardinalidade 1 para N (associação, agregação ou composição)

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <memory>
#include <exception>

using namespace std;

// Classe de exceção personalizada
class EntradaInvalidaException : public exception {
private:
    string mensagem;
public:
    EntradaInvalidaException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class Animal {
protected:
    string nome;
    string raca;
    int idade;
    float preco;

public:
    Animal(string nome, string raca, int idade, float preco) {
        if (nome.empty() || raca.empty())
            throw EntradaInvalidaException("Nome e raça não podem estar vazios.");
        if (idade < 0)
            throw EntradaInvalidaException("Idade não pode ser negativa.");
        if (preco <= 0)
            throw EntradaInvalidaException("Preço deve ser maior que zero.");

        this->nome = nome;
        this->raca = raca;
        this->idade = idade;
        this->preco = preco;
    }

    virtual ~Animal() {}

    string getNome() const { return nome; }
    string getRaca() const { return raca; }
    int getIdade() const { return idade; }
    float getPreco() const { return preco; }

    void setNome(string novoNome) {
        if (!novoNome.empty()) nome = novoNome;
    }

    void setRaca(string novaRaca) {
        if (!novaRaca.empty()) raca = novaRaca;
    }

    void setIdade(int novaIdade) {
        if (novaIdade >= 0) idade = novaIdade;
        else throw EntradaInvalidaException("Idade inválida.");
    }

    void setPreco(float novoPreco) {
        if (novoPreco > 0) preco = novoPreco;
        else throw EntradaInvalidaException("Preço inválido.");
    }

    virtual void mostrarDados() const {
        cout << "Nome: " << nome
             << " | Raça: " << raca
             << " | Idade: " << idade << " anos"
             << " | Preço: R$ " << fixed << setprecision(2) << preco;
    }
};

class Cachorro : public Animal {
private:
    string porte;
public:
    Cachorro(string nome, string raca, int idade, float preco, string porte)
        : Animal(nome, raca, idade, preco) {
        if (porte.empty())
            throw EntradaInvalidaException("Porte do cachorro não pode estar vazio.");
        this->porte = porte;
    }

    string getPorte() const { return porte; }
    void setPorte(string novoPorte) {
        if (!novoPorte.empty()) porte = novoPorte;
    }

    void mostrarDados() const override {
        Animal::mostrarDados();
        cout << " | Porte: " << porte << " (Cachorro)";
    }
};

class Gato : public Animal {
private:
    bool ehPeludo;
public:
    Gato(string nome, string raca, int idade, float preco, bool ehPeludo)
        : Animal(nome, raca, idade, preco), ehPeludo(ehPeludo) {}

    bool getEhPeludo() const { return ehPeludo; }
    void setEhPeludo(bool peludo) { ehPeludo = peludo; }

    void mostrarDados() const override {
        Animal::mostrarDados();
        cout << " | Peludo: " << (ehPeludo ? "Sim" : "Não") << " (Gato)";
    }
};

class LojaAnimais {
private:
    vector<unique_ptr<Animal>> animais;

public:
    void adicionarAnimal() {
        try {
            int tipo;
            string nome, raca;
            int idade;
            float preco;

            cout << "\nTipo de animal:\n1. Cachorro\n2. Gato\nOpção: ";
            cin >> tipo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nome: ";
            getline(cin, nome);

            cout << "Raça: ";
            getline(cin, raca);

            cout << "Idade: ";
            cin >> idade;

            cout << "Preço: R$ ";
            cin >> preco;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (tipo == 1) {
                string porte;
                cout << "Porte (Pequeno/Médio/Grande): ";
                getline(cin, porte);
                animais.emplace_back(make_unique<Cachorro>(nome, raca, idade, preco, porte));
            } else if (tipo == 2) {
                string peludo;
                cout << "É peludo? (S/N): ";
                getline(cin, peludo);
                if (peludo.empty())
                    throw EntradaInvalidaException("Informação de peludo não pode estar vazia.");
                bool ehPeludo = (peludo == "S" || peludo == "s");
                animais.emplace_back(make_unique<Gato>(nome, raca, idade, preco, ehPeludo));
            } else {
                throw EntradaInvalidaException("Tipo de animal inválido.");
            }

            cout << "Animal cadastrado com sucesso!\n";
        } catch (const EntradaInvalidaException& e) {
            cerr << "Erro: " << e.what() << endl;
        }
    }

    void listarAnimais() const {
        if (animais.empty()) {
            cout << "\nNenhum animal cadastrado.\n";
            return;
        }

        cout << "\n=== LISTA DE ANIMAIS ===\n";
        for (size_t i = 0; i < animais.size(); ++i) {
            cout << i + 1 << ". ";
            animais[i]->mostrarDados();
            cout << endl;
        }
    }

    void editarAnimal() {
        if (animais.empty()) {
            cout << "\nNenhum animal cadastrado.\n";
            return;
        }

        listarAnimais();
        cout << "\nDigite o número do animal que deseja editar: ";
        int indice;
        cin >> indice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (indice < 1 || indice > static_cast<int>(animais.size())) {
            cout << "Índice inválido!\n";
            return;
        }

        try {
            Animal* animal = animais[indice - 1].get();
            string novoNome, novaRaca;
            int novaIdade;
            float novoPreco;

            cout << "Novo nome (" << animal->getNome() << "): ";
            getline(cin, novoNome);
            animal->setNome(novoNome);

            cout << "Nova raça (" << animal->getRaca() << "): ";
            getline(cin, novaRaca);
            animal->setRaca(novaRaca);

            cout << "Nova idade (" << animal->getIdade() << "): ";
            string idadeStr;
            getline(cin, idadeStr);
            if (!idadeStr.empty()) animal->setIdade(stoi(idadeStr));

            cout << "Novo preço (" << fixed << setprecision(2) << animal->getPreco() << "): ";
            string precoStr;
            getline(cin, precoStr);
            if (!precoStr.empty()) animal->setPreco(stof(precoStr));

            // Atualizar atributos específicos
            if (auto cachorro = dynamic_cast<Cachorro*>(animal)) {
                string novoPorte;
                cout << "Novo porte (" << cachorro->getPorte() << "): ";
                getline(cin, novoPorte);
                cachorro->setPorte(novoPorte);
            } else if (auto gato = dynamic_cast<Gato*>(animal)) {
                string novoPeludo;
                cout << "É peludo? (" << (gato->getEhPeludo() ? "Sim" : "Não") << "): ";
                getline(cin, novoPeludo);
                if (!novoPeludo.empty())
                    gato->setEhPeludo(novoPeludo == "S" || novoPeludo == "s");
            }

            cout << "Animal editado com sucesso!\n";
        } catch (const EntradaInvalidaException& e) {
            cerr << "Erro: " << e.what() << endl;
        }
    }

    void removerAnimal() {
        if (animais.empty()) {
            cout << "\nNenhum animal cadastrado.\n";
            return;
        }

        listarAnimais();
        cout << "\nDigite o número do animal que deseja remover: ";
        int indice;
        cin >> indice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (indice < 1 || indice > static_cast<int>(animais.size())) {
            cout << "Índice inválido!\n";
            return;
        }

        animais.erase(animais.begin() + indice - 1);
        cout << "Animal removido com sucesso!\n";
    }
};

void exibirMenu() {
    cout << "\n=== MENU LOJA DE ANIMAIS ===\n";
    cout << "1. Adicionar animal\n";
    cout << "2. Listar animais\n";
    cout << "3. Editar animal\n";
    cout << "4. Remover animal\n";
    cout << "5. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    LojaAnimais loja;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1: loja.adicionarAnimal(); break;
            case 2: loja.listarAnimais(); break;
            case 3: loja.editarAnimal(); break;
            case 4: loja.removerAnimal(); break;
            case 5: cout << "Saindo do sistema...\n"; break;
            default: cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}