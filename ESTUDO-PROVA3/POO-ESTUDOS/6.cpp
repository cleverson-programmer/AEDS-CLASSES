#include <iostream>
#include <string>
#include <vector>
#include <limits> // Necessário para std::numeric_limits

using namespace std;

class Livro {
private:
    string _titulo;
    string _autor;
    int _ano;
    int _quantidade;

public:
    Livro(string t = "", string a = "", int y = 0, int q = 0)
        : _titulo(t), _autor(a), _ano(y), _quantidade(q) {}

    void setTitulo(string t) { _titulo = t; }
    void setAutor(string a) { _autor = a; }
    void setAno(int y) { _ano = y; }
    void setQuantidade(int q) { _quantidade = q; }

    string getTitulo() const { return _titulo; }

    void atualizarQtdLivros() {
        int qtd;
        cout << "Digite a nova quantidade: ";
        cin >> qtd;
        _quantidade = qtd;
    }

    void exibir() const {
        cout << "Titulo: " << _titulo << " | Autor: " << _autor
             << " | Ano: " << _ano << " | Quantidade: " << _quantidade << endl;
    }
};

class GerenciarLivros {
private:
    vector<Livro> _livros;

public:
    void cadastrarProdutos() {
        int qtd = 0;
        do {
            Livro livro;
            string titulo, autor;
            int ano;

            cout << "Digite o titulo do livro: ";
            getline(cin, titulo);
            livro.setTitulo(titulo);

            cout << "Digite o autor do livro: ";
            getline(cin, autor);
            livro.setAutor(autor);

            cout << "Digite o ano do livro: ";
            cin >> ano;
            livro.setAno(ano);

            cout << "Digite a quantidade de livros: (0 para sair): ";
            cin >> qtd;
            livro.setQuantidade(qtd);

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa todo o buffer

            _livros.push_back(livro);

        } while (qtd > 0);
    }

    void atualizarEstoque() {
        string titulo;
        cout << "Digite o titulo do livro que deseja: ";
        getline(cin, titulo);

        bool encontrado = false;

        for (auto& livro : _livros) {
            if (livro.getTitulo() == titulo) {
                livro.atualizarQtdLivros();
                livro.exibir();
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            throw runtime_error("Não encontramos livro com esse nome!");
        }
    }
};

string continuar() {
    char c;
    cout << "Deseja atualizar algum produto? (s/n): ";
    cin >> c;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tolower(c) == 's') return "sim";
    throw string("não");
}

int main() {
    GerenciarLivros livros;
    livros.cadastrarProdutos();

    try {
        continuar();
        livros.atualizarEstoque();
    } catch (const string& error) {
        cout << "Fechando programa!" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
