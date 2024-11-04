struct Reserva {
    char nome[50];
    char cpf[15];
    char dia[10];
    int qtdpessoas;
};

struct Reserva reservas[100];

void cabecalho();
void menuprincipal();
void fazerreserva();
void listarreserva();
void totalpessoas();