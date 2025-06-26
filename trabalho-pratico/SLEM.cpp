#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <memory>
#include <exception>
#include <cmath>
#include <cstring>

class LogisticaException : public std::exception {
    private:
        char mensagem[200];
        
    public:
        LogisticaException(const char* msg) {
            strncpy(mensagem, msg, sizeof(mensagem) - 1);
            mensagem[sizeof(mensagem) - 1] = '\0';
        }
        
        const char* what() const noexcept override {
            return mensagem;
        }
};

class Local {
    private:
        char nome[100];
        float coordenadaX;
        float coordenadaY;
        
    public:
        Local() {}
        
        Local(const char* n, float x, float y) {
            strncpy(nome, n, sizeof(nome) - 1);
            nome[sizeof(nome) - 1] = '\0';
            coordenadaX = x;
            coordenadaY = y;
        }
        
        const char* getNome() const { return nome; }
        float getX() const { return coordenadaX; }
        float getY() const { return coordenadaY; }
        
        void setNome(const char* n) {
            strncpy(nome, n, sizeof(nome) - 1);
            nome[sizeof(nome) - 1] = '\0';
        }
        
        void setCoordenadas(float x, float y) {
            coordenadaX = x;
            coordenadaY = y;
        }
        
        void exibir() const {
            std::cout << "Local: " << nome << " (X: " << coordenadaX << ", Y: " << coordenadaY << ")";
        }
};

class Veiculo {
    private:
        char placa[20];
        char modelo[50];
        bool disponivel;
        int idLocalAtual;
        
    public:
        Veiculo() : disponivel(true), idLocalAtual(-1) {}
        
        Veiculo(const char* p, const char* m, int local) {
            strncpy(placa, p, sizeof(placa) - 1);
            placa[sizeof(placa) - 1] = '\0';
            strncpy(modelo, m, sizeof(modelo) - 1);
            modelo[sizeof(modelo) - 1] = '\0';
            disponivel = true;
            idLocalAtual = local;
        }
        
        const char* getPlaca() const { return placa; }
        const char* getModelo() const { return modelo; }
        bool isDisponivel() const { return disponivel; }
        int getLocalAtual() const { return idLocalAtual; }
        
        void setDisponivel(bool disp) { disponivel = disp; }
        void setLocalAtual(int local) { idLocalAtual = local; }
        
        void exibir() const {
            std::cout << "Veículo: " << modelo << " (Placa: " << placa << ") - ";
            std::cout << (disponivel ? "Disponível" : "Ocupado");
            std::cout << " - Local atual ID: " << idLocalAtual;
        }
};

class Pedido {
    private:
        int id;
        int idOrigem;
        int idDestino;
        float peso;
        bool entregue;
        
    public:
        Pedido() : id(-1), idOrigem(-1), idDestino(-1), peso(0), entregue(false) {}
        
        Pedido(int i, int orig, int dest, float p) : 
            id(i), idOrigem(orig), idDestino(dest), peso(p), entregue(false) {}
        
        int getId() const { return id; }
        int getOrigem() const { return idOrigem; }
        int getDestino() const { return idDestino; }
        float getPeso() const { return peso; }
        bool isEntregue() const { return entregue; }
        
        void setEntregue(bool ent) { entregue = ent; }
        
        void exibir() const {
            std::cout << "Pedido ID: " << id << " - Peso: " << peso << "kg - ";
            std::cout << (entregue ? "Entregue" : "Pendente");
            std::cout << " - Origem ID: " << idOrigem << " -> Destino ID: " << idDestino;
        }
};


class SistemaLogistica {
    private:
        std::vector<Local> locais;
        std::vector<Veiculo> veiculos;
        std::vector<Pedido> pedidos;
        int proximoIdPedido;
        
        float calcularDistancia(int idLocal1, int idLocal2) const {
            if (idLocal1 < 0 || idLocal1 >= locais.size() || 
                idLocal2 < 0 || idLocal2 >= locais.size()) {
                throw LogisticaException("Local inválido para cálculo de distância");
            }
            
            float dx = locais[idLocal1].getX() - locais[idLocal2].getX();
            float dy = locais[idLocal1].getY() - locais[idLocal2].getY();
            return std::sqrt(dx*dx + dy*dy);
        }
        
