#include <stdio.h>
#include <stdlib.h>

// Aluna: Maria Eduarda Saldanha Alves

void main() {
    FILE *arquivo;
    const char *caminho = "C:\\Users\\Admin\\Desktop\\resultado.txt";

    int matricula, alunos, pesquisaMatricula;
    float nota, novaNota;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &alunos);

    arquivo = fopen(caminho, "wb+");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.");
    }

    for (int i = 1; i <= alunos; i++) {
        printf("\nInforme o numero de matricula do aluno %d: ", i);
        scanf("%d", &matricula);
        printf("\nInforme a nota de TP do aluno %d: ", i);
        scanf("%f", &nota);
        printf("\n------------------------------------");

        fprintf(arquivo, "\nALUNO %d - Matricula: %d | Nota: %.2f\n", i, matricula, nota);

        if (nota >= 60 && nota <= 100) {
        fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s", "APROVADO!");
        } else if (nota >= 40) {
            fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s", "RECUPERACAO!");
        } else if (nota >= 0){
            fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s", "REPROVADO!");
        }

        fprintf(arquivo, "\n------------------------------------------------------------\n");
    }

    printf("\nInforme a matricula do aluno para uma nova nota: ");
    scanf("%d", &pesquisaMatricula);

    printf("\nInforme a nova nota da matricula %d: ", pesquisaMatricula);
    scanf("%f", &novaNota);

    rewind(arquivo);

    while(fscanf(arquivo, " ALUNO %*d - Matricula: %d", &matricula) == 1) {
        if (matricula == pesquisaMatricula) {
            fseek(arquivo, 9, SEEK_CUR);
            fprintf(arquivo, "%.2f", novaNota);

            if (novaNota >= 60 && novaNota <= 100) {
                fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s", "APROVADO!");
            } else if (novaNota >= 40) {
                fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s", "RECUPERACAO!");
            } else if (novaNota >= 0){
                fprintf(arquivo, "\nSITUACAO DO ALUNO: %-12s","REPROVADO!");
            }
            break;
        }
    }
    fclose(arquivo);
}
