#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// Samuel Gulart Moura - https://www.linkedin.com/in/samuel-gulart-656971216 - 27/12/2021
// Ultima alteração: 08/03

typedef struct{
    char nome[30], cpf[20], senha[20];
    int idade;
    float saldo;
}contas;

contas conta[20];

void limpaTela(void);

void imprimeMenu(void);

int verificaIdade(int x);

int validaConta(char * nome,  int idade, char * cpf);

void quantidadeDeCedulas(int valor, int *c1, int *c5, int *c10, int *c50, int *c100, int * c200);

int extrato(char * nome, char * senha, int qtdContas);

void main(void){
    int checkaConta, valor, c1, c5, c10, c50, c100, c200;
    unsigned int novaConta = 0;
    char escolha, nome[20], senha[20];
    float checkaExtrato;
    setlocale(LC_ALL, "Portuguese");

    do{
        limpaTela();
        imprimeMenu();
        escolha = getch();

        if(escolha == '1'){
            limpaTela();
            printf("  ___   _   ___   _   ___ _____ ___  ___   ");
            printf("\n / __| /_\\ |   \\ /_\\ / __|_   _| _ \\/ _ \\  ");
            printf("\n| (__ / _ \\| |) / _ \\\\__ \\ | | |   / (_) | ");
            printf("\n \\___/_/ \\_\\___/_/ \\_\\___/ |_| |_|_\\\\___/  \n\n");
            printf("Digite seu nome  ");
            scanf("%s", &conta[novaConta].nome);
            printf("Digite sua idade  ");
            scanf("%i", &conta[novaConta].idade);
            printf("Digite seu CPF  ");
            scanf("%s", &conta[novaConta].cpf);
            printf("Digite uma senha (Apenas Números): ");
            scanf("%s", &conta[novaConta].senha);
            checkaConta = validaConta(conta[novaConta].nome, conta[novaConta].idade, conta[novaConta].cpf);
            if(checkaConta == 1){
                conta[novaConta].saldo = 3001 + ( rand() % 7000 );
                novaConta++;
            }
            system("PAUSE");
            limpaTela();
        }else if(escolha == '2'){
            limpaTela();
            printf("  ___   _   ___  _   _ ___ ");
            printf("\n / __| /_\\ / _ \\| | | | __|");
            printf("\n \\__ \\/ _ \\ (_) | |_| | _| ");
            printf("\n |___/_/ \\_\\__\\_\\\\___/|___|\n\n");
            printf("Informe o valor do Saque [NOTAS DISPONIVEIS: 1$ 5$ 10$ 50$ 100$ 200$]: ");
            scanf("%d", &valor);

            quantidadeDeCedulas(valor, &c1, &c5, &c10, &c50, &c100, &c200);
            printf("\n");
            if (c200 != 0) printf("%i cédulas de 200\n", c200);
            if (c100 != 0) printf("%i cédulas de 100\n", c100);
            if (c50 != 0) printf("%i cédulas de 50\n", c50);
            if (c10 != 0) printf("%i cédulas de 10\n", c10);
            if (c5 != 0) printf("%i cédulas de 5\n", c5);
            if (c1 != 0) printf("%i cédulas de 1\n", c1);
            printf("\n");
            system("PAUSE");
            limpaTela();
        }else if(escolha == '3'){
            limpaTela();
            printf(" ____    _    _   _  ____ ___    ____  _______     __");
            printf("\n| __ )  / \\  | \\ | |/ ___/ _ \\  |  _ \\| ____\\ \\   / /");
            printf("\n|  _ \\ / _ \\ |  \\| | |  | | | | | | | |  _|  \\ \\ / / ");
            printf("\n| |_) / ___ \\| |\\  | |__| |_| | | |_| | |___  \\ V / ");
            printf("\n|____/_/   \\_\\_| \\_|\\____\\___/  |____/|_____|  \\_/  \n\n");
            for(int x = 0; x < novaConta; x++){
                printf("Cliente[%i]: %s - CPF: %s\n", x+1, conta[x].nome, conta[x].cpf);
            }
            printf("\n");
            system("PAUSE");
            limpaTela();
        }else if(escolha == '4'){
            limpaTela();
            printf(" ____    _    _   _  ____ ___    ____  _______     __");
            printf("\n| __ )  / \\  | \\ | |/ ___/ _ \\  |  _ \\| ____\\ \\   / /");
            printf("\n|  _ \\ / _ \\ |  \\| | |  | | | | | | | |  _|  \\ \\ / / ");
            printf("\n| |_) / ___ \\| |\\  | |__| |_| | | |_| | |___  \\ V / ");
            printf("\n|____/_/   \\_\\_| \\_|\\____\\___/  |____/|_____|  \\_/  \n\n");
            printf("Insira o Login: ");
            scanf("%s", &nome);
            printf("Insira a senha: ");
            scanf("%s", &senha);
            checkaExtrato = extrato(nome, senha, novaConta);
            if(checkaExtrato == 0){
                system("COLOR 0C");
                printf("\nSENHA INCORRETA OU CONTA INEXISTENTE, CANCELANDO A OPERAÇÃO!!\n\n");
            }else{
                printf("\nO extrato da sua conta bancaria é de: %.2f R$\n\n", checkaExtrato);
            }
            Sleep(3000);
            system("COLOR 07");
        }
    }while(escolha != '5');

    printf("\nATENDIMENTO ENCERRADO!\n\n");
    Sleep(2000);
    exit(0);
}

