#include <stdio.h>
#include <string.h>
#include "editor_texto.h"

#define MAX_PALAVRAS 100
#define TAM_FRASE 1000 

void adicionar_palavra(char *frase, const char *palavra, int posicao) {
    char temp[TAM_FRASE];
    char *palavras[MAX_PALAVRAS];
    int count = 0;

    // Separar a frase em palavras
    char *token = strtok(frase, " ");
    while (token != NULL) {
        palavras[count++] = token;
        token = strtok(NULL, " ");
    }

    if (posicao < 1 || posicao > count + 1 || count >= MAX_PALAVRAS) {
        printf("Posicao invalida ou numero maximo de palavras excedido.\n");
        return;
    }

    // Adicionar a nova palavra na posicao desejada
    temp[0] = '\0';
    for (int i = 0; i < count + 1; i++) {
        if (i == posicao - 1) {
            strcat(temp, palavra);
            strcat(temp, " ");
        }
        if (i < count) {
            strcat(temp, palavras[i]);
            strcat(temp, " ");
        }
    }

    // Remover o espaço extra no final e copiar de volta para frase
    temp[strlen(temp) - 1] = '\0';
    strcpy(frase, temp);
}

void excluir_palavra(char *frase, int posicao) {
    char temp[TAM_FRASE];
    char *palavras[MAX_PALAVRAS];
    int count = 0;

    // Separar a frase em palavras
    char *token = strtok(frase, " ");
    while (token != NULL) {
        palavras[count++] = token;
        token = strtok(NULL, " ");
    }

    if (posicao < 1 || posicao > count) {
        printf("Posicao invalida.\n");
        return;
    }

    // Remover a palavra na posicao desejada
    temp[0] = '\0';
    for (int i = 0; i < count; i++) {
        if (i != posicao - 1) {
            strcat(temp, palavras[i]);
            strcat(temp, " ");
        }
    }

    // Remover o espaço extra no final e copiar de volta para frase
    if (strlen(temp) > 0) {
        temp[strlen(temp) - 1] = '\0';
    }
    strcpy(frase, temp);
}