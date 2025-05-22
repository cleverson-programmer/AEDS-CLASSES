using System;                        // Importa funcionalidades básicas de entrada/saída
using System.Collections.Generic;   // Permite o uso da classe List<T> (vetor dinâmico)
using System.Globalization;         // Necessário para lidar com formatos de número (ponto como separador decimal)


// Define a struct Produto com dois campos: Nome (string) e Preco (float)
struct Produto
{
    public string Nome;   // Nome do produto
    public float Preco;   // Preço do produto
}

class Program
{
    static void Main()
    {
        // Cria uma lista dinâmica de produtos (funciona como realloc em C)
        List<Produto> produtos = new List<Produto>();

        char continuar; // Variável de controle para o loop

        do
        {
            Produto p = new Produto(); // Cria um novo produto

            // Mostra o número do produto com base no tamanho atual da lista
            Console.WriteLine($"Produto {produtos.Count + 1}");

            // Lê o nome do produto do usuário
            Console.Write("Nome: ");
            p.Nome = Console.ReadLine();

            // Limita o nome a 30 caracteres, conforme exigido
            if (p.Nome.Length > 30)
            {
                p.Nome = p.Nome.Substring(0, 30); // Corta o nome para no máximo 30 caracteres
            }

            // Lê o preço do produto e valida a entrada com TryParse
            Console.Write("Preço: ");
            while (!float.TryParse(Console.ReadLine(), NumberStyles.Float, CultureInfo.InvariantCulture, out p.Preco))
            {
                // Caso o valor digitado não seja um float válido, pede novamente
                Console.Write("Entrada inválida. Digite um preço válido: ");
            }

            // Adiciona o produto à lista
            produtos.Add(p);

            // Pergunta se o usuário deseja continuar
            Console.Write("Deseja adicionar outro produto? (s/n): ");
            continuar = Console.ReadKey().KeyChar; // Lê apenas o caractere pressionado
            Console.WriteLine(); // Quebra de linha após a leitura

        } while (char.ToLower(continuar) == 's'); // Continua o loop enquanto o usuário digitar 's'

        // Exibe todos os produtos cadastrados
        Console.WriteLine("\nLista de Produtos:");
        foreach (var produto in produtos)
        {
            // Imprime nome e preço com 2 casas decimais
            Console.WriteLine($"Produto: {produto.Nome} - Preço: R$ {produto.Preco:F2}");
        }
    }
}

// Produto 1
// Nome: Chocolate
// Preço: 5.50
// Deseja adicionar outro produto? (s/n): s
// Produto 2
// Nome: Refrigerante
// Preço: 7.25
// Deseja adicionar outro produto? (s/n): n

// Lista de Produtos:
// Produto: Chocolate - Preço: R$ 5.50
// Produto: Refrigerante - Preço: R$ 7.25