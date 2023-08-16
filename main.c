/*  
Projeto Final InCom 2023-1
Alunos:
Enzo Daniel Marinho
Itamar Rocha
Antony
Josue
*/

// TODO: Lidar com o input do usuário:
// Buffer overflow, valores sem sentido, etc...
// Fazer verificações

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constantes
#define TAMANHO_NOME 30
#define TAMANHO_DESCRICAO 200
#define TOTAL_DE_PRODUTOS 256
#define TOTAL_DE_FORMAS_DE_PAGAMENTO 10
#define MENU_INICIAL 'M'
#define CADASTRAR 'C'
#define CADASTRO_DE_PRODUTOS 'P'
#define CADASTRO_DE_FORMAS_DE_PAGAMENTO 'F'
#define LISTAR 'L'
#define VENDAS 'V'
#define SAIR 'S'

// Estruturas - CUIDADO AO MODIFICAR AS ESTRUTURAS (TYPE CASTING/SAFETY)
struct Produto {
	int codigo;
	char nome[TAMANHO_NOME];
	float preco;
};

struct FormaDePagamento{
	int codigo;
	char nome[TAMANHO_NOME];
	char descricao[TAMANHO_DESCRICAO];
};

// Funções de utilidade
void limparBufferDeEntrada(void);
void limparSaida(void);
void pausar(void);
void listarProdutosVendidos(int produtosVendidos[], int quantidadeProdutos);
int buscarInstancia(void* ponteiroDeListaDeInstancias, size_t tamanhoDaInstancia ,int totalDeInstanciasCadastradas, int codigoDaInstancia);
// TODO: void listarInstancias(void); Lista produtos ou formas de pagamento cadastrados


// Funções de procedimento
void menuInicial(void);
void cadastroDeProdutos(void); // TODO: É possível fazer apenas uma função de cadastro generalista (um pouco complexo? vale a pena?)
void cadastroDeFormasDePagamento(void); // Muito código repetido nessas duas funções...
void processoDeVendas(void);

// Instâncias
struct Produto listaDeProdutos[TOTAL_DE_PRODUTOS];
struct FormaDePagamento listaDeFormasDePagamento[TOTAL_DE_FORMAS_DE_PAGAMENTO];

// Variáveis globais
char procedimento;
int totalDeProdutosCadastrados = 0;
int totalDeFormasDePagamentoCadastradas = 0;

int main()
{
	// Procedimento inicial
	procedimento = MENU_INICIAL;

	// Loop principal
	while(1){
		limparSaida();
		switch(procedimento){
			case MENU_INICIAL:
				menuInicial();
				break;
			case CADASTRO_DE_PRODUTOS:
				cadastroDeProdutos();
				break;
			case CADASTRO_DE_FORMAS_DE_PAGAMENTO:
				cadastroDeFormasDePagamento();
				break;
			case VENDAS:
				processoDeVendas();
				break;
			case SAIR:
				return 0;
			default:
				procedimento = MENU_INICIAL;
		}
	}
}

void limparBufferDeEntrada(void){
	char lixo;
	while((lixo = getchar()) != '\n' && lixo != EOF){continue;}
}

void limparSaida(void){
	fflush(stdout);
	printf("\e[1;1H\e[2J");
}

void pausar(void){
	printf("\nAperte enter para continuar... ");
	getchar();
	limparBufferDeEntrada();
}

int buscarInstancia(void* ponteiroDeListaDeInstancias, size_t tamanhoDaInstancia, int totalDeInstanciasCadastradas, int codigoDaInstancia){
	for (int i = 0; i < totalDeInstanciasCadastradas; i++){
		void* instancia = (char*)ponteiroDeListaDeInstancias + (i*tamanhoDaInstancia);
		struct Base{int codigo;};
		struct Base *instanciaAtual = instancia; // CUIDADO (TYPE CASTING/SAFETY)
		if (instanciaAtual->codigo == codigoDaInstancia){
			return i;
		}
	}

	// Instancia não encontrada
	return -1;
}

void menuInicial(void){
	printf("PROGRAMA DE VENDAS\n\n");
	printf("Informe a operação desejada: \n");
	printf("P - Cadastro de produtos\n");
	printf("F - Cadastro de formas de pagamento\n");
	printf("V - Processo de vendas\n");
	printf("S - Sair\n");
	scanf("%c", &procedimento);
	limparBufferDeEntrada();
}

