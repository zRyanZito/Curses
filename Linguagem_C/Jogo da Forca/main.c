#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "forca.h"

// VARIÁVEIS GLOBAIS //
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

// FUNÇÃO DE ABERTURA DO JOGO //
void abertura() {
    printf("=======================\n");
    printf("||   JOGO DE FORCA   ||\n");
    printf("=======================\n");
}

// FUNÇÃO QUE GUARDA OS CHUTES NO ARRAY //
void chutar(){
    char chute;

    printf("\nChute uma letra: ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

// FUNÇÃO QUE ENCONTRA O CHUTE NA PALAVRA SECRETA //
int encontrou(char letra){
    int achou = 0;

    for (int j = 0; j < chutesdados; j++)
    {
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

// FUNÇÃO QUE ADICIONA UMA PALAVRA NOVA NO BANDO DE DADOS // 
void addpalavra(){
    int resposta;

    printf("\nVoce deseja adicionar uma nova palavra ao banco de dados?\n");
    printf("(1) Sim (2) Nao: ");
    scanf("%d", &resposta);

    if (resposta == 1){
        char novapalavra[TAMANHO_PALAVRA];
        printf("Digite a palavra: ");
        scanf("%s", novapalavra);

        FILE* f = fopen("../dados.txt", "r+");

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
    else if(resposta == 2){
        printf("\nOBRIGADO POR JOGAR!\n");
    }
    else{
        printf("\nVoce precisa escolher uma opcao valida!\n");
        addpalavra();
    }
}

// FUNÇÃO QUE PERGUNTA SE O USUÁRIO QUER JOGAR DE NOVO //
// void reset(){

//     int restart;

//     printf("\nQuer jogar outra vez?\n");
//     printf("(1) Sim (2) Nao: ");
//     scanf("%d", &restart);

//     switch(restart){
//         case 1:
//             system("cls");
//             main();
//             break;

//         case 2:
//             printf("\nOBRIGADO POR JOGAR!\n");
//             break;

//         default:
//             printf("\nVoce precisa escolher uma opcao valida!\n");
//             reset();
//     }
// }

// FUNÇÃO QUE DEFINE A PALAVRA SECRETA //
void definirpalavra(){
    FILE* f = fopen("../dados.txt", "r");

    if(f == 0){
        printf("Banco de dados fora do ar.\n\n");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int random = rand() % qtdpalavras;

    for (int i = 0; i <= random; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

// FUNÇÃO QUE EXIBE A FORCA NA TELA //
void mostrarforca(){
    int erros = chuteserrados();

    printf("\n");

    printf("  _______         \n");
    printf(" |/      |        \n");
    printf(" |      %c%c%c    \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c    \n", (erros >= 2 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : ' '));
    printf(" |       %c       \n", (erros >= 3 ? '|' : ' '));
    printf(" |      %c %c     \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |                \n");
    printf("_|___             \n");
    printf("\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        int achou = encontrou(palavrasecreta[i]);

        if(achou){
            printf("%c ", palavrasecreta[i]);
        }
        else{

            printf("_ ");
        }
    }
}


// FUNÇÃO QUE VERIFICA SE O USUÁRIO ACERTOU A PALAVRA // 
int ganhou(){
    for (int i = 0; i < strlen(palavrasecreta); i++){
        if (!encontrou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int chuteserrados(){
    int erros = 0;

    for (int i = 0; i < chutesdados; i++){
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        
        if(!existe){
            erros++;
        }
    }
    
    return erros;
}

// FUNÇÃO QUE LIMITA OS CHUTES QUE O USUÁRIO PODE DAR //
int perdeu(){
    return chuteserrados() >= 5;
}

// FUNÇÃO MAIN DO JOGO //
int main(){

    definirpalavra();
    abertura();

    do {

        mostrarforca();

        printf("\n");

        chutar();

    } while (!ganhou() && !perdeu());

    if(ganhou && !perdeu()){
    
        printf("\n");
        printf("     .oOOOOOOo.                                  \n");
        printf("   oO'        'Oo                                \n");
        printf("  O'  O      O  'O                               \n");
        printf(" O                O         PARABENS!            \n");
        printf(" O                O      VOCE ACERTOU A          \n");
        printf(" O  Oo,      ,oO  O      PALAVRA SECRETA         \n");
        printf("  O. 'OOOOOOOO' .O                               \n");
        printf("   Yb.        .dP                                \n");
        printf("     'YOOOOOOP'                                  \n");

    } else{

        printf("\n");
        printf("      .-''''''-.                                 \n");
        printf("    .'          '.                               \n");
        printf("   /   O      O   \\                             \n");
        printf("  :           `    :        QUE PENA!            \n");
        printf("  |                |    NAO FOI DESSA VEZ...     \n");
        printf("  :    .------.    :                             \n");
        printf("   \\  '        '  /                             \n");
        printf("    '.          .'                               \n");
        printf("      '-......-'                                 \n");

        printf("\nA PALAVRA SECRETA ERA: %s\n", palavrasecreta);

    }

    addpalavra();

}