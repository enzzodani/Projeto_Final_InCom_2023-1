/*  
Projeto Final InCom 2023-1
Alunos:
Enzo Daniel Marinho
Itamar Rocha
Antony
Josue
*/


#include <stdio.h>
#include <stdlib.h>

struct produto {
	char nomeDoProduto[30];
	int codDoProduto;
	float precoDoProduto;
};

void CadastroDeProdutos ();

int main()
{
	char procedimento = 'I';

	while(1){

		// Limpa o output do terminal
		fflush(stdout);
		system("clear");

		// Lógica de seleção de procedimentos
		switch(procedimento){
			// Tela incial
			case 'I':
				// Lógica da tela inicial
				printf("PROGRAMA DE VENDAS\n\n");
				printf("Informe a operação desejada: \n");
				printf("P - Cadastro de produtos\n");
				printf("F - Cadastro de formas de pagamento\n");
				printf("V - Processo de vendas\n");
				printf("S - Sair\n");
				scanf("%c", &procedimento);
				// Limpa o buffer de input
				fflush(stdin);
				break;
			// Cadastro de produtos
			case 'P':
				// Lógica do cadastro de produtos
				CadastroDeProdutos();
				procedimento = 'I';
				break;
			// Cadastro de formas de pagamento
			case 'F':
				// Lógica do cadastro de formas de pagamento
				procedimento = 'I';
				break;
			// Procedimento de vendas
			case 'V':
				// Lógica do procedimento de vendas
				procedimento = 'I';
				break;
			// Sai do programa
			case 'S':
				return 0;
			default:
				procedimento = 'I';
		}
	}
}

void CadastroDeProdutos (){
	char pescolha = 'N';
	struct produto p[256];
	int contador = 0;

	printf("========== CADASTRO DE PRODUTOS ==========\n\n");
	printf("Deseja cadastrar um produto (S = Sim/N = Nao)? ");
		scanf("%c", &pescolha);
	switch (pescolha){
		case 'S':
		//Procedimento de cadastro
		printf("Digite o nome do produto: ");
			gets(p[contador].nomeDoProduto);
		printf("Digite o codigo do produto: ");
			scanf("%d", &p[contador].codDoProduto);
		printf("Digite o preco do produto: ");
			scanf("%f", &p[contador].precoDoProduto);
		contador++;
		break;

		case 'N': 
		break;

		default:

	}
}