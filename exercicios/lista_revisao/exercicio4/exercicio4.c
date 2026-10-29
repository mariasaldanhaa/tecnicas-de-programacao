#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula, codigoDisciplina;
    float nota1, nota2;
} Aluno;

// b) imprimir as informacoes dos alunos
int imprimindoAlunos() {
    FILE *arq = fopen("Alunos.txt", "r");
    Aluno a;

    printf("\n--- ALUNOS CADASTRADOS ---");
    while(fscanf(arq, "%d %d %f %f \n", &a.matricula, &a.codigoDisciplina, &a.nota1, &a.nota2) == 4) {
        printf("\nMatricula: %d", a.matricula);
        printf("\nCodigo disciplina: %d", a.codigoDisciplina);
        printf("\nNota 1: %.2f", a.nota1);
        printf("\nNota 2: %.2f", a.nota2);
        printf("\n");
        printf("-----------------------------");
    }

    fclose(arq);

    return 0;
}

// c) matricula e codigo dos alunos que conseguiram medias acima de 6.0
int imprimindoAprovados() {
    FILE *arq = fopen("Alunos.txt", "r");
    float media;
    Aluno a;

    printf("\n--- APROVADOS ---");
    while(fscanf(arq, "%d %d %f %f \n", &a.matricula, &a.codigoDisciplina, &a.nota1, &a.nota2) == 4) {
        media = (a.nota1 + a.nota2) / 2;

        if(media > 6) {
            printf("\nMatricula: %d", a.matricula);
            printf("\nCodigo da Disciplina: %d", a.codigoDisciplina);
            printf("\n-----------------");
        }
    }

    fclose(arq);

    return 0;
}

// d) aluno que obteve a maior media
int maiorMedia() {
    FILE *arq = fopen("Alunos.txt", "r");
    float maior = 0, media;
    int matriculaMaior, codigoMaior;
    Aluno a;

    while(fscanf(arq, "%d %d %f %f \n", &a.matricula, &a.codigoDisciplina, &a.nota1, &a.nota2) == 4) {
        media = (a.nota1 + a.nota2) / 2;

        if(media > maior) {
            maior = media;
            matriculaMaior = a.matricula;
            codigoMaior = a.codigoDisciplina;
        }
    }

    printf("\n--- ALUNO COM A MAIOR MEDIA ---");
    printf("\nMatricula: %d", matriculaMaior);
    printf("\nCodigo da disciplina: %d", codigoMaior);

    fclose(arq);

    return 0;
}

// e) imprimir o codigo da disciplina em que pelo menos uma
// das notas do aluno foi menor do que 6.0

int notaMenor() {
    FILE *arq = fopen("Alunos.txt", "r");
    Aluno a;

    printf("\n--- DISCIPLINAS COM NOTAS MENORES QUE 6 ---");
    while(fscanf(arq, "%d %d %f %f \n", &a.matricula, &a.codigoDisciplina, &a.nota1, &a.nota2) == 4) {
        if(a.nota1 < 6 || a.nota2 < 6) {
            printf("\nCodigo da disciplina: %d", a.codigoDisciplina);
            printf("\n");
        }
    }

    fclose(arq);

    return 0;
}

int main() {
    int n;
    Aluno a;
    FILE *arq = fopen("Alunos.txt", "w");

    // qtd de alunos
    printf("Informe a quantidade de alunos a serem informados: ");
    scanf("%d", &n);

    // informacoes dos alunos
    for(int i = 0; i < n; i++) {
        printf("-- ALUNO %d --", i + 1);

        printf("\nDigite o numero de matricula: ");
        scanf("%d", &a.matricula);

        printf("\nDigite o codigo da disciplina: ");
        scanf("%d", &a.codigoDisciplina);

        printf("\nDigite a nota da primeira prova: ");
        scanf("%f", &a.nota1);

        printf("\nDigite a nota da segunda prova: ");
        scanf("%f", &a.nota2);

        printf("\n");

        // a) salvando no arquivo "Alunos.txt"
        fprintf(arq, "%d %d %.2f %.2f \n", a.matricula, a.codigoDisciplina, a.nota1, a.nota2);
    }

    fclose(arq);

    // funcoes
    imprimindoAlunos(n);
    printf("\n");
    imprimindoAprovados();
    printf("\n");
    maiorMedia();
    printf("\n");
    notaMenor();

    return 0;
}
