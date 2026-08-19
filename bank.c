#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char nome[50];
int numero_conta;
int saldo = 10000;
int valor_deposito;
int valor_saque;
int valor_transferencia;
int conta_destino;

void menu();
void depositar_dinheiro();
void sacar_dinheiro();
void transferir_dinheiro();
void detalhes_da_conta();
void detalhes_das_transacoes();
void ultimos_detalhes();

int main() {
    int escolha;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; 

    printf("Digite o numero da sua conta: ");
    scanf("%d", &numero_conta);

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                depositar_dinheiro();
                break;
            case 2:
                sacar_dinheiro();
                break;
            case 3:
                transferir_dinheiro();
                break;
            case 4:
                detalhes_da_conta();
                break;
            case 5:
                detalhes_das_transacoes();
                break;
            case 6:
                ultimos_detalhes();
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (escolha != 6);

    return 0;
}

void menu() {
    printf("\n===== Menu Principal =====\n");
    printf("1. Depositar dinheiro\n");
    printf("2. Sacar dinheiro\n");
    printf("3. Transferir dinheiro\n");
    printf("4. Detalhes da conta\n");
    printf("5. Detalhes das transacoes\n");
    printf("6. Sair\n");
}

void depositar_dinheiro() {
    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Conta.txt", "a");
    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("DEPOSITAR DINHEIRO\n");
    printf("Digite a quantidade: ");
    scanf("%d", &valor_deposito);

    saldo += valor_deposito;
    printf("Dinheiro depositado com sucesso!\n");
    printf("Saldo atual: %d\n", saldo);

    fprintf(ptr, "R$%d foi depositado na sua conta.\n", valor_deposito);
    fprintf(ptr, "Data/hora da transacao: %s", ctime(&tm));

    fclose(ptr);
}

void sacar_dinheiro() {
    time_t tm;
    time(&tm);

    printf("SACAR DINHEIRO\n");
    printf("Digite a quantidade: ");
    scanf("%d", &valor_saque);

    if (valor_saque > saldo) {
        printf("Saldo insuficiente!\n");
        return;
    }

    FILE *ptr = fopen("Conta.txt", "a");
    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    saldo -= valor_saque;
    printf("Saque realizado com sucesso!\n");
    printf("Saldo atual: %d\n", saldo);

    fprintf(ptr, "R$%d foi sacado da sua conta.\n", valor_saque);
    fprintf(ptr, "Data/hora da transacao: %s", ctime(&tm));

    fclose(ptr);
}

void transferir_dinheiro() {
    time_t tm;
    time(&tm);

    printf("TRANSFERIR DINHEIRO\n");
    printf("Digite o numero da conta de destino: ");
    scanf("%d", &conta_destino);

    printf("Digite a quantidade: ");
    scanf("%d", &valor_transferencia);

    if (valor_transferencia > saldo) {
        printf("Saldo insuficiente!\n");
        return;
    }

    FILE *ptr = fopen("Conta.txt", "a");
    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    saldo -= valor_transferencia;
    printf("Transferencia realizada com sucesso!\n");
    printf("Saldo atual: %d\n", saldo);

    fprintf(ptr, "R$%d foi transferido para a conta %d.\n", valor_transferencia, conta_destino);
    fprintf(ptr, "Data/hora da transacao: %s", ctime(&tm));

    fclose(ptr);
}

void detalhes_da_conta() {
    printf("\n===== DETALHES DA CONTA =====\n");
    printf("Nome: %s\n", nome);
    printf("Numero da conta: %d\n", numero_conta);
    printf("Saldo atual: %d\n", saldo);
}

void detalhes_das_transacoes() {
    printf("\n===== HISTORICO DE TRANSACOES =====\n");
    FILE *ptr = fopen("Conta.txt", "r");
    if (ptr == NULL) {
        printf("Nenhuma transacao encontrada ainda.\n");
        return;
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), ptr) != NULL) {
        printf("%s", linha);
    }

    fclose(ptr);
}

void ultimos_detalhes() {
    printf("\n===== RESUMO FINAL =====\n");
    printf("Obrigado por usar o banco, %s!\n", nome);
    printf("Saldo final da conta %d: %d\n", numero_conta, saldo);
}
















