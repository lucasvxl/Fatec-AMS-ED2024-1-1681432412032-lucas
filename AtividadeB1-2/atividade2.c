#include <stdio.h>

void aplicaDesconto(float *preco, float desconto) {
    *preco = *preco - (*preco * (desconto / 100.0));
}

int main() {
    float preco, desconto;

    printf("Insira o preco: ");
    scanf("%f", &preco);

    printf("Insira o desconto (em %%): ");
    scanf("%f", &desconto);

    aplicaDesconto(&preco, desconto);

    printf("Preco original: R$%.2f\n", preco / (1 - (desconto / 100.0)));
    printf("Desconto: %.2f%%\n", desconto);
    printf("Preco final: R$%.2f\n", preco);

    return 0;
}