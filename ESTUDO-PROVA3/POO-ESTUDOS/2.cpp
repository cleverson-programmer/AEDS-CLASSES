// Polimorfismo com Formas geométricas

#include <iostream>
#include <string>

using namespace std;

class Formas {

    public:
        virtual void desenhar(){
            cout << "Desenhando forma genérica\n";
        }
};

class Triangulo : public Formas{

    public:
        void desenhar() override{
            cout << "Desenhando triangulo\n";
        }
};

class Quadrado : public Formas{
    public:
        void desenhar() override{
            cout << "Desenhando quadrado\n";
        }
};

int main(){
    Formas* forma1 = new Triangulo();
    Formas* forma2 = new Quadrado();

    forma1->desenhar(); // Chama o metodo triangulo por polimorfismo
    forma2->desenhar(); // Chama o metodo quadrado por polimorfismo

    delete forma1;
    delete forma2;

    return 0;
}