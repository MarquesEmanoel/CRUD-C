/*Síntese
Objetivo: Um programa que grave até 10 produtos com código numérico.
Entrada: Produtos, Código dos produtos.
Saida: Lista de produtos*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
 char Produtos[20];
 int codigo,contador=0,numProdutos,opcao=0;
 //ciclo do menu principal
 while(opcao!=3){
 	printf("		Menu Principal\n1- Verificar os produtos cadastrados.\n2- Cadastrar novo produto.\n3- Sair.\n");
	 scanf("\n%d",&opcao);
	 //display dos produtos
		if(opcao==1){
			system("cls");
			printf("%s",Produtos);
		}else if(opcao==2){
			//cadastro de produtos
			system("cls");
			printf("Digite o nome do produto: ");
			scanf("%s",&Produtos[contador+1]);
			printf("\n\n\n%s\n\n\n",Produtos);	
			contador++;	
			printf("Produto Cadastrado com sucesso");
		}else if(opcao != 1 && opcao !=2 && opcao!=3){
			system("cls");
			printf("Opção inválida, digite uma opção válida.\n\n");
		}
}
	return 0;
}
