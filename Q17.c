#include <stdio.h>
#include <stdlib.h>

void soma_vetores(int *vetor1, int *vetor2, int *vetor3, int n){
    for (int i = 0; i < n; i++){
        vetor3[i] = vetor1[i] + vetor2[i];
    }
}

int main(){

    int *vetor1, *vetor2, *vetor3, n;

    printf("Insira o tamanho dos vetores: ");
    scanf("%d", &n);

    vetor1 = malloc(n * sizeof(int));
    vetor2 = malloc(n * sizeof(int));
    vetor3 = malloc(n * sizeof(int));

    printf("Insira valores para o primeiro vetor!\n");
    for (int i = 0; i < n; i++){
        printf("\nValor %d: ", i+1);
        scanf("%d", &vetor1[i]);
    }

    printf("Insira valores para o segundo vetor!\n");
    for (int i = 0; i < n; i++){
        printf("\nValor %d: ", i+1);
        scanf("%d", &vetor2[i]);
    }

    soma_vetores(vetor1, vetor2, vetor3, n);

    for (int i = 0; i < n; i++){
        printf("%d\n", vetor3[i]);
    }

    free(vetor1);
    free(vetor2);
    free(vetor3);

    return 0;
}