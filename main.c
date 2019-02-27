/*Síntese
Objetivo: Fazer um CRUD de produtos utilizando vetores.
Entrada: Descrição dos Produtos, Códigos dos produtos, preço dos produtos.
Saida: Produtos cadastrados.*/
#include <stdio.h>
#include <stdlib.h>
#define QTD_PRODUTOS 10

int main(int argc, char *argv[]) {
 char descricoes[20][QTD_PRODUTOS];
 int codigos[QTD_PRODUTOS],contador=0,buscaProdutos,opcao,i,flag=0;
 float precos[QTD_PRODUTOS];
 
 //ciclo do menu principal
 do{
 	printf("		Menu Principal\n\n1- Verificar os produtos cadastrados.\n2- Cadastrar novo produto.\n3- Buscar um produto cadastrado.\n4- Excluir um produto.\n5- Alterar um produto.\n0- Sair.\n");
	scanf("\n%d",&opcao);
	switch(opcao){
		system("cls");
		case 1:{
			system("cls");
			printf("Codigo		Descricao		Preco\n");
			for(i=0;i<contador;i++){
				if(codigos[i] != 0){
					printf("%d		%s			R$%2.f\n",codigos[i],descricoes[i],precos[i]);
				}
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
				gets(descricoes[contador]);
				do{
					flag=0;
					printf("Digite o Codigo do Produto: ");	
					scanf("%d",&codigos[contador]);
					if(codigos[contador] == 0){
						printf("O codigo do produto nao pode ser 0.\n");
					}
					for(i=0;i<contador;i++){
						if(codigos[contador] == codigos[i]){
							system("cls");
							printf("\nCodigo ja cadastrado no sistema, digite um codigo valido ou altere o produto ja cadastrado.\n");
							system("cls");
							flag=1;
							system("pause");
						}
					}
				}while(codigos[contador]==0 || flag==1);
				printf("Digite o Valor do Produto: ");	
				scanf("%f",&precos[contador]);
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
				if(buscaProdutos == codigos[i] &&  codigos[i]!=0){
					printf("Produto encontrado\nCodigo: %d\nDescricao: %s\nPreco: %2.f\n",codigos[i],descricoes[i],precos[i]);
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
				if(buscaProdutos == codigos[i]){
					codigos[i]=0;
					printf("\nProduto excluido com sucesso\n");
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
				if(buscaProdutos == codigos[i]){
					fflush(stdin);
					printf("\nDigite o nome do produto: ");
					gets(descricoes[i]);
					printf("\nDigite o preco do produto: ");
					scanf("%f",&precos[i]);
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
