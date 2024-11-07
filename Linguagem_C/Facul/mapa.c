# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <string.h>
# include "mapa.h"

int sair = 0;
int numeroreserva = 0;

void cabecalho(){
    printf("=====================================\n");
    printf("                               _     \n");
    printf("                              / )    \n");
    printf("                        |||| / /     \n");
    printf("     SEJA               ||||/ /      \n");
    printf("     BEM VINDO AO       \\__(_/      \n");
    printf("     NOSSO MENU          ||//        \n");
    printf("     DE RESERVAS!        ||/         \n");
    printf("                         ||          \n");
    printf("                        (||          \n");
    printf("                         \"\"        \n");
    printf("\n=====================================\n");
}

void menuprincipal(){
    int opcao;

    printf("\n            MENU DE OPCOES           \n");
    printf("\n 1 - Fazer Reserva.\n 2 - Listar Reservas.\n 3 - Total de Pessoas Por Dia.\n 4 - Sair.\n");
    printf("\n=====================================\n");
    printf("\nDigite o numero da opcao desejada: ");
    scanf("%d", &opcao);

    system("cls");

    switch (opcao){
        case 1:
            fazerreserva();
            break;
        case 2:
            listarreserva();
            break;
        case 3:
            totalpessoas();
            break;
        case 4:
            printf("Programa encerrado.\n");
            sair = 1;
    }
}

void fazerreserva(){
    printf("Digite seu nome: ");
    scanf("%s", reservas[numeroreserva].nome);

    printf("\nDigite seu CPF: ");
    scanf("%s", reservas[numeroreserva].cpf);

    escolherdia();

    printf("\nDigite a quantidade de pessoas que deseja reservar: ");
    scanf("%d", &reservas[numeroreserva].qtdpessoas);

    numeroreserva++;

    printf("\n=====================================\n");
    printf("\n    Reserva efetuada com sucesso!    \n");
    printf("\n=====================================\n");

    menuprincipal();
}

void escolherdia(){
        int diasemana;
    printf("\n=====================================\n");
    printf("\n           DIAS DISPONIVEIS          \n");
    printf("\n 1 - Quinta\n 2 - Sexta\n 3 - Sabado\n 4 - Domingo\n");
    printf("\n=====================================\n");
    printf("\nEscolha um dia para a reserva: ");
    scanf("%d", &diasemana);

    switch (diasemana)
    {
    case 1:
        strcpy(reservas[numeroreserva].dia, "Quinta");
        break;
    case 2:
        strcpy(reservas[numeroreserva].dia, "Sexta");
        break;
    case 3:
        strcpy(reservas[numeroreserva].dia, "Sabado");
        break;
    case 4:
        strcpy(reservas[numeroreserva].dia, "Domingo");
        break;
    default:
        printf("Escolha uma opcao valida!\n");
        escolherdia();
        break;
    }
}

void listarreserva(){
    if(numeroreserva > 0){
        printf("=====================================\n");
        for(int i = 0; i < numeroreserva; i++){
            printf("\nNome: %s\nCPF: %s\nDia: %s\nNumero de Pessoas: %d\n", reservas[i].nome, reservas[i].cpf, reservas[i].dia, reservas[i].qtdpessoas);
            printf("\n=====================================\n");
        }
    } else {
        printf("=====================================\n");
        printf("\n  Nao existem reservas no sistema   \n");
        printf("\n=====================================\n");
    }

    menuprincipal();
}

void totalpessoas(){
    int pessoasquinta = 0;
    int pessoassexta = 0;
    int pessoassabado = 0;
    int pessoasdomingo = 0;

    for(int i = 0; i < numeroreserva; i++){
        if(strcmp(reservas[i].dia, "Quinta") == 0){
            pessoasquinta += reservas[i].qtdpessoas;
        }
        else if(strcmp(reservas[i].dia, "Sexta") == 0){
            pessoassexta += reservas[i].qtdpessoas;
        }
        else if(strcmp(reservas[i].dia, "Sabado") == 0){
            pessoassabado += reservas[i].qtdpessoas;
        }
        else if(strcmp(reservas[i].dia, "Domingo") == 0){
            pessoasdomingo += reservas[i].qtdpessoas;
        }
    }

    if(numeroreserva > 0){
        printf("=====================================\n");
        printf("\n   TOTAL DE PESSOAS RESERVADAS     \n");
        printf("\nQuinta: %d\n", pessoasquinta);
        printf("Sexta: %d\n", pessoassexta);
        printf("Sabado: %d\n", pessoassabado);
        printf("Domingo: %d\n", pessoasdomingo);
        printf("\n=====================================\n");
    } else{
        printf("=====================================\n");
        printf("\n  Nao existem reservas no sistema   \n");
        printf("\n=====================================\n");
    }


    menuprincipal();
}

int main(){
    system("cls");

    do{
        cabecalho();
        menuprincipal();
    } while (sair == 0);
} 