void limpaTela(void)
{
    system("@cls||clear");
}

void imprimeMenu(void){
    printf(" ____    _    _   _  ____ ___    ____  _______     __");
    printf("\n| __ )  / \\  | \\ | |/ ___/ _ \\  |  _ \\| ____\\ \\   / /");
    printf("\n|  _ \\ / _ \\ |  \\| | |  | | | | | | | |  _|  \\ \\ / / ");
    printf("\n| |_) / ___ \\| |\\  | |__| |_| | | |_| | |___  \\ V / ");
    printf("\n|____/_/   \\_\\_| \\_|\\____\\___/  |____/|_____|  \\_/  \n\n");
    printf("Seja bem vindo ao Banco DEV!\n");
    printf("escolha uma opção abaixo: \n");
    printf("\n1   Criar conta");
    printf("\n2   Saque");
    printf("\n3   Listar contas ativas");
    printf("\n4   Extrato");
    printf("\n5   Sair\n\n");
}

int verificaIdade(int x){
    if (x >= 18) return 1;
}

int validaConta(char * nome,  int idade, char * cpf){
    int x;
    x = verificaIdade(idade);
    if(x == 1){
        limpaTela();
        printf("  ___ _   _  ___ ___ ___ ___  ___  _ ");
        printf("\n / __| | | |/ __| __/ __/ __|/ _ \\| |");
        printf("\n \\__ \\ |_| | (__| _|\\__ \\__ \\ (_) |_|");
        printf("\n |___/\\___/ \\___|___|___/___/\\___/(_)\n\n");
        printf("Dados da conta: \n\n");
        printf("Nome do cliente  %s\n", nome);
        printf("Idade do cliente  %i\n", idade);
        printf("CPF do cliente  %s\n\n", cpf);
        return 1;
    }else{
        limpaTela();
        printf("  ___ ___ ___  ___  ");
        printf("\n | __| _ \\ _ \\/ _ \\ ");
        printf("\n | _||   /   / (_) |");
        printf("\n |___|_|_\\_|_\\\\___/ \n\n");
        printf("Não permitimos o cadastro de menores de idade!\n\n");
        return 0;
    }
}

void quantidadeDeCedulas(int valor, int *c1, int *c5, int *c10, int *c50, int *c100, int * c200){
    *c200 = valor /200;
    valor = valor % 200;
    *c100 = valor /100;
    valor = valor % 100;
    *c50 = valor /50;
    valor = valor % 50;
    *c10 = valor /10;
    valor = valor % 10;
    *c5 = valor /5;
    valor = valor % 5;
    *c1 = valor;
}

int extrato(char * nome, char * senha, int qtdContas){
    int retorno;

    for(int i = 0; i < qtdContas; i++){
        retorno = strcmp(conta[i].nome, nome);
        if(retorno == 0){
            retorno = strcmp(conta[i].senha, senha);
            if(retorno == 0) return conta[i].saldo;
        }
    }

    return 0;
}
