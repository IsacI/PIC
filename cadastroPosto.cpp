#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// Grupo Projeto Integrador
// ISAC NARCIZO BARONI BAZZANI
// GUSTAVO VENDRAMI DO AMARAL
// KARLLOS EDUARDO RODRIGUES PEREIRA
// LUCCAS YURI DOS SANTOS
// FELIX LUIS EVENCIO DE SOUZA

struct CombustivelG
{
	char nome[9] = "Gasolina";
	float preco;
};

struct CombustivelE
{
	char nome[7] = "Etanol";
	float preco;
};

struct Posto
{
	int codigo;
	char nome[100];
	char rua[100];
	char numero[10];
	char bairro[100];
	char complemento[100];
	char cidade[100];
	char cep[10];
	char uf[2];
	struct CombustivelG gasolina;
	struct CombustivelE etanol;
	bool ativo;
};

void limparEntrada()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
}

void lerTexto(char *buffer, int length)
{
	fgets(buffer, length, stdin);
	strtok(buffer, "\n");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int cadastrarPosto(Posto postos[], int sizePosto);
	void listarPostos(Posto postos[], int qtdPostos);
	void pesquisarUmPosto(Posto postos[], int qtdPostos, int codigoPosto);
	void deletarPosto(Posto postos[], int qtdPostos, int codigoPosto);
	void atualizarPosto(Posto postos[], int qtdPostos, int codigoPosto);
	void editarGasolina(Posto postos[], int qtdPostos, int codigoPosto);
	void editarEtanol(Posto postos[], int qtdPostos, int codigoPosto);

	int opcMenu = 0;
	Posto postos[100];
	int qtdPosto = 0;
	int codPosto = 0;

	do
	{
		printf("\n========== MENU POSTO ==========");
		printf("\n|| 1 - CADASTRAR              ||");
		printf("\n|| 2 - LISTAR TODOS           ||");
		printf("\n|| 3 - PESQUISAR              ||");
		printf("\n|| 4 - DELETAR                ||");
		printf("\n|| 5 - ATUALIZAR              ||");
		printf("\n||===== Menu Combustivel =====||");
		printf("\n|| 6 - Editar Gasolina        ||");
		printf("\n|| 7 - Editar Etanol          ||");
		printf("\n|| 8 - SAIR                   ||");
		printf("\n================================");

		printf("\nInforme uma Op��o: ");
		scanf("%d", &opcMenu);

		switch (opcMenu)
		{
		case 1:
		{
			qtdPosto = cadastrarPosto(postos, qtdPosto);
			system("clear||cls");
			break;
		}
		case 2:
		{
			listarPostos(postos, qtdPosto);
			system("clear||cls");
			break;
		}
		case 3:
		{
			printf("\nInforme o codigo do posto para pesquisar:  ");
			limparEntrada();
			scanf("%d", &codPosto);
			pesquisarUmPosto(postos, qtdPosto, codPosto);
			system("clear||cls");
			break;
		}
		case 4:
		{
			printf("\nInforme o codigo do posto para deletar:  ");
			limparEntrada();
			scanf("%d", &codPosto);
			deletarPosto(postos, qtdPosto, codPosto);
			system("clear||cls");
			break;
		}
		case 5:
		{
			printf("\nInforme o codigo do posto para atualizar:  ");
			limparEntrada();
			scanf("%d", &codPosto);
			atualizarPosto(postos, qtdPosto, codPosto);
			system("clear||cls");
			break;
		}
		case 6:
		{
			limparEntrada();
			printf("\nInforme o codigo do posto para Editar a inform��o combustivel gasolina:  ");			
			scanf("%d", &codPosto);
			editarGasolina(postos, qtdPosto, codPosto);
			system("clear||cls");
			break;
		}
		case 7:
		{
			limparEntrada();
			printf("\nInforme o codigo do posto para Editar a inform��o combustivel etanol:  ");			
			scanf("%d", &codPosto);
			editarEtanol(postos, qtdPosto, codPosto);
			system("clear||cls");
			break;
		}
		case 8:
		{
			system("clear||cls");
			break;
		}
		default:
		{
			printf("Informe um valor valido para op��o do menu!!");
		}
		}
	} while (opcMenu != 5);

	return 0;
}

void editarGasolina(Posto postos[], int qtdPostos, int codPosto)
{
	if (qtdPostos <= 0)
	{
		printf("\nN�o h� posto cadastrado, por favor cadastre um posto!!\n");
	}
	else
	{
		for (int i = 0; i < qtdPostos; i++)
		{
			if (postos[i].codigo == codPosto && postos[i].ativo == 1)
			{
				printf("\nInforme o dados do combustivel Gasolina: ");
				float preco = 0;				
				printf("\nValor: ");
				scanf("%f", &preco);
				limparEntrada();

				postos[i].gasolina.preco = preco;
			}
			else
			{
				printf("\nN�o foi encontrado o posto, por favor informe um posto valido!!\n");
			}
		}
	}

	system("pause");
}