    public:
        SistemaLogistica() : proximoIdPedido(1) {}
        
        // Métodos para Locais
        void adicionarLocal(const Local& local) {
            for (const auto& l : locais) {
                if (strcmp(l.getNome(), local.getNome()) == 0) {
                    throw LogisticaException("Local com este nome já existe");
                }
            }
            locais.push_back(local);
        }
        
        void editarLocal(int id, const char* novoNome, float x, float y) {
            if (id < 0 || id >= locais.size()) {
                throw LogisticaException("ID de local inválido");
            }
            locais[id].setNome(novoNome);
            locais[id].setCoordenadas(x, y);
        }
        
        void removerLocal(int id) {
            if (id < 0 || id >= locais.size()) {
                throw LogisticaException("ID de local inválido");
            }
            locais.erase(locais.begin() + id);
        }
        
        void listarLocais() const {
            if (locais.empty()) {
                std::cout << "Nenhum local cadastrado.\n";
                return;
            }
            
            for (size_t i = 0; i < locais.size(); ++i) {
                std::cout << "ID: " << i << " - ";
                locais[i].exibir();
                std::cout << "\n";
            }
        }
        
        // Métodos para Veículos
        void adicionarVeiculo(const Veiculo& veiculo) {
            for (const auto& v : veiculos) {
                if (strcmp(v.getPlaca(), veiculo.getPlaca()) == 0) {
                    throw LogisticaException("Veículo com esta placa já existe");
                }
            }
            veiculos.push_back(veiculo);
        }

        void editarVeiculo(int id, const char* novaPlaca, const char* novoModelo, int novoLocal) {
            if (id < 0 || id >= veiculos.size()) {
                throw LogisticaException("ID de veículo inválido");
            }
            
            // Verificar se a nova placa já existe (exceto para o próprio veículo)
            for (size_t i = 0; i < veiculos.size(); ++i) {
                if (i != id && strcmp(veiculos[i].getPlaca(), novaPlaca) == 0) {
                    throw LogisticaException("Placa já existe em outro veículo");
                }
            }
            
            veiculos[id].setLocalAtual(novoLocal);
            // Como placa e modelo são arrays fixos, precisamos criar um novo veículo
            veiculos[id] = Veiculo(novaPlaca, novoModelo, novoLocal);
            veiculos[id].setDisponivel(veiculos[id].isDisponivel()); // Mantém o status
        }

        void removerVeiculo(int id) {
            if (id < 0 || id >= veiculos.size()) {
                throw LogisticaException("ID de veículo inválido");
            }
            
            // Verificar se o veículo está em uso
            if (!veiculos[id].isDisponivel()) {
                throw LogisticaException("Não é possível remover veículo em uso");
            }
            
            veiculos.erase(veiculos.begin() + id);
        }
        
        void listarVeiculos() const {
            if (veiculos.empty()) {
                std::cout << "Nenhum veículo cadastrado.\n";
                return;
            }
            
            for (size_t i = 0; i < veiculos.size(); ++i) {
                std::cout << "ID: " << i << " - ";
                veiculos[i].exibir();
                std::cout << "\n";
            }
        }
        
        // Métodos para Pedidos
        void adicionarPedido(int origem, int destino, float peso) {
            if (origem < 0 || origem >= locais.size() || destino < 0 || destino >= locais.size()) {
                throw LogisticaException("Local de origem ou destino inválido");
            }
            pedidos.emplace_back(proximoIdPedido++, origem, destino, peso);
        }

