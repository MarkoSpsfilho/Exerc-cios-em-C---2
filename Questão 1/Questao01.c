/*

Faça um algoritmo que leia três valores inteiros A, B e C e informe se a soma de A + B é menor que C. 

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

void limparBuffer() {
 int c;
 while((c = getchar()) != '\n' && c != EOF);
}

int main() {
 // ==== AJUSTANDO ACENTOS ====
 SetConsoleCP(65001);
 SetConsoleOutputCP(65001);

 // ==== DECLARANDO VARIÁVEIS ====
 int valorA = 0;
 int valorB = 0;
 int valorC = 0;
 int soma;
 
 // ==== PEGANDO E VALIDANDO ENTRADAS DO USUÁRIO ====
 printf("==== ENTRADA DE DADOS ====\n\n");

 // ---PEGANDO E VALIDANDO VALOR A---
 while (true) {
    printf("Digite o valor de A: ");

    if(scanf("%d", &valorA) == 1) {
        printf("\n\n==== VALOR VALIDADO COM SUCESSO! ====\n\n");
        break; // ==== DADO VALIDADO ====
    }
    printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É UM NÚMERO DECIMAL!\n\n");
    limparBuffer();     
}

 // ---PEGANDO E VALIDANDO VALOR B---
 while (true) {
    printf("Digite o valor de B: ");

    if(scanf("%d", &valorB) == 1) {
        printf("\n\n==== VALOR VALIDADO COM SUCESSO! ====\n\n");
        break; // ==== DADO VALIDADO ====
    }
    printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É UM NÚMERO DECIMAL!\n\n");
    limparBuffer();
}

 // ---PEGANDO E VALIDANDO VALOR C---
 while (true) {
    printf("Digite o valor de C: ");

    if(scanf("%d", &valorC) == 1) {
        printf("\n\n==== VALOR VALIDADO COM SUCESSO! ====\n\n");
        break; // ==== DADO VALIDADO ====
    }
    printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É UM NÚMERO DECIMAL!\n\n");
    limparBuffer();
}

 // ==== MENSAGEM PARA O USUÁRIO ====
 printf("==== NÚMEROS VALIDADOS COM SUCESSO! ====\n\n");
 
 // ==== INICIANDO CÁLCULO E FAZENDO COMPARAÇÕES ====
 printf("==== INICIANDO CÁLCULOS ====\n\n");

 soma = valorA + valorB;

 // ==== FAZENDO COMPARAÇÕES ====
 if(soma > valorC) {
    printf("O valor da soma entre %d e %d é %d, este valor é maior que %d\n", valorA, valorB, soma, valorC);
 }
 else if(soma == valorC) {
    printf("O valor da soma entre %d e %d é %d, este valor é igual à %d\n", valorA, valorB, soma, valorC);
 }
 else {
    printf("O valor da soma entre %d e %d é %d, este valor é menor que %d\n", valorA, valorB, soma, valorC);
 }
 
 return 0;
}
