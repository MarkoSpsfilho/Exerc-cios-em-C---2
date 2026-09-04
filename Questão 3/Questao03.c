/*

Faça um algoritmo que receba um número inteiro qualquer e informe se ele é par ou ímpar. 

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// ==== FUNÇAÕ QUE VALIDA SE A FUNÇÃO É UM NÚMERO INTEIRO VÁLIDO ====
bool eh_inteiro_valido(const char *str) {
    // ==== STRING NULA OU VAZIA NÃO É VÁLIDA ====
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    // ==== PERMITE SINAIS POSITIVOS E NEGATIVOS ===
    if(str[0] == '-' || str[0] == '+') {
        i++;
    }

    // ==== SE A STRING SÓ CONTINHA O SINAL, É INVÁLIDÁ ====
    if(str[i] == '\0') return false;
    
    // ==== VERIFICA SE TODOS OS CARACTERES RESTANTES SÃO DÍGITOS (SEM PONTO OU VÍRGULA) ====
    while(str[i] != '\0') {
        if(!isdigit((unsigned char)str[i])) {
            return false; // ==== ENCONTROU PONTO ('.'), VÍRGULA (','), LETRA, ETC. =====
        }
        i++;
    }
    return true;
}

int main() {
    // ==== ARRUMANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS PRINCIPAIS ====
    int numeroInteiro;

    // ==== VARIÁVEIS ESPECÍFICAS PARA CASOS DE INT ====
    char buffer[100];
    int valor = 0;

    // ==== MENSAGEM DE INÍCIO DE PROCESSO ====
    printf("==== ENTRADA DE DADOS ====\n\n");

    // ==== PEDINDO PARA O USUÁRIO O NÚMERO E JÁ APLICANDO A VALIDAÇÃO ====
    while (true) {

        printf("Digite um número INTEIRO qualquer: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO BUFFER ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO =====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer); // ==== CONVERTE STRING PARA INT ====
            numeroInteiro = valor;
            printf("==== NÚMERO VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }

    printf("==== INICIANDO VERIFICAÇÃO E CLASSIFICAÇÃO SE É PAR OU ÍMPAR ====\n\n");

    if(numeroInteiro % 2 == 0) {
        printf("O número %d é par!\n", numeroInteiro);
    }
    else {
        printf("O número %d é ímpar!\n", numeroInteiro);
    }
    
}