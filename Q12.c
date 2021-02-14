// Calculadora para exemplificar o uso de ponteiros para funções
#include <stdio.h>

float adicao(float a, float b){
    return a + b;
}
float subtracao(float a, float b){
    return a - b;
}
float multiplicacao(float a, float b){
    return a * b;
}
float divisao(float a, float b){
    return a / b;
}

int main(){

    float num1, num2;
    int op;
    /* Na próxima linha estou declarando uma array de ponnteiros
    de tamanho 4. De tal forma que esses ponteiros são ponteiros para funções que
    tem como parametros dois números float e retorna um valor float 
    Lembre-se que o próprio nome da função passa o endereço dela.*/
    float (*lista_func[4])(float, float) = {adicao, subtracao, multiplicacao, divisao};

    printf("Qual sera o primeiro numero?: ");
    scanf("%f", &num1);
    printf("Qual sera a operacao realizada? 0 = adicao, 1 = subtracao, 2 = multiplicacao, 3 = divisao: ");
    scanf("%d", &op);
    printf("Qual sera o segundo numero?: ");
    scanf("%f", &num2);
    
    printf("Resultado: %f", lista_func[op](num1, num2));

    return 0;
}