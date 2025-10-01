#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Lista{
    int linha, coluna;
    int info;
    struct Lista* prox;
}Lista;

typedef struct Identidade{
    int ordem;
    struct Lista* prim;
}Identidade;

void libera_matriz(Identidade* matriz){
    Lista* p = matriz->prim;
    while(p != NULL){
        Lista* temp = p;
        p = p->prox;
        free(temp);
    }
    free(matriz);
}

Identidade* cria_matriz(){
    int input_ordem;
    do{
        printf("Digite a ordem da matriz: \n");
        scanf("%d", &input_ordem);
        if(input_ordem < 2)
            printf("A ordem precisa ser no mínimo 2\n");
    }while(input_ordem < 2);
    Identidade* matriz = (Identidade*)malloc(sizeof(Identidade));
    matriz->ordem = input_ordem;
    matriz->prim = NULL;
    return matriz;
}

Lista* criarNo(int l, int c, int valor, Lista* lista){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->linha = l;
    novo->coluna = c;
    novo->info = valor;
    novo->prox = NULL;

    if(lista == NULL)
        return novo;
    else{
        Lista* p = lista;
        while(p->prox != NULL)
            p = p->prox;
        p->prox = novo;
        return lista;
    }
}

Identidade* preenche_matriz(Identidade* mat){
    int input_valor;
    Lista* lista = NULL;
    for(int i = 0; i < mat->ordem; i++){
        for(int j = 0; j < mat->ordem; j++){
            printf("Digite o valor da posição [%d][%d]: \n", i, j);
            scanf("%d", &input_valor);
            if(input_valor != 0)
                lista = criarNo(i, j, input_valor, lista);
        }
    }
    mat->prim = lista;
    return mat;
}

void imprimeMatriz(Identidade* mat) {
    Lista* p = mat->prim;
    printf("Impressao matriz:\n");
    for (int i = 0; i < mat->ordem; i++) {
        for (int j = 0; j < mat->ordem; j++) {
            if(p != NULL && p->linha == i && p->coluna == j){
                printf("%3d", p->info);
                p = p->prox;
            }
            else{
                printf("%3d", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void elementos_violantes(Identidade* mat){
    printf("Elementos que violam a propriedade de identidade: \n");

    int ordem = mat->ordem;
    bool diagonal[ordem];
    for (int i = 0; i < ordem; i++) {
        diagonal[i] = false;
    }

    for (Lista* p = mat->prim; p != NULL; p = p->prox) {
        if (p->linha == p->coluna) {
            if (p->info == 1) {
                if (p->linha < ordem) {
                    diagonal[p->linha] = true;
                }
            }
            else {
                printf("Posicao [%d][%d] deveria ser 1, mas eh %d.\n", p->linha, p->coluna, p->info);
            }
        }
        else {
            printf("Posicao [%d][%d] com valor %d viola matriz identidade.\n", p->linha, p->coluna, p->info);
        }
    }
    printf("\n");
    for (int i = 0; i < mat->ordem; i++) {
        if (diagonal[i] == false) {
            printf("Posicao [%d][%d] deveria ser 1.\n", i, i);
        }
    }
}

int main() {
    Identidade* matriz;
    matriz = cria_matriz();
    matriz = preenche_matriz(matriz);
    imprimeMatriz(matriz);
    elementos_violantes(matriz);
    libera_matriz(matriz);
    return 0;
}