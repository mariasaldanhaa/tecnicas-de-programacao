#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int gravarArquivo(Aluno a1) {
    Aluno a1;
    FILE *arquivo;

    // -- serializacao --
    // arquivo .txt
    arquivo = fopen("alunos.txt", "w");

    if(arquivo == NULL) {
        return 1;
    }

    // registrando no arquivo
    fprintf(arquivo, "%d %s %.2f", a1.matricula, a1.nome, a1.nota);

    fclose(arquivo);

    return 0;
}

void main() {
    Aluno a1;

    printf("\nInforme a matricula do aluno: ");
    scanf("%d", &a1.matricula);

    printf("\nInforme o nome do aluno: ");
    scanf("%s", &a1.nome);

    printf("\nInforme a nota do aluno: ");
    scanf("%f", &a1.nota);

    gravarArquivo(a1);
}
