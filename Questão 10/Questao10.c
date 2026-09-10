/*

O IMC — Índice de Massa Corporal — é um indicador utilizado para avaliar a condição de peso de uma
pessoa adulta.
A fórmula para o cálculo é:
IMC = peso / altura²
Faça um algoritmo que leia o peso e a altura de uma pessoa, calcule seu IMC e apresente sua
condição de acordo com a tabela:
IMC Condição
Menor que 18,5 Abaixo do peso
Entre 18,5 e 25 Peso normal
IMC Condição
Entre 25 e 30 Acima do peso
Acima de 30 Obeso


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>

int ler_double_valido(double *resultado) {
    char buffer[100];

    // ==== LER A LINHA INTEIRA DE ENTRADA ====
    if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    char *endptr;

    // ==== CONVERTE O TEXTO PARA DOUBLE ====
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

    return 1;
}


int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    double peso;
    double altura;

    printf("==== ENTRADA DE DADOS ====\n\n");
    while(true) {
        printf("Digite seu peso (ex: 65.6 para 65,6 kg): ");

        if(ler_double_valido(&peso)) {
            printf("==== PESO VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É IGUAL À ZERO!\n\n");
    }

    while(true) {
        printf("Digite sua altura (ex: 1.80 para 1,80m): ");

        if(ler_double_valido(&altura)) {
            printf("==== ALTURA VALIDADA! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É IGUAL À ZERO!\n\n");
    }

    printf("==== INICIANDO CÁLCULOS ====\n\n");

    // ==== VARIÁVEL JÁ COM OS VALORES RECEBIDOS ====
    double IMC = (peso / pow(altura, 2));

    if(IMC < 18.5) {
        printf("Você está com IMC de %.2lf kg, e está abaixo do peso.", IMC);
    }
    else if(IMC >= 18.5 || IMC <= 25) {
        printf("Você está com IMC de %.2lf kg, e está com o peso normal.", IMC);
    }
    else if(IMC >= 25 || IMC <= 30) {
        printf("Você está com IMC de %.2lf kg, e está acima do peso.", IMC);
    }
    else if(IMC > 30) {
        printf("Você está com IMC de %.2lf kg, e está obeso.", IMC);
    }
    else {
        printf("Não foi possível realizar o cálculo, verifique se todas as entradas correspondem ao que foi requisitado.");
    }
    return 0;
}