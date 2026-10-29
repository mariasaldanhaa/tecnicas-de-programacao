#include <stdio.h>

// ALUNA: MARIA EDUARDA SALDANHA ALVES

char parada;
int qtd = 0;
float notas[100], soma = 0;

int main() {
    printf("-- CADASTRO DE NOTAS --\n");

    // cadastrando notas
    while (1) {
        printf("Informe a nota do aluno %d: ", qtd + 1);
        scanf("%f", &notas[qtd]);

        soma = soma + notas[qtd];
        qtd++;

        printf("-----------------------------------\n");

        printf("Deseja continuar? (Digite 'p' para parar) ");
        scanf("%s" ,&parada);

        printf("-----------------------------------\n");

        if (parada == 'p' || parada == 'P') {
            break;
        }
    }

    // calculando a media e imprimindo notas acima da media
    printf("\n----- INFORMACOES -----");

    float media = soma / qtd;
    printf("\nMedia: %.2f", media);

    for (int i = 0; i < qtd; i++) {
        if(notas[i] >= media) {
            printf("\n-- ALUNO %d --", i + 1);
            printf("\nNota: %.2f", notas[i]);
        }
    }

    return 0;
}