void cadastroDeProdutos(void){

	procedimento = CADASTRO_DE_PRODUTOS;
	int quantidadeDeCadastros;

	while(1){
		limparSaida();
		switch (procedimento){
			case CADASTRO_DE_PRODUTOS:
				printf("CADASTRO DE PRODUTOS\n\n");
				printf("Informe a operação desejada: \n");
				printf("C - Cadastrar novos produtos\n");
				printf("L - Listar produtos cadastrados\n");
				printf("M - Retornar ao menu inicial\n");
				scanf("%c", &procedimento);
				limparBufferDeEntrada();
				break;
			case CADASTRAR:
				if (totalDeProdutosCadastrados == TOTAL_DE_PRODUTOS){
				printf("Limite de produtos cadastrados alcançado.");
				pausar();
				}
				while(1){
					int temp;
					printf("Digite quantos produtos deseja cadastrar: ");
					scanf("%d", &temp);
					limparBufferDeEntrada();    			
					if (temp + totalDeProdutosCadastrados > TOTAL_DE_PRODUTOS){
						printf("Há espaço para armazenar %d novos produtos. Por favor insira um número dentro do limite de produtos.\n", TOTAL_DE_PRODUTOS - totalDeProdutosCadastrados);
						pausar();
					} else {
						quantidadeDeCadastros = temp;
						break;
					}
				}
				for (int i = 0; i < quantidadeDeCadastros; i++){
					int codigo;
					limparSaida();
					printf("Cadastrando %d novos produtos, %d já cadastrados, restam %d.\n\n", quantidadeDeCadastros, i, quantidadeDeCadastros-i);
					while(1){
						printf("Digite o codigo do produto %d: ", i+1);
						scanf("%d", &codigo);
						limparBufferDeEntrada();
						if (buscarInstancia(listaDeProdutos, sizeof(listaDeProdutos[0]), totalDeProdutosCadastrados, codigo) == -1){
							listaDeProdutos[totalDeProdutosCadastrados].codigo = codigo;
							break;
						} else {
							printf("Já existe um produto cadastrado com esse código. Insira um novo código.\n");
						}
					}

					printf("Digite o nome do produto %d: ", i+1);
					scanf("%[^\n]", listaDeProdutos[totalDeProdutosCadastrados].nome);
					limparBufferDeEntrada();

					printf("Digite o preco do produto %d: ", i+1);
					scanf("%f", &listaDeProdutos[totalDeProdutosCadastrados].preco);
					limparBufferDeEntrada();

					totalDeProdutosCadastrados++;
				}
				procedimento = CADASTRO_DE_PRODUTOS;
				break;
			case LISTAR:
				// TODO
				break;
			case MENU_INICIAL:
				return;
				break;
			default:
				procedimento = CADASTRO_DE_PRODUTOS;
		}
	}
}

void cadastroDeFormasDePagamento(void){

	procedimento = CADASTRO_DE_FORMAS_DE_PAGAMENTO;
	int quantidadeDeCadastros;

	while(1){
		limparSaida();
		switch (procedimento){
			case CADASTRO_DE_FORMAS_DE_PAGAMENTO:
				printf("CADASTRO DE FORMAS DE PAGAMENTO\n\n");
				printf("Informe a operação desejada: \n");
				printf("C - Cadastrar novas formas de pagamento\n");
				printf("L - Listar formas de pagamento cadastradas\n");
				printf("M - Retornar ao menu inicial\n");
				scanf("%c", &procedimento);
				limparBufferDeEntrada();
				break;
			case CADASTRAR:
				if (totalDeFormasDePagamentoCadastradas == TOTAL_DE_FORMAS_DE_PAGAMENTO){
					printf("Limite de formas de pagamento cadastrados alcançado.");
					pausar();
				}
				while(1){
					int temp;
					printf("Digite quantas formas de pagamento deseja cadastrar: ");
					scanf("%d", &temp);
					limparBufferDeEntrada();    			
					if (temp + totalDeFormasDePagamentoCadastradas > TOTAL_DE_FORMAS_DE_PAGAMENTO){
						printf("Há espaço para armazenar %d novas formas de pagamento. Por favor insira um número dentro do limite de formas de pagamento.\n", TOTAL_DE_FORMAS_DE_PAGAMENTO - totalDeFormasDePagamentoCadastradas);
						pausar();
					} else {
						quantidadeDeCadastros = temp;
						break;
					}
				}
				for (int i = 0; i < quantidadeDeCadastros; i++){
					int codigo;
					limparSaida();
					printf("Cadastrando %d novas formas de pagamento, %d já cadastradas, restam %d.\n\n", quantidadeDeCadastros, i, quantidadeDeCadastros-i);
					while(1){
						printf("Digite o codigo da forma de pagamento %d: ", i+1);
						scanf("%d", &codigo);
						limparBufferDeEntrada();
						if (buscarInstancia(listaDeFormasDePagamento, sizeof(listaDeFormasDePagamento[0]), totalDeFormasDePagamentoCadastradas, codigo) == -1){
							listaDeFormasDePagamento[totalDeFormasDePagamentoCadastradas].codigo = codigo;
							break;
						} else {
							printf("Já existe uma forma de pagamento cadastrada com esse código. Insira um novo código.\n");
						}
					}
					printf("Digite o nome da forma de pagamento %d: ", i+1);
					scanf("%[^\n]", listaDeFormasDePagamento[totalDeFormasDePagamentoCadastradas].nome);
					limparBufferDeEntrada();
					printf("Digite a descrição da forma de pagamento %d: ", i+1);
					scanf("%[^\n]", listaDeFormasDePagamento[totalDeFormasDePagamentoCadastradas].descricao);
					limparBufferDeEntrada();
					totalDeFormasDePagamentoCadastradas++;
				}
				procedimento = CADASTRO_DE_FORMAS_DE_PAGAMENTO;
				break;
			case LISTAR:
				// TODO
				break;
			case MENU_INICIAL:
				return;
				break;
			default:
				procedimento = CADASTRO_DE_FORMAS_DE_PAGAMENTO;
		}
	}
}

