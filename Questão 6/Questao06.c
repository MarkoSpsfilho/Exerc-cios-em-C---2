/*

Escreva um algoritmo que leia dois valores booleanos (lógicos) e determine se ambos são
VERDADEIROS ou se ambos são FALSOS. 

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>

// ==== VERIFICAÇÃO DE INTEIRO ====
bool eh_inteiro_valido(const char *str) {
    // ==== STRING NULA OU VAZIA NÃO É VÁLIDA ====
    if(str == NULL || *str == '\0') return false;

    int i = 0;

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
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS DE PEGADA DE ENTRADA ====
    int valor01 = 0;
    int valor02 = 0;

    //==== DECLARANDO VARIÁVEIS PARA COMPARAÇÕES ====
    char buffer[100];
    int valor = 0;

    // ==== PEDINDO ENTRADA ====
    printf("==== ENTRADA DE DADOS ====\n\n");

    // ---Validando valor 01---
    while (true) {
        printf("Digite o valor 01 (SOMENTE 0 OU 1): ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO E 0 OU 1 ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            if (valor == 1 || valor == 0) {
                valor01 = valor;
                printf("==== VALOR VALIDADO ====\n\n");
                break;
            }
        }
        printf("==== VALOR INVÁLIDO! DIGITE SOMENTE 1 OU 0 ====\n\n");
    }

    // ---Validando valor 02---
    while(true) {
        printf("Digite o valor 02: (SOMENTE 0 OU 1): ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO E 0 OU 1 ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            if(valor == 1 || valor == 0) {
                valor02 = valor;
                printf("==== VALOR VALIDADO ====\n\n");
                break;
            }
        }
        printf("==== VALOR INVÁLIDO! DIGITE SOMENTE 1 OU 0 ====\n\n");
    }

    // ==== VARIÁVEIS DE CONVERSÃO ====
    bool valorValidado01 = valor01;
    bool valorValidado02 = valor02;

    // ==== FAZENDO VERIFICAÇÕES ====
    printf("==== VALORES VALIDADOS! INICIANDO COMPARAÇÕES ====\n\n");

    if(valorValidado01 == 1 && valorValidado02 == 1) {
        printf("==== OS DOIS VALORES SÃO VERDADEIROS! ====\n\n");
    }
    else if(valorValidado01 == 0 && valorValidado02 == 0) {
        printf("==== OS DOIS VALORES SÃO FALSOS! ====\n\n");
    }
    else if((valorValidado01 == 1 && valorValidado02 == 0) || (valorValidado01 == 0 && valorValidado02 == 1)) {
        if(valorValidado01 == 1 && valorValidado02 == 0) {
            printf("==== O VALOR 01 É VERDADEIRO E O VALOR 02 É FALSO! ====\n\n");
        }
        if(valorValidado01 == 0 && valorValidado02 == 1) {
            printf("==== O VALOR 01 É FALSO E O VALOR 02 É VERDADEIRO! ====\n\n");
        }
    }
    else {
        printf("==== NÃO FOI POSSÍVEL REALIZAR A VERIFICAÇÃO, VEJA SE ALGUM DOS VALORES É VÁLIDO ====\n\n");
    }
    return 0;
}