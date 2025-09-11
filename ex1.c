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

//ta muito feio a saida
void print_matriz(Diagonal* matriz){
    for(int i = 0; i < matriz->ordem; i++){
        for(int j = 0; j < matriz->ordem; j++){
            if(i == j)
                printf("%d ", matriz->v[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

//Arrumar isso, se por uma coordenada fora da matriz ele retorna 0, o que está errado
int consulta_elemento(Diagonal* matriz, int i, int j){
    if(i == j)
        return matriz->v[i];
    else
        return 0;
}

int main() {
    int input_i, input_j, elemento;
    Diagonal* matrizDiagonal = criarMatriz();
    matrizDiagonal = preenchimento_matriz(matrizDiagonal);
    print_matriz(matrizDiagonal);
    printf("Qual posição da matriz deseja consultar? \n");
    scanf("%d %d", &input_i, &input_j);
    elemento = consulta_elemento(matrizDiagonal, input_i, input_j);
    printf("Elemento nessa coordenada: %d\n", elemento);
    return 0;
}