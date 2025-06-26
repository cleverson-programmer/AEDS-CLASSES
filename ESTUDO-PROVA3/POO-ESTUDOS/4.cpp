#include <iostream>
#include <string>
#include <vector> // Necessário para usar std::vector

using namespace std;

class Aluno {
private:
    vector<float> notas; // Alocação dinâmica usando vector

public:
    // Método para definir os dados do aluno
    void setNotas(float n) {
        notas.push_back(n);
    }

    // Calcula a média das notas armazenadas no vetor
    float calcularMedia() const {
        float soma = 0;
        for (int i = 0; i < notas.size(); i++) { // Percorre o vetor
            soma += notas[i]; // Soma todas as notas
        }
        return notas.empty() ? 0 : soma / notas.size(); // Evita divisão por zero
    }

    // Exibe a media das notas
    void mostrar() const {
        cout << " - Média: " << calcularMedia() << fixed << setprecision(2);
    }

    void inserirNotas(){
        float nota;
        int count = 0;

        do{
            cout << "Digite a nota do " << count + 1 << " aluno ou 0 para sair";
            cin >> nota;
            if(nota == 0){
                break;
            }
            notas.push_back(nota);
            count++;
        } while(nota >= 0);
    }
};

int main() {
    Aluno alunos;
    alunos.inserirNotas();
    alunos.mostrar();
    return 0;
}