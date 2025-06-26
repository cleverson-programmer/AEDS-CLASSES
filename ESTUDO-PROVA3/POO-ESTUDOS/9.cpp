// Implemente a classe Aluno com os atributos privados: nome, idade, notas[3] e presença (bool).
// Use métodos de acesso para manipular os dados.
// Permita cadastrar alunos, calcular a média e verificar se ele está aprovado (média ≥ 6 e presença = true).
// Use um vetor de objetos Aluno.

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Aluno {
private:
    string _name;
    int _age;
    float _grades[3];
    bool _presence;

public:
    void setData(const string& name, int age, float n1, float n2, float n3, bool presence) {
        _name = name;
        _age = age;
        _grades[0] = n1;
        _grades[1] = n2;
        _grades[2] = n3;
        _presence = presence;
    }

    void inputData() {
        char c;

        cout << "Nome: ";
        getline(cin, _name);

        cout << "Idade: ";
        cin >> _age;

        for (int i = 0; i < 3; i++) {
            cout << "Nota " << i + 1 << ": ";
            cin >> _grades[i];
        }

        cout << "Presente (s/n): ";
        cin >> c;
        cin.ignore(); // Limpa o buffer após o char

        _presence = tolower(c) == 's';
    }

    float getAverage() const {
        float sum = 0.0f;
        for (int i = 0; i < 3; i++) {
            sum += _grades[i];
        }
        return sum / 3.0f;
    }

    bool isApproved() const {
        return _presence && getAverage() >= 6.0f;
    }

    void showResult() const {
        cout << fixed << setprecision(2);
        cout << "\nAluno: " << _name << "\n";
        cout << "Idade: " << _age << "\n";
        cout << "Média: " << getAverage() << "\n";
        cout << "Presença: " << (_presence ? "Sim" : "Não") << "\n";
        cout << "Situação: " << (isApproved() ? "Aprovado" : "Reprovado") << "\n";
    }
};

int main() {
    int q;
    cout << "Quantidade de alunos: ";
    cin >> q;
    cin.ignore(); // limpa buffer após ler int

    vector<Aluno> alunos(q);

    for (int i = 0; i < q; i++) {
        cout << "\n--- Cadastro do Aluno " << i + 1 << " ---\n";
        alunos[i].inputData();
    }

    cout << "\n======= RESULTADOS =======\n";
    for (int i = 0; i < q; i++) {
        alunos[i].showResult();
    }

    return 0;
}