// FUNÇOES DA BIBLIOTECA STDLIB.H

// malloc --> Aloca um bloco contínuo de memória com o tamanho especificado em bytes, a memória não e inicializada e pode conter lixo.

// int *vetor = (int *) malloc(10 * sizeof(int));
// EXPLICAÇÃO:
    // int *vetor --> declara um ponteiro do tipo inteiro chamado vetor
    //(int *) --> Faz um type cast (conversão de tipo) do ponteiro void * retornado por malloc para int *.
    // malloc(10 * sizeof(int)) --> solicita ao sistema um bloco de memória capaz de armazenar 10 inteiros
    // sizeof(int) --> retorna o tamanho de um inteiro em bytes (4)
    // 10 * sizeof(int) --> calcula o total de bytes a serem alocados 10 * 4 = 40 bytes



// calloc --> Aloca espaço para vários elementos de mesmo tamanho.
// int *vetor = (int *) calloc(10, sizeof(int));
// EXPLICAÇÃO:
    // calloc(n_elementos, tamanho_de_cada_elemento) --> aloca e zera os bytes não deixando lixo

//realloc --> Redimensiona um bloco de memória previamente alocado. Pode realocar em um novo local se necessário (copia os dados automaticamente).
// vetor = (int *) realloc(vetor, 20 * sizeof(int));
// EXPLICAÇÃO:
    // realloc: redimensiona a área de memória apontada por vetor para 20 inteiros.
    // 20 * sizeof(int): 80 bytes (se int = 4 bytes).
    // O conteúdo original é mantido (até o limite do menor tamanho entre original e novo).
    // Se necessário, a função aloca nova área, copia os dados antigos e libera a anterior.
    // O ponteiro retornado deve ser reatribuído a vetor.

// free --> libera a memória alocada

// EXEMPLO PRÁTICO REALLOC

// Imagine que você deseja armazenar notas, 
// mas não sabe quantas serão. Então você vai perguntando uma
// a uma ao usuário e armazenando num vetor, redimensionando conforme necessário.

