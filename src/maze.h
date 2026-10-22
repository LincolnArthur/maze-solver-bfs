#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>

//PAUSA = tempo entre um passo e outro da animação
//No Windows o Sleep é em milissegundos, no Linux o usleep é em microssegundos
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA Sleep(150)
#else
    #include <unistd.h>
    #define PAUSA usleep(150000)
#endif

//TAMANHO DO LABIRINTO
#define LINHAS   10
#define COLUNAS  20

//CORES E CARACTERES
//Cada célula usa 2 caracteres pra ficar quadradinha no terminal
#define RESET  "\033[0m"
#define WALL   "\033[1;37m##\033[0m"
#define PATH   "  "
#define VISIT  "\033[0;34m..\033[0m"
#define HEAD   "\033[1;33m@@\033[0m"
#define FINAL  "\033[1;32m**\033[0m"
#define BORDER "\033[1;34m"

//x = linha, y = coluna
typedef struct {
    int x, y;
} Ponto;

// FILA (fila.c)
void enfileirar(Ponto p);
Ponto desenfileirar();
int filaVazia();

void resetarFila();

// BUSCA E LEITURA DE ARQUIVO (busca.c e indexar.c)
void imprimirLabirinto(int lab[LINHAS][COLUNAS], int passo, const char *status);
void executarBusca(int lab[LINHAS][COLUNAS]);
void carregarLabirinto(int lab[LINHAS][COLUNAS]);

#endif
