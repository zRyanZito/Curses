# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "mapa.h"

void copiarmapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocarmapa(destino);

    for (int i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andar(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){

    char personagem = m->matriz[xorigem][yorigem];

    m->matriz[xdestino][ydestino] = personagem;

    m->matriz[xorigem][yorigem] = '.';
}

int vazio(MAPA* m, int x, int y){
    return m->matriz[x][y] == '.';
}

int ehparede(MAPA* m, int x, int y){
    return m->matriz[x][y] == '|' || m->matriz[x][y] == '-';
}

int ehpersonagem(MAPA* m, char personagem, int x, int y){
    return m->matriz[x][y] == personagem;
}

int podeandar(MAPA* m, char personagem, int x, int y){
    return limitemapa(m, x, y) && !ehparede(m, x, y) && !ehpersonagem(m, personagem, x, y);
}

int limitemapa(MAPA* m, int x, int y){
    if(x >= m->linhas){
        return 0;
    }
    if(y >= m->colunas){
        return 0;
    }

    return 1;
}

int encontramapa(MAPA* m, POSICAO* p, char c){
    for (int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            if (m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
}

void alocarmapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void lermapa(MAPA* m){
    FILE* f = fopen("./mapa.txt", "r");

    fscanf(f,"%d %d", &(m->linhas), &(m->colunas));

    alocarmapa(m);
    
    if(f == 0){
        printf("Erro ao ler arquivo\n");
        exit(1);
    }
    
    for (int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void liberarmapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}