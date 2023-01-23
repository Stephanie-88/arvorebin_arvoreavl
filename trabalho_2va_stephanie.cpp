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
noh_bin *criacelula(char palavra[TAM]){

	noh_bin *novo = (noh_bin*)malloc(sizeof(noh_bin));
	
	strcpy(novo->palavra, palavra);
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	
	return novo;
}//cria a celula e atribui valores

arvore_bin insere (arvore_bin r, noh_bin *novo, char palavra[]) { 
	arvore_bin aux;
	 
    if (r == NULL) return novo;
    if (strcmp(r->palavra, novo->palavra)<0) {
	
		if(r->esq->pai == NULL) r->esq->pai = r;
    	r->esq = insere (r->esq, novo, palavra);
	}
    else if(strcmp(r->palavra, novo->palavra)>0){
    	if(r->dir->pai == NULL) r->dir->pai = r;
    	r->dir = insere (r->dir, novo, palavra);
	}
	else {
		r->freq++;
	}
    return r;
}//insere a celula criada na arvore



char arq[TAM];

void escolhearvore(arvore_bin r) {
	FILE *arquivo;
	int Op;
	char palavra[TAM];
	
	fflush(stdin);
	printf("\t\nDigite o nome do arquivo com a extensão: ");
	gets(arq);
	
	arquivo = fopen(arq,"r");
	if(arq == NULL) {
		printf("Problemas para abrir o arquivo.");
		exit (EXIT_FAILURE);
	}
	else{
		
		do{
				printf("\t\nEscolha o mecanismo de busca e armazenamento: \n");
				printf("\t\n1 - Árvore Binária de Busca. ");
				printf("\t\n2 - Árvore Balanceada AVL");
				printf("\t\n0 - Menu inicial");
			
			switch(Op) {
			case 1:
				//chama arvbin
				
				while((palavra = fgetc(arquivo)) =! EOF) {
					r = insere(r, criacelula, palavra);
				}
				break;
			case 2:
				//chama arvavl
				break;
			default:
				printf("\n\n\tOpção inválida! Digite novamente, por favor.\n\n\n");
				system("pause");
				system("cls");
			}
		}while(Op != 0);
		
	}
	
	
	
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
