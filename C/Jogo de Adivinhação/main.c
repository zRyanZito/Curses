#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

reset(){

    int restart;

    printf("\nQuer jogar outra vez?\n");
    printf("(1) Sim (2) Nao: ");
    scanf("%d", &restart);

    switch(restart){
        case 1:
            system("cls");
            main();
            break;

        case 2:
            printf("\nOBRIGADO POR JOGAR!\n");
            break;

        default:
            printf("\nVoce precisa escolher uma opcao valida!\n");
            reset();
    }
}

main() {
    printf("          _____                                         \n");
    printf("      ,-:` \\;',`'-,                                    \n");
    printf("    .'-;_,;  ':-;_,'.                                   \n");
    printf("   /;   '/    ,  _`.-\\                                 \n");
    printf("  | '`. (`     /` ` \\`|        BEM VINDO AO            \n");
    printf("  |:.  `\\`-.   \\_   / |     JOGO DE ADIVINHACAO       \n");
    printf("  |     (   `,  .`\\ ;'|                                \n");
    printf("   \\     | .'     `-'/                                 \n");
    printf("    `.   ;/        .'                                   \n");
    printf("      `'-._____.                                        \n");
    printf("\n");

    int dificuldade;
    int tentativas;
    float pontos = 1000;

    printf("Escolha a dificuldade:\n");
    printf("(1) Facil (2) Medio (3) Dificil: ");
    scanf("%d", &dificuldade);

    srand(time(0));

    int numerorandom = rand();
    int numerosecreto = numerorandom % 100;

    int chute;

    switch(dificuldade){
        case 1:
            printf("\nVoce escolheu a dificuldade: Facil.\n");
            tentativas = 15;
            break;

        case 2:
            printf("\nVoce escolheu a dificuldade: Media.\n");
            tentativas = 8;
            break;

        case 3:
            printf("\nVoce escolheu a dificuldade: Dificil.\n");
            tentativas = 5;
            break;

        default:
            system("cls");
            printf("Escolha alguma das 3 dificuldades.\n\n");
            main();
    }

    for (int i = 1; i <= tentativas; i++){
        printf("\nTentativa %d de %d\n", i, tentativas);
        printf("Chute um numero entre 0 e 100: ");
        scanf("%d", &chute);
        system("cls");
        printf("Seu ultimo chute foi: %d\n", chute);

        if(chute < 0 || chute > 100){
            printf("\nPor favor, digite um numero valido.\n");
            i--;

            continue;
        }
        else if(chute == numerosecreto){
            system("cls");
            printf("\n");
            printf("      , ; ,   .-'''''-.   , ; ,                           \n");
            printf("      \\\\|/  .'         '.  \\|//                        \n");
            printf("       \\-;-/   ()   ()   \\-;-/                          \n");
            printf("       // ;               ; \\\\        PARABENS!         \n");
            printf("      //__; :.         .; ;__\\\\     VOCE ACERTOU!       \n");
            printf("     `-----\\'.'-.....-'.'/-----'                         \n");
            printf("            '.'.-.-,_.'.'                                 \n");
            printf("              '(  (..-'                                   \n");
            printf("                '-'                                       \n");     
            printf("\n");
            printf("Total de pontos: %.1f\n", pontos);
            break;
        }
        else if(chute < numerosecreto){
            printf("\nO numero do chute eh menor que o numero secreto.\n");
        }
        else if(chute > numerosecreto){
            printf("\nO numero do chute eh maior que o numero secreto.\n");
        }
        else{-
            printf("\nOcorreu um erro! Certifique-se de que voce digitou um numero maior que 0!");
        }

        float result = abs(chute - numerosecreto) / (float)2;
        pontos = pontos - result;
    }

    if(chute != numerosecreto && dificuldade <= 3){

        system("cls");
        printf("\n");
        printf("               ______               \n");
        printf("    GAME      /|_||_\\`.__          \n");
        printf("    OVER!    (   _    _ _\\         \n");
        printf("             =`-(_)--(_)-           \n\n");
        printf("O numero secreto era: %d\n", numerosecreto);
    }

    reset();
}