#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define PAUSA Sleep(150)
#else
    #include <unistd.h>
    #define PAUSA usleep(150000)
#endif

#define LINHAS   10
#define COLUNAS  20

// Definicao de Cores e Caracteres
#define RESET  "\033[0m"
#define WALL   "\033[1;37m##\033[0m"
#define PATH   "  "
#define VISIT  "\033[0;34m..\033[0m"
#define HEAD   "\033[1;33m@@\033[0m"
#define FINAL  "\033[1;32m**\033[0m"
#define BORDER "\033[1;34m"

typedef struct {
    int x, y;
} Ponto;

// Prototipos da Estrutura de Dados (Fila)
void enfileirar(Ponto p);
Ponto desenfileirar();
int filaVazia();

void resetarFila();

// Prototipos de Logica
void imprimirLabirinto(int lab[LINHAS][COLUNAS], int passo, const char *status);
void executarBusca(int lab[LINHAS][COLUNAS]);
void carregarLabirinto(int lab[LINHAS][COLUNAS]);

#endif
