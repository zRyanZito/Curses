#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

reset(){
    int restart;

    printf("\nQuer consultar a tabuada de outro numero?\n");
    printf("(1) Sim (2) Nao:");
    scanf("%d", &restart);

    switch(restart){
        case 1:
            system("cls");
            main();
            break;
        case 2:
            printf("\nOk! Volte sempre que precisar!\n");
            break;
        default:
            printf("\nPor favor, escolha uma das duas opcoes\n");
            reset();
            break;
    }
}

main(){

    int numero;
    printf("=================================\n");
    printf("   WEB TABUADA 2024 ATUALIZADA   \n");
    printf("=================================\n\n");

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if(numero <= 1000000){
        printf("\nAqui esta, a tabuada do %d!\n\n", numero);
        for (int i = 1; i <= 10; i++){
            int resultado = numero * i;
            printf("     %d x %d = %d    \n", numero, i, resultado);
        }
    }
    else{
        system("cls");
        printf("Suportamos apenas ate o numero 1.000.000\n\n");
        main();
    }

    reset();
}