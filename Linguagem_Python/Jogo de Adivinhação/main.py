import random
import os

tentativas = 0
numerosecreto = random.randint(1, 100)
pontos = 1000

def msginicial():
    print("          _____                                         ")
    print("      ,-:` \\;',`'-,                                    ")
    print("    .'-;_,;  ':-;_,'.                                   ")
    print("   /;   '/    ,  _`.-\\                                 ")
    print("  | '`. (`     /` ` \\`|        BEM VINDO AO            ")
    print("  |:.  `\\`-.   \\_   / |     JOGO DE ADIVINHAÇÃO       ")
    print("  |     (   `,  .`\\ ;'|                                ")
    print("   \\     | .'     `-'/                                 ")
    print("    `.   ;/        .'                                   ")
    print("      `'-._____.                                      \n")

def escolherdificuldade():
    global tentativas
    dificuldade = str(input("Escolha a dificuldade:\n(1) Fácil (2) Médio (3) Difícil: "))

    if dificuldade == "1":
        tentativas = 15
        print("\nDificuldade escolhida: Fácil\nVocê tem {} tentativas.".format(tentativas))
    elif dificuldade == "2":
        tentativas = 8
        print("\nDificuldade escolhida: Média\nVocê tem {} tentativas.".format(tentativas))
    elif dificuldade == "3":
        tentativas = 3
        print("\nDificuldade escolhida: Díficil\nVocê tem {} tentativas.".format(tentativas))
    else:
        print("\nDIGITE UMA OPÇÃO VÁLIDA!\n")
        escolherdificuldade()

def gameloop():
    global tentativas
    global pontos

    for i in range(1, tentativas + 1):
        print("\nTentativa {} de {}".format(i, tentativas))
        chute = int(input("Chute um número entre 0 a 100: "))

        if chute < 1 or chute > 100:
            print("Digite um número válido!")
            continue

        if chute < numerosecreto:
            os.system('cls')
            print("\nO número chutado ({}) é MENOR que o número secreto!".format(chute))
        elif chute > numerosecreto:
            os.system('cls')
            print("\nO número chutado ({}) é MAIOR que o número secreto!".format(chute))
        else:
            os.system('cls')
            print("\n")
            print("      , ; ,   .-'''''-.   , ; ,                           ");
            print("      \\\\|/  .'         '.  \\|//                        ");
            print("       \\-;-/   ()   ()   \\-;-/                          ");
            print("       // ;               ; \\\\        PARABENS!         ");
            print("      //__; :.         .; ;__\\\\     VOCE ACERTOU!       ");
            print("     `-----\\'.'-.....-'.'/-----'                         ");
            print("            '.'.-.-,_.'.'                                 ");
            print("              '(  (..-'                                   ");
            print("                '-'                                     \n"); 
            print("O número secreto era: {}".format(numerosecreto))
            print("Seu total de pontos foi: {}\n".format(pontos))
            break

        resultado = abs(chute - numerosecreto) / 2.0
        pontos = pontos - resultado

    if chute != numerosecreto:
        os.system('cls')
        print("               ______               ");
        print("    GAME      /|_||_\\`.__          ");
        print("    OVER!    (   _    _ _\\         ");
        print("             =`-(_)--(_)-         \n");
        print("O número secreto era: {}".format(numerosecreto))
        print("Seu total de pontos foi: {}\n".format(pontos))

def restart():
    reset = str(input("Quer jogar outra vez?\n(1) Sim (2) Não: "))
    
    if reset == "1":
        os.system('cls')
        main()
    elif reset == "2":
        print("\nOBRIGADO POR JOGAR!\n")
    else:
        print("\nESCOLHA UMA OPÇÃO VÁLIDA!\n")
        restart()

def main():

    os.system('cls')
    msginicial()
    escolherdificuldade()
    gameloop()
    restart()

main()