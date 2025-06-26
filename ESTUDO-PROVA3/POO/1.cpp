//COMANDO PARA RODAR C++:
// g++ -g main.cpp -o main
// ./main


#include <iostream>      // Biblioteca para entrada e saída padrão (std::cout, std::cin)
#include <vector>        // Biblioteca para usar o container dinâmico std::vector
#include <iomanip>       // Biblioteca para controlar a formatação da saída (std::setprecision)

// Definindo uma classe que gerencia as notas
class GerenciadorNotas {
private:
    std::vector<float> notas; // Vetor dinâmico que armazena as notas

public:
    // Método para adicionar uma nova nota ao vetor
    void adicionarNota(float nota) {
        notas.push_back(nota); // push_back insere um novo elemento no final do vetor
    }

    // Método que lê notas do usuário até que uma nota negativa seja digitada
    void lerNotas() {
        float nota;
        int i = 1; // Contador de notas (só para mostrar o número da nota ao usuário)

        while (true) {
            std::cout << "Digite a " << i << "ª nota: "; // Saída no console
            std::cin >> nota; // Entrada do usuário

            if (nota < 0) break; // Sai do laço se a nota for negativa

            adicionarNota(nota); // Adiciona a nota no vetor
            i++; // Incrementa o contador
        }
    }

    // Método que exibe todas as notas e calcula a média
    void mostrarNotasEMedia() const {
        if (notas.empty()) {
            std::cout << "Nenhuma nota foi inserida.\n";
            return;
        }

        float soma = 0;

        std::cout << "Notas inseridas:\n";
        for (size_t i = 0; i < notas.size(); i++) {  // Loop no estilo C
            std::cout << notas[i] << " ";
            soma += notas[i];
        }
        std::cout << "\nMédia das notas: " << std::fixed << std::setprecision(2) << (soma / notas.size()) << "\n";
    }
};

// Função principal
int main() {
    GerenciadorNotas gerenciador; // Cria um objeto da classe GerenciadorNotas
    gerenciador.lerNotas();       // Chama o método para ler as notas
    gerenciador.mostrarNotasEMedia(); // Chama o método para exibir as notas e a média
    return 0; // Fim do programa
}
