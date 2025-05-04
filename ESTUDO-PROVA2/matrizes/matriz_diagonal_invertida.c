//REGRA DA DIAGONAL INVERTIDA: Se a matriz é de ordem n (EX: 2X3), então a diagonal invertida está nos elementos matriz[i][n - 1 - i]

/*
int n = 3;
for (int i = 0; i < n; i++) {
    printf("%d ", matriz[i][n - 1 - i]);
}
*/

/*
1   2   3
4   5   6
7   8   9
*/

/*
3 (posição [0][2])
5 (posição [1][1])
7 (posição [2][0])
*/

