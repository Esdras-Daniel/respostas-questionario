#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minha_qsort(int *primeiro_elem, int nums_elem, int (*func)(int a, int b)){
    int temp;
    for (int j = 0; j < nums_elem - 1; j++){
        for (int i = 0; i < nums_elem - 1; i++){
            if (func(*(primeiro_elem+i), *(primeiro_elem+(i+1))) > 0){
                temp = *(primeiro_elem+i);
                *(primeiro_elem+i) = *(primeiro_elem+(i+1));
                *(primeiro_elem+(i+1)) = temp;
            }
        }
    } 
}

int minha_comparacao(int a, int b){
    if (a > b){
        return 1;
    } else if (a < b){
        return -1;
    } else{
        return 0;
    }
}

int main(){

    clock_t t1, t2, t3;

    int n;
    int *lista;

    printf("Deseja alocar quantos elementos para a lista?: ");
    scanf("%d", &n);

    lista = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("%d elemento: ", i+1);
        scanf("%d", &lista[i]);
    }

    t1 = clock();

    minha_qsort(lista, n, minha_comparacao);

    for (int i = 0; i < n; i++){
        printf("%d ", lista[i]);
    }

    free(lista);

    t2 = clock();
    t3 = difftime(t2, t1);

    printf("\nTempo de execucao do programa: %f segundos", ((float)t3)/CLOCKS_PER_SEC);
    return 0;
}