#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void inserirNaLista(struct Node** head, int valor) {
    struct Node* novo_no = (struct Node*) malloc(sizeof(struct Node));
    novo_no->data = valor;
    novo_no->next = NULL;

    if (*head == NULL) {
        *head = novo_no;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = (*head)->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    novo_no->next = slow->next;
    slow->next = novo_no;
}

void imprimirLista(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* segundo = NULL;
    struct Node* terceiro = NULL;
    struct Node* quarto = NULL;

    head = (struct Node*) malloc(sizeof(struct Node));
    segundo = (struct Node*) malloc(sizeof(struct Node));
    terceiro = (struct Node*) malloc(sizeof(struct Node));
    quarto = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->next = segundo;

    segundo->data = 25;
    segundo->next = terceiro;

    terceiro->data = 40;
    terceiro->next = quarto;

    quarto->data = 80;
    quarto->next = NULL;

    int valor = 30;

    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    inserirNaLista(&head, valor);
    fim = clock();

    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Lista após inserção: ");
    imprimirLista(head);
    printf("Tempo de processamento: %f segundos\n", tempo);

    return 0;
}
