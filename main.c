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

void clearInputBuffer(void);
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
				clearInputBuffer();
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
				struct pagamento{
					char nome[30];
					char codigo[30];
					char descricao[200];
				};

				struct pagamento c[20];
				int i, j; 
				char proced = 'N';

				for(i=0; i<20; i){
					printf("Insira a forma de pagamento.\n");
					scanf("%[^\n]", c[i].nome);

					printf("\nInsira um código.\n");
					scanf("%s", c[i].codigo);

					printf("\nInsira uma descrição.\n");
					scanf("%[^\n]", c[i].descricao);

					printf("Deseja cadastrar outra forma de pagamento? (S/N)\n");
					scanf("%c", &proced);
					switch (proced){
						case 'S':
							i++;
							break;
						case 'N':
							i = i + 21;
							break;
					}
				}
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

void clearInputBuffer(void){
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
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
