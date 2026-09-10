/*

Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um algoritmo que calcule seu
peso ideal utilizando as seguintes fórmulas:
• Para homens:
peso ideal = (72,7 × altura) - 58
• Para mulheres:
peso ideal = (62,1 × altura) - 44,7 

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

bool eh_inteiro_valido(const char *str){
    
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

int ler_double_valido(double *resultado) {
    char buffer[100];

    // ==== LER A LINHA INTEIRA DE ENTRADA ====
    if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    char *endptr;

    // ==== CONVERTE TEXTO PARA DOUBLE ====
    *resultado = strtod(buffer, &endptr);

    // ==== SE endptr APONTAR PARA O INÍCIO DO BUFFER, NADA FOI CONVERTIDO ====
    if(endptr == buffer) {
        return 0;
    }

    // ==== IGNORA ESPAÇOS E QUEBRAS DE LINHA PENDENTES APÓS O NÚMERO ====
     while(*endptr != '\0') {
        if(!isspace((unsigned char)*endptr)) {
            // ==== ENCONTROU UM CARACTERE NÃO NUMÉRICO ====
            return 0;
        }
        endptr++;
     }

     if(*resultado == 0.0) {
        return 0;
     }
     
     return 1; // ====LEITURA 100% VÁLIDA ====
}


int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    double altura = 0.0;
    int sexo = 0;
    double pesoIdeal = 0.0;

    // ==== VARIÁVEIS PARA O INT ====
    char buffer[100];
    int valor = 0;

    printf("==== ENTRADA DE DADOS ====\n\n");
    while(true) {
        printf("Digite seu sexo (1 para Feminino, 2 para Masculino): ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }
        
        buffer[strcspn(buffer, "\n")] = '\0';

        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            if(valor == 1 || valor == 2) {
                sexo = valor;
                printf("==== SEXO VALIDADO! ====\n\n");
                break;
            }
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS! DIGITE APENAS UMA DAS DUAS OPÇÕES.\n\n");
    }

    while(true) {
        printf("Digite o valor da sua altura: ");

        if(ler_double_valido(&altura)) {
            printf("==== ALTURA VALIDADA! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É IGUAL À ZERO!\n\n");
    }

    printf("==== INICIANDO CÁLCULOS ====\n\n");

    if(sexo == 1) {
        pesoIdeal = (62.1 * altura) - 44.7;
        printf("Como você é do sexo feminino, seu peso ideal é de: %.2lf kg", pesoIdeal);
    }
    else if(sexo == 2) {
        pesoIdeal = (72.7 * altura) - 58;
        printf("Como você é do sexo masculino, seu peso ideal é de: %.2lf kg", pesoIdeal);
    }
    else {
        printf("==== Não foi possível fazer a verificação, veja se todos os dados inseridos estão corretos! ====\n\n");
    }
    return 0;
}