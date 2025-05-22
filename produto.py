# Define uma classe Produto para armazenar nome e preço
class Produto:
    def __init__(self, nome: str, preco: float):
        self.nome = nome[:30]  # Limita o nome a 30 caracteres
        self.preco = preco     # Armazena o preço como float


def main():
    produtos = []  # Lista dinâmica que simula o realloc de C
    continuar = 's'  # Inicializa a variável de controle

    while continuar.lower() == 's':
        print(f"Produto {len(produtos) + 1}")  # Mostra o número do próximo produto

        nome = input("Nome: ")[:30]  # Lê o nome com no máximo 30 caracteres
        while True:
            try:
                preco = float(input("Preço: "))  # Tenta ler o preço como float
                break
            except ValueError:
                print("Preço inválido. Digite um número válido.")

        # Cria um objeto Produto e adiciona à lista
        produtos.append(Produto(nome, preco))

        continuar = input("Deseja adicionar outro produto? (s/n): ")

    # Exibe todos os produtos cadastrados
    print("\nLista de Produtos:")
    for produto in produtos:
        print(f"Produto: {produto.nome} - Preço: R$ {produto.preco:.2f}")

# Executa o programa principal
if __name__ == "__main__":
    main()


# Produto 1
# Nome: Caneta Vermelha
# Preço: 3.5
# Deseja adicionar outro produto? (s/n): s
# Produto 2
# Nome: Borracha Branca
# Preço: 1.25
# Deseja adicionar outro produto? (s/n): n

# Lista de Produtos:
# Produto: Caneta Vermelha - Preço: R$ 3.50
# Produto: Borracha Branca - Preço: R$ 1.25