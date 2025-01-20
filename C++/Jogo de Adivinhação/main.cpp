# include <cstdlib>
# include <iostream>
# include <windows.h>
# include <ctime>

using namespace std;

int tentativas;
int pontos = 1000;

void msginicial(){
    cout << "          _____                                         " << endl;
    cout << "      ,-:` \\;',`'-,                                    " << endl;
    cout << "    .'-;_,;  ':-;_,'.                                   " << endl;
    cout << "   /;   '/    ,  _`.-\\                                 " << endl;
    cout << "  | '`. (`     /` ` \\`|        BEM VINDO AO            " << endl;
    cout << "  |:.  `\\`-.   \\_   / |     JOGO DE ADIVINHACAO       " << endl;
    cout << "  |     (   `,  .`\\ ;'|                                " << endl;
    cout << "   \\     | .'     `-'/                                 " << endl;
    cout << "    `.   ;/        .'                                   " << endl;
    cout << "      `'-._____.                                        " << endl;
}

void escolherdificuldade(){
    int dificuldade;

    cout << "\nEscolha uma dificuldade\n(1) Facil (2) Media (3) Dificil: ";
    cin >> dificuldade;

    if(dificuldade == 1){
        cout << "\nVoce escolheu a dificuldade: Facil" << endl;
        tentativas = 15;
    }
    else if(dificuldade == 2){
        cout << "\nVoce escolheu a dificuldade: Media" << endl;
        tentativas = 10;
    }
    else if(dificuldade == 3){
        cout << "\nVoce escolheu a dificuldade: Dificil" << endl;
        tentativas = 5;
    }
    else {
        cout << "\nEscolha uma opcao valida!" << endl;
        escolherdificuldade();
    }
}

void gameloop(int numerosecreto){
    int chute;

    for (int i = 1; i <= tentativas; i++){
        cout << "\nTentativa " << i << " de " << tentativas << endl;
        cout << "Chute um numero entre 1 e 100: ";
        cin >> chute;

        if(chute < 1 || chute > 100){
            i--;
            cout << "\nDIGITE APENAS NUMEROS DE 1 A 100!\n";
            continue;
        }

        if(chute > numerosecreto){
            system("cls");
            cout << "\nO numero chutado (" << chute << ") eh MAIOR que o numero secreto!\n";
        }
        else if(chute < numerosecreto){
            system("cls");
            cout << "\nO numero chutado (" << chute << ") eh MENOR que o numero secreto!\n";
        }
        else{
            system("cls");
            cout << "\n";
            cout << "      , ; ,   .-'''''-.   , ; ,                           \n";
            cout << "      \\\\|/  .'         '.  \\|//                        \n";
            cout << "       \\-;-/   ()   ()   \\-;-/                          \n";
            cout << "       // ;               ; \\\\        PARABENS!         \n";
            cout << "      //__; :.         .; ;__\\\\     VOCE ACERTOU!       \n";
            cout << "     `-----\\'.'-.....-'.'/-----'                         \n";
            cout << "            '.'.-.-,_.'.'                                 \n";
            cout << "              '(  (..-'                                   \n";
            cout << "                '-'                                       \n\n"; 
            cout << "O numero secreto era: " << numerosecreto << endl;
            cout << "Seu total de pontos foi: " << pontos << endl;

            break;
        }

        float result = abs(chute - numerosecreto) / (float)2;
        pontos = pontos - result;
    }

    if(chute != numerosecreto){
        system("cls");
        cout << "\n";
        cout << "               ______               \n";
        cout << "    GAME      /|_||_\\`.__          \n";
        cout << "    OVER!    (   _    _ _\\         \n";
        cout << "             =`-(_)--(_)-           \n\n";
        cout << "O numero secreto era: " << numerosecreto << endl;
        cout << "Seu total de pontos foi: " << pontos << endl;
    }
}

int restart(){
    int reset;

    cout << "\nDeseja jogar outra vez?\n(1) Sim (2) Nao: ";
    cin >> reset;

    if(reset == 1){
        return true;
    }
    else if(reset == 2){
        return false;
    }
    else{
        cout << "\nEscolha uma opcao valida!" << endl;
        restart();
    }
}

int main(){
    srand(time(NULL));
    int numerosecreto = rand() % 101;

    system("cls");
    msginicial();
    escolherdificuldade();
    gameloop(numerosecreto);

    if(restart()){
        main();
    }
    else{
        cout << "\nObrigado por jogar...";
    }
}