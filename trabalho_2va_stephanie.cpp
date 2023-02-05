#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

#define TAM 40

typedef struct celula_bin {
	char palavra[TAM];
	int freq;
	struct celula_bin *dir, *esq, *pai;
}noh_bin;

typedef noh_bin *arvore_bin;

typedef struct celula_avl {
	char palavra[TAM];
	int altura, freq;
	struct celula_avl *dir, *esq, *pai;
}noh_avl;

typedef noh_avl *arvore_avl;

int contbin, buscabin, contavl, buscaavl;

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

void interfacearvore() {
	printf("\t\nSelecione a opção desejada: \n");
	printf("\t\n1 - Árvore Binária de Busca. ");
	printf("\t\n2 - Árvore Balanceada AVL");
	printf("\t\n0 - Menu inicial");
	printf("\n\tOpção:");
}

//Back

//Árvore binária-----------------------------------------------------
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

arvore_bin criabin(arvore_bin r) {
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
		printf("\n\n\tPalavra: %s\n\tNúmero de ocorrências: %d\n\tNúmero de comparações: %d\n\n",r->palavra,r->freq, buscabin);
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
//Árvore binária-----------------------------------------------------

//Árvore AVL---------------------------------------------------------

void imprime_avl(arvore_avl r) {
	if(r != NULL) {
		imprime_avl(r->esq);
		printf("\n\tPalavra: %s\n\tOcorrências: %i\n", r->palavra, r->freq);
		imprime_avl(r->dir);
	}
}

noh_avl *criacelulaavl(char palavra[TAM]){

	noh_avl *novo = (noh_avl*)malloc(sizeof(noh_avl));
	
	strcpy(novo->palavra, palavra);
	novo->freq = 1;
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->altura = 0;
	
	return novo;
}//cria a celula e atribui valores

int maior(int alt1, int alt2) {
	return (alt1>alt2)? alt1 : alt2;
}

int alturanoh(noh_avl *noh) {
	if(noh == NULL) {
		return -1;
	}
	else {
		return noh->altura;
	}
}

int fb(noh_avl *noh) {
	if(noh) {
		return (alturanoh(noh->esq)-alturanoh(noh->dir));
	}
	else {
		return 0;
	}
}

noh_avl *rotacaoesq(noh_avl *noh) {
	noh_avl *novaraiz, *filho;
	
	novaraiz = noh->dir;
	filho = novaraiz->esq;
	novaraiz->esq = noh;
	noh->dir = filho;
	
	noh->altura = maior(alturanoh(noh->esq), alturanoh(noh->dir)) + 1;
	novaraiz->altura = maior(alturanoh(novaraiz->esq), alturanoh(novaraiz->dir) + 1);
	
	return novaraiz;
}

noh_avl *rotacaodir(noh_avl *noh) {
	noh_avl *novaraiz, *filho;
	
	novaraiz = noh->esq;
	filho = novaraiz->dir;
	novaraiz->dir = noh;
	noh->esq = filho;
	
	noh->altura = maior(alturanoh(noh->esq),alturanoh(noh->dir)) + 1;
	novaraiz->altura = maior(alturanoh(novaraiz->esq), alturanoh(novaraiz->dir) + 1);
	
	return novaraiz;
}

noh_avl *balancear(noh_avl *noh) {
	int fatb = fb(noh);
	
	if(fatb < -1) {
		noh = rotacaoesq(noh);
	}
	else if(fatb > 1) {
		noh = rotacaodir(noh);
	}
	
	return noh;
}

arvore_avl insereavl(arvore_avl r,noh_avl *novo, char palavra[]) {
    if (r == NULL) return novo;
    if (strcmp(r->palavra, novo->palavra)>0) {
    	contavl++;
		if(r->esq == NULL && r->dir == NULL) novo->pai = r;
    	r->esq = insereavl(r->esq, novo, palavra);
	}
    else if(strcmp(r->palavra, novo->palavra)<0){
    	contavl++;
    	if(r->esq == NULL && r->dir == NULL) novo->pai = r;
    	r->dir = insereavl(r->dir, novo, palavra);
	}
	else {
		r->freq++;
		contavl+=2;
	}
	r->altura = maior(alturanoh(r->esq),alturanoh(r->dir)) + 1;
	
	r = balancear(r);
	
    return r;
}//insere a celula criada na arvore

void busca_avl(arvore_avl r, char palavra[]) {
	int i;
	
	if(r == NULL) {
		printf("\n\tPalavra não encontrada!\n\n");
	}
	else {
		if((i = strcmp(r->palavra, palavra)) == 0) {
		buscaavl++;
		printf("\n\tPalavra encontrada!\n");
		printf("\n\n\tPalavra: %s\n\tNúmero de ocorrências: %d\n\tNúmero de comparações: %d\n\n",r->palavra,r->freq, buscabin);
		}
		else if(i>0) {
			buscaavl++;
			busca_avl(r->esq, palavra);
		}
		else {
			buscaavl++;
			busca_avl(r->dir, palavra);
		}
	}
}

arvore_avl criaavl(arvore_avl r) {
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
				r = insereavl(r, criacelulaavl(palavra), palavra);
			}
			i=0;
			}
				
			system("cls");
			if(r != NULL){
				printf("\n\tÁrvore binária criada!\n\n");
				system("pause");
				imprime_avl(r);
			}
			else {
				printf("\n\tAlgo deu errado!\n\n");
			}
			printf("\n\tQuantidade de comparações para inserção: %i\n\n",contavl);
			printf("\n\tDeseja fazer outra operação?\n\n");
			system("pause");
		
	}
	return r;
}

//Árvore AVL---------------------------------------------------------

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	int Op, Op2;
	arvore_bin abin = NULL;
	arvore_avl aavl = NULL;
	FILE *arquivo;
	int i=0;
	char palavra[TAM],caracter;
	
	
	do{
		interface();
		scanf("%d",&Op);
		
		switch(Op) {
			case 1:
				do {
					system("cls");
					interfacearvore();
					scanf("%d",&Op2);
					switch(Op2) {
						case 1:
							abin = NULL;
							abin = criabin(abin);
							break;
						case 2:
							aavl = NULL;
							aavl = criaavl(aavl);
							break;
						case 0:
							break;
						default:
							printf("\n\n\tOpção inválida! Digite novamente, por favor.\n\n\n");
							system("pause");
							system("cls");
					}
				}while(Op2 != 0);
				
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
				if(aavl == NULL) {
					printf("\t\nA árvore está vazia!\n\n");
					system("pause");
					system("cls");
				}
				else {
					imprime_avl(aavl);
					printf("\n\tQuantidade de comparações para inserção: %i\n\n",contavl);
					system("pause");
					system("cls");
				}
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
				if(aavl == NULL) {
					printf("\n\tA árvore está vazia!\n\n");
					system("pause");
					system("cls");
				}
				else {
					fflush(stdin);
					printf("\n\tDigite a palavra que deseja buscar: ");
					gets(palavra);
					buscaavl = 0;
					busca_avl(aavl, palavra);
					system("pause");
					system("cls");
				}
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
