/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                                                                        */
/*                         Lucas Vilas Boas                               */
/*     Objetivo: Manipulação de Array de Inteiros com Ponteiros           */
/*                                                                        */
/*                                                        Data:16/03/2024 */
/*------------------------------------------------------------------------*/ 

#include <stdio.h>

#define constante 5

// Programa 1
float encontrarMaiorElemento(float *notas) {
    float maior = *notas;
    for (int i = 1; i < constante; i++) {
        if (*(notas + i) > maior) {
            maior = *(notas + i);
        }
    }
    return maior;
}

// Programa 2
float calcularSoma(float *notas) {
    float soma = 0;
    for (int i = 0; i < constante; i++) {
        soma += *(notas + i);
    }
    return soma;
}

// Programa 3
void imprimirArray(float *notas) {
    printf("Array de notas: ");
    for (int i = 0; i < constante; i++) {
        printf("%.2f ", *(notas + i));
    }
    printf("\n");
}

// Programa 4
void multiplicarPorValor(float *notas, float valor) {
    for (int i = 0; i < constante; i++) {
        *(notas + i) *= valor;
    }
}

// Programa 5
int main() {
    float notas[constante];
    
    printf("Digite as %d notas:\n", constante);
    for (int i = 0; i < constante; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    
    for (int i = 0; i < constante - 1; i++) {
        for (int j = i + 1; j < constante; j++) {
            if (notas[i] > notas[j]) {
                float temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
    
    printf("\n--- Resultados ---\n");
    printf("Maior elemento: %.2f\n", encontrarMaiorElemento(notas));
    printf("Soma dos elementos: %.2f\n", calcularSoma(notas));
    imprimirArray(notas);
    
    float multiplicador;
    printf("Digite o valor pelo qual deseja multiplicar os elementos: ");
    scanf("%f", &multiplicador);
    multiplicarPorValor(notas, multiplicador);
    printf("Array de notas multiplicado por %.2f:\n", multiplicador);
    imprimirArray(notas);
    
    return 0;
}
