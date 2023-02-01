#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

#define TAM 40

typedef struct celula_bin {
	char palavra[TAM];
	int freq, compara, busca;
	struct celula_bin *dir, *esq, *pai;
}noh_bin;

typedef noh_bin *arvore_bin;

typedef struct celula_avl {
	char palavra[TAM];
	int fb, freq, compara, busca;
	struct celula_avl *dir, *esq, *pai;
}noh_avl;

typedef noh_avl *arvore_avl;

int contbin, buscabin;

//Front
void interface() {
	printf("\t======================================================================================================\n");
	printf("\t                                    --CONTADOR DE PALAVRAS--\n");
	printf("\t======================================================================================================\n");
	printf("\n\tSelecione a opção desejada: \n");
	printf("\n\t1 - Criar nova árvore.");
	printf("\n\t2 - Mostrar dados da Árvore Binária.");
	printf("\n\t3 - Mostrar dados da Árvore AVL.");
	printf("\n\t4 - Pesquisar palavra na Árvore Binária.");
	printf("\n\t5 - Pesquisar palavra na Árvore AVL.");
	printf("\n\t0 - Sair.\n\n");
	printf("\t======================================================================================================\n");
	printf("\n\tOpção:");
}

//Back
noh_bin *criacelula(char palavra[TAM]){

	noh_bin *novo = (noh_bin*)malloc(sizeof(noh_bin));
	
	strcpy(novo->palavra, palavra);
	novo->freq = 1;
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	
	return novo;
}//cria a celula e atribui valores

arvore_bin insere (arvore_bin r, noh_bin *novo, char palavra[]) { 
	arvore_bin aux;
	 
    if (r == NULL) return novo;
    if (strcmp(r->palavra, novo->palavra)>0) {
    	contbin++;
		if(r->esq == NULL && r->dir == NULL) novo->pai = r;
    	r->esq = insere (r->esq, novo, palavra);
	}
    else if(strcmp(r->palavra, novo->palavra)<0){
    	contbin++;
    	if(r->esq == NULL && r->dir == NULL) novo->pai = r;
    	r->dir = insere (r->dir, novo, palavra);
	}
	else {
		r->freq++;
		contbin+=2;
	}
    return r;
}//insere a celula criada na arvore

void imprime_bin(arvore_bin r) {
	if(r != NULL) {
		imprime_bin(r->esq);
		printf("\n\tPalavra: %s\n\tOcorrências: %i\n", r->palavra, r->freq);
		imprime_bin(r->dir);
	}
}

char arq[TAM];

arvore_bin escolhearvore(arvore_bin r) {
	FILE *arquivo;
	int Op,i=0;
	char palavra[TAM],caracter;
	
	fflush(stdin);
	printf("\t\nDigite o nome do arquivo com a extensão: ");
	gets(arq);
	
	arquivo = fopen(arq,"r");
	if(arquivo == NULL) {
		printf("\n\tProblemas para abrir o arquivo.\n\n\n");
		system("pause");
		
	}
	else{
		
		do{
				printf("\t\nEscolha o mecanismo de busca e armazenamento: \n");
				printf("\t\n1 - Árvore Binária de Busca. ");
				printf("\t\n2 - Árvore Balanceada AVL");
				printf("\t\n0 - Menu inicial");
				printf("\n\tOpção:");
				scanf("%d",&Op);
			
			switch(Op) {
			case 1:
				//chama arvbin
				contbin = 0;
				while(!feof(arquivo) && !ferror(arquivo)){
					while(!feof(arquivo) && !ferror(arquivo)) {
						caracter = fgetc(arquivo);
						if(caracter == EOF) {
							break;
						}
						if(!isalpha(caracter) || isspace(caracter) || ispunct(caracter)) {
							break;
						}
						else{
							palavra[i] = tolower(caracter);
							i++;
						}
					}
					palavra[i] = '\0';
					if(palavra[0] == '\0') {
						
					}
					else{
						r = insere(r, criacelula(palavra), palavra);
					}
					i=0;
				}
				
				system("cls");
				if(r != NULL){
					printf("\n\tÁrvore binária criada!\n\n");
					system("pause");
					imprime_bin(r);
				}
				else {
					printf("\n\tAlgo deu errado!\n\n");
				}
				printf("\n\tQuantidade de comparações para inserção: %i\n\n",contbin);
				printf("\n\tDeseja fazer outra operação?\n\n");
				system("pause");
				
				break;
			case 2:
				//chama arvavl
				break;
			case 0:
				break;
			default:
				printf("\n\n\tOpção inválida! Digite novamente, por favor.\n\n\n");
				system("pause");
				system("cls");
			}
		}while(Op != 0);
		
	}
	return r;
}

void busca_bin(arvore_bin r, char palavra[]) {
	int i;
	
	if(r == NULL) {
		printf("\n\tPalavra não encontrada!\n\n");
	}
	else {
		if((i = strcmp(r->palavra, palavra)) == 0) {
		buscabin++;
		printf("\n\tPalavra encontrada!\n");
		printf("\n\n\t%sNúmero de ocorrências: %d\n\tNúmero de comparações: %d\n\n",r->palavra,r->freq, buscabin);
		}
		else if(i>0) {
			buscabin++;
			busca_bin(r->esq, palavra);
		}
		else {
			buscabin++;
			busca_bin(r->dir, palavra);
		}
	}
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	int Op;
	arvore_bin abin = NULL;
	FILE *arquivo;
	int Op2,i=0;
	char palavra[TAM],caracter;
	
	
	do{
		interface();
		scanf("%d",&Op);
		
		switch(Op) {
			case 1:
				abin = escolhearvore(abin);
				system("cls");
				break;
			case 2:
				if(abin == NULL) {
					printf("\t\nA árvore está vazia!\n\n");
					system("pause");
					system("cls");
				}
				else {
					imprime_bin(abin);
					printf("\n\tQuantidade de comparações para inserção: %i\n\n",contbin);
					system("pause");
					system("cls");
				}
				break;
			case 3:
				system("cls");
				break;
			case 4:
				if(abin == NULL) {
					printf("\n\tA árvore está vazia!\n\n");
					system("pause");
					system("cls");
				}
				else {
					fflush(stdin);
					printf("\n\tDigite a palavra que deseja buscar: ");
					gets(palavra);
					buscabin = 0;
					busca_bin(abin, palavra);
					system("pause");
					system("cls");
				}
				break;
			case 5:
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
