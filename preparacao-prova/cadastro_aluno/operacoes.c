#include <stdbool.h>
#include <stdio.h>
#include "contato.h"

int gravarContato() {
    Contato c;
    FILE *arq;
    c.qtd = 0;

    arq = fopen("contatos.txt", "a");

    if (arq == NULL) return 1;

    while (1) {
        printf("\n -- CONTATO %d --", c.qtd);

        printf("\nInforme o nome do contato %d:", c.qtd);
        scanf("%s", c.nome);

        printf("\nInforme a idade do contato %d:", c.qtd);
        scanf("%d", &c.idade);

        fprintf(arq, "%s %d\n", c.nome, c.idade);
        c.qtd++;

        int resp;
        printf("\nDeseja continuar?(1/0) ");
        scanf("%d", &resp);

        if (resp == 0) break;
    }

    fclose(arq);

    return 0;
}

int listarContato() {
    Contato c;
    c.qtd = 0;
    FILE *arq;

    arq = fopen("contatos.txt", "r");

    if (arq == NULL) return 1;

    printf("\nExibindo contatos...");

    while (fscanf(arq, "%s %d", c.nome, &c.idade) == 2) {
        printf("\n-- CONTATO %d --", c.qtd);
        printf("\nNome do contato: %s", c.nome);
        printf("\nIdade do contato: %d", c.idade);
    }

    fclose(arq);

    return 0;
}

int gravarBinario() {
    Contato c;
    FILE *arq;
    c.qtd = 0;

    arq = fopen("contatos.bin", "ab");

    if (arq == NULL) {
        printf("\nERRO!");
        return 1;
    }

    while (1) {
        printf("\n -- CONTATO %d --", c.qtd);

        printf("\nInforme o nome do contato %d:", c.qtd);
        scanf("%s", c.nome);

        printf("\nInforme a idade do contato %d:", c.qtd);
        scanf("%d", &c.idade);

        fwrite(&c, sizeof(Contato), 1, arq);
        c.qtd++;

        int resp;
        printf("\nDeseja continuar?(1/0) ");
        scanf("%d", &resp);

        if (resp == 0) break;
    }

    fclose(arq);

    return 0;
}

int listarBinario() {
    Contato c;
    c.qtd = 0;
    FILE *arq;

    arq = fopen("contatos.bin", "rb");

    if (arq == NULL) return 1;

    printf("\nExibindo contatos...");

    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        printf("\n-- CONTATO %d --", c.qtd);
        printf("\nNome do contato: %s", c.nome);
        printf("\nIdade do contato: %d", c.idade);
    }

    fclose(arq);

    return 0;
}

int main() {
    Contato c;
    c.qtd = 0;
    int opcao = 0;

    while (opcao != 5) {
        printf("\n-- OPCOES --");
        printf("\n1 - Cadastrar Contato");
        printf("\n2 - Listar Contatos");
        printf("\n3 - Cadastrar Contatos .bin");
        printf("\n4 - Listar Contatos .bin");
        printf("\n5 - Sair");

        printf("\nQual opcao deseja escolher? ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                gravarContato();
                break;
            case 2:
                listarContato();
                break;
            case 3:
                gravarBinario();
                break;
            case 4:
                listarBinario();
                break;
        }
    }
    return 0;
}