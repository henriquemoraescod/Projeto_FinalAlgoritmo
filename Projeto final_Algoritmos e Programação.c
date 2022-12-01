//Integrantes:
//Henrique Moraes Farias, UC22200106, An�lise e Desenvolvimento de Sistemas
//Larissa Lorraine Ferreira Barbosa, UC22200367, An�lise e Desenvolvimento de Sistemas
//Stela Sousa Alves, UC22200017, Ci�ncia da Computa��o

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
	
	setlocale(LC_ALL, "PORTUGUESE"); //Setando os caracteres para o padr�o portugu�s
	menu:
		printf("\tCinema de Bras�lia\n\n1. An�lise de sess�es\n2. Sair\n\nDigite a op��o desejada: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1: 
			//Caso das sess�es
			system("cls");
			printf("Digite a quantidade de sess�es: ");
			scanf("%d", &quantidadeSessoes[i]);
			//Valid��o da quantidade de sess�es 
			if(quantidadeSessoes[i] != 2){
				do{
					system("cls"); //Limpeza de terminal
					printf("Quantidade inv�lida, �nica quantidade aceita: 2.\nDigite a quantidade de sess�es: ");
					scanf("%d", &quantidadeSessoes[i]);
				}while(quantidadeSessoes[i] != 2);
			}
			
			//For que incia o cadastro de informa��es de cada sess�o
			for(i=0;i<quantidadeSessoes[i];i++){
				system("cls"); //Comando que limpa a tela
				printf("Digite aqui o nome do filme da sess�o %d: ", i+1);
				fflush(stdin); //Comando que limpa o buffer do teclado
				fgets(nomeFilme[i], 50, stdin);
				
				system("cls");
				printf("Digite aqui a quantidade de pessoas que assistiram ao filme %d: ", i+1);
				scanf("%d", &quantidadePessoas[i]);
				//Valida��o da quantidade de espectadores
				if(quantidadePessoas[i]<10){
					do{
						system("cls");  //Limpeza de terminal
						printf("Quantidade inv�lida, min�mo de 10 espectadores.\nDigite aqui a quantidade de pessoas que assistiram ao filme %d: ", i+1);
						scanf("%d", &quantidadePessoas[i]);
					}while(quantidadePessoas[i]<10);
				}				
			
			//For para cadastro de informa��es individuais
			for(j=0;j<quantidadePessoas[i];j++){
				system("cls");  //Limpeza de terminal
				printf("Sexo do espectador %d\nMasculino: M\nFeminino: F\nDigite a op��o desejada: ", j+1);
				fflush(stdin);
				scanf("%s", &sexo[i]);
				
			//Contando a quantidade de espectadores de cada sexo
				if(strcmp(sexo[i], "M")==0){
					masculino++;
				}else if(strcmp(sexo[i], "F")==0){
					feminino++;
				}
			//Valida��o do g�nero do espectador
				if(strcmp(sexo[i], "M")!=0 && strcmp(sexo[i], "F")!= 0){
					do{
					system("cls");  //Limpeza de terminal
					printf("Op��o inv�lida, utilize 'M' ou 'F'.\nSexo do espectador %d\nMasculino: M\nFeminino: F\nDigite a op��o desejada: ");
					scanf("%s", &sexo[i]);
			//Contando a quantidade de espectadores de cada g�nero
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
			//Contagem do n�mero de pessoas de cada faixa et�ria
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
				
			//Valida��o da idade do espectador
				if(idadeEspectador[i]<3 || idadeEspectador[i] > 100){
					do{
					system("cls");  //Limpeza de terminal
					printf("Idade inv�lida, coloque um n�mero entre 3 e 100.\nDigite aqui a idade do espectador %d: ", j+1);
					scanf("%d", &idadeEspectador[i]);
					}while(idadeEspectador[i]<3 || idadeEspectador[i]>100);
				}
				
				system("cls");  //Limpeza de terminal
				printf("Qual foi o tipo de entrada do espectador?\n-Meia entrada(R$25,00): Meia\n-Entrada inteira(R$50,00): Inteira\nDigite aqui o tipo de entrada do espectador %d: ", j+1);
				scanf("%s", &entradaEspectador[i]);
				
			//Contagem da arrecada��o de cada tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")==0 ){
					meia = meia+25;
				}else if(strcmp(entradaEspectador[i], "Inteira")==0){
					inteira = inteira+50;
				}
				
			//Valida��o do tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")!= 0 && strcmp(entradaEspectador[i], "Inteira") != 0){
					do{
						system("cls");  //Limpeza de terminal
						printf("Op��o inv�lida.\nQual foi o tipo de entrada do espectador?\n-Meia entrada(R$25,00): Meia\n-Entrada inteira(R$50,00): Inteira\nDigite aqui o tipo de entrada do espectador %d: ", j+1);
						scanf("%s", &entradaEspectador);
			//Contagem da arrecada��o de cada tipo de entrada
				if(strcmp(entradaEspectador[i], "Meia")==0){
					meia = meia+25;
				}else if(strcmp(entradaEspectador[i], "Inteira")==0){
					inteira =  inteira+50;
				}
					}while(strcmp(entradaEspectador[i], "Meia") != 0 && strcmp(entradaEspectador[i], "Inteira") != 0);
				}
				valorSessao = inteira + meia;
				
			//Nova funcionalidade: Avalia��o do espectador sobre o filme 
					system("cls");
					printf("Como o espectador avaliou o filme?\n-Um filme agrad�vel: Bom\n-Um filme desagrad�vel: Ruim\nDigite a op��o desejada: ");
					scanf("%s", &avaliacaoFilme[i]);
			//Contagem de opini�es		
					if(strcmp(avaliacaoFilme[i], "Bom")==0){
						bom++;
					}else if(strcmp(avaliacaoFilme[i], "Ruim")==0){
						ruim++;
					}
			//Valida��o da nova funcionalidade
					if(strcmp(avaliacaoFilme[i], "Bom")!= 0 && strcmp(avaliacaoFilme[i], "Ruim")!=0){
						do{
							system("cls");
							printf("Op��o inv�lida.\nComo o espectador avaliou o filme?\n-Um filme agrad�vel: Bom\n-Um filme desagrad�vel: Ruim\nDigite a op��o desejada: ");
							scanf("%s", &avaliacaoFilme);
						}while(strcmp(avaliacaoFilme[i], "Bom")!= 0 && strcmp(avaliacaoFilme[i], "Ruim")!=0);
					}
					
					
					
					
					
			}
			
			  		 //Impress�o das informa��es
			 
			 system("cls");																//Limpeza do buffer do teclado
			 printf("Nome do filme: %s", nomeFilme);									//Nome do filme
			 printf("\nN�mero de espectadores do sexo masculino: %d", masculino);		//N�mero de espectadores do g�nero masculino
			 printf("\nN�mero de espectadores do sexo feminino: %d", feminino);			//N�mero de espectadores do g�nero feminino
			 printf("\n\nValor arrecadado com as inteiras: R$%d", inteira);				//Valor arrecadado com a entrada inteira 
			 printf("\nValor arrecadado com as meias: R$%d", meia);						//Valor arrecadado com a meia entrada
			 printf("\nValor total arrecadado: R$%d", valorSessao); 					//Valor total arrecadado com o filme
			 printf("\n\nN�mero de homens maiores de idade: %d", homemMaior);			//N�mero de espectadores homens maiores de idade
			 printf("\nN�mero de mulheres maiores de idade: %d", mulherMaior);			//N�mero de espectadores mulheres maiores de idade
			 printf("\n\nN�mero de crian�as que assistiram: %d", crianca);				//N�mero de crian�as que assistiram ao filme
			 printf("\nN�mero de adolescentes que assistiram: %d", adolescente);		//N�mero de adolescentes que assistira, ao filme
			 printf("\nN�mero de adultos que assistiram: %d", adulto);					//N�mero de adultos que assistiram ao filme 
			 printf("\nN�mero de idosos que assistiram ao filme: %d", idoso);			//N�mero de idosos que assistiram ao filme
			 printf("\n\nN�mero de espectadores que acharam o filme bom: %d", bom); 	//N�mero de espectadores que acharam o filme bom
			 printf("\nN�mero de espectadores que acharam o filme ruim: %d", ruim); 	//N�mero de espectadores que acharam o filme ruim
			 if(meia>inteira){															//Condi��o qual tipo de entrada foi mais comprada
			 	printf("\n\nHouve maior pagamento de meia entrada.");
			 }else if(inteira>meia){
			 	printf("\n\nHouve maior pagamento de entrada inteira");
			 }else if(meia==inteira){
			 	printf("\n\nO valor de cada tipo de entrada foi equivalente");
			 }
			 
			 printf("\n\nO programa ir� finalizar em alguns segundos...");
			 Sleep(30000);	//Fun��o de espera
			 
			break;
			 
	}
	
		//Caso que finaliza o programa e fecha o prompt
			 case 2:
			 	system("cls");						//Comando que limpa o terminal
			 	printf("Programa finalizado.");		//Mensagem que avisa da finaliza��o do programa
			 	exit(0);							//Comando que fecha o terminal
			 
			 break;
			 
			 
			 
			 
		}
	
	
	
	
	
	
	return 0;
}
