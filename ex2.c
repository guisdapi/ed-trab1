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

    if (l == NULL) {
        return novo;
    } else {
        Lista* p = l;
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novo;
        return l;
    }
}

Esparsa* criarMatriz() {

    int lin, col;
    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    Esparsa* mat = (Esparsa*) malloc(sizeof(Esparsa));
    mat->linhas = lin;
    mat->colunas = col;
    mat->prim = NULL;

    return mat;
}

Esparsa* preencheMatriz(Esparsa* mat) {
    int valor;
    Lista* lis = NULL;

    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &valor);
            if (valor != 0) {
                lis = criarNo(i, j, valor, lis);
            }   
        }
    }

    mat->prim = lis;

    return mat;
}

void imprimeMatriz(Esparsa* mat) {

    Lista* p = mat->prim;

    printf("Impressao matriz:\n");
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            if (p != NULL){
                if (p->linha == i && p->coluna == j) {
                    printf("%d  ", p->info);
                    p = p->prox;
                }
            } else {
                printf("0  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void consultaMatriz(Esparsa* mat) {
    int linCons, colCons;
    printf("Digite a linha da matriz para consultar: ");
    scanf("%d", &linCons);
    printf("Digite a coluna da matriz para consultar: ");
    scanf("%d", &colCons);

    Lista* p = mat->prim;
    while (p!=NULL) {
        if (p->linha == linCons && p->coluna == colCons) {
            printf("Valor na posicao [%d][%d]: %d\n", linCons, colCons, p->info);
            return;
        }
        p=p->prox;
    }
    printf("Posicao fora do escopo da matriz...\n");
}

void imprimeSomatorio(Esparsa* mat) {

}

void percentualNaoNulos(Esparsa* mat) {

}

int main() {

    Esparsa* mat = criarMatriz();
    mat = preencheMatriz(mat);
    imprimeMatriz(mat);
    consultaMatriz(mat);
    imprimeSomatorio(mat);
    percentualNaoNulos(mat);

    return 0;
}