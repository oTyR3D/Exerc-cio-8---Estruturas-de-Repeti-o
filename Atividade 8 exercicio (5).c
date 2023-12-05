#include <stdio.h>

struct Entrevistado
{
    char nome[50];
    int idade;
    char genero;
    int voto;
};

char jogadoras()
{
    printf("Qual das jogadoras listadas na tabela abaixo e considerada a melhor?\n");
    printf("Opção 1: Sam Kerr - Australia\n");
    printf("Opção 2: Alex Morgan - Estados Unidos\n");
    printf("Opção 3: Dzsenifer Marozsan - Alemanha\n");
    printf("Opção 4: Amandine Henzy - França\n");
    printf("Opção 5: Marta Vieira - Brasil\n");

    char opcao;
    printf("Opção: ");
    scanf(" %c", &opcao);

    return opcao;
}

int main()
{
    int entrevistados;

    while (1)
    {
        printf("Digite o numero de entrevistados (entre 50 e 300): ");
        scanf("%d", &entrevistados);
        if (entrevistados >= 50 && entrevistados <= 300)
        {
            break;
        }
        else
        {
            printf("O numero de entrevistados deve estar entre 50 e 300.\n");
        }
    }

    struct Entrevistado listaEntrevistados[entrevistados];

    for (int i = 0; i < entrevistados; i++)
    {
        printf("\nEntrevistado %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", listaEntrevistados[i].nome);

        printf("Digite a idade (maior que 12 anos): ");
        scanf("%d", &listaEntrevistados[i].idade);

        if (listaEntrevistados[i].idade > 12)
        {
            printf("Idade: %d (maior que 12 anos)\n", listaEntrevistados[i].idade);
        }
        else
        {
            printf("Sua idade nao atende aos criterios (menor ou igual a 12 anos).\n");
            i--; // Decrementa o índice para repetir a entrada
            continue;
        }

        printf("Digite o genero (M para masculino e F para feminino): ");
        scanf(" %c", &listaEntrevistados[i].genero);

        if (listaEntrevistados[i].genero == 'M' || listaEntrevistados[i].genero == 'm')
        {
            printf("Genero: Masculino\n");
        }
        else if (listaEntrevistados[i].genero == 'F' || listaEntrevistados[i].genero == 'f')
        {
            printf("Genero: Feminino\n");
        }
        else
        {
            printf("Genero nao reconhecido.\n");
            i--; // Decrementa o índice para repetir a entrada
            continue;
        }

        listaEntrevistados[i].voto = jogadoras();

        printf("Voto registrado com sucesso!\n");
    }

    int contarVotos[5] = {0};
    for (int i = 0; i < entrevistados; i++)
    {
        contarVotos[listaEntrevistados[i].voto - '0' - 1]++;
    }

    printf("\nQuantidade de votos para cada jogadora:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Jogadora %d: %d votos\n", i + 1, contarVotos[i]);
    }

    int maxVotos = 0;
    printf("\nJogadoras mais votadas:\n");
    for (int i = 0; i < 5; i++)
    {
        if (contarVotos[i] > maxVotos)
        {
            maxVotos = contarVotos[i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (contarVotos[i] == maxVotos)
        {
            printf("Jogadora %d: %d votos\n", i + 1, maxVotos);
        }
    }

    printf("\nMulheres:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].genero == 'F' || listaEntrevistados[i].genero == 'f')
        {
            printf("Nome: %s, Idade: %d, Genero: %c\n", listaEntrevistados[i].nome, listaEntrevistados[i].idade, listaEntrevistados[i].genero);
        }
    }

    printf("\nHomens:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].genero == 'M' || listaEntrevistados[i].genero == 'm')
        {
            printf("Nome: %s, Idade: %d, Genero: %c\n", listaEntrevistados[i].nome, listaEntrevistados[i].idade, listaEntrevistados[i].genero);
        }
    }

    printf("\nMaiores de idade:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].idade > 12)
        {
            printf("Nome: %s, Idade: %d, Genero: %c\n", listaEntrevistados[i].nome, listaEntrevistados[i].idade, listaEntrevistados[i].genero);
        }
    }

    printf("\nMenores de idade:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].idade <= 12)
        {
            printf("Nome: %s, Idade: %d, Genero: %c\n", listaEntrevistados[i].nome, listaEntrevistados[i].idade, listaEntrevistados[i].genero);
        }
    }

    printf("\nPessoas maiores de idade que votaram na Marta Vieira:\n");
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].idade > 12 && listaEntrevistados[i].voto == 5)
        {
            printf("Nome: %s\n", listaEntrevistados[i].nome);
        }
    }

    int contarMulheres = 0;
    for (int i = 0; i < entrevistados; i++)
    {
        if (listaEntrevistados[i].genero == 'F' || listaEntrevistados[i].genero == 'f')
        {
            contarMulheres++;
        }
    }
    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", contarMulheres);

    return 0;
}