void editarEtanol(Posto postos[], int qtdPostos, int codPosto)
{
	if (qtdPostos <= 0)
	{
		printf("\nN�o h� posto cadastrado, por favor cadastre um posto!!\n");
	}
	else
	{
		for (int i = 0; i < qtdPostos; i++)
		{
			if (postos[i].codigo == codPosto && postos[i].ativo == 1)
			{
				printf("\nInforme o dados do combustivel Etanol: ");
				float preco;

				printf("\nValor: ");
				scanf("%f", &preco);
				limparEntrada();

				postos[i].etanol.preco = preco;
			}
			else
			{
				printf("\nN�o foi encontrado o posto para ser atualizado, por favor informe um posto valido!!\n");
			}
		}
	}

	system("pause");
}

int cadastrarPosto(Posto postos[], int sizePosto)
{
	Posto postoNovo;

	postoNovo.codigo = sizePosto + 1;
	postoNovo.ativo = 1;

	printf("\nInforme os dados do Posto de Gasolina: ");

	printf("\nNome: ");
	limparEntrada();
	lerTexto(postoNovo.nome, 100);

	printf("Rua: ");
	lerTexto(postoNovo.rua, 100);

	printf("Numero: ");
	lerTexto(postoNovo.numero, 10);

	printf("Complemento: ");
	lerTexto(postoNovo.complemento, 100);

	printf("Bairro: ");
	lerTexto(postoNovo.bairro, 100);

	printf("Cep: ");
	lerTexto(postoNovo.cep, 10);

	printf("Cidade: ");
	lerTexto(postoNovo.cidade, 100);

	printf("UF: ");
	lerTexto(postoNovo.uf, 2);

	postos[sizePosto] = postoNovo;

	system("pause");
	return sizePosto + 1;
}

void atualizarPosto(Posto postos[], int qtdPostos, int codigoPosto)
{
	Posto postoNovo;

	for (int i = 0; i < qtdPostos; i++)
	{
		if (postos[i].codigo == codigoPosto && postos[i].ativo == 1)
		{
			printf("\nInforme os dados do Posto de Gasolina: ");
			postoNovo = postos[i];

			printf("\nNome: ");
			limparEntrada();
			lerTexto(postoNovo.nome, 100);

			postoNovo.ativo = 1;
			postoNovo.codigo = i;

			postos[i] = postoNovo;
		}
		else
		{
			printf("\nN�o foi encontrado o posto para ser atualizado, por favor informe um posto valido!!\n");
		}
	}

	system("pause");
}

void listarPostos(Posto postos[], int qtdPostos)
{
	printf("\n=============================================== LISTA DE POSTOS ===============================================\n");
	printf("\n      |   Codigo  |   Nome\n");

	for (int i = 0; i < qtdPostos; i++)
	{
		if (postos[i].ativo == 1)
		{
			printf("\nPOSTO |     %d     | %s \n", postos[i].codigo, postos[i].nome);
		}
	}
	printf("\n=============================================== LISTA DE POSTOS ===============================================\n");

	system("pause");
}

void pesquisarUmPosto(Posto postos[], int qtdPostos, int codigoPosto)
{

	for (int i = 0; i < qtdPostos; i++)
	{
		if (codigoPosto == postos[i].codigo && postos[i].ativo == 1)
		{
			printf("\nInforma��o do Posto\n");
			printf("\nCodigo      : %d", postos[i].codigo);
			printf("\nNome        : %s", postos[i].nome);
			printf("\nRua         : %s", postos[i].rua);
			printf("\nNumero      : %s", postos[i].numero);
			printf("\nComplemento : %s", postos[i].complemento);
			printf("\nBairro      : %s", postos[i].bairro);
			printf("\nCidade      : %s", postos[i].cidade);
			printf("\nUF          : %s", postos[i].uf);
			printf("\nGasolina  R$: %.3f", postos[i].gasolina.preco);
			printf("\nEtanol    R$: %.3f\n", postos[i].etanol.preco);
		}
	}
	system("pause");
}

void deletarPosto(Posto postos[], int qtdPostos, int codigoPosto)
{
	fseek(stdin, 0, SEEK_END);

	for (int i = 0; i < qtdPostos; i++)
	{
		if (codigoPosto == postos[i].codigo)
		{
			postos[i].ativo = 0;
			printf("Posto com codigo %d, foi deletado com sucesso!!", codigoPosto);
		}
	}
}
