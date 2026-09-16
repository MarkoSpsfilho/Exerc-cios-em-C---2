#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main() {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    int codigoPrato = 0;

    // ==== DECLARANDO VARIÁVEIS ESPECÍFICAS PARA INT ====
    char buffer[100];
    int valor = 0;

    printf("====== CARDÁPIO ======\n");
    printf("CÓDIGO |\t PRATO\t\t |\t VALOR\n");
    printf("1 \tHambúrguer com Fritas \tR$ 28,00\n 2 \tFilé de frango grelhado \tR$ 32,00\n 3 \tLasanha à bolonhesa \tR$ 35,00\n 4 \tFilé de peixe com arroz \tR$ 42,00\n 5 \tSalada especial \tR$ 25,00\n");
    printf("======================\n\n");

    while(true) {
        printf("Digite o código do prato desejado: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro de leitura.\n\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer);
            if(valor == 1 || valor == 2 || valor == 3 || valor == 4 || valor == 5) {
                printf("==== CÓDIGO VALIDADO ====\n\n");
                codigoPrato = valor;
                break;
            }
            printf("==== ERRO! DIGITE UMA DAS OPÇÕES DO CARDÁPIO ====\n\n");
        }
    }

    switch (codigoPrato) {
    case 1:
        printf("==== HAMBÚRGUER COM FRITAS SELECIONADO ====\n");
        printf("==== VALOR: R$ 28,00 ====\n");
        break;

    case 2:
        printf("==== FILÉ DE FRANGO GRELHADO SELECIONADO ====\n");
        printf("==== VALOR: R$ 32,00 ====\n");
        break;

    case 3: 
        printf("==== LASANHA à BOLANHESA SELECIONADO ====\n");
        printf("==== VALOR: R$ 35,00 ====\n");
        break;

    case 4:
        printf("==== FILÉ DE PEIXE COM ARROZ SELECIONADO ====\n");
        printf("==== VALOR: R$ 42,00 ====\n");
        break;

    case 5:
        printf("==== SALADA ESPECIAL SELECIONADO ====\n");
        printf("==== VALOR: R$ 25,00 ====\n");
        break;
    
    default:
        printf("==== OPÇÃO INVÁLIDA ====\n\n");
        break;
    }

    return 0;
}