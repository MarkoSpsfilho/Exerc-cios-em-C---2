#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

    if(*resultado <= 0.0) {
        return 0;
    }

    return 1;

}


int main() {
    // ==== AJUSTANDOA CENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    double vel_max = 0.0;
    double vel_regegistrada = 0.0;
    double percentual = 0.0;
    char classificacaoFinal[100];

    printf("==== ENTRADA DE DADOS ====\n\n");

    while(true) {
        printf("Digite a velocidade máxima permitida: ");

        if(ler_double_valido(&vel_max)) {
            printf("==== VELOCIDADE VALIDADA! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }

    while(true) {
        printf("Digite a velocidade registrada: ");

        if(ler_double_valido(&vel_regegistrada)) {
            printf("==== VELOCIDADE VALIDADA! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS!\n\n");
    }

    printf("==== VELOCIDADES VALIDADAS =====\n\n");
    printf("==== INICIANDO CÁLCULOS ====\n\n");

    if(vel_regegistrada > vel_max) {
        percentual = ((vel_regegistrada - vel_max)/vel_max) * 100.0;

        printf("==== LIMITE DE VELOCIDADE ULTRAPASSADO! ====\n\n");

        if(percentual <= 20.0) {
            printf("==== PERCENTUAL DE ATÉ 20%% ACIMA DO LIMITE =====\n");
            printf("==== INFRAÇÃO MÉDIA ====\n");
            strcpy(classificacaoFinal, "Infração Média");
        }

        else if(percentual <= 50.0) {
            printf("==== PERCENTUAL ENTRE 20%% E 50%% ACIMA DO LIMITE =====\n");
            printf("==== INFRAÇÃO GRAVE ====\n");
            strcpy(classificacaoFinal, "Infração Grave");
        }

        else {
            printf("==== PERCENTUAL ACIMA DE 50%% DO LIMITE =====\n");
            printf("==== INFRAÇÃO GRAVÍSSIMA ====\n");
            strcpy(classificacaoFinal, "Infração Gravíssima");
        }

        if(vel_regegistrada > 120.0) {
            printf("==== ALERTA DE VELOCIDADE EXTREMAMENTE ELEVADA ====\n");
        }
    }
    else {
        printf("==== SEM INFRAÇÕES ====\n\n");
        strcpy(classificacaoFinal, "Sem Infrações");
    }

    // ==== EXIBIÇÃO DO RESULTADO FINAL ====
    printf("==== APRESENTANDO DADOS ====\n\n");
    printf("Limite da via: %.2lf\n", vel_max);
    printf("Velocidade registrada: %.2lf\n", vel_regegistrada);
    printf("Percentual excedido: %.2lf\n", percentual);
    printf("Classificação final da situação: %s\n", classificacaoFinal);

    return 0;
}