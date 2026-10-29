#include <stdio.h>
#include <stdlib.h>

// b) qtd de elementos e os elementos pares do vetor A
int paresVetorA(int n, int *vetorA) {
    int qtdPares = 0;

    printf("\n --- ELEMENTOS PARES ---");
    for (int i = 0; i < n; i++) {
        if (vetorA[i] % 2 == 0) {
            printf("\n%d ", vetorA[i]);
            qtdPares++;
        }
    }

    printf("\n");
    printf("\nQuantidade de elementos pares: %d", qtdPares);

    return 0;
}

// c) somatorio dos valores do vetor A
int somaElementosA(int n, int *vetorA) {
    int soma = 0;

    printf("\n --- SOMATORIO DO VETOR A ---");
    for (int i = 0; i < n; i++) {
        soma = soma + vetorA[i];
    }

    printf("\nValor da soma: %d",  soma);

    return 0;
}

// d) maior elemento de B e o numero de vezes em q ele aparece
int maiorElementoB(int n, int *vetorB) {
    int maior = vetorB[0], qtd = 0;

    printf("\n --- MAIOR ELEMENTO ---");
    for (int i = 0; i < n; i++) {
        if (vetorB[i] > maior) {
            maior = vetorB[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (maior == vetorB[i]) {
            qtd++;
        }
    }

    printf("\nMaior elemento: %d", maior);
    printf("\nQuantidade de vezes em que o %d aparece: %d", maior, qtd);

    return 0;
}

// e) substituindo os elementos negativos por 0 do vetor B
int substituicaoB(int n, int *vetorB) {
    printf("\n --- SUBSTITUICAO DO VETOR B ---");
    printf("\nVetor Original: ");
    for (int i = 0; i < n; i++) {
        printf("\nB[%d] = %d", i + 1, vetorB[i]);
    }

    printf("\nVetor Modificado: ");
    for (int i = 0; i < n; i++) {
        if(vetorB[i] < 0) {
            vetorB[i] = 0;
        }
        printf("\nB[%d] = %d", i + 1, vetorB[i]);
    }

    return 0;
}

// f) troca de elementos dos vetores
int trocaVetores(int n, int *vetorA, int *vetorB) {
    int aux;

    printf("\n --- TROCA DE VETORES ---");
    for (int i = 0; i < n; i++) {
        aux = vetorA[i];
        vetorA[i] = vetorB[i];
        vetorB[i] = aux;
    }

    printf("\nVetor A apos a troca: ");
    for (int i = 0; i < n; i++) {
        printf("\nA[%d] = %d", i + 1, vetorA[i]);
    }

    printf("\nVetor B apos a troca: ");
    for (int i = 0; i < n; i++) {
        printf("\nB[%d] = %d", i + 1, vetorB[i]);
    }

    return 0;
}

int main() {
    int *vetorA, *vetorB, n;

    // a) tamanho dos vetores
    printf("Informe o tamanho dos vetores A e B: ");
    scanf("%d", &n);

    // a) alocacao dinamica
    vetorA = (int*)malloc(n*sizeof(int));
    vetorB = (int*)malloc(n*sizeof(int));

    // VETOR A
    printf("\n --- VETOR A ---");
    for(int i = 0; i < n; i++) {
        printf("\nDigite um valor para o vetor A[%d]: ", i + 1);
        scanf("%d", &vetorA[i]);
    }

    printf("\n");

    // VETOR B
    printf("\n --- VETOR B ---");
    for(int i = 0; i < n; i++) {
        printf("\nDigite um valor para o vetor B[%d]: ", i + 1);
        scanf("%d", &vetorB[i]);
    }

    // funcoes
    paresVetorA(n, vetorA);
    printf("\n");
    somaElementosA(n, vetorA);
    printf("\n");
    maiorElementoB(n, vetorB);
    printf("\n");
    substituicaoB(n, vetorB);
    printf("\n");
    trocaVetores(n, vetorA, vetorB);

    // desalocando os vetores
    free(vetorA);
    free(vetorB);

    return 0;
}
