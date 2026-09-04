/*

Faça um algoritmo que leia dois valores inteiros, A e B.
• Se os valores forem iguais, some A + B.
• Caso sejam diferentes, multiplique A * B.
Ao final, armazene o resultado em uma variável C e apresente seu valor na tela.

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

// ==== FUNÇÃO PARA VERIFICAÇÃO E VALIDAÇÃO DE INTEIROS ====
bool eh_inteiro_valido(const char *str) {
    // ==== STRING NULA OU VAZIA NÃO É VÁLIDA ====
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    // ==== PERMITE SINAIS POSITIVOS E NEGATIVOS ====
    if(str[0] == '-' || str[0] == '+') {
        i++;
    }

    // ==== SE A STRING SÓ CONTINHA SINAL, É INVÁLIDA ====
    if(str[i] == '\0') return false;

    // ==== VERIFICA SE TODOS OS CARACTERES RESTANTES SÃO DÍGITOS ====
    while(str[i] != '\0') {
        if(!isdigit((unsigned char)str[i])) {
            return false; // ==== ENCONTROU PONTO ETC ====
        }
        i++;
    }
    return true;
}


int main() {
    // ==== ARRUMANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    int valorA = 0;
    int valorB = 0;
    int resultadoC = 0;

    // ==== DECLARANDO VARIÁVEIS PARA COMPARAÇÕES ====
    char buffer[100];
    int valor = 0;

    // ==== MENSAGEM PARA O USUÁRIO ====
    printf("==== ENTRADA DE DADOS ====\n\n");

    // ==== INICIANDO VALIDAÇÕES ====

    // ---Validando valor A---
    while (true) {
        printf("Digite o valor de A: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            valorA = valor;
            printf("==== VALOR A VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");

    }
    
    // ---Validando valor B---
    while (true) {
        printf("Digite o valor de B: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            valorB = valor;
            printf("==== VALOR B VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NUMÉRICO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }
    
    // ==== MENSAGEM PARA O USUÁRIO ====
    printf("==== TODOS OS DADOS FORAM VALIDADOS! REALIZANDO CÁLCULOS! ====\n\n");

    // ==== REALIZANDO COMPARAÇÕES ====
    if(valorA == valorB) {
        resultadoC = valorA + valorB;
        printf("Os valores %d e %d são iguais, portanto, somando eles o resultado é: %d.\n\n", valorA, valorB, resultadoC);
    }
    else if(valorA != valorB) {
        resultadoC = valorA * valorB;
        printf("Os valores %d e %d são diferentes, portanto, multiplicando eles o resultado é: %d.\n\n", valorA, valorB, resultadoC);
    }
    else {
        printf("Não foi possível realizar os cálculos, verifique se algum dos valores foi devidamente digitado.\n\n");
    }

}