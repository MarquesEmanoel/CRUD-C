/*Síntese
   Objetivo: CRUD de produtos utilizando Lista simplesmente encadeada sem uso de funções.
   Autor: Emanoel Roberto Marques da Silva.
   Data: 08/05/2019;
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 50

typedef struct produto{
	int cod;
	char nome[MAX];
	float preco;
}produto;

typedef struct nod{
	struct nod *prox;
	produto dado;
}nod;

void exclui(nod **lst,int cod){
	struct nod *p,*aux;
	//exclusão de primeiro
	p=*lst;
	if(cod == (*lst)->dado.cod){
		*lst=(*lst)->prox;
		free(p);
		return;
	}else{
		aux=*lst;
		p=(*lst)->prox;
		//exclusão de meio ou fim
		while(p != NULL){
			if(p->dado.cod ==cod){
				printf("a");
				aux->prox=p->prox;
				free(p);
				return;
			}
			aux=p;
			p=p->prox;
		}
	}
	printf("Elemento não existe na lista...");
}

void buscar(nod *lst,int cod){
	nod *p;
	p=lst;
	while(p != NULL){
		if(cod == p->dado.cod){
			printf("Produto Encontrado\nCodigo		Descricao		Preco\n%d		%s			R$%.2f\n",p->dado.cod,p->dado.nome,p->dado.preco);
			return;
		}
		p=p->prox;
	}
	printf("Código buscado não cadastrado.");
}

void listar(nod *lst){
	nod *p;
	p=lst;
	printf("Codigo		Descricao		Preco\n");
	while(p != NULL){
		printf("%d		%s			R$%.2f\n",p->dado.cod,p->dado.nome,p->dado.preco);
		p=p->prox;
	}
}

void alterar(nod **lst,int cod){
	nod *p;
	p=*lst;
	while(p != NULL){
		if(cod == p->dado.cod){
			fflush(stdin);
			printf("Digite o novo nome do produto: ");
			gets(p->dado.nome);
			printf("Digite o novo Valor do Produto: ");
			scanf("%f",&p->dado.preco);
		}
		p=p->prox;
	}
}
void incluir(nod **lst){
	nod *novo,*p;
	novo = malloc(sizeof(nod));
	fflush(stdin);
	printf("Digite o nome do produto: ");
	gets(novo->dado.nome);
	printf("Digite o Codigo do Produto: ");	
	scanf("%d",&novo->dado.cod);
	printf("Digite o Valor do Produto: ");
	scanf("%f",&novo->dado.preco);
	novo->prox=NULL;
	if(*lst == NULL)
		*lst=novo;
	else{
		p=*lst;
		while(p->prox != NULL){
			p=p->prox;	
		}
		p->prox=novo;
	}	
}

void explodir(nod **lista){
	nod *aux;
	aux=*lista;
	*lista=aux->prox;
	while(*lista != NULL){
		free(aux);
		aux = *lista;
		*lista = aux->prox;
	}
	free(aux);
}

int main(void) {
	//lista
	nod *lista=NULL;
	//auxiliares
	nod *novo,*p;
	int opcao,cod;
		
	do{
		printf("	MENU");
		printf("\n1- Listar.");
		printf("\n2- Incluir.");
		printf("\n3- Buscar.");
		printf("\n4- Alterar");
		printf("\n5- Excluir");
		printf("\n0- Sair.\n");
		scanf("%d",&opcao);
		switch(opcao){
		system("cls");
			case 1:{
				//listar
				if(lista != NULL){
					listar(lista);
				}
				system("pause");
				break;
			}
			case 2:{
				//inclusão
				incluir(&lista);
				printf("Produto Cadastrado com sucesso!\n");
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				//busca
				if(lista != NULL){
					p=lista;
					printf("Digite o codigo a ser buscado: ");
					scanf("%d",&cod);
					system("cls");
					buscar(lista,cod);
				}	
				break;
			}
			case 4:{
				//alteração
				if(lista != NULL){
					p=lista;
					printf("Digite o codigo a ser alterado: ");
					scanf("%d",&cod);
					system("cls");
					alterar(&lista,cod);
				}	
				break;
			}
			case 5:{
				//exclusão
				if(lista != NULL){
					p=lista;
					printf("Digite o codigo do produto a ser excluido: ");
					scanf("%d",&cod);
					system("cls");
					exclui(&lista,cod);
				}
			}
		}
	}while(opcao != 0);
	explodir(&lista);
	return 0;
}
