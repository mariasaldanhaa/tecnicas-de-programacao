// Alunos: Paulo Henrique Ferreira e Maria Eduarda Saldanha Alves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id, inicio, fim;
} Atividades;

// função usada pelo qsort parar comparar as atividades
int compararFim(const void *a, const void *b) {
    Atividades *atividadeA = (Atividades *)a;
    Atividades *atividadeB = (Atividades *)b;

    return atividadeA -> fim - atividadeB -> fim;
}

int main() {
    FILE *arquivo;

    Atividades atividades[100];
    int n = 0, ultimoFim = -1, quantidade = 0;

    // leitura do arquivo
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return 1;
    }

    // leitura dos dados e armazena cada uma no vetor atividades
    while(fscanf(arquivo, "%d %d %d", &atividades[n].id, &atividades[n].inicio, &atividades[n].fim) == 3) {
        n++;
    }

    // ordena o vetor pelo horário de término
    // atividades - o vetor que será ordenado
    // n - quantidade de atividades
    // sizeof(Atividades) - tamanho de cada elemento
    // compararFim - função que define o critério de ordenação
    qsort(atividades, n, sizeof(Atividades), compararFim);

    printf("Atividades ordenadas: \n");

    for (int i = 0; i < n; i++) {
        printf("ID: %d | Inicio: %d | Fim: %d\n", atividades[i].id, atividades[i].inicio, atividades[i].fim);
    }

    printf("\n");

    // algoritmo guloso
    printf("Atividades selecionadas: \n");

    for (int i = 0; i < n; i++) {
        if (atividades[i].inicio >= ultimoFim) {
            printf("ID: %d | Inicio: %d | Fim: %d\n", atividades[i].id, atividades[i].inicio, atividades[i].fim);
            ultimoFim = atividades[i].fim;
            quantidade++;
        }
    }

    printf("\n");

    printf("Quantidade de atividades disponiveis: %d\n", quantidade);

    fclose(arquivo);

    return 0;
}
