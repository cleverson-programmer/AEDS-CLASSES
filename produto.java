import java.util.ArrayList;  // Importa a classe ArrayList para armazenar produtos dinamicamente
import java.util.Scanner;    // Importa a classe Scanner para entrada de dados do usuário
import java.util.Locale;     // Importa a classe Locale para configurar o formato numérico (ponto decimal)

// Classe que representa um produto com nome e preço
class Produto {
    String nome;      // Nome do produto (até 30 caracteres, mas em Java o limite é lógico, não fixo)
    float preco;      // Preço do produto

    // Construtor da classe Produto
    Produto(String nome, float preco) {
        this.nome = nome;
        this.preco = preco;
    }
}

public class CadastroProdutos {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US); // Define o ponto como separador decimal
        Scanner scanner = new Scanner(System.in); // Cria scanner para entrada de dados

        ArrayList<Produto> produtos = new ArrayList<>(); // Lista dinâmica para armazenar produtos
        char continuar;

        do {
            // Solicita dados do produto ao usuário
            System.out.println("Produto " + (produtos.size() + 1)); // Exibe o número do produto atual

            System.out.print("Nome: ");
            String nome = scanner.nextLine(); // Lê o nome do produto

            System.out.print("Preço: ");
            float preco = scanner.nextFloat(); // Lê o preço do produto
            scanner.nextLine(); // Limpa o buffer após ler float

            // Cria novo objeto Produto e adiciona à lista
            produtos.add(new Produto(nome, preco));

            // Pergunta ao usuário se deseja adicionar outro produto
            System.out.print("Deseja adicionar outro produto? (s/n): ");
            continuar = scanner.nextLine().charAt(0); // Lê o primeiro caractere da resposta

        } while (continuar == 's' || continuar == 'S'); // Continua se usuário digitar 's' ou 'S'

        // Exibe os produtos cadastrados
        System.out.println("\nLista de Produtos:");
        for (Produto p : produtos) {
            System.out.printf("Produto: %s - Preço: R$ %.2f%n", p.nome, p.preco);
        }

        scanner.close(); // Fecha o Scanner (boa prática)
    }
}


// Produto 1
// Nome: Caneta Azul
// Preço: 2.50
// Deseja adicionar outro produto? (s/n): s
// Produto 2
// Nome: Lápis Preto
// Preço: 1.20
// Deseja adicionar outro produto? (s/n): n

// Lista de Produtos:
// Produto: Caneta Azul - Preço: R$ 2.50
// Produto: Lápis Preto - Preço: R$ 1.20