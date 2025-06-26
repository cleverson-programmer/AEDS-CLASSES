//Classe usada nos exercícios:
#include <iostream>
#include <string>
#include <limits>
#include <expcepiton>

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