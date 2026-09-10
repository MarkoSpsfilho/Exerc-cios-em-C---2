/*

Faça um algoritmo que leia um número inteiro.
• Caso seja par, some 5 ao seu valor.
• Caso seja ímpar, some 8 ao seu valor.
Ao final, apresente o resultado da operação.

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

bool eh_inteiro_valido(const char *str) {
    // ==== STRING NULA OU VAZIA NÃO É VÁLIDA ====
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    // ==== PERMITE SINAIS POSITIVOS E NEGATIVOS ====
    if(str[0] == '-' || str[0] == '+') {
        i++;
    }
    
    // ==== SE A STRING CONTÉM SÓ SINAL, É INVÁLIDA ====
    if(str[i] == '\0') return false;

    // ==== VERIFICA SE HÁ PONTO OU OUTRO CARACTERE ====
    while(str[i] != '\0') {
        if(!isdigit((unsigned char)str[i])) {
            return false; // ==== ACHOU PONTO ====
        }
        i++;
    }
    return true;
}

int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    int numeroInteiro = 0;
    char buffer[100];
    int valor = 0;

    // ==== INICIANDO VALIDAÇÕES ====
    printf("==== ENTRADA DE DADOS ====\n\n");

    while(true) {
        printf("Digite um número inteiro: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INEIRO ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            numeroInteiro = valor;
            printf("==== NÚMERO VALIDADO ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }

    printf("==== NÚMERO VALIDADO ====\n\n");

    // ==== INICIANDO VARIFICAÇÃO PAR OU IMPAR ====
    if(numeroInteiro % 2 == 0) {
        printf("==== O NÚMERO %d É PAR! ====\n", numeroInteiro);
        printf("==== ADICIONANDO +5 AO VALOR ====\n");
        printf("==== O NÚMERO %d É PAR, ADICIONANDO +5 AO SEU VALOR, O RESULTADO É: %d ====\n\n", numeroInteiro, numeroInteiro + 5);
    }
    else if(numeroInteiro % 2 != 0) {
        printf("==== O NÚMERO %d É ÍMPAR! ====\n", numeroInteiro);
        printf("==== ADICIONANDO +8 AO VALOR ====\n");
        printf("==== O NÚMERO %d É ÍMPAR, ADICIONANDO +8 AO SEU VALOR, O RESULTADO É: %d ====\n\n", numeroInteiro, numeroInteiro + 8);
    }
    else {
        printf("==== NÃO FOI POSSÍVEL FAZER A VERIFICAÇÃO, VEJA SE O VALOR DIGITADO É REALMENTE UM NÚMERO ====");
    }
    return 0;
}