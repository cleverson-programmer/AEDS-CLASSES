#include <iostream>
#include <string>

using namespace std;

class Turma {
    private:
        string nomes[3];
        float matriz[3][3];

    public:
        void preencher(){
            for(int i = 0; i < 3; i++){
                cout << "Digite o nome: ";
                getline(cin, nomes[i]);

                for(int j = 0; j < 3; j++){
                    cout << "\nDigite a " << j + 1 << "° nota: ";
                    cin >> matriz[i][j];
                    cin.ignore();
                }
            }
        }

        void mostrarMedias(){

            for(int i = 0; i < 3; i++){
                float soma = 0;
                cout << "\nMedia do " << i + 1 << " aluno: ";
                
                for(int j = 0; j < 3; j++){
                    soma += matriz[i][j];
                }

                float media = soma / 3;
                cout << "\nNome:" << nomes[i] << " | " << "Media: " << media;
            }
        }
};

int main(){
    Turma aeds;
    aeds.preencher();
    aeds.mostrarMedias();

    return 0;
}