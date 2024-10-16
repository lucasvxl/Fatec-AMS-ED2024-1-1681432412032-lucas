#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    bool trocou;

    for (i = 0; i < n-1; i++) {
        trocou = false; // Inicializa a flag como falsa para cada iteração

        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos adjacentes se estiverem na ordem errada
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocou = true; // Indica que houve uma troca
            }
        }

        // Se nenhuma troca foi feita, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}

// Função para exibir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para obter o input do array
void lerArray(int arr[], int n) {
    printf("Digite %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;

    // Solicita o número de elementos ao usuário
    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    int arr[n];

    // Lê o array do usuário
    lerArray(arr, n);

    // Exibe o array original
    printf("Array original: \n");
    printArray(arr, n);

    // Ordena o array com Bubble Sort otimizado
    bubbleSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
