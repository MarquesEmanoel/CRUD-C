/*Síntese
   Objetivo: CRUD de produtos utilizando todos os conhecimentos aprendidos até a prova P1.
   Autor: Emanoel Roberto Marques da Silva.
   Data: 29/04/2019;
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 50

struct produto{
	int cod;
	char nome[MAX];
	float preco;	
};

int menuprincipal(void);
void listarprod(struct produto prod[],int);
void mostraprod(struct produto vet[],int cod);
int buscaseq(struct produto vet[], int tamanho, int chave);
int recebecod();
void incluiprod(struct produto prod[],int *local);
void excluiprod(struct produto prod[],int *local);

int main(int argc, char *argv[]) {
	struct produto produtos[MAX],backup[MAX];
	int qtdprod=0,opcao,flag=0,codbusca,i,contadorBackup,flagBackup;
	setlocale(LC_ALL,"Portuguese");
	do{
		opcao=menuprincipal();
		switch(opcao){
			case 1:{
				listarprod(produtos,qtdprod);
				break;
			}
			case 2:{
				system("CLS");
				printf("--------------------Busca-----------\n");
				codbusca=recebecod();
				flag=buscaseq(produtos,qtdprod,codbusca);
				if(flag == -1){
					system("CLS");
					printf("Código buscado não encontrado\n");
				}else{
					mostraprod(produtos,flag);
				}
				break;
			}
			case 3:{
				produtos[qtdprod].cod=recebecod();
				incluiprod(produtos,&qtdprod);
				break;
			}
			case 4:{
				system("CLS");
				printf("ALTERAÇÃO\n");
				codbusca=recebecod();
				flag=buscaseq(produtos,qtdprod,codbusca);
				if(flag == -1){
					system("CLS");
					printf("Código buscado não encontrado\n");
				}else{
					incluiprod(produtos,&flag);
				}	
				break;
			}
			case 5:{
				system("CLS");
				printf("Exclusão\n");
				codbusca=recebecod();
				flag=buscaseq(produtos,qtdprod,codbusca);
				if(flag == -1){
					system("CLS");
					printf("Código buscado não encontrado\n");
				}else{
					excluiprod(produtos,&qtdprod);
				}	
				break;
			}
			case 6:{
			//Backup
			for(i=0;i<qtdprod;i++){
				backup[i].cod=produtos[i].cod;
				strcpy(backup[i].nome,produtos[i].nome);
				backup[i].preco=produtos[i].preco;
			}
			system("cls");
			contadorBackup=qtdprod;
			printf("Backup Concluido!\n");
			flagBackup=1;
			break;
		}
		case 7:{
			//Restaurar Backup
			system("cls");
			printf("Tem certeza que deseja prosseguir com o backup? Todos os arquivos não salvos serao perdidos\n1- Continuar\n2- Retornar ao menu principal\n");
			scanf("%d",&opcao);
			switch(opcao){
				case 1:{
					if(flagBackup==1){
						for(i=0;i<qtdprod;i++){
							produtos[i].cod=backup[i].cod;
							strcpy(produtos[i].nome,backup[i].nome);
							produtos[i].preco=backup[i].preco;
						}
						qtdprod=contadorBackup;
						printf("\nBackup restaurado com sucesso!\n");
					}else{
						system("cls");
						printf("Restauracao nao concluida, nao ha nenhum backup cadastrado atualmente\n");
					}
					break;
				}
				case 2:{
					system("cls");
					printf("Operação cancelada com sucesso\n");
					break;
				}
				default:{
					printf("Opcao invalida!");
					system("pause");
					break;
				}
				}
			break;
		}
		}
	}while(opcao!=0);
	
	return 0;
}

int menuprincipal(void){
	int op;
	printf("	MENU");
	printf("\n1- Listar.");
	printf("\n2- Consultar.");
	printf("\n3- Incluir.");
	printf("\n4- Alterar.");
	printf("\n5- Excluir.");
	printf("\n6- Salvar Backup.");
	printf("\n7- Retomar Ponto Salvo.");
	printf("\n0- Sair.\n");
	scanf("%d",&op);
	if(op>=0 && op<8)
		return op;
	else{
		system("CLS");
		printf("\nOpção inválida.\n");
		return menuprincipal();
	}
}

void listarprod(struct produto prod[],int qt){
	int i;
	if(qt>0){
		printf("\nCódigo			Nome			Preço\n");
		for(i=0;i<qt;i++){
			printf("%d			%s				R$%.2f\n",prod[i].cod,prod[i].nome,prod[i].preco);
		}
	}else
		printf("\nNão há nenhum produto cadastrado atualmente.\n");
}

int buscaseq(struct produto vet[], int tamanho, int chave) {
	int i=0;
	while ((vet[i].cod < chave) && (i < tamanho)) {
		i++;
	}
	if (vet[i].cod == chave){
		return i;
	}else{
		return -1;
	}
}

int recebecod(){
	int i;
	printf("Digite o código: ");
	scanf("%d",&i);
	return i;
}

void mostraprod(struct produto vet[],int cod){
	system("CLS");
	printf("Encontrado\nCódigo: %d\nNome: %s\nPreço:%.2f",vet[cod].cod,vet[cod].nome,vet[cod].preco);
}

void incluiprod(struct produto prod[],int *local){
	fflush(stdin);
	printf("Digite o Nome: ");
	gets(prod[*local].nome);
	printf("Digite o Preço: ");
	scanf("%f",&prod[*local].preco);
	(*local)++;
}

void excluiprod(struct produto prod[],int *local){
	prod[*local] = prod[*local-1];
	(*local)--;
	printf("\nExcluído com sucesso.");
}

