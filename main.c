/*Síntese
Objetivo: Fazer um CRUD de produtos utilizando vetores e registro sem função;
Autor: Emanoel Roberto Marques da Silva;
Data da ultima modificação: 06/03/2019;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_PRODUTOS 10

struct cadastro{
	char nome[20];
	float preco;
	int codigo;
};

int main(int argc, char *argv[]) {
 struct cadastro produtos[QTD_PRODUTOS],backup[QTD_PRODUTOS];
 int contador=0,buscaProdutos,opcao,i,flag=0,flagBackup=0,contadorBackup=0;
 
 //ciclo do menu principal
 do{
 	printf("		Menu Principal\n\n1- Verificar os produtos cadastrados.\n2- Cadastrar novo produto.\n3- Buscar um produto cadastrado.\n4- Excluir um produto.\n5- Alterar um produto.\n6- Salvar Backup.\n7- Restaurar Backup Salvo.\n0- Sair.\n");
	scanf("\n%d",&opcao);
	switch(opcao){
		system("cls");
		case 1:{
			system("cls");
			printf("Codigo		Descricao		Preco\n");
			for(i=0;i<contador;i++){
				printf("%d		%s			R$%2.f\n",produtos[i].codigo,produtos[i].nome,produtos[i].preco);
			}
			system("pause");
			break;
		}
		case 2:{
			//cadastro de produtos
			if(contador<QTD_PRODUTOS){
				system("cls");
				fflush(stdin);
				printf("Digite o nome do produto: ");
				gets(produtos[contador].nome);
				do{
					flag=0;
					printf("Digite o Codigo do Produto: ");	
					scanf("%d",&produtos[contador].codigo);
					for(i=0;i<contador;i++){
						if(produtos[contador].codigo == produtos[i].codigo){
							system("cls");
							printf("\nCodigo ja cadastrado no sistema, digite um codigo valido ou altere o produto ja cadastrado.\n");
							flag=1;
						}
					}
				}while(flag==1);
				printf("Digite o Valor do Produto: ");	
				scanf("%f",&produtos[contador].preco);
				contador++;	
				printf("Produto Cadastrado com sucesso!\n");
				system("pause");
				system("cls");
			}else{
				system("cls");
				printf("\nNumero maximo de produtos cadastrados, Exclua algum produto para poder continuar a incluir novos produtos\n");
			}
			break;
		}
		case 3:{
			//busca de produtos
			printf("Digite o codigo do produto a ser buscado: ");
			scanf("%d",&buscaProdutos);
			for(i=0;i<contador;i++){
				if(buscaProdutos == produtos[i].codigo){
					printf("Produto encontrado\nCodigo: %d\nDescricao: %s\nPreco: %2.f\n",produtos[i].codigo,produtos[i].nome,produtos[i].preco);
					system("pause");
					system("cls");
					flag=1;
				}
			}
			if(flag==0){
				printf("Codigo digitado nao pertence a um produto cadastrado.\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 4:{
			//excluir um produto
			system("cls");
			printf("Digite o codigo do produto a ser excluido: ");
			scanf("%d",&buscaProdutos);
			for(i=0;i<contador;i++){
				if(buscaProdutos == produtos[i].codigo){
					produtos[i].codigo=produtos[contador-1].codigo;
					strcpy(produtos[i].nome,produtos[contador-1].nome);
					produtos[i].preco=produtos[contador-1].preco;
					printf("\nProduto excluido com sucesso\n");
					contador--;
					system("pause");
					system("cls");
					flag=1;
					
				}
			}
			if(flag==0){
				printf("Codigo digitado nao pertence a um produto cadastrado.\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 5:{
			//alterar nome e preço de um produto
			system("cls");
			printf("Digite o codigo do produto a ser alterado: ");
			scanf("%d",&buscaProdutos);
			for(i=0;i<contador;i++){
				if(buscaProdutos == produtos[i].codigo){
					fflush(stdin);
					printf("\nDigite o nome do produto: ");
					gets(produtos[i].nome);
					printf("\nDigite o preco do produto: ");
					scanf("%f",&produtos[i].preco);
					i=contador;
				}
				printf("\nProduto alterado com sucesso\n");
				system("pause");
				system("cls");
				flag=1;
			}
			if(flag==0){
				printf("Codigo digitado nao pertence a um produto cadastrado.\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 6:{
			//Backup
			for(i=0;i<contador;i++){
				backup[i].codigo=produtos[i].codigo;
				strcpy(backup[i].nome,produtos[i].nome);
				backup[i].preco=produtos[i].preco;
			}
			system("cls");
			contadorBackup=contador;
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
						for(i=0;i<contador;i++){
							produtos[i].codigo=backup[i].codigo;
							strcpy(produtos[i].nome,backup[i].nome);
							produtos[i].preco=backup[i].preco;
						}
						contador=contadorBackup;
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
		case 0:{
			//mensagem de término
			system("cls");
			printf("Aplicacao finalizada com sucesso!");
			break;
		}
		default:{
			//mensagem de opção inválida
			system("cls");
			printf("Opcao invalida, digite uma opcao valida.\n\n");
			break;
		}
	}
}while(opcao!=0);
	return 0;
}
