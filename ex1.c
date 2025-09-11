#include <stdio.h>
#include <stdlib.h>

struct diagonal 
{ 
    int ordem; //ordem da matriz 
    int* v; //o tamanho do vetor é igual a ordem da matriz. Os elementos da diagonal principal são armazenados neste vetor 
}; 
typedef struct diagonal Diagonal; 

Diagonal* criarMatriz() {
    int ordem;
    printf("Qual a ordem?");
    scanf("%d", &ordem);

    Diagonal* nova = (Diagonal*) malloc(sizeof(Diagonal));
    nova->ordem = ordem;
}

int main() {

    Diagonal* mat = criarMatriz();

    return 0;
}