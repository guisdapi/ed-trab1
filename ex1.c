#include <stdio.h>
#include <stdlib.h>

typedef struct Diagonal { 
    int ordem; //ordem da matriz 
    int* v; //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados neste vetor 
}Diagonal; 

Diagonal* criarMatriz() {
    int ordem;
    printf("Qual a ordem?");
    scanf("%d", &ordem);

    Diagonal* matriz = (Diagonal*)malloc(sizeof(Diagonal));
    matriz->ordem = ordem;

    matriz->v = (int*)malloc(ordem*sizeof(int));

    return matriz;
}

Diagonal* preenchimento_matriz(Diagonal* matriz){
    int input;
    for(int i = 0; i < matriz->ordem; i++){
        printf("Insira um número: \n");
        scanf("%d", &input);
        matriz->v[i] = input;
    }
    return matriz;
}

void print_matriz(Diagonal* matriz){
    for(int i = 0; i < matriz->ordem; i++){
        for(int j = 0; j < matriz->ordem; j++){
            if(i == j)
                printf("%3d ", matriz->v[i]);
            else
                printf("%3d ", 0);
        }
        printf("\n");
    }
}

void consulta_elemento(Diagonal* matriz){
    int input_i, input_j;
    printf("Qual posição da matriz deseja consultar? \n");
    scanf("%d %d", &input_i, &input_j);
    if(input_i > matriz->ordem || input_j > matriz->ordem){
        printf("Coordenada fora da matriz\n");
        return;
    }
    if(input_i == input_j)
        printf("Valor nessa posição: %d\n", matriz->v[input_i]);
    else
        printf("Valor nessa posição: 0\n");
}

int main() {
    Diagonal* matrizDiagonal = criarMatriz();
    matrizDiagonal = preenchimento_matriz(matrizDiagonal);
    print_matriz(matrizDiagonal);
    consulta_elemento(matrizDiagonal);
    return 0;
}