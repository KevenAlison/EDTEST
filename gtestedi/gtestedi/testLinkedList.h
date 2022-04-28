#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no* prox;
};

struct linkedlist {
	//primiro n� da lista
	struct no* cabeca;
	int tamanho;
};

struct linkedlist* inicializar(){
	//aloca��o do in�cio da lista
	struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	//iniciando uma lista vazia
	lista->cabeca = NULL;
	lista->tamanho = 0;
	return lista; 
}

struct no* alocarNovoNo(int valor)
{
	//alocando novo espa�o de memoria para o n�
	struct no* novoNo = (struct no*)malloc(sizeof(struct no));
	//atribuindo valor do n�
	novoNo->valor = valor;
	//n� apontando para espa�o nulo
	novoNo->prox = NULL;
	return novoNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
	//alocndo novo vetor 
	struct no *noFim = alocarNovoNo(valor);
	//alocando um espa�o de memoria auxiliar
	struct no *aux = NULL;
	//caso a lista esteja vazia
	if (lista->cabeca == NULL){
		lista->cabeca = noFim;
	} 
	//caso a lista possua elementos
	else {
		//o n�o auxiliar recebe os atributos do n� "cabe�a"
		aux = lista->cabeca;
		//varrer a lista at� que achar um n� que aponte para um espa�o vazio(ultimo n�)
		while (aux->prox != NULL){
			//navegando entre os n�s
			aux = aux->prox;
		}
		//o n� auxiliar agora compreeende o �ltimo n� da lista que aponta para um espa�o de mem�ria vazio ond o n� "noFim" ser� armazenado
		aux->prox = noFim;
	}
	//registro de aumento da lista
	lista->tamanho++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
	//alocndo novo vetor 
	struct no* noInicio = alocarNovoNo(valor);
	//caso a lista esteja vazia
	if (lista->cabeca == NULL) {
		lista->cabeca = noInicio;
	}
	//caso a lista possua elementos
	else {
		//o vetor para onde o novo n� apoonta recebe os atributos do n� cabe�a
		noInicio->prox = lista->cabeca;
		//o n� cabe�a recebe os atributos do novo vetor
		lista->cabeca = noInicio;
	}
	//registro de aumento da lista
	lista->tamanho++;
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
	//verificar se a posi��o selecionada existe dentro da lista
	if (posicao >= 0 && lista->tamanho >= posicao) {
		//criar no auxiliar para peercorrer pela lista
		struct no* aux = lista->cabeca;
		//variavel de contagem 
		int count = 0;

		while (count < posicao) {
			aux = aux->prox;
			count++;
		}
		return aux->valor;
	}
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
	//caso a lista esteja vazia
	if (posicao >= 0 && posicao <= lista->tamanho) {
		if (posicao == 0) {
			inserirElementoNoInicio(lista, valor);
		}
		else if (lista->cabeca != NULL) {
			//alocando novo no
			struct no* noNovo = alocarNovoNo(valor);
			//alocando no auxiliar
			struct no* aux = lista->cabeca;
			//variavel de contagem 
			int count = 0;
			for (int i = 1; i < posicao; i++) {
				aux = aux->prox;
			}
			noNovo->prox = aux->prox;
			aux->prox = noNovo;

			//registro de aumento da lista
			lista->tamanho++;
		}
	}
}

void removerElementoEmPosicao(struct linkedlist *lista, int posicao){
	if (posicao >= 0 && posicao < lista->tamanho){
		if (posicao == 0){
			lista->cabeca = lista->cabeca->prox;
		}
		else if (posicao == (lista->tamanho - 1)){
			no *aux = lista->cabeca;
			while (aux->prox->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = NULL;
		}
		else{
			if (lista->cabeca != NULL){
				no *aux = lista->cabeca;
				for (int i = 1; i < posicao; i++){
					aux = aux->prox;
				}
				aux->prox = aux->prox->prox;
			}
		}
	}
	lista->tamanho--;
}

void imprimirLista(struct linkedlist* lista) {
	//usamos o aux para percorrer a lista
	if (lista->cabeca != NULL) {
		struct no* aux = lista->cabeca;
		//navega partindo da cabe�a at� chegar NULL
		printf("[");
		do {
			printf("%d", aux->valor);
			aux = aux->prox;
			if (aux != NULL) {
				printf(", ");
			}
		} while (aux != NULL);
		printf("]");
	}
	else {
		printf("A lista est� vazia!");
	}
}

class testLinkedList
{
};

