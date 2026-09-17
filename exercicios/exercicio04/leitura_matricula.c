#include <stdio.h>
#include <stdlib.h>

// Aluna: Maria Eduarda Saldanha Alves

void main() {
    FILE *arquivo;
    const char *caminho = "C:\\Users\\Admin\\Desktop\\resultado.txt";

    int matricula, alunos;
    float nota;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &alunos);

    for (int i = 1; i <= alunos; i++ ) {
        printf("\nInforme o numero de matricula do aluno %d: ", i);
        scanf("%d", &matricula);
        printf("\nInforme a nota de TP do aluno %d: ", i);
        scanf("%f", &nota);
        printf("\n------------------------------------");
    }

    arquivo = fopen(caminho, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.");
    }

    for (int i = 1; i <= alunos; i++) {
        fprintf(arquivo, "\nALUNO %d - Matricula: %d | Nota: %.2f\n", i, matricula, nota);

        if (nota >= 60 && nota <= 100) {
        fprintf(arquivo, "\nSITUACAO DO ALUNO %d: APROVADO!", i);
        } else if (nota >= 40) {
            fprintf(arquivo, "\nSITUACAO DO ALUNO %d: RECUPERACAO!", i);
        } else if (nota >= 0){
            fprintf(arquivo, "\nSITUACAO DO ALUNO %d: REPROVADO!", i);
        }

        fprintf(arquivo, "\n------------------------------------------------------------\n");
    }

    fclose(arquivo);
}
