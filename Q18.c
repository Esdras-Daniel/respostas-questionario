#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int num_linhas, int num_colunas){
    int **matriz;
    //Alocando bloco auxiliar.
    matriz = (int **) malloc(sizeof(int *) * num_linhas);
    //Alocando o único bloco onde vão ficar os valores.
    matriz[0] = malloc(num_linhas * num_colunas * sizeof(int));
    //Fixando os ponteiros.
    for (int i = 1; i < num_linhas; i++){
        matriz[i] = matriz[i - 1] + num_colunas;
    }

    return matriz;
}

void adiciona_valores(int **matriz, int num_linhas, int num_colunas){
    printf("Adicione valores para a matriz\n");
    int valor;
    for (int i = 0; i < num_linhas; i++){
        for (int j = 0; j < num_colunas; j++){ 
            scanf("%d", &valor);
            *(*(matriz+i)+j) = valor;
        }
    }
}

void multiplicacao(int **matrizA, int **matrizB, int **matrizC, int l_matrizA, int c_matrizA, int c_matrizB){
    int somatorio = 0;
    for (int i = 0; i < l_matrizA; i++){
        for (int j = 0; j < c_matrizB; j++){
            somatorio = 0;
            for (int k = 0; k < c_matrizA; k++){
                //           Não depende de j     Não depende de i
                somatorio += *(*(matrizA+i)+k) * (*(*(matrizB+k)+j));
            }
            *(*(matrizC+i)+j) = somatorio;
        }
    } 
}

int main(){

    int l_matrizA, c_matrizA, l_matrizB, c_matrizB;

    printf("Insira o numero de linhas da matriz A: ");
    scanf("%d", &l_matrizA);
    printf("Insira o numero de colunas da matriz A: ");
    scanf("%d", &c_matrizA);
    printf("Insira o numero de colunas da matriz B: ");
    scanf("%d", &c_matrizB);

    l_matrizB = c_matrizA;

    int** matrizA = alocaMatriz(l_matrizA, c_matrizA);
    int** matrizB = alocaMatriz(l_matrizB, c_matrizB);
    int** matrizC = alocaMatriz(l_matrizA, c_matrizB);

    adiciona_valores(matrizA, l_matrizA, c_matrizA);
    adiciona_valores(matrizB, l_matrizB, c_matrizB);

    multiplicacao(matrizA, matrizB, matrizC, l_matrizA, c_matrizA, c_matrizB);

    printf("MATRIZ A\n");
    for (int i = 0; i < l_matrizA; i++){
        for (int j = 0; j < c_matrizA; j++){
            printf("%d  ", *(*(matrizA+i)+j));
        }
        printf("\n");
    }

    printf("MATRIZ B\n");
    for (int i = 0; i < l_matrizB; i++){
        for (int j = 0; j < c_matrizB; j++){
            printf("%d  ", *(*(matrizB+i)+j));
        }
        printf("\n");
    }

    printf("MATRIZ C\n");
    for (int i = 0; i < l_matrizA; i++){
        for (int j = 0; j < c_matrizB; j++){
            printf("%d  ", *(*(matrizC+i)+j));
        }
        printf("\n");
    }
    
    free(matrizA[0]);
    free(matrizA);
    free(matrizB[0]);
    free(matrizB);
    free(matrizC[0]);
    free(matrizC);

    return 0;
}