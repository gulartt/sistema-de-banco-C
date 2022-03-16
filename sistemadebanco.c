#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

// Samuel Gulart Moura - https://www.linkedin.com/in/samuel-gulart-656971216 - 27/12/2021
// Ultima alteração: 16/03

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

int loga(char * nome, char * senha, int qtdContas);

void main(void){
    int checkaConta, valor, c1, c5, c10, c50, c100, c200, logado;
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
            gets(conta[novaConta].nome);
            setbuf(stdin, NULL);
            printf("Digite sua idade  ");
            scanf("%d", &conta[novaConta].idade);
            setbuf(stdin, NULL);
            printf("Digite seu CPF  ");
            gets(conta[novaConta].cpf);
            setbuf(stdin, NULL);
            printf("Digite uma senha: ");
            gets(conta[novaConta].senha);
            setbuf(stdin, NULL);
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
            setbuf(stdin, NULL);
            printf("Insira seu login [nome da conta]: ");
            gets(nome);
            setbuf(stdin, NULL);
            printf("Agora insira sua senha: ");
            gets(senha);
            setbuf(stdin, NULL);
            logado = loga(nome, senha, novaConta);
            if(logado != -1){
                limpaTela();
                printf("  ___   _   ___  _   _ ___ ");
                printf("\n / __| /_\\ / _ \\| | | | __|");
                printf("\n \\__ \\/ _ \\ (_) | |_| | _| ");
                printf("\n |___/_/ \\_\\__\\_\\\\___/|___|\n\n");
                printf("seu saldo é de: %.2f\n", conta[logado].saldo);
                printf("Informe o valor do Saque [NOTAS DISPONIVEIS: 1$ 5$ 10$ 50$ 100$ 200$]: ");
                scanf("%d", &valor);
                setbuf(stdin, NULL);
                if(valor > conta[logado].saldo){
                    system("COLOR 0C");
                    printf("\nVALOR INSUFICIENTE, CANCELANDO A OPERAÇÃO\n\n");
                    Sleep(3000);
                    system("COLOR 07");
                }else{
                    quantidadeDeCedulas(valor, &c1, &c5, &c10, &c50, &c100, &c200);
                    printf("\n");
                    if (c200 != 0) printf("%i cédulas de 200\n", c200);
                    if (c100 != 0) printf("%i cédulas de 100\n", c100);
                    if (c50 != 0) printf("%i cédulas de 50\n", c50);
                    if (c10 != 0) printf("%i cédulas de 10\n", c10);
                    if (c5 != 0) printf("%i cédulas de 5\n", c5);
                    if (c1 != 0) printf("%i cédulas de 1\n", c1);
                    conta[logado].saldo = conta[logado].saldo - valor;
                    printf("\n");
                    system("PAUSE");
                }
            }
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
            printf("Insira o Login [nome da conta]: ");
            setbuf(stdin, NULL);
            gets(nome);
            setbuf(stdin, NULL);
            printf("Insira a senha: ");
            gets(senha);
            setbuf(stdin, NULL);
            logado = loga(nome, senha, novaConta);
            if(logado == -1){
                system("COLOR 0C");
                printf("\nSENHA INCORRETA OU CONTA INEXISTENTE, CANCELANDO A OPERAÇÃO!!\n\n");
            }else{
                printf("\nO extrato da sua conta bancaria é de: %.2f R$\n\n", conta[logado].saldo);
            }
            system("PAUSE");
            system("COLOR 07");
        }
    }while(escolha != '5');

    printf("\nATENDIMENTO ENCERRADO!\n\n");
    Sleep(2000);
    exit(0);
}

// Limpa a tela

void limpaTela(void)
{
    system("@cls||clear");
}

// Imprime o Menu

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

// Verifica se o cliente é maior de idade

int verificaIdade(int x){
    if (x >= 18) return 1;
}

// Valida e Cria a Conta

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

// Faz a contagem de cédulas pro saque

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

// Confere se o login e a senha enviados batem com alguma dascontas registradas

int loga(char * nome, char * senha, int qtdContas){
    int valor;
    for(int i = 0; i < qtdContas; ++i){
        valor = strcmp(conta[i].nome, nome);
        if(valor == 0){
            valor = strcmp(conta[i].senha, senha);
            if(valor == 0) return i;
        }
    }

    return -1;
}
