#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

struct Aluno {
    std::string nome;
    float nota;

    Aluno(const std::string& n = "", float nt = 0.0f) : nome(n), nota(nt) {}
};

class GerenciadorAlunos {
private:
    std::vector<Aluno> alunos;

public:
    void lerAlunos() {
        char continuar;
        do {
            std::string nome;
            float nota;

            std::cout << "Digite o nome do " << alunos.size() + 1 << "° aluno: ";
            std::getline(std::cin, nome);

            std::cout << "Digite a nota do " << alunos.size() + 1 << "° aluno: ";
            std::cin >> nota;
            std::cin.ignore(); // Limpa o buffer depois de ler a nota

            // O emplace_back é um método do std::vector que:
            // Constrói o objeto diretamente no final do vetor (no lugar), evitando cópias desnecessárias
            // Aceita os parâmetros do construtor do objeto que será criado
            // É mais eficiente que push_back quando se trabalha com objetos complexos
            //EQUIVALENTE A: alunos.push_back(Aluno(nome, nota));
            alunos.emplace_back(nome, nota);

            std::cout << "Deseja continuar (s/n): ";
            std::cin >> continuar;
            continuar = std::tolower(continuar);
            std::cin.ignore();
        } while(continuar == 's');
    }

    float calcularMediaAprovados() const { 
        float soma = 0;
        int count = 0;

        for(size_t i = 0; i < alunos.size(); i++) {
            if(alunos[i].nota > 6.0f) {
                soma += alunos[i].nota;
                count++;
            }
        }

        return count > 0 ? soma / count : 0.0f;
    }

    void exibirMedia() const {
        float media = calcularMediaAprovados();
        std::cout << "A média dos alunos aprovados é: " 
                  << std::fixed << std::setprecision(2) << media << std::endl;
    }
};

int main() {
    GerenciadorAlunos gerenciador;
    
    gerenciador.lerAlunos();
    gerenciador.exibirMedia();

    return 0;
}