#include <stdio.h>

int main()
{
    char nome[10];
    char sexo;
    float altura, peso;
    float numero_homens = 0, numero_mulheres = 0;
    float soma_altura_homens = 0, soma_altura_mulheres = 0, soma_altura_grupo = 0;
    float soma_peso_homens = 0, soma_peso_mulheres = 0, soma_peso_grupo = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite seu nome %d: ", i + 1);
        scanf("%s", nome);

        printf("Digite o sexo (M para masculino e F para feminino): ");
        scanf(" %c", &sexo);

        printf("Digite sua altura: ");
        scanf("%f", &altura);

        printf("Digite seu peso: ");
        scanf("%f", &peso);

        if (sexo == 'M' || sexo == 'm')
        {
            numero_homens++;
            soma_altura_homens += altura;
            soma_peso_homens += peso;
        }
        else if (sexo == 'F' || sexo == 'f')
        {
            numero_mulheres++;
            soma_altura_mulheres += altura;
            soma_peso_mulheres += peso;
        }

        soma_altura_grupo += altura;
        soma_peso_grupo += peso;
    }

    float media_altura_homens = (numero_homens > 0) ? soma_altura_homens / numero_homens : 0;
    float media_altura_mulheres = (numero_mulheres > 0) ? soma_altura_mulheres / numero_mulheres : 0;
    float media_altura_grupo = (numero_homens + numero_mulheres > 0) ? soma_altura_grupo / (numero_homens + numero_mulheres) : 0;

    float media_peso_homens = (numero_homens > 0) ? soma_peso_homens / numero_homens : 0;
    float media_peso_mulheres = (numero_mulheres > 0) ? soma_peso_mulheres / numero_mulheres : 0;
    float media_peso_grupo = (numero_homens + numero_mulheres > 0) ? soma_peso_grupo / (numero_homens + numero_mulheres) : 0;

    printf("\nO número de homens é: %.2f", numero_homens);
    printf("\nO número de mulheres é: %.2f", numero_mulheres);
    printf("\nA altura média dos homens é: %.2f", media_altura_homens);
    printf("\nA altura média das mulheres é: %.2f", media_altura_mulheres);
    printf("\nA altura média do grupo é: %.2f", media_altura_grupo);
    printf("\nO peso médio dos homens é: %.2f", media_peso_homens);
    printf("\nO peso médio das mulheres é: %.2f", media_peso_mulheres);
    printf("\nO peso médio do grupo é: %.2f", media_peso_grupo);

    return 0;
}
