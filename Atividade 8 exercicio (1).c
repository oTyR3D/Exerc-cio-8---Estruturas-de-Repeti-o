#include <stdio.h>

int main()
{
    int idade = 0;
    char opiniao;
    int capacidade = 100;
    int cont_otimo = 0;
    int cont_bom = 0;
    int cont_regular = 0;
    int cont_ruim = 0;
    int cont_pessimo = 0;
    int idade_maior_pessimo = 0;
    int idade_maior_otimo = 0;
    int media_idade_ruim = 0;
    int idade_maior_ruim = 0;
    int percentagem_pessimo = 0;
    int quantidade = 0;
    int percentual = 0;

    do
    {
        printf("Digite sua idade (ou digite 0 para encerrar): ");
        scanf("%d", &idade);

        if (idade > 0)
        {
            printf("Qual a sua opinião sobre o filme? (A - Ótimo, B - Bom, C - Regular, D - Ruim, E - Péssimo): ");
            scanf(" %c", &opiniao);

            switch (opiniao)
            {
            case 'A':
                printf("Você escolheu: Ótimo\n");
                cont_otimo++;
                if (idade > idade_maior_otimo)
                    idade_maior_otimo = idade;
                break;
            case 'B':
                printf("Você escolheu: Bom\n");
                cont_bom++;
                break;
            case 'C':
                printf("Você escolheu: Regular\n");
                cont_regular++;
                break;
            case 'D':
                printf("Você escolheu: Ruim\n");
                cont_ruim++;
                media_idade_ruim += idade;
                if (idade > idade_maior_ruim)
                    idade_maior_ruim = idade;
                break;
            case 'E':
                printf("Você escolheu: Péssimo\n");
                cont_pessimo++;
                if (idade > idade_maior_pessimo)
                    idade_maior_pessimo = idade;
                break;
            default:
                printf("Opção inválida.\n");
            }
            quantidade++;
        }

    } while (idade > 0);

    percentual = (cont_bom - cont_regular);

    if (cont_ruim != 0)
    {
        media_idade_ruim = media_idade_ruim / cont_ruim;
        printf("A média de idade das pessoas que responderam ruim: %d\n", media_idade_ruim);
    }
    else
    {
        printf("Ninguém optou pela resposta 'RUIM'.\n");
    }

    percentagem_pessimo = (cont_pessimo * 100) / quantidade;

    printf("A maior idade que respondeu péssimo foi: %d\n", idade_maior_pessimo);
    printf("A percentagem dos entrevistados que responderam Péssimo foi: %d%%\n", percentagem_pessimo);
    printf("Optaram por Ótimo: %d\n", cont_otimo);
    printf("Optaram por Bom: %d\n", cont_bom);
    printf("Optaram por Regular: %d\n", cont_regular);
    printf("Optaram por Ruim: %d\n", cont_ruim);
    printf("Optaram por Péssimo: %d\n", cont_pessimo);

    return 0;
}