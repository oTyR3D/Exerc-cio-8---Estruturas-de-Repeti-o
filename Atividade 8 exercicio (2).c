#include <stdio.h>

int main()
{
    int moradores = 5;
    int cont_ElevadorA = 0;
    int cont_ElevadorB = 0;
    int cont_ElevadorC = 0;
    int cont_PeriodoMatutino = 0;
    int cont_PeriodoVespertino = 0;
    int cont_PeriodoNoturno = 0;
    char maisFrequentadoElevador;
    char maisFrequentadoPeriodo;
    int maiorFluxoElevador;
    int maiorFluxoPeriodo;

    for (int i = 1; i <= moradores; i++)
    {
        char elevador, periodo;

        printf("Informe o elevador mais utilizado pelo morador %d (A/B/C): ", i);
        scanf(" %c", &elevador);

        printf("Informe o período de utilização (M/V/N) pelo morador %d: ", i);
        scanf(" %c", &periodo);

        switch (elevador)
        {
        case 'A':
            cont_ElevadorA++;
            break;
        case 'B':
            cont_ElevadorB++;
            break;
        case 'C':
            cont_ElevadorC++;
            break;
        default:
            printf("Elevador inválido. Tente novamente.\n");
            i--;
            continue;
        }

        switch (periodo)
        {
        case 'M':
            cont_PeriodoMatutino++;
            break;
        case 'V':
            cont_PeriodoVespertino++;
            break;
        case 'N':
            cont_PeriodoNoturno++;
            break;
        default:
            printf("Período inválido. Tente novamente.\n");
            i--;
            continue;
        }
    }

    if (cont_ElevadorA >= cont_ElevadorB && cont_ElevadorA >= cont_ElevadorC)
    {
        maisFrequentadoElevador = 'A';
        maiorFluxoElevador = cont_ElevadorA;
    }
    else if (cont_ElevadorB >= cont_ElevadorA && cont_ElevadorB >= cont_ElevadorC)
    {
        maisFrequentadoElevador = 'B';
        maiorFluxoElevador = cont_ElevadorB;
    }
    else
    {
        maisFrequentadoElevador = 'C';
        maiorFluxoElevador = cont_ElevadorC;
    }

    if (cont_PeriodoMatutino >= cont_PeriodoVespertino && cont_PeriodoMatutino >= cont_PeriodoNoturno)
    {
        maisFrequentadoPeriodo = 'M';
        maiorFluxoPeriodo = cont_PeriodoMatutino;
    }
    else if (cont_PeriodoVespertino >= cont_PeriodoMatutino && cont_PeriodoVespertino >= cont_PeriodoNoturno)
    {
        maisFrequentadoPeriodo = 'V';
        maiorFluxoPeriodo = cont_PeriodoVespertino;
    }
    else
    {
        maisFrequentadoPeriodo = 'N';
        maiorFluxoPeriodo = cont_PeriodoNoturno;
    }

    int menorFluxo = (cont_ElevadorA <= cont_ElevadorB && cont_ElevadorA <= cont_ElevadorC) ? cont_ElevadorA : (cont_ElevadorB <= cont_ElevadorA && cont_ElevadorB <= cont_ElevadorC) ? cont_ElevadorB
                                                                                                                                                                                        : cont_ElevadorC;

    float diferencaPercentual = 100.0 * (maiorFluxoElevador - menorFluxo) / moradores;

    int totalFluxoMedio = (cont_ElevadorA + cont_ElevadorB + cont_ElevadorC) - maiorFluxoElevador;
    float percentagemFluxoMedio = 100.0 * totalFluxoMedio / moradores;

    printf("O elevador mais frequentado é o elevador %c no período %c.\n", maisFrequentadoElevador, maisFrequentadoPeriodo);
    printf("O elevador mais utilizado é o elevador %c no período %c.\n", (cont_ElevadorA >= cont_ElevadorB && cont_ElevadorA >= cont_ElevadorC) ? 'A' : (cont_ElevadorB >= cont_ElevadorA && cont_ElevadorB >= cont_ElevadorC) ? 'B'
                                                                                                                                                                               : 'C',
           (cont_PeriodoMatutino >= cont_PeriodoVespertino && cont_PeriodoMatutino >= cont_PeriodoNoturno) ? 'M' : (cont_PeriodoVespertino >= cont_PeriodoMatutino && cont_PeriodoVespertino >= cont_PeriodoNoturno) ? 'V'
                                                                                                                                                                                     : 'N');
    printf("Diferença percentual entre o mais usado e o menos usado: %.2f%%\n", diferencaPercentual);
    printf("Percentagem sobre o total de serviços prestados do elevador de média utilização: %.2f%%\n", percentagemFluxoMedio);

    return 0;
}
