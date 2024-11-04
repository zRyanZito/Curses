# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <time.h>
# include "pacman.h"
# include <windows.h>
# include "mapa.h"
# include "ui.h"

MAPA m;
POSICAO pacman;
int tempilula = 0;

// FUNÇÃO QUE MOVE O FANTASMA ALEATORIAMENTE //
int moverfantasma(int xatual, int yatual, int* xdestino, int* ydestino){
    int direcao[4][2] = {
        {xatual, yatual +1,},
        {xatual +1, yatual},
        {xatual, yatual -1},
        {xatual -1, yatual}
    };

    srand(time(0));

    for (int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, direcao[posicao][0], direcao[posicao][1]) && !ehpersonagem(&m, PILULA, direcao[posicao][0], direcao[posicao][1])){
            *xdestino = direcao[posicao][0];
            *ydestino = direcao[posicao][1];

            return 1;
        }
    }

    return 0;
}

// FUNÇÃO QUE VERIFICA SE O FANTASMA PODE ANDAR //
void fantasma(){
    MAPA copia;

    copiarmapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++){

        for (int j = 0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){

                int xdestino;
                int ydestino;
                int encontrou = moverfantasma(i, j, &xdestino, &ydestino);

                if(encontrou){
                    andar(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberarmapa(&copia);
}

// FUNÇÃO QUE ACABA O JOGO QUANDO O PACMAN MORRE //
int acabou(){
    POSICAO pos;

    int pacmanvivo = encontramapa(&m, &pos, PACMAN);

    return !pacmanvivo;
}

// FUNÇÃO QUE VALIDA A DIREÇÃO DO PACMAN //
int ehvalido(char direcao){
    return direcao == CIMA || direcao == BAIXO || direcao == ESQUERDA || direcao == DIREITA;
}

// FUNÇÃO QUE MOVIMENTA O PACMAN E VERIFICA A ENTRADA DO USUÁRIO //
void mover(char direcao){

    int proximox = pacman.x;
    int proximoy = pacman.y;

    if(!ehvalido(direcao)){
        return;
    }

    switch(direcao){
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if(!podeandar(&m, FANTASMA, proximox, proximoy)){
        return;
    }

    if(ehpersonagem(&m, PILULA, proximox, proximoy)){
        tempilula = 1;
    }

    andar(&m, pacman.x, pacman.y, proximox, proximoy);

    pacman.x = proximox;
    pacman.y = proximoy; 

}

void explodepilula(){
    explodepilula2(pacman.x, pacman.y, 0, 1, 3);
    explodepilula2(pacman.x, pacman.y, 0, -1, 3);
    explodepilula2(pacman.x, pacman.y, 1, 0, 3);
    explodepilula2(pacman.x, pacman.y, -1, 0, 3);
}

void explodepilula2(int x, int y, int somax, int somay, int qtd){

    int novox = x + somax;
    int novoy = y + somay;

    if(qtd == 0) return;
    if(!limitemapa(&m, novox, novoy)) return;
    if(ehparede(&m, novox, novoy)) return;

    m.matriz[novox][novoy] = '.';
    explodepilula2(novox, novoy, somax, somay, qtd-1);
}

int main(){

    lermapa(&m);
    encontramapa(&m, &pacman, PACMAN);

    do{

        system("cls");
        imprimirmapa(&m);
        printf("Tem Pilula: %s\n", (tempilula ? "SIM" : "NAO"));
        char comando;
        scanf(" %c", &comando);
        comando = toupper(comando);
        mover(comando);

        if(comando == 'B' && tempilula == 1){
            explodepilula(pacman.x, pacman.y, 3);
            tempilula = 0;
        }
        
        fantasma();

    } while(!acabou());

        system("cls");
        printf("\n");
        printf("              .-.          \n");
        printf("    GAME     | OO|        \n");
        printf("    OVER!    |   |        \n");
        printf("             '^^^'        \n\n");

    liberarmapa(&m);
}
