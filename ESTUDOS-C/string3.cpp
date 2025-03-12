#include <iostream>
#include <string>

//TRABALHANDO COM STRINGS EM C++

//std:: tipo de dado <nome da variavel> --> Define uma variavel

//std::count << --> funciona como o printf para trabalhar com saidade de dados do C
//std::getline --> funciona como o fgets ou scanf do C. std::cin é como se fosse o & que passa para o scanf e o sizeof() do fgets
int main() {
    std::string nome;
    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome);

    //em vez de usar o % dentro do texto usamos o <<
    std::cout << "Nome digitado: " << nome << std::endl;
    return 0;
}