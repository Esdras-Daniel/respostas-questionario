#include <stdio.h>
#include <stdlib.h>

int main(){

    float *lista, temp;
    int n;

    printf("Quantos numeros deseja na lista?: ");
    scanf("%d", &n);
    lista = malloc(n * sizeof(float));

    for (int i = 0; i < n; i++){
        printf("\nInsira o %d numero na lista: ", i+1);
        scanf("%f", &lista[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (lista[j] > lista[i]){
                temp = lista[j];
                lista[j] = lista[i];
                lista[i] = temp;
            } 
        }
    }

    for (int i = 0; i < n; i++){
        printf("\n%d: %.1f", (i+1), lista[i]);
    }
    
    return 0;    
}