        void editarPedido(int id, int novaOrigem, int novoDestino, float novoPeso) {
            if (id < 1 || id >= proximoIdPedido) {
                throw LogisticaException("ID de pedido inválido");
            }
            
            for (auto& p : pedidos) {
                if (p.getId() == id) {
                    if (p.isEntregue()) {
                        throw LogisticaException("Não é possível editar pedido já entregue");
                    }
                    if (novaOrigem < 0 || novaOrigem >= locais.size() || 
                        novoDestino < 0 || novoDestino >= locais.size()) {
                        throw LogisticaException("Local de origem ou destino inválido");
                    }
                    
                    p = Pedido(id, novaOrigem, novoDestino, novoPeso);
                    return;
                }
            }
            
            throw LogisticaException("Pedido não encontrado");
        }

        void removerPedido(int id) {
            if (id < 1 || id >= proximoIdPedido) {
                throw LogisticaException("ID de pedido inválido");
            }
            
            for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
                if (it->getId() == id) {
                    if (it->isEntregue()) {
                        throw LogisticaException("Não é possível remover pedido já entregue");
                    }
                    pedidos.erase(it);
                    return;
                }
            }
            
            throw LogisticaException("Pedido não encontrado");
        }
        
        void listarPedidos() const {
            if (pedidos.empty()) {
                std::cout << "Nenhum pedido cadastrado.\n";
                return;
            }
            
            for (const auto& p : pedidos) {
                p.exibir();
                std::cout << "\n";
            }
        }
        
        // Método para calcular rota de entrega
        void calcularRotaEntrega(int idPedido) {
            // Etapa 1: Encontrar o pedido e calcular a rota
            Pedido* pedido = nullptr;
            for (auto& p : pedidos) {
                if (p.getId() == idPedido && !p.isEntregue()) {
                    pedido = &p;
                    break;
                }
            }
            
            if (!pedido) {
                throw LogisticaException("Pedido não encontrado ou já entregue");
            }

            // Encontrar veículo disponível mais próximo
            int idVeiculo = -1;
            float menorDistancia = std::numeric_limits<float>::max();
            
            for (size_t i = 0; i < veiculos.size(); ++i) {
                if (veiculos[i].isDisponivel()) {
                    float dist = calcularDistancia(veiculos[i].getLocalAtual(), pedido->getOrigem());
                    if (dist < menorDistancia) {
                        menorDistancia = dist;
                        idVeiculo = i;
                    }
                }
            }
            
            if (idVeiculo == -1) {
                throw LogisticaException("Nenhum veículo disponível");
            }

            // Calcular distâncias
            float distOrigemDestino = calcularDistancia(pedido->getOrigem(), pedido->getDestino());
            float distTotal = menorDistancia + distOrigemDestino;

            // Marcar veículo como ocupado (mas pedido ainda não entregue)
            veiculos[idVeiculo].setDisponivel(false);

            // Exibir rota calculada
            std::cout << "\n=== ROTA CALCULADA ===\n";
            std::cout << "Pedido ID: " << pedido->getId() << "\n";
            std::cout << "Veículo designado: " << veiculos[idVeiculo].getPlaca() << "\n";
            std::cout << "Distância total: " << distTotal << " unidades\n";
            std::cout << "Status: Veículo marcado como OCUPADO\n";

            // Opções para o usuário
            int opcao;
            do {
                std::cout << "\n1. Listar veículos para ver status atual";
                std::cout << "\n2. Confirmar entrega concluída";
                std::cout << "\n0. Cancelar (marcar veículo como disponível)";
                std::cout << "\nEscolha uma opção: ";
                std::cin >> opcao;

                switch (opcao) {
                    case 1:
                        std::cout << "\n=== LISTA DE VEÍCULOS ===\n";
                        listarVeiculos();
                        break;
                    case 2:
                        // Confirmar entrega
                        pedido->setEntregue(true);
                        veiculos[idVeiculo].setLocalAtual(pedido->getDestino());
                        veiculos[idVeiculo].setDisponivel(true);
                        
                        std::cout << "\n=== ENTREGA CONCLUÍDA ===\n";
                        std::cout << "Pedido ID: " << pedido->getId() << " entregue!\n";
                        std::cout << "Veículo " << veiculos[idVeiculo].getPlaca() 
                                << " agora está DISPONÍVEL no local de destino.\n";
                        return;
                    case 0:
                        // Cancelar - marcar veículo como disponível novamente
                        veiculos[idVeiculo].setDisponivel(true);
                        std::cout << "Operação cancelada. Veículo marcado como disponível.\n";
                        return;
                    default:
                        std::cout << "Opção inválida!\n";
                }
            } while (opcao != 0);
        }
        
        // Métodos para backup e restauração
        void fazerBackup() const {
            // Salvar locais
            std::ofstream arqLocais("locais.bin", std::ios::binary);
            if (!arqLocais) {
                throw LogisticaException("Falha ao criar arquivo de backup de locais");
            }
            
            size_t numLocais = locais.size();
            arqLocais.write(reinterpret_cast<const char*>(&numLocais), sizeof(numLocais));
            arqLocais.write(reinterpret_cast<const char*>(locais.data()), numLocais * sizeof(Local));
            
            // Salvar veículos
            std::ofstream arqVeiculos("veiculos.bin", std::ios::binary);
            if (!arqVeiculos) {
                throw LogisticaException("Falha ao criar arquivo de backup de veículos");
            }
            
            size_t numVeiculos = veiculos.size();
            arqVeiculos.write(reinterpret_cast<const char*>(&numVeiculos), sizeof(numVeiculos));
            arqVeiculos.write(reinterpret_cast<const char*>(veiculos.data()), numVeiculos * sizeof(Veiculo));
            
            // Salvar pedidos
            std::ofstream arqPedidos("pedidos.bin", std::ios::binary);
            if (!arqPedidos) {
                throw LogisticaException("Falha ao criar arquivo de backup de pedidos");
            }
            
            size_t numPedidos = pedidos.size();
            arqPedidos.write(reinterpret_cast<const char*>(&numPedidos), sizeof(numPedidos));
            arqPedidos.write(reinterpret_cast<const char*>(pedidos.data()), numPedidos * sizeof(Pedido));
            
            // Salvar próximo ID de pedido
            std::ofstream arqId("id_pedido.bin", std::ios::binary);
            if (!arqId) {
                throw LogisticaException("Falha ao criar arquivo de backup do ID de pedido");
            }
            arqId.write(reinterpret_cast<const char*>(&proximoIdPedido), sizeof(proximoIdPedido));
            
            std::cout << "Backup realizado com sucesso!\n";
        }

        void restaurarDados() {
            // Carregar locais
            std::ifstream arqLocais("locais.bin", std::ios::binary);
            if (!arqLocais) {
                throw LogisticaException("Falha ao abrir arquivo de backup de locais");
            }
            
            size_t numLocais;
            arqLocais.read(reinterpret_cast<char*>(&numLocais), sizeof(numLocais));
            locais.resize(numLocais);
            arqLocais.read(reinterpret_cast<char*>(locais.data()), numLocais * sizeof(Local));
            
            // Carregar veículos
            std::ifstream arqVeiculos("veiculos.bin", std::ios::binary);
            if (!arqVeiculos) {
                throw LogisticaException("Falha ao abrir arquivo de backup de veículos");
            }
            
            size_t numVeiculos;
            arqVeiculos.read(reinterpret_cast<char*>(&numVeiculos), sizeof(numVeiculos));
            veiculos.resize(numVeiculos);
            arqVeiculos.read(reinterpret_cast<char*>(veiculos.data()), numVeiculos * sizeof(Veiculo));
            
            // Carregar pedidos
            std::ifstream arqPedidos("pedidos.bin", std::ios::binary);
            if (!arqPedidos) {
                throw LogisticaException("Falha ao abrir arquivo de backup de pedidos");
            }
            
            size_t numPedidos;
            arqPedidos.read(reinterpret_cast<char*>(&numPedidos), sizeof(numPedidos));
            pedidos.resize(numPedidos);
            arqPedidos.read(reinterpret_cast<char*>(pedidos.data()), numPedidos * sizeof(Pedido));
            
            // Carregar próximo ID de pedido
            std::ifstream arqId("id_pedido.bin", std::ios::binary);
            if (arqId) {
                arqId.read(reinterpret_cast<char*>(&proximoIdPedido), sizeof(proximoIdPedido));
            } else {
                // Se não encontrar, calcula o próximo ID baseado nos pedidos existentes
                proximoIdPedido = 1;
                for (const auto& p : pedidos) {
                    if (p.getId() >= proximoIdPedido) {
                        proximoIdPedido = p.getId() + 1;
                    }
                }
            }
            
            std::cout << "Dados restaurados com sucesso!\n";
        }
};

