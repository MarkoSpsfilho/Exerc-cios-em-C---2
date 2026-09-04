/*

Faça um algoritmo que leia um número.
• Caso ele seja positivo, calcule o seu dobro.
• Caso ele seja negativo, calcule o seu triplo.
Ao final, apresente o resultado

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

// ==== FUNÇÃO PARA GARANTIR QUE NA VARIÁVEL NÃO HAVERÁ NENHUMA LETRA ====
// ==== VALIDA A ENTRADA DO USUÁRIO E ARMAZENA O VALOR LIDO NO PONTEIRO 'RESULTADO' ====
// ==== RETORNA 1 PARA LEITURA BEM-SUCEDIDA OU 0 SE A ENTRADA FOR INVÁLIDA ====

int ler_double_valido(double *resultado) {
    char buffer[100];

    // ==== LER A LINHA INTEIRA DE ENTRADA ====
    if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    char *endptr;
    // ==== CONVERTE TEXTO PARA DOUBLE ====
    *resultado = strtod(buffer, &endptr);

    // ==== Se endptr apontar para o início do bufffer, nada foi convertido (ex: "abc") ====
    if(endptr == buffer) {
        return 0;
    }

    // ==== IGNORA ESPAÇOS E QUEBRAS DE LINHA PENDENTES APÓS O NÚMERO ====
    while(*endptr != '\0') {
        if(!isspace((unsigned char)*endptr)) {
            // ==== ENCONTROU UM CARACTERE NÃO NUMÉRICO EXTRA (ex: 'a' em '1a')
            return 0;
        }
        endptr++;
    }
    return 1; // ==== LEITURA 100% VÁLIDA =====
}

int main() {
    // ==== ARRUMANDOA CENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEL ====
    double numeroDeEntrada = 0.0;

    // ==== PEDINDO ENTRADA PARA O USUÁRIO E FAZENDO VALIDAÇÕES ====
    printf("==== ENTRADA DE DADOS ====\n\n");

    while (true) {
        printf("Digite o valor do número: ");

        if(ler_double_valido(&numeroDeEntrada)) {
            printf("==== NÚMERO VALIDADO ====\n\n");
            break; // ==== NÚMERO VALIDADO ====
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É IGUAL À ZERO!\n\n");
        
    }

    // ==== MOSTRANDO MENSAGEM E REALIZANDO COMPARAÇÕES E CÁLCULOS ====
    printf("==== INICIANDO CÁLCULOS ====\n\n");

    if(numeroDeEntrada > 0) {
        printf("O número %.2lf é maior que zero, seu dobro é: %.2lf.\n\n", numeroDeEntrada, numeroDeEntrada*2);
    }
    else if(numeroDeEntrada < 0) {
        printf("O número %.2lf é maior que zero, seu triplo é: %.2lf.\n\n", numeroDeEntrada, numeroDeEntrada*3);
    }
    else {
        printf("Não foi possível calcular, verifique se o valor digitado é realmente um número.\n\n");
    }

    return 0;
}