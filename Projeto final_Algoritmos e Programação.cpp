//Integrantes:
//Henrique Moraes Farias, UC22200106, Análise e Desenvolvimento de Sistemas
//Larissa Lorraine Ferreira Barbosa, UC22200367, Análise e Desenvolvimento de Sistemas
//Stela Sousa Alves, UC22200017, Ciência da Computação

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int opcao, quantidadeSessoes[100], i, quantidadePessoas[100], j, idadeEspectador[100];
char nomeFilme[50][100], entradaEspectador[50][100], avaliacaoFilme[50][100];
char sexo[10][1];
int masculino=0, feminino=0;
int meia=0, inteira=0, valorSessao;
int homemMaior=0, mulherMaior=0;
int crianca=0, adolescente=0, adulto=0, idoso=0;
int bom=0, ruim=0;

int main(){
	
	setlocale(LC_ALL, "PORTUGUESE"); //Setando os caracteres para o padrão português
	menu:
		printf("\tCinema de Brasília\n\n1. Análise de sessões\n2. Sair\n\nDigite a opção desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1: 
			//Caso das sessões
			system("cls");
			printf("Digite a quantidade de sessões: ");
			scanf("%d", &quantidadeSessoes[i]);
			//Validção da quantidade de sessões 
			if(quantidadeSessoes[i] != 2){
				do{
					system("cls"); //Limpeza de terminal
					printf("Quantidade inválida, única quantidade aceita: 2.\nDigite a quantidade de sessões: ");
					scanf("%d", &quantidadeSessoes[i]);
				}while(quantidadeSessoes[i] != 2);
			}
			
			//For que incia o cadastro de informações de cada sessão
			for(i=0;i<quantidadeSessoes[i];i++){
				system("cls"); //Comando que limpa a tela
				printf("Digite aqui o nome do filme da sessão %d: ", i+1);
				fflush(stdin); //Comando que limpa o buffer do teclado
				fgets(nomeFilme[i], 50, stdin);
				
				system("cls");
				printf("Digite aqui a quantidade de pessoas que assistiram ao filme %d: ", i+1);
				scanf("%d", &quantidadePessoas[i]);
				//Validação da quantidade de espectadores
				if(quantidadePessoas[i]<10){
					do{
						system("cls");  //Limpeza de terminal
						printf("Quantidade inválida, minímo de 10 espectadores.\nDigite aqui a quantidade de pessoas que assistiram ao filme %d: ", i+1);
						scanf("%d", &quantidadePessoas[i]);
					}while(quantidadePessoas[i]<10);
				}				
			
			//For para cadastro de informações individuais
			for(j=0;j<quantidadePessoas[i];j++){
				system("cls");  //Limpeza de terminal
				printf("Sexo do espectador %d\nMasculino: M\nFeminino: F\nDigite a opção desejada: ", j+1);
				fflush(stdin);
				scanf("%s", &sexo[i]);
				
			//Contando a quantidade de espectadores de cada sexo
				if(strcmp(sexo[i], "M")==0){
					masculino++;
				}else if(strcmp(sexo[i], "F")==0){
					feminino++;
				}
			//Validação do gênero do espectador
				if(strcmp(sexo[i], "M")!=0 && strcmp(sexo[i], "F")!= 0){
					do{
					system("cls");  //Limpeza de terminal
					printf("Opção inválida, utilize 'M' ou 'F'.\nSexo do espectador %d\nMasculino: M\nFeminino: F\nDigite a opção desejada: ");
					scanf("%s", &sexo[i]);
			//Contando a quantidade de espectadores de cada gênero
					if(strcmp(sexo[i], "M")==0){
					masculino++;
				}else if(strcmp(sexo[i], "F")==0){
					feminino++;
					
				}
					}while(strcmp(sexo[i], "M")!=0 && strcmp(sexo[i], "F")!= 0);
				}
				
				system("cls");  //Limpeza de terminal
				printf("Digite aqui a idade do espectador %d: ", j+1);
				scanf("%d", &idadeEspectador[i]);
			//Contagem do número de pessoas de cada faixa etária
				if(idadeEspectador[i]>3 && idadeEspectador[i]<=13){
					crianca++;
				}else if(idadeEspectador[i]>13 && idadeEspectador[i]<=18){
					adolescente++;
				}else if(idadeEspectador[i]>18 && idadeEspectador[i]<=64){
					adulto++;
				}else if(idadeEspectador[i]>64 && idadeEspectador[i]<=100){
					idoso++;
				}
				
				
				
			//Contando a quantidade de espectadores maiores de idade
				if(idadeEspectador[i]>18 && strcmp(sexo[i], "M")==0){
					homemMaior++;
				}else if(idadeEspectador[i]>18 && strcmp(sexo[i], "F")==0){
					mulherMaior++;
				}
				
			//Validação da idade do espectador
				if(idadeEspectador[i]<3 || idadeEspectador[i] > 100){
					do{
					system("cls");  //Limpeza de terminal
					printf("Idade inválida, coloque um número entre 3 e 100.\nDigite aqui a idade do espectador %d: ", j+1);
					scanf("%d", &idadeEspectador[i]);
					}while(idadeEspectador[i]<3 || idadeEspectador[i]>100);
				}
				
				system("cls");  //Limpeza de terminal
				printf("Qual foi o tipo de entrada do espectador?\n-Meia entrada(R$25,00): Meia\n-Entrada inteira(R$50,00): Inteira\nDigite aqui o tipo de entrada do espectador %d: ", j+1);
				scanf("%s", &entradaEspectador[i]);
				
			//Contagem da arrecadação de cada tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")==0 ){
					meia = meia+25;
				}else if(strcmp(entradaEspectador[i], "Inteira")==0){
					inteira = inteira+50;
				}
				
			//Validação do tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")!= 0 && strcmp(entradaEspectador[i], "Inteira") != 0){
					do{
						system("cls");  //Limpeza de terminal
						printf("Opção inválida.\nQual foi o tipo de entrada do espectador?\n-Meia entrada(R$25,00): Meia\n-Entrada inteira(R$50,00): Inteira\nDigite aqui o tipo de entrada do espectador %d: ", j+1);
						scanf("%s", &entradaEspectador);
			//Contagem da arrecadação de cada tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")==0){
					meia = meia+25;
				}else if(strcmp(entradaEspectador[i], "Inteira")==0){
					inteira =  inteira+50;
				}
					}while(strcmp(entradaEspectador[i], "Meia") != 0 && strcmp(entradaEspectador[i], "Inteira") != 0);
				}
				valorSessao = inteira + meia;
				
			//Nova funcionalidade: Avaliação do espectador sobre o filme 
					system("cls");
					printf("Como o espectador avaliou o filme?\n-Um filme agradável: Bom\n-Um filme desagradável: Ruim\nDigite a opção desejada: ");
					scanf("%s", &avaliacaoFilme[i]);
			//Contagem de opiniões		
					if(strcmp(avaliacaoFilme[i], "Bom")==0){
						bom++;
					}else if(strcmp(avaliacaoFilme[i], "Ruim")==0){
						ruim++;
					}
			//Validação da nova funcionalidade
					if(strcmp(avaliacaoFilme[i], "Bom")!= 0 && strcmp(avaliacaoFilme[i], "Ruim")!=0){
						do{
							system("cls");
							printf("Opção inválida.\nComo o espectador avaliou o filme?\n-Um filme agradável: Bom\n-Um filme desagradável: Ruim\nDigite a opção desejada: ");
							scanf("%s", &avaliacaoFilme);
						}while(strcmp(avaliacaoFilme[i], "Bom")!= 0 && strcmp(avaliacaoFilme[i], "Ruim")!=0);
					}
					
					
					
					
					
			}
			
			  		 //Impressão das informações
			 
			 system("cls");																//Limpeza do buffer do teclado
			 printf("Nome do filme: %s", nomeFilme);									//Nome do filme
			 printf("\nNúmero de espectadores do sexo masculino: %d", masculino);		//Número de espectadores do gênero masculino
			 printf("\nNúmero de espectadores do sexo feminino: %d", feminino);			//Número de espectadores do gênero feminino
			 printf("\n\nValor arrecadado com as inteiras: R$%d", inteira);				//Valor arrecadado com a entrada inteira 
			 printf("\nValor arrecadado com as meias: R$%d", meia);						//Valor arrecadado com a meia entrada
			 printf("\nValor total arrecadado: R$%d", valorSessao); 					//Valor total arrecadado com o filme
			 printf("\n\nNúmero de homens maiores de idade: %d", homemMaior);			//Número de espectadores homens maiores de idade
			 printf("\nNúmero de mulheres maiores de idade: %d", mulherMaior);			//Número de espectadores mulheres maiores de idade
			 printf("\n\nNúmero de crianças que assistiram: %d", crianca);				//Número de crianças que assistiram ao filme
			 printf("\nNúmero de adolescentes que assistiram: %d", adolescente);		//Número de adolescentes que assistira, ao filme
			 printf("\nNúmero de adultos que assistiram: %d", adulto);					//Número de adultos que assistiram ao filme 
			 printf("\nNúmero de idosos que assistiram ao filme: %d", idoso);			//Número de idosos que assistiram ao filme
			 printf("\n\nNúmero de espectadores que acharam o filme bom: %d", bom); 	//Número de espectadores que acharam o filme bom
			 printf("\nNúmero de espectadores que acharam o filme ruim: %d", ruim); 	//Número de espectadores que acharam o filme ruim
			 if(meia>inteira){															//Condição qual tipo de entrada foi mais comprada
			 	printf("\n\nHouve maior pagamento de meia entrada.");
			 }else if(inteira>meia){
			 	printf("\n\nHouve maior pagamento de entrada inteira");
			 }else if(meia==inteira){
			 	printf("\n\nO valor de cada tipo de entrada foi equivalente");
			 }
			 
			 printf("\n\nO programa irá finalizar em alguns segundos...");
			 Sleep(30000);	//Função de espera
			 
			break;
			 
	}
	
		//Caso que finaliza o programa e fecha o prompt
			 case 2:
			 	system("cls");						//Comando que limpa o terminal
			 	printf("Programa finalizado.");		//Mensagem que avisa da finalização do programa
			 	exit(0);							//Comando que fecha o terminal
			 
			 break;
			 
			 
			 
			 
		}
	
	
	
	
	
	
	return 0;
}
