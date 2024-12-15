# include "main.hpp"
# include <iostream>
# include <windows.h>
# include <map>
# include <vector>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <cctype>

using namespace std;

char chute;
int erros = 0;
int tentativas = 4;
bool enforcou = false;
string palavra;
map<char, bool> chutou;
vector<char> chutes_dados;

void imprime_cabecalho(){
    cout << "=======================" << endl;
    cout << "||   JOGO DE FORCA   ||" << endl;
    cout << "=======================\n" << endl;
}

bool letra_existe(char chute){
    for (char letra : palavra){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool ganhou(){
    for (char letra : palavra){
        if (!chutou[letra]){
            return false;
        }
    }
    return true;
}

void imprime_forca(){
    for (char letra : palavra){
        if (chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }

    cout << endl;
}

void imprime_chutes(){
    cout << "\nTentativas restantes: " << tentativas - erros << endl;
    cout << "\nChutes dados: ";

    for (char letra : chutes_dados){
        cout << letra << " ";
    }
    cout << endl;
}

void fim_de_jogo(){
    cout << "Fim de jogo!" << endl;

    if(ganhou()){
        int resposta;

        cout << "\nParabens, voce ganhou, a palavra secreta era: " << palavra << endl;

        cout << "\nDeseja adicionar uma nova palavra no banco de palavras?\n(1) Sim (2) Nao: ";
        cin >> resposta;
        cout << endl;

        switch(resposta){
            case 1:
                addpalavra();
                break;
            case 2:
                cout << "Obrigado por jogar!" << endl;
                break;
            default:
                cout << "Escolha uma opcao valida!\n" << endl;
                fim_de_jogo();
                break;
        }
    }
    else{
        cout << "\nQue pena, nao foi dessa vez! A palavra era: " << palavra << endl;
    }
}

void salvar_arquivo(vector<string> nova_lista){
    ofstream arquivo;

    arquivo.open("../dados.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;

        for (size_t i = 0; i < nova_lista.size(); i++){
            arquivo << nova_lista[i] << endl;
        }

        arquivo.close();
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras!" << endl;
        exit(0);
    }
}

void addpalavra(){
    string palavra_nova;

    cout << "Digite uma nova palavra: ";
    cin >> palavra_nova;

    for (size_t i = 0; i < palavra_nova.size(); i++){
        palavra_nova[i] = toupper(palavra_nova[i]);
    }
    
    vector<string> lista_palavras = ler_arquivo();

    lista_palavras.push_back(palavra_nova);

    salvar_arquivo(lista_palavras);
}

void verifica_chutes(){
    for (size_t i = 0; i < chutes_dados.size(); i++){
        if(chutes_dados[i - 1] == chute){
            cout << "Voce ja chutou essa letra!\n" << endl;
            chutes_dados.pop_back();
            break;
        }
    }
}

vector<string> ler_arquivo(){
    ifstream arquivo;

    arquivo.open("../dados.txt");

    if(arquivo.is_open()){
        int qtd_palavras;
        arquivo >> qtd_palavras;

        vector<string> palavras_arquivo;

        for (int i = 0; i < qtd_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;

            palavras_arquivo.push_back(palavra_lida);
        }

        arquivo.close();

        return palavras_arquivo;
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras!" << endl;
        exit(0);
    }
}

void sortear_palavra(){
    vector<string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice = rand() % palavras.size();
    palavra = palavras[indice];
}

int main(){
    imprime_cabecalho();

    ler_arquivo();

    sortear_palavra();

    while (!ganhou() && !enforcou){
        imprime_forca();

        imprime_chutes();
        
        cout << "\nChute uma letra: ";
        cin >> chute;
        chute = toupper(chute);
        chutes_dados.push_back(chute);
        chutou[chute] = true;        

        system("cls");

        verifica_chutes();

        if (!letra_existe(chute)){
            erros++;
        }

        if (erros == tentativas){
            enforcou = true;
        }
    }

    fim_de_jogo();
}