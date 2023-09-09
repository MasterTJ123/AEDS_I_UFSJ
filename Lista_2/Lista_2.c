#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void menu_principal();
void menu_cliente();
void cadastra_cliente();
void imprime_cliente();
void procura_cliente();
void exclui_cliente();
void menu_jogo();
void cadastra_jogo();
void imprime_jogo();
void procura_jogo();
void exclui_jogo();
void menu_venda();
void cadastra_venda();
void imprime_venda();
void procura_venda();
void exclui_venda();
void comando_invalido();

struct estrutura_cliente {
    char nome_cliente[30], email_cliente[50], cpf_cliente[30];
};

struct estrutura_jogo {
    char nome_jogo[30], lancamento_jogo[10], preco_jogo[30];
};

struct estrutura_venda {
    char nome_jogo[30], cartao_cliente[30], cep_cliente[30];
};

char comando_menu_principal, comando_submenu;
int contador_submenu_cliente_cadastro = 0, contador_submenu_jogo_cadastro = 0, contador_submenu_venda_cadastro = 0, cliente_cadastrado = 0, jogo_cadastrado = 0, venda_cadastrada = 0;
struct estrutura_cliente cliente[1000];
struct estrutura_jogo jogo[1000];
struct estrutura_venda venda[1000];

int main(){
    setlocale(LC_ALL,"Portuguese");
    for(int i = 0; i <= 999; i++){
        strcpy(cliente[i].nome_cliente, "NULL");
        strcpy(cliente[i].email_cliente, "NULL");
        strcpy(cliente[i].cpf_cliente, "NULL");
    }
    for(int i = 0; i <= 999; i++){
        strcpy(jogo[i].nome_jogo, "NULL");
        strcpy(jogo[i].lancamento_jogo, "NULL");
        strcpy(jogo[i].preco_jogo, "NULL");
    }
    for(int i = 0; i <= 999; i++){
        strcpy(venda[i].nome_jogo, "NULL");
        strcpy(venda[i].cartao_cliente, "NULL");
        strcpy(venda[i].cep_cliente, "NULL");
    }
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
    scanf("%c", &comando_menu_principal);
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
    printf("3- Procurar\n");
    printf("4- Excluir\n");
    printf("5- Voltar\n\n");
    printf("Selecione uma opção:");
    scanf("%c", &comando_submenu);
    fflush(stdin);
    if(comando_submenu == 49){
        cadastra_cliente();
    } else if(comando_submenu == 50){
        imprime_cliente();
    } else if(comando_submenu == 51){
        procura_cliente();
    } else if(comando_submenu == 52){
        exclui_cliente();
    } else if(comando_submenu == 53){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}

void cadastra_cliente(){
    if (contador_submenu_cliente_cadastro == 1000){
        system("cls");
        printf("Limite de cadastros atingido! Impossível cadastrar outro cliente!\n\n");
        system("pause");
        system("cls");
        menu_cliente();
    } else {
        printf("\n\nInsira o nome completo do cliente:");
        scanf(" %[^\n]%*c", &cliente[contador_submenu_cliente_cadastro].nome_cliente);
        fflush(stdin);
        printf("\nInsira o CPF do cliente:");
        scanf("%s", &cliente[contador_submenu_cliente_cadastro].cpf_cliente);
        fflush(stdin);
        printf("\nInsira o e-mail do cliente:");
        scanf("%s", &cliente[contador_submenu_cliente_cadastro].email_cliente);
        fflush(stdin);
        printf("\nCadastro realizado com sucesso!\n\n");
        contador_submenu_cliente_cadastro++;
        cliente_cadastrado = 1;
        fflush(stdin);
        system("pause");
        system("cls");
        menu_cliente();
    }
}

void imprime_cliente(){
    if(cliente_cadastrado == 1){
        system("cls");
        for(int i = 0; i < contador_submenu_cliente_cadastro; i++){
            printf("\n\nNome completo do Cliente:%s", cliente[i].nome_cliente);
            printf("\nCPF do cliente:%s", cliente[i].cpf_cliente);
            printf("\nE-mail do cliente:%s\n\n", cliente[i].email_cliente);
        }
    } else {
        system("cls");
        printf("Não existem clientes cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_cliente();
}

void procura_cliente(){
    char nome_cliente_procura[30];
    int cliente_localizado = 0;
    system("cls");
    if(cliente_cadastrado == 1){
        printf("Informe o nome do cliente que você deseja visualizar a ficha cadastrada: ");
        scanf(" %[^\n]%*c", &nome_cliente_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_cliente_cadastro; i++){
            if(strcmp(nome_cliente_procura, cliente[i].nome_cliente) == 0){
                printf("\n\nNome completo do Cliente:%s", cliente[i].nome_cliente);
                printf("\nCPF do cliente:%s", cliente[i].cpf_cliente);
                printf("\nE-mail do cliente:%s\n\n", cliente[i].email_cliente);
                cliente_localizado++;
            }
        }
        if(cliente_localizado == 0){
            printf("\n\nNome completo do Cliente:%s", cliente[contador_submenu_cliente_cadastro+1].nome_cliente);
            printf("\nCPF do cliente:%s", cliente[contador_submenu_cliente_cadastro+1].cpf_cliente);
            printf("\nE-mail do cliente:%s\n\n", cliente[contador_submenu_cliente_cadastro+1].email_cliente);
        }
    } else {
        printf("Não existem clientes cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_cliente();
}

void exclui_cliente(){
    char nome_cliente_procura[30];
    int posicoes_cliente[1000], j = 0, opcao_excluir = 0, nome_localizado = 0;
    system("cls");
    if(cliente_cadastrado == 1){
        printf("Informe o nome do cliente que você deseja excluir a ficha cadastrada: ");
        scanf(" %[^\n]%*c", &nome_cliente_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_cliente_cadastro; i++){
            if(strcmp(nome_cliente_procura, cliente[i].nome_cliente) == 0){
                posicoes_cliente[j] = i;
                j++;
                nome_localizado++;
            }
        }
        if(nome_localizado == 0){
            printf("Não foi localizado nenhum cliente com esse nome!\n\n");
        } else {
            for(int i = 0; i < j; i++){
                printf("\n\nOpção %i", i);
                printf("\nNome completo do Cliente:%s", cliente[posicoes_cliente[i]].nome_cliente);
                printf("\nCPF do cliente:%s", cliente[posicoes_cliente[i]].cpf_cliente);
                printf("\nE-mail do cliente:%s\n", cliente[posicoes_cliente[i]].email_cliente);
            }
            printf("\n\nQual cliente você deseja excluir: ");
            scanf("%d", &opcao_excluir);
            fflush(stdin);
            strcpy(cliente[posicoes_cliente[opcao_excluir]].nome_cliente, "NULL");
            strcpy(cliente[posicoes_cliente[opcao_excluir]].email_cliente, "NULL");
            strcpy(cliente[posicoes_cliente[opcao_excluir]].cpf_cliente, "NULL");
            system("cls");
            printf("Cliente excluído com sucesso!\n\n");
        }
    } else {
    printf("Não existem clientes cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_cliente();
}

//Submenu para a opção jogo
void menu_jogo(){
    printf("-----------------------------\n            Jogo         \n-----------------------------\n\n");
    printf("1- Cadastrar\n");
    printf("2- Visualizar\n");
    printf("3- Procurar\n");
    printf("4- Excluir\n");
    printf("5- Voltar\n\n");
    printf("Selecione uma opção:");
    scanf("%c", &comando_submenu);
    fflush(stdin);
    if(comando_submenu == 49){
        cadastra_jogo();
    } else if(comando_submenu == 50){
        imprime_jogo();
    } else if(comando_submenu == 51){
        procura_jogo();
    } else if(comando_submenu == 52){
        exclui_jogo();
    } else if(comando_submenu == 53){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}

void cadastra_jogo(){
    if(contador_submenu_jogo_cadastro == 1000){
        system("cls");
        printf("Limite de cadastros atingido! Impossível cadastrar outro jogo!\n\n");
        system("pause");
        system("cls");
        menu_jogo();
    } else {
        printf("\n\nInsira o nome do jogo:");
        scanf(" %[^\n]%*c", &jogo[contador_submenu_jogo_cadastro].nome_jogo);
        fflush(stdin);
        printf("\nInsira o ano de lançamento do jogo:");
        scanf("%s", &jogo[contador_submenu_jogo_cadastro].lancamento_jogo);
        fflush(stdin);
        printf("\nInsira o preço do jogo:");
        scanf("%s", &jogo[contador_submenu_jogo_cadastro].preco_jogo);
        fflush(stdin);
        printf("\nCadastro realizado com sucesso!\n\n");
        contador_submenu_jogo_cadastro++;
        jogo_cadastrado = 1;
        fflush(stdin);
        system("pause");
        system("cls");
        menu_jogo();
    }
}

void imprime_jogo(){
    if(jogo_cadastrado == 1){
        system("cls");
        for(int i = 0; i < contador_submenu_jogo_cadastro; i++){
            printf("\n\nNome do jogo:%s", jogo[i].nome_jogo);
            printf("\nAno de lançamento do jogo:%s", jogo[i].lancamento_jogo);
            printf("\nPreço do jogo:%s\n\n", jogo[i].preco_jogo);
        }
    } else {
        system("cls");
        printf("Não existem jogos cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_jogo();
}

void procura_jogo(){
    char nome_jogo_procura[30];
    int jogo_localizado = 0;
    system("cls");
    if(jogo_cadastrado == 1){
        printf("Informe o nome do jogo que você deseja visualizar a ficha cadastrada: ");
        scanf(" %[^\n]%*c", &nome_jogo_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_jogo_cadastro; i++){
            if(strcmp(nome_jogo_procura, jogo[i].nome_jogo) == 0){
                printf("\n\nNome do jogo:%s", jogo[i].nome_jogo);
                printf("\nAno de lançamento do jogo:%s", jogo[i].lancamento_jogo);
                printf("\nPreço do jogo:%s\n\n", jogo[i].preco_jogo);
                jogo_localizado++;
            }
        }
        if(jogo_localizado == 0){
            printf("\n\nNome do jogo:%s", jogo[contador_submenu_jogo_cadastro+1].nome_jogo);
            printf("\nAno de lançamento do jogo:%s", jogo[contador_submenu_jogo_cadastro+1].lancamento_jogo);
            printf("\nPreço do jogo:%s\n\n", jogo[contador_submenu_jogo_cadastro+1].preco_jogo);
        }
    } else {
        printf("Não existem jogos cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_jogo();
}

void exclui_jogo(){
    char ano_lancamento_jogo_procura[30];
    int posicoes_jogo[1000], j = 0, opcao_excluir = 0, jogo_localizado = 0;
    system("cls");
    if(jogo_cadastrado == 1){
        printf("Informe o ano de lançamento do jogo que você deseja excluir a ficha cadastrada: ");
        scanf("%s", &ano_lancamento_jogo_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_jogo_cadastro; i++){
            if(strcmp(ano_lancamento_jogo_procura, jogo[i].lancamento_jogo) == 0){
                posicoes_jogo[j] = i;
                j++;
                jogo_localizado++;
            }
        }
        if(jogo_localizado == 0){
            printf("Não foi localizado nenhum jogo com esse ano de lançamento!\n\n");
        } else {
            for(int i = 0; i < j; i++){
                printf("\n\nOpção %i", i);
                printf("\nNome do jogo:%s", jogo[posicoes_jogo[i]].nome_jogo);
                printf("\nAno de lançamento do jogo:%s", jogo[posicoes_jogo[i]].lancamento_jogo);
                printf("\nPreço do jogo:%s\n", jogo[posicoes_jogo[i]].preco_jogo);
            }
            printf("\n\nQual jogo você deseja excluir: ");
            scanf("%d", &opcao_excluir);
            fflush(stdin);
            strcpy(jogo[posicoes_jogo[opcao_excluir]].nome_jogo, "NULL");
            strcpy(jogo[posicoes_jogo[opcao_excluir]].lancamento_jogo, "NULL");
            strcpy(jogo[posicoes_jogo[opcao_excluir]].preco_jogo, "NULL");
            system("cls");
            printf("Jogo excluído com sucesso!\n\n");
        }
    } else {
    printf("Não existem jogos cadastrados no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_jogo();
}

//Submenu para a opção venda
void menu_venda(){
    printf("-----------------------------\n            Venda         \n-----------------------------\n\n");
    printf("1- Comprar\n");
    printf("2- Ver compra\n");
    printf("3- Procurar\n");
    printf("4- Excluir\n");
    printf("5- Voltar\n\n");
    printf("Selecione uma opção:");
    scanf("%c", &comando_submenu);
    fflush(stdin);
    if(comando_submenu == 49){
        cadastra_venda();
    } else if(comando_submenu == 50){
        imprime_venda();
    } else if(comando_submenu == 51){
        procura_venda();
    } else if(comando_submenu == 52){
        exclui_venda();
    } else if(comando_submenu == 53){
        system("cls");
        menu_principal();
    } else {
        system("cls");
        comando_invalido();
    }
}

void cadastra_venda(){
    if(contador_submenu_venda_cadastro == 1000){
        system("cls");
        printf("Limite de vendas atingido! Impossível cadastrar outra venda!\n\n");
        system("pause");
        system("cls");
        menu_venda();
    } else {
        printf("\n\nInsira o nome do jogo:");
        scanf(" %[^\n]%*c", &venda[contador_submenu_venda_cadastro].nome_jogo);
        printf("\nInsira o número do seu cartão:");
        scanf("%s", &venda[contador_submenu_venda_cadastro].cartao_cliente);
        printf("\nInsira o seu CEP:");
        scanf("%s", &venda[contador_submenu_venda_cadastro].cep_cliente);
        printf("\nCadastro realizado com sucesso!\n\n");
        contador_submenu_venda_cadastro++;
        venda_cadastrada = 1;
        fflush(stdin);
        system("pause");
        system("cls");
        menu_venda();
    }
}

void imprime_venda(){
    if(venda_cadastrada == 1){
        system("cls");
        for(int i = 0; i < contador_submenu_venda_cadastro; i++){
            printf("\n\nNome do jogo:%s", venda[i].nome_jogo);
            printf("\nNúmero do seu cartão:%s", venda[i].cartao_cliente);
            printf("\nSeu CEP:%s\n\n", venda[i].cep_cliente);
        }
    } else {
        system("cls");
        printf("Não existem vendas cadastradas no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_venda();
}

void procura_venda(){
    char cartao_cliente_procura[30];
    int cartao_localizado = 0;
    system("cls");
    if(venda_cadastrada == 1){
        printf("Informe o cartão que você deseja visualizar a venda cadastrada: ");
        scanf(" %[^\n]%*c", &cartao_cliente_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_venda_cadastro; i++){
            if(strcmp(cartao_cliente_procura, venda[i].cartao_cliente) == 0){
                printf("\n\nNome do jogo:%s", venda[i].nome_jogo);
                printf("\nNúmero do seu cartão:%s", venda[i].cartao_cliente);
                printf("\nSeu CEP:%s\n\n", venda[i].cep_cliente);
                cartao_localizado++;
            }
        }
        if(cartao_localizado == 0){
            printf("\n\nNome do jogo:%s", venda[contador_submenu_venda_cadastro+1].nome_jogo);
            printf("\nNúmero do seu cartão:%s", venda[contador_submenu_venda_cadastro+1].cartao_cliente);
            printf("\nSeu CEP:%s\n\n", venda[contador_submenu_venda_cadastro+1].cep_cliente);
        }
    } else {
        printf("Não existem vendas cadastradas no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_venda();
}

void exclui_venda(){
    char nome_jogo_procura[30];
    int posicoes_venda[1000], j = 0, opcao_excluir = 0, nome_localizado = 0;
    system("cls");
    if(venda_cadastrada == 1){
        printf("Informe o nome do jogo que você deseja excluir a ficha de venda cadastrada: ");
        scanf(" %[^\n]%*c", &nome_jogo_procura);
        fflush(stdin);
        system("cls");
        for(int i = 0; i < contador_submenu_venda_cadastro; i++){
            if(strcmp(nome_jogo_procura, venda[i].nome_jogo) == 0){
                posicoes_venda[j] = i;
                j++;
                nome_localizado++;
            }
        }
        if(nome_localizado == 0){
            printf("Não foi localizada nenhuma venda com esse nome de jogo!\n\n");
        } else {
            for(int i = 0; i < j; i++){
                printf("\n\nOpção %i", i);
                printf("\nNome do jogo:%s", venda[posicoes_venda[i]].nome_jogo);
                printf("\nNúmero do seu cartão:%s", venda[posicoes_venda[i]].cartao_cliente);
                printf("\nSeu CEP:%s\n", venda[posicoes_venda[i]].cep_cliente);
            }
            printf("\n\nQual venda você deseja excluir: ");
            scanf("%d", &opcao_excluir);
            fflush(stdin);
            strcpy(venda[posicoes_venda[opcao_excluir]].nome_jogo, "NULL");
            strcpy(venda[posicoes_venda[opcao_excluir]].cartao_cliente, "NULL");
            strcpy(venda[posicoes_venda[opcao_excluir]].cep_cliente, "NULL");
            system("cls");
            printf("Venda excluída com sucesso!\n\n");
        }
    } else {
    printf("Não existem vendas cadastradas no momento!\n\n");
    }
    system("pause");
    system("cls");
    menu_venda();
}

//Mensagem de erro caso o usuário insira um comando inválido (vale apenas para a movimentação entre os menus)
void comando_invalido(){
    fflush(stdin);
    printf("Comando inválido!\n\n");
    system("pause");
    system("cls");
    menu_principal();
}
