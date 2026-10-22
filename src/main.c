#include "maze.h"

//============================================================
//UNIVASF - Universidade Federal do Vale do São Francisco
//Algoritmos e Estruturas de Dados I - Projeto 1
//Solucionador de Labirintos (BFS)
//============================================================

//============================================================
//Docente: Professora Dra. Ana Emilia de Melo Queiroz
//Discentes: Arthur Lincoln Pinheiro Herculino Almeida
//           Caio Benevides Pontes
//============================================================

//Labirinto padrão (0 = livre, 1 = parede). É o que roda se não carregar nenhum arquivo
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

    //Liga as cores (\033) no console do Windows
    #ifdef _WIN32
        SetConsoleOutputCP(65001); //pros acentos aparecerem certo
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                // Pra funcionar em qualquer powershell, ou cmd
                dwMode |= 0x0004; 
                SetConsoleMode(hOut, dwMode);
            }
        }
    #endif

    do {
        printf("\033[2J\033[H"); //Limpa a tela
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
                getchar(); getchar(); //o primeiro getchar pega o Enter que sobrou do scanf
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