void exibirMenu() {
    std::cout << "\n=== SISTEMA DE LOGÍSTICA ===\n";
    std::cout << "1. Cadastro de Locais\n";
    std::cout << "2. Cadastro de Veículos\n";
    std::cout << "3. Cadastro de Pedidos\n";
    std::cout << "4. Listar Locais\n";
    std::cout << "5. Listar Veículos\n";
    std::cout << "6. Listar Pedidos\n";
    std::cout << "7. Calcular Rota de Entrega\n";
    std::cout << "8. Fazer Backup de Dados\n";
    std::cout << "9. Restaurar Dados\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

void menuLocais(SistemaLogistica& sistema) {
    int opcao;
    do {
        std::cout << "\n=== CADASTRO DE LOCAIS ===\n";
        std::cout << "1. Adicionar Local\n";
        std::cout << "2. Editar Local\n";
        std::cout << "3. Remover Local\n";
        std::cout << "4. Listar Locais\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        try {
            switch (opcao) {
                case 1: {
                    char nome[100];
                    float x, y;
                    std::cout << "Nome do local: ";
                    std::cin.ignore();
                    std::cin.getline(nome, 100);
                    std::cout << "Coordenada X: ";
                    std::cin >> x;
                    std::cout << "Coordenada Y: ";
                    std::cin >> y;
                    sistema.adicionarLocal(Local(nome, x, y));
                    break;
                }
                case 2: {
                    int id;
                    char nome[100];
                    float x, y;
                    sistema.listarLocais();
                    std::cout << "ID do local a editar: ";
                    std::cin >> id;
                    std::cout << "Novo nome: ";
                    std::cin.ignore();
                    std::cin.getline(nome, 100);
                    std::cout << "Nova coordenada X: ";
                    std::cin >> x;
                    std::cout << "Nova coordenada Y: ";
                    std::cin >> y;
                    sistema.editarLocal(id, nome, x, y);
                    break;
                }
                case 3: {
                    int id;
                    sistema.listarLocais();
                    std::cout << "ID do local a remover: ";
                    std::cin >> id;
                    sistema.removerLocal(id);
                    break;
                }
                case 4:
                    sistema.listarLocais();
                    break;
            }
        } catch (const LogisticaException& e) {
            std::cerr << "Erro: " << e.what() << "\n";
        }
    } while (opcao != 0);
}

