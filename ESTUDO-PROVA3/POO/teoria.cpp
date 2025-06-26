// Você deve usar um construtor quando:
    // Quer garantir que o objeto comece com valores válidos desde sua criação.
    // Quer evitar repetição de código ao inicializar os atributos.
    // Deseja facilitar a criação de objetos passando os valores diretamente.

// Você pode não precisar de um construtor personalizado quando:
    // Vai setar os dados depois (ex: com set...() ou outro método).
    // Os objetos serão manipulados de forma interativa, como leitura pelo teclado.
    // Quer flexibilidade na ordem ou condição em que os dados são atribuídos.

// | Situação                                        | Use Construtor?    | Por quê?                                     |
// | ----------------------------------------------- | ------------------ | -------------------------------------------- |
// | Valores fixos ou lidos de arquivo/dados prontos | ✅ Sim              | Evita código repetido                        |
// | Entrada do usuário (ex: `cin`, `getline`)       | ❌ Não              | Você não tem os dados no momento da criação  |
// | Testes e protótipos rápidos                     | ✅ Sim              | Facilita a criação de objetos já preenchidos |
// | Objetos compostos (contêm outros objetos)       | ✅ Muitas vezes sim | Ajuda a inicializar membros automaticamente  |

// Herança (é-um): Não faz sentido porque um gerenciador não é um produto
// Composição (tem-um): Faz sentido porque um gerenciador tem produtos

// Encapsulamento
// Esconder os detalhes internos da implementação e permitir acesso apenas por meio de métodos públicos (get/set).

// 🔒 private: acesso restrito à própria classe.

// ⚙️ protected: acesso à própria classe e às classes derivadas.

// 🌐 public: acesso livre a qualquer parte do código.

        class Pessoa {
            private:
                string nome;
                int idade;

            public:
                void setNome(string n) { nome = n; }
                string getNome() const { return nome; }

                void setIdade(int i) { idade = i; }
                int getIdade() const { return idade; }
        };

// Herança
// Uma classe pode herdar atributos e métodos de outra.

        class Animal {
        public:
            void fazerSom() { cout << "Som genérico\n"; }
        };

        class Cachorro : public Animal {
        public:
            void latir() { cout << "Au Au!\n"; }
        };

//QUANDO USAR OU NÃO CONSTRUTORES:  
        // USAR QUANDO:
        // Use construtores quando quiser forçar a inicialização correta.
        // Para objetos imutáveis ou com regras rígidas de inicialização, o construtor é essencial.
        //NÃO USAR QUANDO:
        // Evite usar se o objeto será preenchido depois via métodos ou dados do usuário.
        // Em structs simples que funcionam como “pacotes de dados”

        // Quando devo criar múltiplos construtores?
        // Quando você quer flexibilidade na criação de objetos com diferentes quantidades de informação.
        class Livro {
            private:
                string titulo;
                string autor;
            public:
                Livro(string t) { titulo = t; autor = "Desconhecido"; }
                Livro(string t, string a) { titulo = t; autor = a; }
        };

// Polimorfismo
// Capacidade de usar o mesmo nome de função com comportamentos diferentes.

// Polimorfismo de tempo de compilação: Sobrecarga

// Polimorfismo de tempo de execução: Herança com funções virtual

//EM TEMPO DE COMPILAÇÃO: Múltiplas funções com mesmo nome
//EM TEMPO DE EXECUÇÃO: Métodos redefinidos em classes filhas

        class Forma {
        public:
            virtual void desenhar() { cout << "Desenhando forma genérica\n"; }
        };

        class Circulo : public Forma {
        public:
            void desenhar() override { cout << "Desenhando círculo\n"; }
        };

// Polimorfismo em Tempo de Compilação (Sobrecarga)
// ➤ Ocorre quando o compilador escolhe qual versão da função usar durante a compilação.

// ° Sobrecarga de função
// ° Sobrecarga de operador

        class Soma {
        public:
            int somar(int a, int b) {
                return a + b;
            }

            float somar(float a, float b) {
                return a + b;
            }

            int somar(int a, int b, int c) {
                return a + b + c;
            }
        };

        int main() {
            Soma s;
            cout << s.somar(2, 3) << endl;          // Chama somar(int, int)
            cout << s.somar(2.5f, 3.1f) << endl;    // Chama somar(float, float)
            cout << s.somar(1, 2, 3) << endl;       // Chama somar(int, int, int)
            return 0;
        }

// Polimorfismo em Tempo de Execução (virtual + override)
// ➤ Ocorre quando a decisão sobre qual método executar é feita em tempo de execução. Isso é possível com ponteiros para a classe base e o uso da palavra-chave virtual.

        using namespace std;

        class Animal {
        public:
            virtual void fazerSom() {
                cout << "Animal faz som genérico\n";
            }
        };

        class Cachorro : public Animal {
        public:
            void fazerSom() override {
                cout << "Cachorro late: au au\n";
            }
        };

        class Gato : public Animal {
        public:
            void fazerSom() override {
                cout << "Gato mia: miau\n";
            }
        };

        int main() {
            Animal* a1 = new Cachorro();
            Animal* a2 = new Gato();

            a1->fazerSom(); // Chama método de Cachorro por polimorfismo
            a2->fazerSom(); // Chama método de Gato por polimorfismo

            delete a1;
            delete a2;

            return 0;
        }

