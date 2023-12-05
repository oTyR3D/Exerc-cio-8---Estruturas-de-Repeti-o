#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int inputNum;
    int currentTerm = 1, previousTerm = 0, tempTerm;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &inputNum);

    printf("\n0 ");
    inputNum--;

    while (inputNum)
    {
        printf("%d ", currentTerm);
        tempTerm = currentTerm;
        currentTerm += previousTerm;
        previousTerm = tempTerm;
        inputNum--;
    }

    printf("\n\n");

    return 0;
}