void menuVeiculos(SistemaLogistica& sistema) {
    int opcao;
    do {
        std::cout << "\n=== CADASTRO DE VEÍCULOS ===\n";
        std::cout << "1. Adicionar Veículo\n";
        std::cout << "2. Editar Veículo\n";
        std::cout << "3. Remover Veículo\n";
        std::cout << "4. Listar Veículos\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        try {
            switch (opcao) {
                case 1: {
                    char placa[20], modelo[50];
                    int local;
                    
                    std::cout << "Placa: ";
                    std::cin.ignore();
                    std::cin.getline(placa, 20);
                    
                    std::cout << "Modelo: ";
                    std::cin.getline(modelo, 50);
                    
                    sistema.listarLocais();
                    std::cout << "ID do local atual: ";
                    std::cin >> local;
                    
                    sistema.adicionarVeiculo(Veiculo(placa, modelo, local));
                    break;
                }
                case 2: {
                    int id, local;
                    char placa[20], modelo[50];
                    
                    sistema.listarVeiculos();
                    std::cout << "ID do veículo a editar: ";
                    std::cin >> id;
                    
                    std::cout << "Nova placa: ";
                    std::cin.ignore();
                    std::cin.getline(placa, 20);
                    
                    std::cout << "Novo modelo: ";
                    std::cin.getline(modelo, 50);
                    
                    sistema.listarLocais();
                    std::cout << "Novo local atual: ";
                    std::cin >> local;
                    
                    sistema.editarVeiculo(id, placa, modelo, local);
                    break;
                }
                case 3: {
                    int id;
                    sistema.listarVeiculos();
                    std::cout << "ID do veículo a remover: ";
                    std::cin >> id;
                    sistema.removerVeiculo(id);
                    break;
                }
                case 4:
                    sistema.listarVeiculos();
                    break;
            }
        } catch (const LogisticaException& e) {
            std::cerr << "Erro: " << e.what() << "\n";
        }
    } while (opcao != 0);
}

