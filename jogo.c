#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[3][3])
{
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

char verificarVencedor(char tabuleiro[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
        {
            return tabuleiro[i][0];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
        {
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        return tabuleiro[0][2];
    }

    return ' ';
}

int main()
{
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    int linha, coluna;
    char jogador = 'X';
    char vencedor = ' ';

    while (vencedor == ' ')
    {

        imprimirTabuleiro(tabuleiro);

        printf("Jogador %c, digite a linha e a coluna: ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ')
        {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha - 1][coluna - 1] = jogador;

        vencedor = verificarVencedor(tabuleiro);

        jogador = (jogador == 'X') ? 'O' : 'X';

        printf("\n");
    }

    imprimirTabuleiro(tabuleiro);

    if (vencedor == 'X' || vencedor == 'O')
    {
        printf("Jogador %c venceu!\n", vencedor);
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
