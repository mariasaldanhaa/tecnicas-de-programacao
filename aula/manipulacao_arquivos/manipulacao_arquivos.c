#include <stdio.h>

typedef struct {
    char nome[36];
    int idade;
    float nota;
} Aluno;

void main () {
    Aluno a1;

    // escrever no arquivo txt
    printf("Informe o nome do aluno: ");
    scanf("%s", a1.nome);

    printf("Informe a idade do aluno: ");
    scanf("%d", &a1.idade);

    printf("Informe a nota do aluno: ");
    scanf("%f", &a1.nota);

    FILE *arq = fopen("aluno.txt", "w");

    fprintf(arq, "%s %d %.2f", a1.nome, a1.idade, a1.nota);

    fclose(arq);

    // leitura no arquivo txt (deserializar)
    arq = fopen("aluno.txt", "r");

    fscanf(arq, "%s %d %f", a1.nome, &a1.idade, &a1.nota);

    printf("\nTexto");
    printf("Nome do aluno: %s\n", a1.nome);
    printf("Idade do aluno: %d\n", a1.idade);
    printf("Nota do aluno: %.2f\n", a1.nota);

    fclose(arq);

    // escrever em um arquivo bin
    arq = fopen("aluno.bin", "wb");

    fwrite(&a1, sizeof(Aluno), 1, arq);

    fclose(arq);

    // leitura de um arquivo bin
    arq = fopen("aluno.bin", "rb");

    fread(&a1, sizeof(Aluno), 1, arq);

    printf("\nBinario");
    printf("Nome do aluno: %s\n", a1.nome);
    printf("Idade do aluno: %d\n", a1.idade);
    printf("Nota do aluno: %.2f\n", a1.nota);

    fclose(arq);

    // armazena mais de um aluno em bin
    int resp;

    printf("\nALUNOS EM .BIN:");

    arq = fopen("aluno.bin", "wb");

    while (1){

        printf("\nDigite o nome do aluno: ");
        scanf("%s", &a1.nome);
        printf("\nDigite a idade do aluno: ");
        scanf("%d", &a1.idade);
        printf("\nDigite a nota do aluno: ");
        scanf("%f", &a1.nota);

        fwrite(&a1, sizeof(Aluno), 1, arq);

        printf("\nDeseja continuar (1 - Sim/ 0 - Nao)? ");
        scanf("%d", &resp);

        if (resp == 0) break;
    }

    fclose(arq);
}
