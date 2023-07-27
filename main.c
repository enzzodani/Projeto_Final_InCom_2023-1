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
