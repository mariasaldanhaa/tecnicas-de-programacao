#include <stdio.h>
#include <stdlib.h>

// a) salvar a matriz em um arquivo
int salvarMatriz(int m, int n, int **matriz) {
    FILE *arq = fopen("matrizM.txt", "w");

    if (arq == NULL) {
        return 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(arq, "%d | ", matriz[i][j]);
        }
        fprintf(arq,"\n");
    }

    fclose(arq);

    return 0;
}

// b) abrir o arquivo e imprimir a matriz
int imprimirMatriz(int m, int n, int **matriz) {
    FILE *arq = fopen("matrizM.txt", "r");

    if (arq == NULL) {
        return 1;
    }

    printf("\n-- MATRIZ M --\n");
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            fscanf(arq, "%d | ", &matriz[i][j]);
            printf("%d | ", matriz[i][j]);
        }
        printf("\n");
    }

    fclose(arq);

    return 0;
}

// c) qtd de numers pares existem na matriz e imprimir o resultado
int qtdPares(int m, int n, int **matriz) {
    int qtd = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] % 2 == 0) {
                qtd++;
            }
        }
    }

    printf("\nQtd de numeros pares: %d", qtd);

    return 0;
}

// d) media dos elementos e imprimir o resultado
int mediaElementos(int m, int n, int **matriz) {
    float soma = 0;
    int qtd = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            soma = soma + matriz[i][j];
            qtd++;
        }
    }

    float media = soma / qtd;

    printf("\nMedia dos elementos: %.2f", media);

    return 0;
}

// e) maior elementos e o menor elemento da matriz e imprimir o resultado
int maiorMenorElementos(int m, int n, int **matriz) {
    int maior = matriz[0][0], menor = matriz[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }

            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }

    printf("\nMaior elemento: %d",  maior);
    printf("\nMenor elemento: %d",  menor);

    return 0;
}

// f) calcular a soma dos valores das colunas da matriz
int somaValoresColunas(int m, int n, int **matriz) {
    int somaColunas = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            somaColunas = somaColunas + matriz[i][j];
        }
        printf("\nSoma das colunas %d: %d", j, somaColunas);
    }

    return 0;
}

int main() {
    int m, n, **matrizM;

    // pedindo pro usuario informacoes
    printf("Informe a quantidade de linhas da matriz M: ");
    scanf("%d", &m);

    printf("\nInforme a quantidade de colunas da matriz M: ");
    scanf("%d", &n);

    // -- alocacao dinamica --
    // alocando as linhas
    matrizM = (int**)malloc(m*sizeof(int));

    // alocando as colunas
    for (int j = 0; j < n; j++) {
        matrizM[j] = (int*)malloc(n*sizeof(int));
    }

    // armazenando conteudo na matriz
    for (int i = 0; i < m; i++) {
        for (int j= 0; j < n; j++) {
            printf("\nDigite um numero a ser armazenado na matriz M[%d, %d]: ", i+1, j+1);
            scanf("%d", &matrizM[i][j]);
        }
    }

    // funcoes
    salvarMatriz(m, n, matrizM);
    imprimirMatriz(m, n, matrizM);
    qtdPares(m, n, matrizM);
    mediaElementos(m, n, matrizM);
    maiorMenorElementos(m, n, matrizM);
    maiorMenorElementos(m, n, matrizM);
    somaValoresColunas(m, n, matrizM);

    // liberando a memoria
    free(matrizM);

    return 0;
}