void menuPedidos(SistemaLogistica& sistema) {
    int opcao;
    do {
        std::cout << "\n=== CADASTRO DE PEDIDOS ===\n";
        std::cout << "1. Adicionar Pedido\n";
        std::cout << "2. Editar Pedido\n";
        std::cout << "3. Remover Pedido\n";
        std::cout << "4. Listar Pedidos\n";
        std::cout << "0. Voltar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        try {
            switch (opcao) {
                case 1: {
                    int origem, destino;
                    float peso;
                    
                    sistema.listarLocais();
                    std::cout << "ID do local de origem: ";
                    std::cin >> origem;
                    
                    std::cout << "ID do local de destino: ";
                    std::cin >> destino;
                    
                    std::cout << "Peso do item (kg): ";
                    std::cin >> peso;
                    
                    sistema.adicionarPedido(origem, destino, peso);
                    break;
                }
                case 2: {
                    int id, origem, destino;
                    float peso;
                    
                    sistema.listarPedidos();
                    std::cout << "ID do pedido a editar: ";
                    std::cin >> id;
                    
                    sistema.listarLocais();
                    std::cout << "Novo ID de origem: ";
                    std::cin >> origem;
                    
                    std::cout << "Novo ID de destino: ";
                    std::cin >> destino;
                    
                    std::cout << "Novo peso (kg): ";
                    std::cin >> peso;
                    
                    sistema.editarPedido(id, origem, destino, peso);
                    break;
                }
                case 3: {
                    int id;
                    sistema.listarPedidos();
                    std::cout << "ID do pedido a remover: ";
                    std::cin >> id;
                    sistema.removerPedido(id);
                    break;
                }
                case 4:
                    sistema.listarPedidos();
                    break;
            }
        } catch (const LogisticaException& e) {
            std::cerr << "Erro: " << e.what() << "\n";
        }
    } while (opcao != 0);
}

int main() {
    SistemaLogistica sistema;
    int opcao;
    
    do {
        exibirMenu();
        std::cin >> opcao;
        
        try {
            switch (opcao) {
                case 1:
                    menuLocais(sistema);
                    break;
                case 2:
                    menuVeiculos(sistema);
                    break;
                case 3:
                    menuPedidos(sistema);
                    break;
                case 4:
                    sistema.listarLocais();
                    break;
                case 5:
                    sistema.listarVeiculos();
                    break;
                case 6:
                    sistema.listarPedidos();
                    break;
                case 7: {
                    int idPedido;
                    sistema.listarPedidos();
                    std::cout << "ID do pedido para calcular rota: ";
                    std::cin >> idPedido;
                    sistema.calcularRotaEntrega(idPedido);
                    break;
                }
                case 8:
                    sistema.fazerBackup();
                    break;
                case 9:
                    sistema.restaurarDados();
                    break;
                case 0:
                    std::cout << "Saindo do sistema...\n";
                    break;
                default:
                    std::cout << "Opção inválida!\n";
            }
        } catch (const LogisticaException& e) {
            std::cerr << "Erro: " << e.what() << "\n";
        } catch (...) {
            std::cerr << "Erro desconhecido!\n";
        }
        
    } while (opcao != 0);
    
    return 0;
}