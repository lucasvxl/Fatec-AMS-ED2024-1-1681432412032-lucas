/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                        Estrutura de Dados */
/*                                                                        */
/*                           Lucas Vilas Boas                             */
/*                       Objetivo: Busca Linear                           */
/*                                                                        */
/*                                                       Data: 09/09/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>

int buscalinear(int array[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) { 
        if (array[i] == alvo) { 
            return i;  
        }
    }
    return -1;  
}

int main() { 
    int array[] = {0, 1, 2, 3, 4};  
    int tamanho = sizeof(array) / sizeof(array[0]);
    int alvo = 4; 
    int resultado = buscalinear(array, tamanho, alvo);
    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado); 
    } else {
        printf("Elemento não encontrado\n"); 
    }
    return 0;
}