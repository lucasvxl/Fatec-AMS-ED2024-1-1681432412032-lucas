#include <stdio.h>


float adicionar(float a, float b) {
    return a + b;
}


float subtrair(float a, float b) {
    return a - b;
}


float multiplicar(float a, float b) {
    return a * b;
}


float dividir(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: divisão por zero!\n");
        return 0.0; 
    }
}

int main() {
    float num1, num2, resultado;
    char operador;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    printf("Escolha a operação (+, -, *, /): ");
    scanf(" %c", &operador);

    switch (operador) {
        case '+':
            resultado = adicionar(num1, num2);
            break;
        case '-':
            resultado = subtrair(num1, num2);
            break;
        case '*':
            resultado = multiplicar(num1, num2);
            break;
        case '/':
            resultado = dividir(num1, num2);
            break;
        default:
            printf("Operador inválido!\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}