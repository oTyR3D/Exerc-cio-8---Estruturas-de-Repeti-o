#include <stdio.h>

int main()
{
    int mes, dias, ano;
    char resposta;

    do
    {
        printf("Digite o mes (1 a 12): ");
        scanf("%d", &mes);

        // Se o número digitado não estiver no intervalo de 1 a 12, solicitar novamente
        if (mes < 1 || mes > 12)
        {
            printf("Mes invalido. Tente novamente.\n");
            continue;
        }

        printf("Digite o ano: ");
        scanf("%d", &ano);

        // Considerar a existência de anos bissextos: (ano % 4 == 0 e ano % 100 != 0) ou ano % 400 == 0.
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        {
            // Ano bissexto
            switch (mes)
            {
            case 2:
                dias = 29;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dias = 30;
                break;
            default:
                dias = 31;
                break;
            }
        }
        else
        {
            // Ano não bissexto
            switch (mes)
            {
            case 2:
                dias = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dias = 30;
                break;
            default:
                dias = 31;
                break;
            }
        }

        printf("O mes %d/%d tem %d dias.\n", mes, ano, dias);

        printf("Deseja outras entradas (S/s para sim, qualquer outro caractere para nao)? ");
        scanf(" %c", &resposta);

    } while (resposta == 'S' || resposta == 's');

    return 0;
}