// virtual	        Diz ao compilador: "esta função pode ser sobrescrita pelas classes filhas"
// override	    Garante que o método sobrescreve corretamente uma função virtual
// Animal*	        Um ponteiro da classe base pode apontar para qualquer classe derivada
// a1->fazerSom()	O método é escolhido em tempo de execução, baseado no tipo real do objeto


//TRABALHANDO COM STRINGS EM C++
// | Em C (string.h)     | Em C++ moderno (`std::string`)                          |
// | ------------------- | ------------------------------------------------------- |
// | `strcmp(s1, s2)`    | `s1 == s2` ou `s1.compare(s2)`                          |
// | `strcpy(dest, src)` | `dest = src;`                                           |
// | `strlen(s)`         | `s.length()` ou `s.size()`                              |
// | `strcat(s1, s2)`    | `s1 += s2;`                                             |
// | `strtok(s, delim)`  | `std::getline()` ou `std::stringstream` com delimitador |

// | Função                        | O que faz                                                     |
// | ----------------------------- | ------------------------------------------------------------- |
// | `s.length()` ou `s.size()`    | Retorna tamanho da string                                     |
// | `s.substr(pos, len)`          | Retorna substring a partir da posição `pos` com tamanho `len` |
// | `s.find("texto")`             | Retorna posição da primeira ocorrência                        |
// | `s.erase(pos, len)`           | Remove parte da string                                        |
// | `s.insert(pos, "abc")`        | Insere "abc" na posição `pos`                                 |
// | `s.replace(pos, len, "nova")` | Substitui parte da string                                     |

        #include <sstream>
        #include <string>
        #include <iostream>

        int main() {
            std::string dados = "123,456,789"; //Define uma string com valores separados por vírgula.
            std::stringstream ss(dados); //Cria um fluxo de string (como se fosse um cin) a partir da string dados.
            std::string valor;  //Variável que vai armazenar cada pedaço da string separado por vírgula.

            // A função std::getline() com 3 parâmetros lê até encontrar o delimitador (,) e armazena o pedaço em valor.
            // O while continua até o final da string.
            // Cada valor é impresso em uma nova linha.
            while (std::getline(ss, valor, ',')) {
                std::cout << valor << std::endl;
            }

            return 0;
        }

        //Saida
        // 123
        // 456
        // 789


//TRABALHANDO COM LIB memory PARA GERENCIAMENTO DE MEMORIA USANDO POLIMORFISMO COM PONTEIROS

// ======= IMPORTANTE ==========

            // vector<unique_ptr<ContaCorrente>>
            //Usamos quando estamos trabalhando com polimorfirmo e sobrecarga usando virtual e override.
            //Permite que cadastremos em um único vetor tipos diferentes instâncias que são herdadas da classe mãe,
            //nesse caso ContaCorrente.
            // Com o vector de unique_ptr podemos armazenar os objetos da forma abaixo:

            //contas.emplace_back(make_unique<ContaCorrente>(nome, saldoInicial));
            //contas.emplace_back(make_unique<ContaEspecial>(nome, saldoInicial));

            //emplace_back para passar os argumentos que o construtor da classe espera, ele já instância o objeto automaticamente a partir do construtor e já coloca no fim do vetor
            //make_unique<Classe> ele já cria e retorna um objeto do tipo unique_ptr que já espera os argumentos da classe passada


// ======= FIM ==========

// #include <memory>
// Essa biblioteca fornece recursos de gerenciamento inteligente de memória, como:
    // std::unique_ptr
        // Dono exclusivo de um objeto.
        // Não pode ser copiado, apenas movido (std::move).
        // O objeto é desalocado automaticamente quando o unique_ptr sai do escopo.
        //Use quando:
        // Apenas um dono do recurso existe (ex: polimorfismo, encapsulamento).
        #include <memory>

        std::unique_ptr<int> ptr = std::make_unique<int>(10);
        // *ptr == 10

    // std::shared_ptr
        // Permite compartilhamento de posse entre múltiplos ponteiros.
        // Usa contagem de referências interna.
        // O objeto é deletado quando o último shared_ptr que o aponta é destruído.
        //Use quando:
        // Múltiplas partes do programa precisam acessar e manter vivo o mesmo objeto.
        // Ex: gráficos, árvores, caches, callbacks, etc.
        #include <memory>

        std::shared_ptr<int> a = std::make_shared<int>(42);
        std::shared_ptr<int> b = a;

    // std::weak_ptr
        // std::weak_ptr<T>
        // Ponteiro não-dominante, usado com shared_ptr.
        // Não aumenta a contagem de referência.
        // Usado para evitar ciclos de referência (ex: em árvores ou grafos)
        // Usa quando:
        // Precisa acessar um objeto gerenciado por shared_ptr, mas sem manter ele vivo.
        // Evita memory leaks causados por ciclos de shared_ptr.
        #include <memory>

        std::shared_ptr<int> a = std::make_shared<int>(5);
        std::weak_ptr<int> b = a; // b não mantém o objeto vivo

    // std::make_unique<T>(args...)
    // Cria e retorna um unique_ptr<T>, passando args para o construtor de T.
    // Mais seguro que new + unique_ptr, evita erros em situações com exceção.
    auto ptr = std::make_unique<int>(10);

    // std::make_shared<T>(args...)
    // Cria e retorna um shared_ptr<T>, passando args para o construtor de T.
    // Mais eficiente que shared_ptr<T>(new T(...)), pois faz uma única alocação para o objeto + controle.