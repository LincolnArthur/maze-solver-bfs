#include "maze.h"

// CARREGAR LABIRINTO DE ARQUIVO
//O arquivo tem que estar em testes/arquivo_N.txt (10 linhas com 20 números, 0 = livre e 1 = parede)
// um ponteiro para a matriz a ser preenchida
void carregarLabirinto(int lab[LINHAS][COLUNAS]) {
    int i, j, escolha;
    char nome_arquivo[50];
    FILE *file;

    printf("\n--- CARREGAR LABIRINTO ESPECIFICO ---\n");
    printf("Digite o numero do arquivo de labirinto (ex: 1 para arquivo_1.txt): ");
    if (scanf("%d", &escolha) != 1) return;

    sprintf(nome_arquivo, "testes/arquivo_%d.txt", escolha); //monta o nome do arquivo com o número digitado
    file = fopen(nome_arquivo, "r");

    if (file) {
        printf("[Indexador] Lendo estrutura de %s...\n", nome_arquivo);
        for (i = 0; i < LINHAS; i++) {
            for (j = 0; j < COLUNAS; j++) {
                //Lê número por número e já vai salvando na matriz
                if (fscanf(file, "%d", &lab[i][j]) != 1) {
                    printf("Erro ao ler dados no ponto [%d][%d]\n", i, j);
                }
            }
        }
        fclose(file);
        printf("\033[1;32m[Sucesso] Labirinto %d carregado na memoria!\033[0m\n", escolha);
    } else {
        printf("\033[1;31m[Erro] Arquivo %s não encontrado na pasta /testes.\033[0m\n", nome_arquivo);
    }
    
    printf("\nPressione Enter para voltar ao menu...");
    getchar(); getchar(); //o primeiro getchar pega o Enter que sobrou do scanf
}