void listarProdutosVendidos(int produtosVendidos[], int quantidadeProdutos) {
    printf("Produtos vendidos:\n");

    for (int i = 0; i < quantidadeProdutos; i++) {
        int codigoProduto = produtosVendidos[i];
        int indiceProduto = buscarInstancia(listaDeProdutos, sizeof(listaDeProdutos[0]), totalDeProdutosCadastrados, codigoProduto);

        if (indiceProduto != -1) {
            printf("Código: %d\n", listaDeProdutos[indiceProduto].codigo);
            printf("Nome: %s\n", listaDeProdutos[indiceProduto].nome);
            printf("Preço: %.2f\n", listaDeProdutos[indiceProduto].preco);
            printf("\n");
        }
    }
}

// Função para processar a venda
void processoDeVendas(void) {
    int codigoProduto, quantidadeProduto, codigoFormaPagamento;
    float valorFormaPagamento = 0, valorTotalVenda = 0, valorRestante = 0;
	int produtosVendidos[TOTAL_DE_PRODUTOS];
    int quantidadeProdutosVendidos = 0;
    bool finalizarVenda = false;

    printf("PROCESSO DE VENDAS\n\n");
    int i = 0;
    while (!finalizarVenda) {
        printf("Digite o código do produto: ");
        scanf("%d", &codigoProduto);
        limparBufferDeEntrada();

        // Verificar se o código do produto existe
        int indiceProduto = buscarInstancia(listaDeProdutos, sizeof(listaDeProdutos[0]), totalDeProdutosCadastrados, codigoProduto);
        if (indiceProduto == -1) {
            printf("Produto não encontrado. Por favor, insira um código válido.\n");
            continue;
        }
        produtosVendidos[i] = codigoProduto;
        i++;
        quantidadeProdutosVendidos++;

        printf("Digite a quantidade do produto: ");
        scanf("%d", &quantidadeProduto);
        limparBufferDeEntrada();

        if (quantidadeProduto <= 0) {
            printf("Quantidade do produto deve ser maior que zero.\n");
            continue;
        }

        valorTotalVenda += listaDeProdutos[indiceProduto].preco * quantidadeProduto;

        printf("Deseja adicionar mais produtos? (S/N): ");
        char resposta;
        scanf("%c", &resposta);
        limparBufferDeEntrada();
        if (resposta == 'N' || resposta == 'n') {
            finalizarVenda = true;
        }
    }
    valorRestante = valorTotalVenda;
    // Coletar informações das formas de pagamento
    while (true) {
        printf("\nValor total da venda: %.2f\n", valorTotalVenda);

        printf("Digite o código da forma de pagamento: ");
        scanf("%d", &codigoFormaPagamento);
        limparBufferDeEntrada();

        // Verificar se o código da forma de pagamento existe
        int indiceFormaPagamento = buscarInstancia(listaDeFormasDePagamento, sizeof(listaDeFormasDePagamento[0]), totalDeFormasDePagamentoCadastradas, codigoFormaPagamento);
        if (indiceFormaPagamento == -1) {
            printf("Forma de pagamento não encontrada. Por favor, insira um código válido.\n");
            continue;
        }

        printf("Digite o valor da forma de pagamento: ");
        scanf("%f", &valorFormaPagamento);
        limparBufferDeEntrada();

        valorRestante -= valorFormaPagamento;

        printf("Deseja adicionar mais formas de pagamento? (S/N): ");
        char resposta;
        scanf("%c", &resposta);
        limparBufferDeEntrada();
        if (resposta == 'N' || resposta == 'n') {
            if(valorRestante == 0) {
                break;
            } else{
                printf("Ainda faltam %f reais a serem pagos", valorRestante);
            }
        }
        
    }

    // Mostrar o cupom da venda
    limparSaida();limparSaida();
    printf("CUPOM DA VENDA\n");
    printf("Valor total da venda: %.2f\n", valorTotalVenda);
    printf("Produtos:\n");
	listarProdutosVendidos(produtosVendidos, quantidadeProdutosVendidos);
    printf("\nVenda finalizada!\n");
    pausar();
}
