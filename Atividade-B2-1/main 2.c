#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO_PILHA 100

typedef struct {
    double itens[TAMANHO_PILHA];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == TAMANHO_PILHA - 1;
}

void empilhar(Pilha *p, double valor) {
    if (esta_cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
    p->itens[++(p->topo)] = valor;
}

double desempilhar(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return p->itens[(p->topo)--];
}

double calcular(double op1, double op2, char operador) {
    switch(operador) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if (op2 != 0)
                return op1 / op2;
            else {
                printf("Erro: Divisão por zero!\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Erro: Operador inválido!\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    printf("Digite a expressão RPN (terminando com '='):\n");

    double operando;
    char entrada;
    while (scanf(" %c", &entrada) == 1 && entrada != '=') {
        if (isdigit(entrada) || (entrada == '-' && isdigit(getchar()))) {
            ungetc(entrada, stdin);
            scanf("%lf", &operando);
            empilhar(&pilha, operando);
        } else if (entrada == '+' || entrada == '-' || entrada == '*' || entrada == '/') {
            double op2 = desempilhar(&pilha);
            double op1 = desempilhar(&pilha);
            empilhar(&pilha, calcular(op1, op2, entrada));
        } else {
            printf("Entrada inválida!\n");
            exit(EXIT_FAILURE);
        }
    }

    if (!esta_vazia(&pilha)) {
        double resultado = desempilhar(&pilha);
        printf("Resultado: %.2f\n", resultado);
    } else {
        printf("Não há resultado\n");
    }

    return 0;
}