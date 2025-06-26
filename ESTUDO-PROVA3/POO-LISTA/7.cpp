// Escreva uma classe em C++ que gerencie o acesso de um usuário ao sistema. O usuário deverá
// logar no sistema com o usuário "aluno" e a senha "1234". Caso o aluno tente entrar com um login
// diferente do informado, o sistema deverá lançar uma exceção, posteriormente tratada, indicando
// que o acesso não foi autorizado. Caso o usuário não informe o nome de usuário ou senha, o
// sistema também deve também lançar uma exceção, tratada pelo procedimento principal (main).
// A sua classe deve ter os atributos usuário e senha podendo ser carregados no construtor ou no
// método logar, que retornar um booleano indicando sucesso no login. Utilize o conceito de
// polimorfismo paramétrico (sobrecarga de método).

#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Exceção: Acesso negado
class AcessoNegadoException : public exception {
private:
    string mensagem;
public:
    AcessoNegadoException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Exceção: Campos vazios
class CampoVazioException : public exception {
private:
    string mensagem;
public:
    CampoVazioException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Classe de login com polimorfismo paramétrico
class LoginSistema {
private:
    string usuario;
    string senha;
    const string usuarioCorreto = "aluno";
    const string senhaCorreta = "1234";

public:
    // Construtor vazio (poderia aceitar parâmetros, mas neste caso não obrigatório)
    LoginSistema() {}

    // Método logar com parâmetros
    bool logar(string user, string pass) {
        if (user.empty() || pass.empty())
            throw CampoVazioException("Usuário ou senha não podem estar vazios.");
        if (user != usuarioCorreto || pass != senhaCorreta)
            throw AcessoNegadoException("Acesso negado. Usuário ou senha incorretos.");

        usuario = user;
        senha = pass;
        return true;
    }

    // Método logar sem parâmetros (input do usuário)
    bool logar() {
        string user, pass;

        cout << "Usuário: ";
        getline(cin, user);

        cout << "Senha: ";
        getline(cin, pass);

        return logar(user, pass); // reaproveita o outro método (polimorfismo paramétrico)
    }

    void mensagemSucesso() const {
        cout << "\nLogin efetuado com sucesso. Bem-vindo, " << usuario << "!\n";
    }
};

int main() {
    LoginSistema sistema;

    try {
        cout << "=== SISTEMA DE LOGIN ===\n";
        if (sistema.logar()) {
            sistema.mensagemSucesso();
        }
    }
    catch (const CampoVazioException& e) {
        cerr << "\nErro: " << e.what() << endl;
    }
    catch (const AcessoNegadoException& e) {
        cerr << "\nErro: " << e.what() << endl;
    }
    catch (...) {
        cerr << "\nErro desconhecido ao tentar realizar o login.\n";
    }

    return 0;
}