#include "SistemaLogistica.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstring>

// Construtor
SistemaLogistica::SistemaLogistica() : proximoIdPedido(1) {}

// Métodos para Locais
void SistemaLogistica::adicionarLocal(const Local& local) {
    for (const auto& l : locais) {
        if (strcmp(l.getNome(), local.getNome()) == 0) {
            throw LogisticaException("Local com este nome já existe");
        }
    }
    locais.push_back(local);
}

void SistemaLogistica::editarLocal(int id, const char* novoNome, float x, float y) {
    if (id < 0 || static_cast<size_t>(id) >= locais.size()) {
        throw LogisticaException("ID de local inválido");
    }
    locais[id].setNome(novoNome);
    locais[id].setCoordenadas(x, y);
}

void SistemaLogistica::removerLocal(int id) {
    if (id < 0 || static_cast<size_t>(id) >= locais.size()) {
        throw LogisticaException("ID de local inválido");
    }
    locais.erase(locais.begin() + id);
}

void SistemaLogistica::listarLocais() const {
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
void SistemaLogistica::adicionarVeiculo(const Veiculo& veiculo) {
    for (const auto& v : veiculos) {
        if (strcmp(v.getPlaca(), veiculo.getPlaca()) == 0) {
            throw LogisticaException("Veículo com esta placa já existe");
        }
    }
    veiculos.push_back(veiculo);
}

void SistemaLogistica::editarVeiculo(int id, const char* novaPlaca, const char* novoModelo, int novoLocal) {
    if (id < 0 || static_cast<size_t>(id) >= veiculos.size()) {
        throw LogisticaException("ID de veículo inválido");
    }
    for (size_t i = 0; i < veiculos.size(); ++i) {
        if (i != static_cast<size_t>(id) && strcmp(veiculos[i].getPlaca(), novaPlaca) == 0) {
            throw LogisticaException("Placa já existe em outro veículo");
        }
    }
    veiculos[id] = Veiculo(novaPlaca, novoModelo, novoLocal);
    veiculos[id].setDisponivel(veiculos[id].isDisponivel());
}

void SistemaLogistica::removerVeiculo(int id) {
    if (id < 0 || static_cast<size_t>(id) >= veiculos.size()) {
        throw LogisticaException("ID de veículo inválido");
    }
    if (!veiculos[id].isDisponivel()) {
        throw LogisticaException("Não é possível remover veículo em uso");
    }
    veiculos.erase(veiculos.begin() + id);
}

void SistemaLogistica::listarVeiculos() const {
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
void SistemaLogistica::adicionarPedido(int origem, int destino, float peso) {
    if (origem < 0 || static_cast<size_t>(origem) >= locais.size() || destino < 0 || static_cast<size_t>(destino) >= locais.size()) {
        throw LogisticaException("Local de origem ou destino inválido");
    }
    pedidos.emplace_back(proximoIdPedido++, origem, destino, peso);
}

void SistemaLogistica::editarPedido(int id, int novaOrigem, int novoDestino, float novoPeso) {
    if (id < 1 || id >= proximoIdPedido) {
        throw LogisticaException("ID de pedido inválido");
    }
    for (auto& p : pedidos) {
        if (p.getId() == id) {
            if (p.isEntregue()) {
                throw LogisticaException("Não é possível editar pedido já entregue");
            }
            if (novaOrigem < 0 || static_cast<size_t>(novaOrigem) >= locais.size() || 
                novoDestino < 0 || static_cast<size_t>(novoDestino) >= locais.size()) {
                throw LogisticaException("Local de origem ou destino inválido");
            }
            p = Pedido(id, novaOrigem, novoDestino, novoPeso);
            return;
        }
    }
    throw LogisticaException("Pedido não encontrado");
}

void SistemaLogistica::removerPedido(int id) {
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

void SistemaLogistica::listarPedidos() const {
    if (pedidos.empty()) {
        std::cout << "Nenhum pedido cadastrado.\n";
        return;
    }
    for (const auto& p : pedidos) {
        p.exibir();
        std::cout << "\n";
    }
}

// Cálculo de rota
void SistemaLogistica::calcularRotaEntrega(int idPedido) {
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

    float distOrigemDestino = calcularDistancia(pedido->getOrigem(), pedido->getDestino());
    float distTotal = menorDistancia + distOrigemDestino;
    veiculos[idVeiculo].setDisponivel(false);

    std::cout << "\n=== ROTA CALCULADA ===\n";
    std::cout << "Pedido ID: " << pedido->getId() << "\n";
    std::cout << "Veículo designado: " << veiculos[idVeiculo].getPlaca() << "\n";
    std::cout << "Distância total: " << distTotal << " unidades\n";

    int opcao;
    do {
        std::cout << "\n1. Listar veículos";
        std::cout << "\n2. Confirmar entrega";
        std::cout << "\n0. Cancelar";
        std::cout << "\nEscolha: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                listarVeiculos();
                break;
            case 2:
                pedido->setEntregue(true);
                veiculos[idVeiculo].setLocalAtual(pedido->getDestino());
                veiculos[idVeiculo].setDisponivel(true);
                std::cout << "Entrega concluída.\n";
                return;
            case 0:
                veiculos[idVeiculo].setDisponivel(true);
                std::cout << "Operação cancelada.\n";
                return;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

// Backup e restauração
void SistemaLogistica::fazerBackup() const {
    std::ofstream arq("locais.bin", std::ios::binary);
    size_t n = locais.size();
    arq.write(reinterpret_cast<const char*>(&n), sizeof(n));
    arq.write(reinterpret_cast<const char*>(locais.data()), n * sizeof(Local));

    std::ofstream av("veiculos.bin", std::ios::binary);
    n = veiculos.size();
    av.write(reinterpret_cast<const char*>(&n), sizeof(n));
    av.write(reinterpret_cast<const char*>(veiculos.data()), n * sizeof(Veiculo));

    std::ofstream ap("pedidos.bin", std::ios::binary);
    n = pedidos.size();
    ap.write(reinterpret_cast<const char*>(&n), sizeof(n));
    ap.write(reinterpret_cast<const char*>(pedidos.data()), n * sizeof(Pedido));

    std::ofstream ai("id_pedido.bin", std::ios::binary);
    ai.write(reinterpret_cast<const char*>(&proximoIdPedido), sizeof(proximoIdPedido));

    std::cout << "Backup realizado com sucesso.\n";
}

void SistemaLogistica::restaurarDados() {
    std::ifstream arq("locais.bin", std::ios::binary);
    size_t n;
    arq.read(reinterpret_cast<char*>(&n), sizeof(n));
    locais.resize(n);
    arq.read(reinterpret_cast<char*>(locais.data()), n * sizeof(Local));

    std::ifstream av("veiculos.bin", std::ios::binary);
    av.read(reinterpret_cast<char*>(&n), sizeof(n));
    veiculos.resize(n);
    av.read(reinterpret_cast<char*>(veiculos.data()), n * sizeof(Veiculo));

    std::ifstream ap("pedidos.bin", std::ios::binary);
    ap.read(reinterpret_cast<char*>(&n), sizeof(n));
    pedidos.resize(n);
    ap.read(reinterpret_cast<char*>(pedidos.data()), n * sizeof(Pedido));

    std::ifstream ai("id_pedido.bin", std::ios::binary);
    if (ai)
        ai.read(reinterpret_cast<char*>(&proximoIdPedido), sizeof(proximoIdPedido));
    else {
        proximoIdPedido = 1;
        for (const auto& p : pedidos) {
            if (p.getId() >= proximoIdPedido)
                proximoIdPedido = p.getId() + 1;
        }
    }

    std::cout << "Dados restaurados com sucesso.\n";
}

// Função auxiliar
float SistemaLogistica::calcularDistancia(int idLocal1, int idLocal2) const {
    if (idLocal1 < 0 || static_cast<size_t>(idLocal1) >= locais.size() || //Pode dar erro aqui!!!
        idLocal2 < 0 || static_cast<size_t>(idLocal2) >= locais.size()) {
        throw LogisticaException("Local inválido para cálculo de distância");
    }

    float dx = locais[idLocal1].getX() - locais[idLocal2].getX();
    float dy = locais[idLocal1].getY() - locais[idLocal2].getY();
    return std::sqrt(dx * dx + dy * dy);
}
