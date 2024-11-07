# include <iostream>
# include <windows.h>
# include <map>
# include <string>

using namespace std;

int erros = 0;
string palavra = "BANANA";
map<char, bool> chutou;

bool letra_existe(char chute){
    for (char letra : palavra){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

int main(){

    int tentativas = 6;
    bool ganhou = false; 
    bool enforcou = false;

    while (!ganhou && !enforcou){
        char chute;
        
        for (char letra : palavra){
            if (chutou[letra]){
                cout << letra << " ";
            }
            else{
                cout << "_ ";
            }
        }

        cout << endl;

        if(!letra_existe(chute)){
            erros++;
        }
        
        for(char letra : palavra){
            if(chutou[letra] == true){
                ganhou = true;
                
            }
        }

        cout << "\nChute uma letra: ";
        cin >> chute;
        chute = toupper(chute);
        chutou[chute] = true;

        if(erros >= tentativas){
            enforcou = true;
        }
    }
    
}