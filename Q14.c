#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *p1, const void *p2){   //Essa função definirá a ordem dos elementos retornando um valor negativo se p1 vier antes de p2. Um valor nulo se p1 = p2.
    if (*(float*)p1 - *(float*)p2 > 0){         //E um positivo se p1 vier depois de p2.
        return 1;
    } else if (*(float*)p1 - *(float*)p2 < 0){
        return -1;
    } else{
        return 0;
    }        
}

int main(){

    clock_t t1, t2, t3; // Criando variaveis usando a biblioteca time.h para responder a questão 16.

    float *lista;  //Declaração do ponteiro que irá armazenar o primeiro endereço da alocação de memória
    int n;

    printf("Quantos numeros deseja na lista?: ");
    scanf("%d", &n);
    lista = malloc(n * sizeof(float)); //Alocação de n elementos do tipo float da memória

    for (int i = 0; i < n; i++){  //Simples loop for que irá armazenar os números inseridos pelo usuário em lista[i]
        printf("\nInsira o %d numero na lista: ", i+1);
        scanf("%f", &lista[i]);
    }

    t1 = clock(); // Inicializando o cronômetro

    qsort(lista, n, sizeof(float), comparar);       //A função qsort requer um ponteiro para o primeiro elemento da lista. A quantidade de elementos do array apontado
                                                    //pelo primeiro parâmetro. O tamanho, em bytes, do tipo dos elementos da array e a função criada que irá comparar
                                                    //dois elementos da array e retornar um valor negativo, nulo ou positivo.
    
    for (int i = 0; i < n; i++){                    //Simples loop for para imprimir os valores organizados de forma crescente.
        printf("\n%d: %.1f", (i+1), lista[i]);
    }

    free(lista);

    t2 = clock(); // Parando o cronômetro
    t3 = difftime(t2, t1);

    printf("\nTempo de execucao do programa: %f segundos", ((float)t3)/CLOCKS_PER_SEC);
    return 0;    
}