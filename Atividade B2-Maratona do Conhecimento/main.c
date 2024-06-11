#include <stdio.h>
#include <stdlib.h>
#include "editor_texto.h"

void exibir_menu() {
    printf("Menu:\n");
    printf("1. Escolher frase\n");
    printf("2. Adicionar palavra\n");
    printf("3. Excluir palavra\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int escolha;
    char frase[100] = "";
    char palavra[20];
    int posicao;

    while (1) {
        exibir_menu();
        scanf("%d", &escolha);
        getchar(); // Limpar o buffer

        switch (escolha) {
            case 1:
                printf("Digite uma frase: ");
                fgets(frase, sizeof(frase), stdin);
                frase[strcspn(frase, "\n")] = '\0'; // Remover o '\n' do final
                break;
            case 2:
                printf("Digite a palavra para adicionar: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0'; // Remover o '\n' do final
                printf("Digite a posicao para adicionar: ");
                scanf("%d", &posicao);
                getchar(); // Limpar o buffer
                adicionar_palavra(frase, palavra, posicao);
                break;
            case 3:
                printf("Digite a posicao da palavra para excluir: ");
                scanf("%d", &posicao);
                getchar(); // Limpar o buffer
                excluir_palavra(frase, posicao);
                break;
            case 4:
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

        printf("Frase atual: %s\n", frase);
    }

    return 0;
}