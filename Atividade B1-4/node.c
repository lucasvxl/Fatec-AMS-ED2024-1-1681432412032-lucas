#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int id;
  char aluno[50];
  struct node *next;
};

typedef struct node Node;

Node *alunoNovo(int id, char aluno[50]) {
  Node *novo_aluno = (Node*)malloc(sizeof(Node)); // 
  novo_aluno->id = id;
  strcpy(novo_aluno->aluno, aluno);
  novo_aluno->next = NULL;
  return novo_aluno;
}

void adicionarAluno(Node **head, int id, char aluno[50]) {
  Node *novo = alunoNovo(id, aluno);
  Node *atual = *head;
  Node *anterior = NULL;

  while (atual != NULL && atual->id < id) {
    anterior = atual;
    atual = atual->next;
  }

  if (anterior == NULL) {
    novo->next = *head;
    *head = novo;
  } else {
    anterior->next = novo;
    novo->next = atual;
  }
}

void removerAluno(Node** head, int id) {
  Node *atual = *head;
  Node *anterior = NULL;

    while (atual != NULL && atual->id != id) {
      anterior = atual;
      atual = atual->next;
    }

    if (atual != NULL) {
      if (anterior == NULL) {
        *head = atual->next;
      }  else {
        anterior->next = atual->next;
      }
        free(atual);
    } else {
      printf("Aluno com ID %d não encontrado.\n", id);
    }
}

Node* buscarAluno(Node *head, int id) {
  Node* atual = head;
  while (atual != NULL && atual->id != id) {
    atual = atual->next;
  }
  return atual;
}

void imprimirLista(Node *head) {
  Node* atual = head;

  printf("Lista de Alunos:\n");
  while (atual != NULL) {
    printf("ID: %d, Aluno: %s\n", atual->id, atual->aluno);
    atual = atual->next;
  }
}


int main() {
    Node* lista_alunos = NULL;
    int id;
    char nome[50];
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar aluno\n");
        printf("2. Remover aluno\n");
        printf("3. Buscar aluno\n");
        printf("4. Imprimir lista de alunos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &id);
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                adicionarAluno(&lista_alunos, id, nome);
                break;
            case 2:
                printf("Digite a matrícula do aluno a ser removido: ");
                scanf("%d", &id);
                removerAluno(&lista_alunos, id);
                break;
            case 3:
                printf("Digite a matrícula do aluno a ser buscado: ");
                scanf("%d", &id);
                Node* aluno_encontrado = buscarAluno(lista_alunos, id);
                if (aluno_encontrado != NULL) {
                    printf("Aluno encontrado: Matrícula: %d, Nome: %s\n", aluno_encontrado->id, aluno_encontrado->aluno);
                } else {
                    printf("Aluno com matrícula %d não encontrado.\n", id);
                }
                break;
            case 4:
                imprimirLista(lista_alunos);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 5);

    return 0;
}