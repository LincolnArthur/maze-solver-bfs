# 🧭 Maze Solver BFS: solucionador de labirintos em C

Programa de terminal que encontra a saída de um labirinto usando **Busca em Largura (BFS)** e mostra a exploração **animada, passo a passo**, até reconstruir o caminho mais curto.

Projeto 1 da disciplina **Algoritmos e Estruturas de Dados I**, do curso de Engenharia de Computação da UNIVASF.

## Demonstração

O caminho encontrado aparece em `**`, as células visitadas pela busca aparecem em `..` e as paredes em `##`:

```
+----------------------------------------+
| BFS MAZE SOLVER  passo: 132            |
+----------------------------------------+
|****##****************##                |
|##**##**############**##  ############  |
|##******##************##            ##  |
|######..##**######################  ##  |
|........##**********************##  ##  |
|..############################**##  ##  |
|..................##************##      |
|################..##**################  |
|............##....##****************##  |
|..########......##################******|
+----------------------------------------+
 Status : Reconstruindo caminho...

SUCESSO: Saida encontrada!
```

No terminal a animação é colorida: paredes em branco, visitados em azul, a "cabeça" da busca (`@@`) em amarelo e o caminho final em verde.

## Como funciona

1. A busca começa no canto superior esquerdo `(0, 0)` e procura a saída no canto inferior direito `(9, 19)`.
2. Cada posição alcançada é colocada numa **fila**. A cada passo o programa retira a posição da frente da fila e visita os 4 vizinhos (cima, baixo, esquerda, direita).
3. Uma matriz `visitado` impede que a mesma célula entre na fila duas vezes.
4. Uma matriz `pai` guarda de onde cada célula foi alcançada. Quando a saída é encontrada, o programa segue os "pais" de volta até a origem para **reconstruir o caminho**.

Como a BFS explora o labirinto em "camadas" de distância, o caminho encontrado é sempre o **mais curto** possível. A complexidade é **O(L × C)** em tempo e memória, sendo L o número de linhas e C o de colunas.

### Estruturas de dados utilizadas

| Estrutura | Onde | Para quê |
|---|---|---|
| Fila sequencial (vetor estático) | `src/fila.c` | Ordem de exploração da BFS (FIFO) |
| Matriz `int[10][20]` | `src/main.c` | Representação do labirinto |
| Matriz de `Ponto` | `src/busca.c` | Registro do "pai" de cada célula, para reconstruir o caminho |
| `struct Ponto { int x, y; }` | `src/maze.h` | Coordenada no labirinto |

A fila é encapsulada com variáveis `static`, de modo que só `fila.c` acessa o vetor interno e o resto do programa usa apenas `enfileirar`, `desenfileirar` e `filaVazia`.

## Estrutura do repositório

```
maze-solver-bfs/
├── src/
│   ├── maze.h      # constantes, cores ANSI, struct Ponto e protótipos
│   ├── main.c      # menu e labirinto padrão
│   ├── busca.c     # algoritmo BFS e desenho do labirinto
│   ├── fila.c      # implementação da fila
│   └── indexar.c   # leitura de labirintos a partir de arquivo
├── testes/         # 10 labirintos de exemplo (arquivo_1.txt … arquivo_10.txt)
├── Makefile
└── README.md
```

## Como compilar e executar

É preciso ter o compilador **GCC** instalado.

**Linux / macOS**

```bash
make
./maze_solver
```

**Windows (MinGW)**

```bash
mingw32-make
maze_solver.exe
```

Sem `make`, também dá para compilar diretamente:

```bash
gcc src/*.c -o maze_solver
```

> Execute o programa **a partir da pasta raiz do repositório**, para que ele encontre a pasta `testes/`.

### Menu

```
1. Executar Simulacao (BFS)
2. Carregar Novo Labirinto (Arquivo)
0. Sair
```

Na opção 2, digite um número de 1 a 10 para carregar o `testes/arquivo_N.txt` correspondente.

## Formato dos arquivos de labirinto

Cada arquivo tem 10 linhas com 20 números separados por espaço: `0` é caminho livre e `1` é parede.

```
0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0
0 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
...
```

## Autores

- **Arthur Lincoln P. H. Almeida**
- **Caio Benevides Pontes**

Engenharia de Computação, Universidade Federal do Vale do São Francisco (UNIVASF).
