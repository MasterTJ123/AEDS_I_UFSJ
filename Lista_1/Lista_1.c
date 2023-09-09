#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void menu_principal();
void menu_cliente();
void menu_jogo();
void menu_venda();
void comando_invalido();

char comando_menu_principal, comando_menu_cliente, enter, nome_cliente[30], email_cliente[50], cep_cliente[9];
char nome_jogo_cadastro[30], preco_jogo[30], nome_jogo_compra[30];
long long int cpf_cliente;
long long int cartao_cliente;
int lancamento_jogo;

void main(){
    setlocale(LC_ALL,"Portuguese");
    menu_principal();
}

//Primeiro menu do programa
void menu_principal(){
    printf("-----------------------------\n  Bem-vindo à Gamesiirados  \n-----------------------------\n\n");
    printf("1- Cliente\n");
    printf("2- Jogo\n");
    printf("3- Venda\n");
    printf("4- Sair\n\n");
    printf("Selecione uma opção:");
    comando_menu_principal = getchar();
    fflush(stdin);
    if(comando_menu_principal == 49){
        system("cls");
        menu_cliente();
    } else if(comando_menu_principal == 50){
        system("cls");
        menu_jogo();
    } else if(comando_menu_principal == 51){
        system("cls");
        menu_venda();
    } else if(comando_menu_principal == 52){
        system("cls");
        printf("Fim do Programa! Até outra hora! :)\n\n");
        system("pause");
    } else {
        system("cls");
        comando_invalido();
    }
}

//Submenu para a opção cliente
void menu_cliente(){
    printf("-----------------------------\n           Cliente           \n-----------------------------\n\n");
    printf("1- Cadastrar\n");
    printf("2- Visualizar\n");
    printf("3- Voltar\n\n");
    printf("Selecione uma opção:");
    comando_menu_cliente = getchar();
    fflush(stdin);
    if(comando_menu_cliente == 49){
        printf("\n\nInsira o nome completo do cliente:");
        scanf(" %[^\n]%*c", &nome_cliente);
        printf("\nInsira o CPF do cliente:");
        scanf("%lld", &cpf_cliente);
        printf("\nInsira o e-mail do cliente:");
        scanf("%s", &email_cliente);
        printf("\nCadastro realizado com sucesso!\n\n");
        fflush(stdin);
        system("pause");
        system("cls");
        menu_cliente();
    } else if(comando_menu_cliente == 50){
        printf("\n\nNome completo do Cliente:%s", nome_cliente);
        printf("\nCPF do cliente:%lld", cpf_cliente);
        printf("\nE-mail do cliente:%s\n\n", email_cliente);
        system("pause");
        system("cls");
        menu_cliente();
    } else if(comando_menu_cliente == 51){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}


//Submenu para a opção jogo
void menu_jogo(){
    printf("-----------------------------\n            Jogo         \n-----------------------------\n\n");
    printf("1- Cadastrar\n");
    printf("2- Visualizar\n");
    printf("3- Voltar\n\n");
    printf("Selecione uma opção:");
    comando_menu_cliente = getchar();
    fflush(stdin);
    if(comando_menu_cliente == 49){
        printf("\n\nInsira o nome do jogo:");
        scanf(" %[^\n]%*c", &nome_jogo_cadastro);
        printf("\nInsira o ano de lançamento do jogo:");
        scanf("%d", &lancamento_jogo);
        printf("\nInsira o preço do jogo:");
        scanf("%s", &preco_jogo);
        printf("\nCadastro realizado com sucesso!\n\n");
        fflush(stdin);
        system("pause");
        system("cls");
        menu_jogo();
    } else if(comando_menu_cliente == 50){
        printf("\n\nNome do jogo:%s", nome_jogo_cadastro);
        printf("\nAno de lançamento do jogo:%d", lancamento_jogo);
        printf("\nPreço do jogo:%s\n\n", preco_jogo);
        system("pause");
        system("cls");
        menu_jogo();
    } else if(comando_menu_cliente == 51){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}

//Submenu para a opção venda
void menu_venda(){
    printf("-----------------------------\n            Venda         \n-----------------------------\n\n");
    printf("1- Comprar\n");
    printf("2- Ver compra\n");
    printf("3- Voltar\n\n");
    printf("Selecione uma opção:");
    comando_menu_cliente = getchar();
    fflush(stdin);
    if(comando_menu_cliente == 49){
        printf("\n\nInsira o nome do jogo:");
        scanf(" %[^\n]%*c", &nome_jogo_compra);
        printf("\nInsira o número do seu cartão:");
        scanf("%lld", &cartao_cliente);
        printf("\nInsira o seu CEP:");
        scanf("%s", &cep_cliente);
        printf("\nCadastro realizado com sucesso!\n\n");
        fflush(stdin);
        system("pause");
        system("cls");
        menu_venda();
    } else if(comando_menu_cliente == 50){
        printf("\n\nNome do jogo:%s", nome_jogo_compra);
        printf("\nNúmero do seu cartão:%lld", cartao_cliente);
        printf("\nSeu CEP:%s\n\n", cep_cliente);
        system("pause");
        system("cls");
        menu_venda();
    } else if(comando_menu_cliente == 51){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}

//Mensagem de erro caso o usuário insira um comando inválido (vale apenas para a movimentação entre os menus)
void comando_invalido(){
    fflush(stdin);
    printf("Comando inválido!\n\n");
    system("pause");
    system("cls");
    menu_principal();
}
