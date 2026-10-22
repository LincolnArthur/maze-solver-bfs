#include "maze.h"

void imprimirLabirinto(int lab[LINHAS][COLUNAS], int passo, const char *status) {
    int i, j;
    printf("\033[H");
    printf(BORDER "+" "----------------------------------------" "+\n" RESET);
    printf(BORDER "|" RESET " BFS MAZE SOLVER  passo: %-6d" BORDER "         |\n" RESET, passo);
    printf(BORDER "+" "----------------------------------------" "+\n" RESET);

    for (i = 0; i < LINHAS; i++) {
        printf(BORDER "|" RESET);
        for (j = 0; j < COLUNAS; j++) {
            switch (lab[i][j]) {
                case 0: printf(PATH);  break;
                case 1: printf(WALL);  break;
                case 2: printf(VISIT); break;
                case 3: printf(HEAD);  break;
                case 8: printf(FINAL); break;
            }
        }
        printf(BORDER "|\n" RESET);
    }
    printf(BORDER "+" "----------------------------------------" "+\n" RESET);
    printf(" Status : %-40s\n", status);
}

void executarBusca(int lab[LINHAS][COLUNAS]) {
	resetarFila(); // Limpa a estrutura de dados
    // Limpeza da matriz para permitir re-execução
    
    printf("\033[2J\033[H");
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (lab[i][j] != 1) lab[i][j] = 0; 
        }
    }
    int visitado[LINHAS][COLUNAS] = {0};
    Ponto pai[LINHAS][COLUNAS];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int i, achou = 0, passo_cont = 0;

    enfileirar((Ponto){0, 0});
    visitado[0][0] = 1;
    pai[0][0] = (Ponto){-1, -1};

    while (!filaVazia()) {
        Ponto atual = desenfileirar();
        int ox = atual.x, oy = atual.y;

        if (ox == LINHAS - 1 && oy == COLUNAS - 1) {
            achou = 1;
            break;
        }

        lab[ox][oy] = 3;
        imprimirLabirinto(lab, passo_cont++, "Explorando adjacencias...");
        PAUSA;
        lab[ox][oy] = 2;

        for (i = 0; i < 4; i++) {
            int nx = ox + dx[i];
            int ny = oy + dy[i];
            if (nx >= 0 && nx < LINHAS && ny >= 0 && ny < COLUNAS &&
                lab[nx][ny] == 0 && !visitado[nx][ny]) {
                visitado[nx][ny] = 1;
                pai[nx][ny] = atual;
                enfileirar((Ponto){nx, ny});
            }
        }
    }

    if (achou) {
        Ponto p = (Ponto){LINHAS - 1, COLUNAS - 1};
        while (p.x != -1) {
            lab[p.x][p.y] = 8;
            imprimirLabirinto(lab, passo_cont++, "Reconstruindo caminho...");
            PAUSA;
            p = pai[p.x][p.y];
        }
        printf("\n\033[1;32mSUCESSO: Saida encontrada!\033[0m\n");
    } else {
        printf("\n\033[1;31mFALHA: Caminho inexistente.\033[0m\n");
    }
}
