#include <stdio.h>

#define TAM 10   // tamanho tabuleiro 10x10
#define NAVIO 3  // tamanho dos navios (3 posições)

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // todas posições começam como água
        }
    }
}

// Função para imprimir o tabuleiro na tela
void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // separa por espaço p/ ficar mais fácil de ver
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontal no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    int i;
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // coloca o valor 3 nas posições do navio
    }
}

// Função para posicionar um navio vertical no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    int i;
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // mesma coisa mas agora de cima pra baixo
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro só com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas escolhidas 
    int linhaNavioH = 2; // linha e coluno do navio horizontal
    int colunaNavioH = 4; 

    int linhaNavioV = 6; // linha e coluna inicial do navio vertical
    int colunaNavioV = 1; 

    // Posicionar o navio horizontal
    // Aqui eu verifico se ele cabe no tabuleiro antes
    if (colunaNavioH + NAVIO <= TAM) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH);
    }

    // Posicionar o navio vertical
    if (linhaNavioV + NAVIO <= TAM) {
        posicionarNavioVertical(tabuleiro, linhaNavioV, colunaNavioV);
    }

    // Mostrar o tabuleiro final
    printf("Tabuleiro com os navios posicionados:\n\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}