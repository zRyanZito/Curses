// MAIN.h
#ifndef MAIN_H
#define MAIN_H

#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

extern char chute;
extern int erros;
extern int tentativas;
extern bool enforcou;
extern string palavra;
extern map<char, bool> chutou;
extern vector<char> chutes_dados;

void imprime_cabecalho();
bool letra_existe(char chute);
bool ganhou();
void imprime_forca();
void imprime_chutes();
void fim_de_jogo();
void salvar_arquivo(vector<string> nova_lista);
void addpalavra();
vector<string> ler_arquivo();
void sortear_palavra();
void verifica_chutes();

#endif // MAIN_H
