// Crie uma struct Produto com nome e preço.
// Crie a classe Pedido com uma lista de produtos, quantidade total e valor total.
// Implemente métodos para adicionar produtos e calcular o total.
// Use try/catch para lançar uma exceção se o nome do produto for vazio ou se o preço for negativo.

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>

using namespace std;

struct Product{
    string name;
    float price;
};

class Order{
    private:
        vector<Product> _order;
        int _amount = 0;
        float _valueProduct;
    public:
        void addToProduct(){
            Product p;
            char c;

            while(true){
                cout << "Deseja adicionar produto (s/n): ";
                cin >> c;
                cin.ignore();
                if(tolower(c) != 's'){
                    break;
                }

                cout << "Digite o nome: ";
                getline(cin, p.name);
                if(p.name == ""){
                    throw runtime_error("Erro: nome vazio");
                }

                cout << "Digite o preço: ";
                cin >> p.price;
                if(p.price < 0){
                    throw invalid_argument("preço negativo");
                }
                cin.ignore();


                _order.push_back(p);
            }
        }

        void calculateTotal(){
            for(int i = 0; i < _order.size(); i++){ 
                _amount ++;
                _valueProduct += _order[i].price;
            };
        }

        void showProducts(){

            for(int i = 0; i < _order.size(); i++){
                cout << "\nNome: " << _order[i].name 
                << " Preco: " << fixed << setprecision(2) << "R$" 
                <<  _order[i].price << endl;
            }
        }

        void showTotal(){
            calculateTotal();
            cout << "Total: " << fixed << setprecision(2) 
            << _valueProduct << " Quantidade: " << _amount << endl;
        }

};

int main(){
    Order order;
    try{
        order.addToProduct();
    }catch(const runtime_error& error){
        cout << error.what() << endl;
    }catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    order.showProducts();
    order.showTotal();

    return 0;
}