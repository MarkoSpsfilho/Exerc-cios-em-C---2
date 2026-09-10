#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


bool eh_inteiro_valido(const char *str) {
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    if(str[0] == '-') return false;

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

    if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    char *endptr;

    *resultado = strtod(buffer, &endptr);

    if(endptr == buffer) {
        return 0;
    }

    while(*endptr != '\0') {
        if(!isspace((unsigned char)*endptr)) {
            return 0;
        }
        endptr++;
    }
    
    if(*resultado < 0.0) {
        return 0;
    }

    return 1;
}

int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    int identificador_aluno = 0;
    double nota01 = 0.0;
    double nota02 = 0.0;
    double nota03 = 0.0;
    char conceito = '\0';
    char situacao_final[100] = "";

    // ==== VARIÁVEIS ESPECÍFICAS PARA int identificador_aluno =====
    char buffer[100];

    printf("==== ENTRADA DE DADOS ====\n\n");

    while(true) {
        printf("Digite seu número de identificação: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if(eh_inteiro_valido(buffer)) {
            identificador_aluno = atoi(buffer);
            printf("==== NÚMERO DE IDENTIFICAÇÃO VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }

    while(true) {
        printf("Digite o valor da nota 01: ");

        if(ler_double_valido(&nota01)) {
            printf("==== NOTA 01 VALIDADA ====\n\n");
            break;
        }

        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É MENOR QUE ZERO!\n\n");
    }

    while(true) {
        printf("Digite o valor da nota 02: ");

        if(ler_double_valido(&nota02)) {
            printf("==== NOTA 02 VALIDADA ====\n\n");
            break;
        }

        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É MENOR QUE ZERO!\n\n");
    }

    while(true) {
        printf("Digite o valor da nota 03: ");

        if(ler_double_valido(&nota03)) {
            printf("==== NOTA 03 VALIDADA ====\n\n");
            break;
        }

        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É MENOR QUE ZERO!\n\n");
    }

    // ==== MENSAGEM PARA O USUÁRIO E REALIZANDO CÁLCULOS ====
    printf("==== DADOS VALIDADOS! ====\n\n");
    printf("==== INICIANDO CÁLCULOS ====\n\n");

    // ==== MÉDIA DOS EXERCÍCIOS ====
    printf("==== CALCULANDO MÉDIA DOS EXERCÍCIOS ====\n\n");

    double media_exercicios = (nota01 + nota02 + nota03)/3.0;
    printf("A sua média dos exercícios foi: %.2lf.\n\n", media_exercicios);

    printf("==== CALCULANDO MÉDIA DE APROVEITAMENTO ====\n\n");
    double media_aproveitamento = (nota01 + (nota02 * 2.0) + (nota03 * 3.0) + media_exercicios)/7.0;

    if(media_aproveitamento >= 90.0) {
        printf("Sua média de aproveitamento foi de %.2lf, maior ou igual à 90, logo você ficou no conceito A.\n\n", media_aproveitamento);
        conceito = 'A';
    }
    else if(media_aproveitamento >= 75.0 && media_aproveitamento < 90.0) {
        printf("Sua média de aproveitamento foi de %.2lf, entre 75 e 90, logo você ficou no conceito B.\n\n", media_aproveitamento);
        conceito = 'B';
    }
    else if(media_aproveitamento >= 60.0 && media_aproveitamento < 75.0) {
        printf("Sua média de aproveitamento foi de %.2lf, entre 60 e 75, logo você ficou no conceito C.\n\n", media_aproveitamento);
        conceito = 'C';
    }
    else if(media_aproveitamento >= 40.0 && media_aproveitamento < 60.0) {
        printf("Sua média de aproveitamento foi de %.2lf, entre 40 e 60, logo você ficou no conceito D.\n\n", media_aproveitamento);
        conceito = 'D';
    }
    else if(media_aproveitamento < 40.0) {
        printf("Sua média de aproveitamento foi de %.2lf, menor que 40, logo você ficou no conceito E.\n\n", media_aproveitamento);
        conceito = 'E';
    }
    else {
        printf("Não foi possível realizar os cálculos, verifique se todos os dados inseridos são válidos.");
    }

    switch(conceito) {
        case 'A':
        case 'B':
        case 'C':
            strcpy(situacao_final, "APROVADO");
            break;
        
        case 'D':
        case 'E':
            strcpy(situacao_final, "REPROVADO");
            break;

        default:
            strcpy(situacao_final, "INDETERMINADA");
            break;
    }

    // ==== EXIBIÇÃO DO RESULTADO FINAL ====
    printf("==== RESUMO DO ALUNO ====\n\n");
    printf("Identificação do aluno: %d\n", identificador_aluno);
    printf("Notas: %.2lf | %.2lf | %.2lf\n", nota01, nota02, nota03);
    printf("Média de Aproveitamento: %.2lf\n", media_aproveitamento);
    printf("Condeito Obtido: %c\n", conceito);
    printf("Situação Final: %s\n", situacao_final);
    printf("=========================\n\n");

    return 0;
}