#include "maze.h"

static Ponto fila[LINHAS * COLUNAS]; //SÓ ESSE ARQUIVO ACESSA
static int frente = 0; //SÓ ESSE ARQUIVO ACESSA
static int tras = 0; //SÓ ESSE ARQUIVO ACESSA

void resetarFila() {
    frente = 0;
    tras = 0;
}

void enfileirar(Ponto p) {
    fila[tras++] = p;
}

Ponto desenfileirar() {
    return fila[frente++];
}

int filaVazia() {
    return frente == tras;
}
