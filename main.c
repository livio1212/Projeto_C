#include <stdio.h>
#include <string.h>
#include <locale.h>

// Dados de login pré-definidos (substitua por sua base de dados)
char email_correto[] = "seu_email@example.com";
char senha_correta[] = "sua_senha";

// Função para limpar o buffer de entrada
void limpar_buffer() {
    while (getchar() != '\n');
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char email[100], senha[100];
    int opcao;
    char cnpj[20], razao_social[100], nome_fantasia[100], telefone[20], endereco[200];

    // Tela de login
    do {
        printf("Digite seu email: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0; // Remover o '\n'
        printf("Digite sua senha: ");
        fgets(senha, sizeof(senha), stdin);
        senha[strcspn(senha, "\n")] = 0;

        if (strcmp(email, email_correto) != 0 || strcmp(senha, senha_correta) != 0) {
            printf("Email ou senha incorretos!\n");
        }
    } while (strcmp(email, email_correto) != 0 || strcmp(senha, senha_correta) != 0);

    // Tela de opções
    do {
        printf("\nMenu:\n");
        printf("1. Gerar Relatório\n");
        printf("2. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                // Tela de entrada de dados
                printf("Digite o CNPJ: ");
                fgets(cnpj, sizeof(cnpj), stdin);
                cnpj[strcspn(cnpj, "\n")] = 0;

                printf("Endereço(CEP): ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = 0;

                 printf("Nome fantasia: ");
                fgets(nome_fantasia, sizeof(nome_fantasia), stdin);
                nome_fantasia[strcspn(nome_fantasia, "\n")] = 0;

                 printf("Telefone: ");
                fgets(telefone, sizeof(telefone), stdin);
               telefone[strcspn(telefone, "\n")] = 0;

               printf("Razao social: ");
                fgets(razao_social, sizeof(razao_social), stdin);
               razao_social[strcspn(razao_social, "\n")] = 0;

                // Tela de relatório (simplificada)
                printf("Relatório:");
                printf(" A empresa: %s", nome_fantasia);
                printf(" portadora do CNPJ: %s", cnpj);
                printf(" gertou: 100 Insumos");
                printf(" Totalizando o valor de  R$ 5000.00 para restauraçao");
                printf(" Deseja baixar o relatório em TXT? (s/n): ");
                char resposta;
                scanf(" %c", &resposta);
                if (resposta == 's' || resposta == 'S') {
                     FILE *arquivo = fopen("relatorio.txt", "w");
                        if (arquivo == NULL) {
                    printf("Erro ao criar o arquivo!\n");

            return 1;
                    printf("Relatório baixado com sucesso!\n");
                }
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }


    return 0;
    while (opcao != 2);
}
