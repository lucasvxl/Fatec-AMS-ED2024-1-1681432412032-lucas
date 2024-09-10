/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                        Estrutura de Dados */
/*                                                                        */
/*                           Lucas Vilas Boas                             */
/*                    Objetivo: Busca Linear em Ordem                     */
/*                                                                        */
/*                                                       Data: 09/09/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>

int buscaLinearOrdem(int array[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {  
        if (array[i] == alvo) { 
            return i;  
        }
        if (array[i] > alvo) {
            break;  
        }
    }
    return -1;  
}

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int alvo = 50; 
    int resultado = buscaLinearOrdem(array, tamanho, alvo);
    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado); 
    } else {
        printf("Elemento não encontrado\n"); 
    }
    return 0;
}