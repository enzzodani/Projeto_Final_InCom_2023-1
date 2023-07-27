// Projeto Final InCom 2023-1


#include <stdio.h>
#include <stdlib.h>


int main()
{
	    char e = 'I';
	        while(1){
			        fflush(stdout);
				        system("clear");
					        switch(e){
							         // Tela incial
									         case 'I':
									              // Lógica da tela inicial
											                  printf("PROGRAMA DE VENDAS\n\n");
										                  printf("Informe a operação desejada: \n");
												              printf("P - Cadastro de produtos\n");
													                  printf("F - Cadastro de formas de pagamento\n");
															              printf("V - Processo de vendas\n");
																                  printf("S - Sair\n");
																		               // TODO: corrigir bug do lixo na input stream
																					                 scanf("%c", &e);
																				                 getchar();
																						             break;
																							              // Cadastro de produtos
																									              case 'P':
																									                   // Lógica do cadastro de produtos
																												               e = 'I';
																											               break;
																												                // Cadastro de formas de pagamento
																															        case 'F':
																															             // Lógica do cadastro de formas de pagamento
																																	                 e = 'I';
																																                 break;
																																		          // Procedimento de vendas
																																				          case 'V':
																																				               // Lógica do procedimento de vendas
																																						                   e = 'I';
																																					                   break;
																																							            // Sai do programa
																																									            case 'S':
																																									                return 0;
																																											        default:
																																											            e = 'I';
																																												            }
						    }
}
