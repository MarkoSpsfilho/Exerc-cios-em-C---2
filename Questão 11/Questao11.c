/*

Elabore um algoritmo que calcule o valor a ser pago por um produto, considerando o preço normal da
etiqueta e a condição de pagamento escolhida.
Utilize os códigos abaixo:
Código Condição de pagamento
1 À vista em dinheiro ou cheque: 10% de desconto
2 À vista no cartão de crédito: 15% de desconto
3 Em duas parcelas: preço normal, sem juros
4 Em duas parcelas: acréscimo de 10% sobre o preço normal
O algoritmo deve ler:
• o preço do produto;
• o código da condição de pagamento;
e apresentar o valor final a ser pago.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

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

    if(*resultado <= 0.0) {
        return 0;
     }

    return 1;
}


int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    double precoProduto = 0.0;
    int entradaEscolhaFormaPagamento = 0;
    double valorFinal = 0.0;

    // ==== VARIÁVEIS ESPECÍFICAS PARA INT ====
    char buffer[100];
    int valor = 0;

    printf("==== ENTRADA DE DADOS ====\n\n");

    while(true) {
        printf("Digite o preço do produto (ex: 11.99 para R$ 11,99): ");

        if(ler_double_valido(&precoProduto)) {
            printf("==== VALOR VALIDADO! ====\n\n");
            break;
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É IGUAL À ZERO!\n\n");
    }

    while(true) {
        printf("Escolha uma das opções:\n 1. Pagar À vista em dinheiro ou cheque.\n 2. Pagar à vista no cartão de crédito.\n 3. Pagar em duas parcelas (Preço normal, sem juros).\n 4. Pagar em duas parcelas (Acréscimo de 10% sobre o preço normal).\n Digite sua escolha:\t");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            if(valor >= 1 && valor <= 4) {
                printf("==== ESCOLHA VALIDADA! ====\n\n");
                entradaEscolhaFormaPagamento = valor;
                break;
            }
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO INTEIRO OU POSSUI CARACTERES DIFERENTES DE NÚMEROS! DIGITE APENAS UMA DAS DUAS OPÇÕES.\n\n");
    }

    switch (entradaEscolhaFormaPagamento) {
    case 1:
        printf("==== PAGAMENTO À VISTA EM DINHEIRO OU CHEQUE SELECIONADO ====\n\n");
        valorFinal = precoProduto - (precoProduto * (10.0/100.0));
        printf("O valor final à pagar com 10%% de desconto é: R$ %.2lf.", valorFinal);
        break;
    
    case 2: 
        printf("==== PAGAMENTO À VISTA NO CARTÃO DE CRÉDITO SELECIONADO ====\n\n");
        printf("==== 15%% DE DESCONTO ADICIONADO ====\n\n");
        valorFinal = precoProduto - (precoProduto * (15.0/100.0));
        printf("O valor final à pagar com 15%% de desconto é: R$ %.2lf.", valorFinal);
        break;
    
    case 3:
        printf("==== PAGAMENTO EM DUAS PARCELAS SELECIONADO ====\n\n");
        printf("==== PREÇO NORMAL, SEM JUROS ====\n\n");
        valorFinal = precoProduto;
        printf("O valor final à pagar é: R$ %.2lf.", valorFinal);
        break;

    case 4:
        printf("==== PAGAMENTO EM DUAS PARCELAS SELECIONADO ====\n\n");
        printf("==== ACRÉCIMO DE 10%% SOBRE O PREÇO NORMAL ====\n\n");
        valorFinal = precoProduto + (precoProduto * (10.0/100.0));
        printf("O valor final à pagar com acrécimo de 10%% é: R$ %.2lf.", valorFinal);
        break;
    
    default:
        break;
    }

    return 0;
}