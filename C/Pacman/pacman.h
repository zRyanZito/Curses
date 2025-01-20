# ifndef _PACMAN_H_
# define _PACMAN_H_

int acabou();
void mover(char direcao);
int ehvalido(char direcao);
void fantasma();
int moverfantasma(int xatual, int yatual, int* xdestino, int* ydestino);

# endif
