#include <stdio.h>
#include <stdlib.h>

struct lista {
    int linha;
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct esparsa {
    int linhas;
    int colunas;
    struct lista* prim;
};
typedef struct esparsa Esparsa;

Lista* criarNo(int lin, int col, int valor, Lista* l) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = lin;
    novo->coluna = col;
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

Esparsa* criarMatriz(int lin, int col) {
    Esparsa* mat = (Esparsa*) malloc(sizeof(Esparsa));
    mat->linhas = lin;
    mat->colunas = col;
    mat->prim = NULL;

    return mat;
}

Esparsa* preencheMatriz(Esparsa* mat, int lin, int col) {
    int valor;
    Lista* lis = NULL;

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("Digite o valor da posicao [%d][%d]: ");
            scanf("%d", &valor);

            lis = criarNo(i, j, valor, lis);
        }
    }

    mat->prim = lis;

    return mat;
}

void imprimeMatriz(Esparsa* mat, int lin, int col) {

    Lista* p = mat->prim;

    printf("Impressao matriz:\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (p->linha == i && p->coluna == j) {
                printf("%d  ", p->info);
                p = p->prox;
            } else {
                printf("0  ");
            }
        }
        printf("\n");
    }
}

int main() {

    int lin, col;
    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    Esparsa* mat = criarMatriz(lin, col);
    Esparsa* mat = preencheMatriz(mat, lin, col);
    imprimeMatriz(mat, lin, col);

    return 0;
}