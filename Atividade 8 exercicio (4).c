#include <stdio.h>

int main()
{
    int numeroPositivo;
    int contDivisores = 0;

    printf("Digite um numero positivo:\n");
    scanf("%d", &numeroPositivo);

    printf("Os divisores do numero %d sao: ", numeroPositivo);
    for (int i = 1; i <= numeroPositivo; i++)
    {
        if (numeroPositivo % i == 0)
        {
            contDivisores++;
            printf("%d", i);

            // Se não for o último divisor, imprime a vírgula
            if (i < numeroPositivo)
            {
                printf(", ");
            }
        }
    }

    printf("\nO numero de divisores e %d\n", contDivisores);

    return 0;
}