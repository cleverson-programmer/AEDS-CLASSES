
// int v[] = {10, 20, 30, 40, 50};
// int *p = v; p aponta para o início do vetor v

// p++; --> avança uma posição para o vetor no qual o ponteiro é apontado, se p aponta para v[0] avança para p[1]

// (*p)++; --> incrementa o conteúdo apontado por p, alterando o valor da variavel apontada. Se *p = 10 agora *p= 11 e a posição continua a mesma

// *(p++); --> usa o valor de *p depois avança o ponteiro EX: se *p vale 10, guarda esse valor em uma variavel e depois move o ponteiro para próxima posição.
//Equivalente a: 
    // temp = *p;
    // p = p + 1;

//*(p + 10) --> acessar o valor que está 10 posições a frente de p
