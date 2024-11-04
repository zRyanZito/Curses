# ifndef _MAPA_H_
# define _MAPA_H_

# define PACMAN '@'
# define FANTASMA 'F'
# define PAREDE_VERTICAL '|'
# define PAREDE_HORIZONTAL '-'
# define VAZIO '.'
# define CIMA 'W'
# define BAIXO 'S'
# define ESQUERDA 'A'
# define DIREITA 'D'
# define PILULA 'P'

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int encontramapa(MAPA* m, POSICAO* p, char c);
int limitemapa(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
int vazio(MAPA* m, int x, int y);
void andar(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiarmapa(MAPA* destino, MAPA* origem);
void lermapa(MAPA* m);
void liberarmapa(MAPA* m);
void alocarmapa(MAPA* m);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);

# endif