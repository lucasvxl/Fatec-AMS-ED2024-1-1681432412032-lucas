/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                        Estrutura de Dados */
/*                                                                        */
/*                           Lucas Vilas Boas                             */
/*                       Objetivo: Busca Binária                          */
/*                                                                        */
/*                                                       Data: 09/09/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>

int buscabinaria(int array[], int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1; 
    while (esquerda <= direita) {   
        int meio = esquerda + (direita - esquerda) / 2; 
        if (array[meio] == alvo) { 
            return meio;  
        }
        if (array[meio] < alvo) { 
            esquerda = meio + 1; 
        } else {
            direita = meio - 1; 
        }
    }
    return -1;  
}

int main() {
    int array[] = {10, 30, 50, 70, 90};  
    int tamanho = sizeof(array) / sizeof(array[0]);
    int alvo = 90; 
    int resultado = buscabinaria(array, tamanho, alvo);
    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado);  
    } else {
        printf("Elemento não encontrado\n");
    }
    return 0;
}