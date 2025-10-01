#include <stdio.h>
#include <stdlib.h>

int*** aloca_matriz (int m, int n, int z) {
    int ***matriz = (int***) malloc(m*sizeof(int**));
    if (matriz == NULL) {
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        matriz[i] = (int**) malloc(n*sizeof(int*));
        if (matriz[i] == NULL) {
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == NULL) {
                return NULL;
            }
            matriz[i][j] = (int*) malloc(z*sizeof(int));
        }
    }

    return matriz;
}

void preenche_matriz (int m, int n, int z, int ***mat) {
    for (int i = 0; i < z; i++) {
        printf("Camada/Profundidade %d:\n", i);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                printf("Posicao [%d][%d]: ", j, k);
                scanf("%d", &mat[j][k][i]);
            }
        }
    }
}

void imprime_matriz (int m, int n, int z, int ***mat) {
    for (int i = 0; i < z; i++) {
        printf("Camada/Profundidade %d:\n", i);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                printf("Posicao [%d][%d]:%d  ", j, k, mat[j][k][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void libera_matriz (int m, int n, int ***mat) {
    if (mat == NULL) {
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}


int main() {
    int m, n, z;
    printf("Digite o tamanho da dimensao m: ");
    scanf("%d", &m);
    printf("Digite o tamanho da dimensao n: ");
    scanf("%d", &n);
    printf("Digite o tamanho da dimensao z: ");
    scanf("%d", &z);

    int ***mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);
    libera_matriz(m, n, mat);
    return 0;
}