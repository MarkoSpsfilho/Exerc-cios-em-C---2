/*

Escreva um algoritmo que leia três valores inteiros diferentes entre si e apresente-os em ordem
decrescente

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

bool eh_inteiro_valido(const char *str) {
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    if(str[0] == '-' || str[0] == '+') {
        i++;
    }

    if(str[i] == '\0') return false;

    while(str[i] != '\0') {
        if(!isdigit((unsigned char)str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int arrayValores[3];
    char buffer[100];
    int valor = 0;
    int i = 0;
    
    printf("==== ENTRADA DE DADOS ====\n\n");

    while(i < 3) {
        printf("Digite o valor %d: ", i + 1);

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.");
            return 1;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if(!eh_inteiro_valido(buffer)) {
            printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO!\n\n");
            continue;
        }

        valor = atoi(buffer);

        // ==== VERIFICA SE O VALOR É DUPLICADO EM RELAÇÃO AOS ANTERIORES JÁ INSERIDOS ====
        bool duplicado = false;
        for(int j = 0; j < i; j++) {
            if(arrayValores[j] == valor) {
                    duplicado = true;
                break;
            }
        }

        if(duplicado) {
            printf("==== ERRO! VALOR DUPLICADO! DIGITE UM VALOR DIFERENTE! ====\n\n");
            continue;
        }

        arrayValores[i] = valor;
        printf("==== VALOR VALIDADO ====\n\n");
        i++;
    }
    
    // ==== ORDENAÇÃO DECRESCENTE (3 COMPARAÇÕES) ====

    // ==== GARANTE arrayValores[0] >= arrayValores[1] ====
    if(arrayValores[0] < arrayValores[1]) {
        int temp = arrayValores[0];
        arrayValores[0] = arrayValores[1];
        arrayValores[1] = temp;
    }

    // ==== GARANTE arrayValores[1] >= arrayValores[2] ====
    if(arrayValores[1] < arrayValores[2]) {
        int temp = arrayValores[1];
        arrayValores[1] = arrayValores[2];
        arrayValores[2] = temp; 
    }

    // ==== GARANTE  NOVAMENTE arrayValores[0] >= arrayValores[1] ====
    // CASO O MENOR ELEMENTO ESTIVESSE NA POSIÇÃO 0 E TENHA IDO PARA A POSIÇÃO 1 NO ARRAY
    if(arrayValores[0] < arrayValores[1]) {
        int temp = arrayValores[0];
        arrayValores[0] = arrayValores[1];
        arrayValores[1] = temp;
    }

    printf("\nOS VALORES EM ORDEM DECRESCENTE SÃO: \n");
    for(i = 0; i < 3; i++) {
        printf("%d\n", arrayValores[i]);
    }
    return 0;
}