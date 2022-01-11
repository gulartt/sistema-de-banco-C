#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Samuel Gulart Moura - https://www.linkedin.com/in/samuel-gulart-656971216 - 27/12/2021

void limpaTela()
{
    system("@cls||clear");
}

int validaConta(int idade){
    if(idade < 18){
        return 0;
    }else{
        return 1;
    }
}

void quantidadeDeCedulas(int valor, int *c1, int *c5, int *c10, int *c50, int *c100, int * c500){
    *c500 = valor /500;
    valor = valor % 500;
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

main(){
    setlocale(LC_ALL, "Portuguese");

    char escolha, cpf[20], nome[30];
    int senha, idade, contaCheck, valor, c1, c5, c10, c50, c100, c500;

    printf("================== BANCO DEV ===================\n\n");
    printf("Seja bem vindo ao Banco DEV!\n");
    printf("escolha uma opção abaixo: ");
    printf("\n1 - Criar Conta");
    printf("\n2 - Saque");
    printf("\n3 - Sair\n\n>> ");

    scanf("%d", &escolha);

	if(escolha == 1){
    limpaTela();
    printf("================== CADASTRO DE CONTAS ===================\n\n");
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%i", &idade);
    printf("Digite seu CPF (Apenas Números): ");
    scanf("%s", &cpf);
    printf("Digite uma senha (Apenas Números): ");
    scanf("%i", &senha);
    contaCheck = validaConta(idade);

    if(contaCheck != 1){
        limpaTela();
        printf("================== CADASTRO DE CONTAS ===================\n\n");
        printf("Não foi possivel criar a conta pois você é menor de idade!!\n\n");
        printf("=========================================================\n\n");
        Sleep(2000);
        limpaTela();
        main();
    }else{
        limpaTela();
        printf("================== SUA CONTA FOI CRIADA COM SUCESSO ===================\n\n");
        printf("=========================== Dados da conta! ===========================\n\n");
        printf("Nome do cliente: %s\n", nome);
        printf("Idade do cliente: %i\n", idade);
        printf("CPF do cliente: %s\n\n", cpf);
        printf("=======================================================================\n\n");
        system("Pause");
        limpaTela();
        main();
        }
	}else if(escolha == 2){
        limpaTela();
        printf("========================= SAQUE =========================\n\n");
        printf("Informe o valor do Saque [NOTAS DISPONIVEIS: 1$ 5$ 10$ 50$ 100$ 500$]: ");
        scanf("%d", &valor);

        quantidadeDeCedulas(valor, &c1, &c5, &c10, &c50, &c100, &c500);
        if (c500 != 0) printf("%i cédulas de 500\n", c500);
        if (c100 != 0) printf("%i cédulas de 100\n", c100);
        if (c50 != 0) printf("%i cédulas de 50\n", c50);
        if (c10 != 0) printf("%i cédulas de 10\n", c10);
        if (c5 != 0) printf("%i cédulas de 5\n", c5);
        if (c1 != 0) printf("%i cédulas de 1\n", c1);
        printf("\n=========================================================\n\n");
        system("PAUSE");
        limpaTela();
        main();
	}else if(escolha == 3){
	    printf("\n\nATENDIMENTO ENCERRADO!\n\n");
	    Sleep(2000);
	    exit(0);
	}else{
        printf("\n\nOPÇÃO INVALIDA!!!!!\n\n");
        Sleep(1000);
        limpaTela();
        main();
	}
}
