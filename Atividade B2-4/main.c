/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                                                        */
/*                         Lucas Vilas Boas                               */
/*     Objetivo: Implemementar fila de atendimento - Hospital             */
/*                                                                        */
/*                                                        Data:13/05/2024 */
/*------------------------------------------------------------------------*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char motivo[100];
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Fila;

void inicializarFila(Fila* fila) {
    fila->front = NULL;
    fila->rear = NULL;
    fila->count = 0;
}

int filaVazia(Fila* fila) {
    return (fila->count == 0);
}

void adicionarPaciente(Fila* fila, Paciente paciente) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->paciente = paciente;
    newNode->next = NULL;

    if (filaVazia(fila)) {
        fila->front = newNode;
        fila->rear = newNode;
    } else {
        fila->rear->next = newNode;
        fila->rear = newNode;
    }

    fila->count++;
}

Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: A fila está vazia!\n");
        exit(1);
    }

    Node* temp = fila->front;
    Paciente paciente = temp->paciente;
    fila->front = fila->front->next;

    free(temp);
    fila->count--;

    return paciente;
}

void exibirPaciente(Paciente paciente) {
    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Motivo da consulta: %s\n", paciente.motivo);
    printf("\n");
}

void exibirFila(Fila* fila, char* tipo) {
    Node* current = fila->front;
    printf("Fila de pacientes %s:\n", tipo);
    while (current != NULL) {
        exibirPaciente(current->paciente);
        current = current->next;
    }
}

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    Fila filaUrgente;

    inicializarFila(&filaNormal);
    inicializarFila(&filaPrioritaria);
    inicializarFila(&filaUrgente);

    int opcao;
    do {
        printf("Selecione uma opcao:\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender pacientes\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Paciente novoPaciente;
                printf("Nome: ");
                scanf("%s", novoPaciente.nome);
                printf("Idade: ");
                scanf("%d", &novoPaciente.idade);
                printf("Motivo da consulta: ");
                scanf("%s", novoPaciente.motivo);

                int tipoFila;
                printf("Selecione o tipo de fila:\n");
                printf("1. Normal\n");
                printf("2. Prioritaria\n");
                printf("3. Urgente\n");
                printf("Opcao: ");
                scanf("%d", &tipoFila);

                switch (tipoFila) {
                    case 1:
                        adicionarPaciente(&filaNormal, novoPaciente);
                        break;
                    case 2:
                        adicionarPaciente(&filaPrioritaria, novoPaciente);
                        break;
                    case 3:
                        adicionarPaciente(&filaUrgente, novoPaciente);
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }

                break;
            }
            case 2: {
                printf("Atendendo pacientes:\n");

                while (!filaVazia(&filaUrgente)) {
                    Paciente paciente = removerPaciente(&filaUrgente);
                    printf("\nAtendendo paciente da fila urgente:\n");
                    exibirPaciente(paciente);
                }

                while (!filaVazia(&filaPrioritaria)) {
                    Paciente paciente = removerPaciente(&filaPrioritaria);
                    printf("\nAtendendo paciente da fila prioritaria:\n");
                    exibirPaciente(paciente);
                }
l
                int pacientesAtendidos = 0;
                while (!filaVazia(&filaNormal) && pacientesAtendidos < 5) {
                    Paciente paciente = removerPaciente(&filaNormal);
                    printf("\nAtendendo paciente da fila normal:\n");
                    exibirPaciente(paciente);
                    pacientesAtendidos++;
                }

                break;
            }
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
