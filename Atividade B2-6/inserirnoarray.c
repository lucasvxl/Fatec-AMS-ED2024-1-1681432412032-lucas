#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inserirNoArray(int *array, int tamanho, int valor) {
    int meio = tamanho / 2;
    for (int i = tamanho; i > meio; i--) {
        array[i] = array[i - 1];
    }
    array[meio] = valor;
}

int main() {
    int array[6] = {10, 25, 40, 80}; // Último elemento deixado vazio para inserção
    int tamanho = 4;
    int valor = 30;

    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    inserirNoArray(array, tamanho, valor);
    fim = clock();

    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Array após inserção: ");
    for (int i = 0; i <= tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTempo de processamento: %f segundos\n", tempo);

    return 0;
}
