#include "maze.h"

//FILA SEQUENCIAL (vetor)
//Tamanho LINHAS * COLUNAS porque cada célula só entra na fila uma vez

static Ponto fila[LINHAS * COLUNAS]; //SÓ ESSE ARQUIVO ACESSA
static int frente = 0; //SÓ ESSE ARQUIVO ACESSA
static int tras = 0; //SÓ ESSE ARQUIVO ACESSA

// 1. ZERAR A FILA
//Tem que chamar antes de toda busca, senão fica lixo da busca anterior
void resetarFila() {
    frente = 0;
    tras = 0;
}

// 2. ENFILEIRAR (entra no fim)
void enfileirar(Ponto p) {
    fila[tras++] = p;
}

// 3. DESENFILEIRAR (sai do começo)
Ponto desenfileirar() {
    return fila[frente++];
}

// 4. FILA VAZIA?
//Se a frente alcançou o tras não tem mais ninguém pra visitar
int filaVazia() {
    return frente == tras;
}
