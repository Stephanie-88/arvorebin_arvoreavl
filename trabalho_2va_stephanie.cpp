#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

#define TAM 30

typedef struct celula_bin {
	char palavra[TAM];
	int freq;
	struct celula_bin *dir, *esq, *pai;
}noh_bin;

typedef noh_bin *arvore_bin;

typedef struct celula_avl {
	char palavra[TAM];
	int fb, freq;
	struct celula_avl *dir, *esq, *pai;
}noh_avl;

typedef noh_avl *arvore_avl;

//Front
void interface() {
	printf("\t======================================================================================================\n");
	printf("\t                                    --CONTADOR DE PALAVRAS--\n");
	printf("\t======================================================================================================\n");
	printf("\n\tSelecione a opção desejada: \n");
	printf("\n\t1 - Abrir novo arquivo.");
	printf("\n\t3 - Mostrar dados da Árvore Binária.");
	printf("\n\t4 - Mostrar dados da Árvore AVL.");
	printf("\n\t0 - Sair.\n\n");
	printf("\t======================================================================================================\n");
	printf("\n\tOpção:");
}

//Back





void learquivo() {
	char arq[TAM];
	
	fflush(stdin);
	printf("\t\nDigite o nome do arquivo: ");
	gets(arq);
	printf("\t\nEscolha o mecanismo de busca e armazenamento: ");
	
	
}


int main() {
	setlocale(LC_ALL,"Portuguese");
	
	int Op;
	arvore_bin abin = NULL;
	
	
	do{
		interface();
		scanf("%d",&Op);
		
		switch(Op) {
			case 1:
				system("cls");
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				system("cls");
				break;
			case 0:
				printf("\n\n\tEncerrando programa...\n\n\n");
				system("pause");
				break;
			default:
				printf("\n\n\tOpção inválida! Digite novamente, por favor.\n\n\n");
				system("pause");
				system("cls");
		}
		
	}while(Op!=0);
	
	
	return 0;
}
