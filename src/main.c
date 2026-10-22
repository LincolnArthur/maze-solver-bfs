#include "maze.h"

// Variável global para manter o labirinto carregado na memória
int lab_original[LINHAS][COLUNAS] = {
    {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0},
    {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0},
    {1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
    {1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0},
    {0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0}
};

int main() {
    int opcao;

    #ifdef _WIN32
        SetConsoleOutputCP(65001); // acentos em UTF-8 no console
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                // Ativa o ENABLE_VIRTUAL_TERMINAL_PROCESSING (0x0004)
                // Pra funcionar em qualquer powershell, ou cmd
                dwMode |= 0x0004; 
                SetConsoleMode(hOut, dwMode);
            }
        }
    #endif
    /* ---------------------------------------------- */

    do {
        printf("\033[2J\033[H"); // Limpa a tela
        printf("\n");
        printf("||=====================================================||\n");
        printf("||      SOLUCIONADOR DE LABIRINTOS (MODELO BFS)        ||\n");
		printf("||=====================================================||\n\n");
        printf("1. Executar Simulacao (BFS)\n");
        printf("2. Carregar Novo Labirinto (Arquivo)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                executarBusca(lab_original);
                printf("\nPressione Enter para voltar ao menu...");
                getchar(); getchar();
                break;

            case 2:
                carregarLabirinto(lab_original);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                PAUSA;
        }
    } while (opcao != 0);

    return 0;
}
