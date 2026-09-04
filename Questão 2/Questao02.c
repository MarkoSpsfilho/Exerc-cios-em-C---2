/*

Faça um algoritmo que leia o nome, o sexo e o estado civil de uma pessoa. Caso o sexo seja F e o
estado civil seja CASADA, solicite também o tempo de casamento, em anos. 

*/

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// ==== FUNÇÃO QUE VALIDA SE UMA STRING É UM NÚMERO INTEIRO VÁLIDO ====
bool eh_inteiro_valido(const char *str) {
    if(str == NULL || *str == '\0') return false;

    int i = 0;

    // ==== PERMITE APENAS POSITIVOS ====
    if(str[0] == '+') {
        i++;
    }

    // ==== SE A STRING SÓ CONTINHA O SINAL, É INVÁLIDA ====
    if(str[i] == '\0') return false;

    // ==== VERIFICA SE TODOS OS CARACTERES RESTANTES SÃO DÍGITOS (SEM PONTO OU VÍRGULA) ====
    while (str[i] != '\0') {
        if(!isdigit((unsigned char)str[i])) {
            return false; // ==== ENCONTROU PONTO ('.'), VÍRGULA (','), LETRA, ETC. =====
        }
        i++;
    }
    return true;

}


int main(void) {
    // ==== AJUSTANDO ACENTOS ====
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ==== DECLARANDO VARIÁVEIS ====
    char nome[100];
    int sexo = 0;
    int estadoCivil = 0;
    int tempoDeCasamentoAnos = 0;
    int tempoDeCasamentoMeses = 0;

    // ==== VARIÁVEL ESPECÍFICA PARA CASOS DE INT ====
    char buffer[100];
    int valor = 0;

    // ==== ENTRADA DE DADOS E VALIDAÇÕES ====
    printf("==== ENTRADA DE DADOS ====\n\n");


    // ==== VALIDANDO NOME ====
    while (true) {
        // ==== DECLARANDO VARIÁVEL ESPECÍFICA PARA O CASO ====
        int tem_numero;

        printf("Digite seu nome (seu números): ");
        fgets(nome, sizeof(nome), stdin);

        // ==== REMOVE A QUEBRA DE LINHA ('\n') capturada pelo fgets, se existir ====
        nome[strcspn(nome, "\n")] = '\0';

        tem_numero = 0; // ==== RESET DA FLAG DE VALIDAÇÃO ====

        // ==== PERCORRE CADA CARACTERE DA STRING PARA VERIFICAR SE HÁ ALGUN DÍGITO ====
        for(int i = 0; nome[i] != '\0'; i++) {
            if(isdigit((unsigned char)nome[i])) {
                tem_numero = 1;
                break; // ==== SE ENCONTROU AO MENOS UM NÚMERO, PARA O FOR ====
            }
        }

        // ==== SE ENCONTROL ALGUM NÚMERO, EXIBE MENSAGEM E O LOOP CONTINUA ====

        if(tem_numero) {
            printf("ERRO! A ENTRADA CONTÉM NÚMEROS! TENTE NOVAMENTE.\n\n");
        }
        else {
            // ==== SE FOR VÁLIDA, SAI DO LAÇO WHILE ====
            printf("==== NOME VALIDADO COM SUCESSO! ====\n\n");
            break;
        }

    }

    //==== VALIDANDO SEXO ====
    while (true) {
        // ==== PEGANDO VARIÁVEL ESPECÍFICA PARA O CASO ====
        printf("Digite seu sexo (ex: 1 para FEMININO e 2 para MASCULINO): ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO fgets ====
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer); //==== CONVERTE STRING PARA INT ==== 

            if(valor == 1 || valor == 2) {
                sexo = valor;
                printf("==== SEXO VALIDADO COM SUCESSO! ====\n\n");
                break; // ==== ENCERRA O LOOP POIS A ENTRADA FOI VÁLIDA ====
            }
        } 
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É DIFERENTE DAS OPÇÕES REQUISITADAS\n\n");
    }

    // ==== VALIDANDO ESTADO CIVIL ====
    while (true) {
        // ==== PEGANDO VARIÁVEL ESPECÍFICA PARA O CASO ====
        printf("==== DECLARANDO ESTADO CIVIL ====\n\n");
        printf("1. Solteiro(a)\n2. Casado(a)\n3. Separado(a)\n4. Divorciado(a)\n5. Viúvo(a)\n\n");
        printf("Digite seu estado civil: ");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura.\n\n");
            continue;
        }

        // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO fgets ====
        buffer[strcspn(buffer, "\n")] = '\0';

        // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
        if(eh_inteiro_valido(buffer)) {
            valor = atoi(buffer); // ==== CONVERTE STRING PARA INT ====

            if(valor == 1 || valor == 2 || valor == 3 || valor == 4 || valor == 5) {
               estadoCivil = valor;
               printf("==== ESTADO CIVIL VALIDADO COM SUCESSO!\n\n");
               break; 
            }
        }
        printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É DIFERENTE DAS OPÇÕES REQUISITADAS\n\n");
    }

    // ==== CRIANDO VERIFICAÇÃO REQUISITADA ====
    /*
    
    Caso o sexo seja F e o estado civil seja CASADA, solicite também o tempo de casamento, em anos
    
    */
    
    if(sexo == 1 && estadoCivil == 2) {
        printf("==== FELICIDADES! DIGITE O TEMPO DE CASAMENTO EM ANOS! ====\n\n");

        // ==== CRIANDO VALIDAÇÃO ====
        while (true) {
            // ==== PEGANDO VARIÁVEL ESPECÍFICA PARA O CASO ====
            printf("Digite a quantidade de anos: ");

            if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro na leitura.\n\n");
                continue;
            }

            // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO fgets ====
            buffer[strcspn(buffer, "\n")] = '\0';

            // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
            if(eh_inteiro_valido(buffer)) {
                valor = atoi(buffer);
                tempoDeCasamentoAnos = valor;
                printf("==== QUANTIDADE DE ANOS VALIDADA! ====\n\n");
                break;
            }
            printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É DIFERENTE DAS OPÇÕES REQUISITADAS\n\n");
        }

        printf("==== GOSTARIA DE INFORMAR A QUANTIDADE DE MESES? ====\n\n");
        printf("1 para Sim, 0 para Não\n\n");

        while(true) {

            printf("Digite sua escolha: ");

            if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro na leitura. Assumindo que deseja pular opção.\n\n");
                break;
            }
            else {
                // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO fgets ====
                buffer[strcspn(buffer, "\n")] = '\0';

                // ==== VALIDA SE A ENTRADA É ESTRITAMENTE UM INTEIRO ====
                if(eh_inteiro_valido(buffer)) {
                    valor = atoi(buffer);
                    
                    if(valor == 0 || valor == 1) {
                        if(valor == 0) {
                            printf("==== TUDO BEM! ====\n\n");
                            break; // ==== Parando a operação ====
                        }
                        if(valor == 1) {
                            while(true) {
                                int valor02 = 0;

                                printf("Digite a quantidade de meses: ");

                                if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
                                    printf("Erro na leitura.\n\n");
                                    continue;
                                }

                                // ==== REMOVE O '\n' DO FINAL CAPTURADO PELO fgets ====
                                buffer[strcspn(buffer, "\n")] = '\0';

                                if(eh_inteiro_valido(buffer)) {
                                    valor02 = atoi(buffer);
                                    tempoDeCasamentoMeses = valor02;

                                    printf("==== QUANTIDADE DE MESES VALIDADA! ====\n\n");

                                    break;
                                }
                                printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É DIFERENTE DAS OPÇÕES REQUISITADAS\n\n");
                            }
                            break;
                        }
                    }
                }
                printf("ERRO! O VALOR DIGITADO NÃO É UM NÚMERO OU É DIFERENTE DAS OPÇÕES REQUISITADAS\n\n");
            } 
        }
       
    }

    // ==== DECLARANDO VARIÁVEIS NECESSÁRIAS PARA A VALIDAÇÃO DA MENSAGEM À SER MOSTRADA ====
    bool tem_tempoDeCasamentoAnos = (tempoDeCasamentoAnos != 0);
    bool tem_tempoDeCasamentoMeses = (tempoDeCasamentoMeses != 0);

    if(tem_tempoDeCasamentoAnos && tem_tempoDeCasamentoMeses) {
        printf("Você é casada há %d anos e %d meses.\n", tempoDeCasamentoAnos, tempoDeCasamentoMeses);
    }
    else if(tem_tempoDeCasamentoAnos && !tem_tempoDeCasamentoMeses) {
        printf("Você é casada há %d anos.\n", tempoDeCasamentoAnos);
    }
    else if(tem_tempoDeCasamentoMeses && !tem_tempoDeCasamentoAnos) {
        printf("Você é casada há %d meses.\n", tempoDeCasamentoMeses);
    }
    else if(!tem_tempoDeCasamentoAnos && !tem_tempoDeCasamentoMeses) {
        printf("Você é casada há menos de 1 mês! Felicidades!\n");
    }
    else {
        printf("Não foi possível verificar a quantidade de tempo exata, mas felicidades!\n");
    }

    return 0;
      
}