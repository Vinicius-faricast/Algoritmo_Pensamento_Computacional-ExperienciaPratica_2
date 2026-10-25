#include <stdio.h>
#include <stdlib.h>

int lerValorPositivoInteiro(const char *mensagem, int *valor)
{
    // Lê valor positivo com validação e limpeza de buffer
    while (1)
    {
        printf("Informe o consumo de almocos no %s:", mensagem);

        if (scanf("%d", valor) != 1)
        {
            printf("Entrada invalida! Digite um numero.\n");

            // Limpa os caracteres restantes da entrada
            int caractere;
            while ((caractere = getchar()) != '\n' &&
                   caractere != EOF)
            {
            }

            continue;
        }

        if (*valor <= 0)
        {
            printf("O valor deve ser maior que zero.\n");
            continue;
        }

        return 1;
    }
}

int main(void)
{
    // Vetor que armazena o consumo de almoços para cada dia da semana
    int consumoDeAlmocoDiario[7];
    // Vetor de strings com os nomes dos 7 dias
    char *diasDaSemana[7] = {
        "Domingo", "Segunda-feira", "Terca-feira",
        "Quarta-feira", "Quinta-feira", "Sexta-feira",
        "Sabado"};
    int totalAlmocos = 0;
    float mediaNumeroAlmocos;

    // Percorre o vetor de 7 posições (um para cada dia)
    for (int i = 0; i < 7; i++)
    {
        lerValorPositivoInteiro(diasDaSemana[i], &consumoDeAlmocoDiario[i]);
        // Soma o valor lido ao total acumulado no vetor
        totalAlmocos += consumoDeAlmocoDiario[i];
    }

    // Calcula a média dividindo o total pelo número de elementos do vetor
    mediaNumeroAlmocos = (float)totalAlmocos / 7;

    printf("Total de almocos consumidos: %d\n", totalAlmocos);
    printf("Media de almocos consumidos: %.2f\n", mediaNumeroAlmocos);
    return 0;
}