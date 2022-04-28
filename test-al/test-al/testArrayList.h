
#include <stdio.h>
#include <stdlib.h>

struct arraylist {
	int* vetor;
	int qtdade;
	int tamanho;
};

struct arraylist* inicializar(int tamanho) {
	struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
	lista->vetor = (int*)calloc(tamanho, sizeof(int));
	lista->qtdade = 0;
	lista->tamanho = tamanho;
	return lista;
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
	
	if (posicao >= 0 && posicao < lista->tamanho) {
		return lista->vetor[posicao];
	};

	return 0;
}

void duplicartamanho(struct arraylist* lista) {
	lista->vetor = (int*)realloc(lista->vetor, 2 * lista->tamanho * sizeof(int));
	lista->tamanho *= 2;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
	if (lista->tamanho == lista->qtdade) {
		duplicartamanho(lista);
	}
	lista->vetor[lista->qtdade] = valor;
	lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
	if (posicao >= 0 && posicao <= lista->qtdade) {
		if (lista->tamanho == lista->qtdade) {
			duplicartamanho(lista);
		}
		for (int i = lista->qtdade; i > posicao; i--) {
			lista->vetor[i] = lista->vetor[i - 1];
		}
		lista->vetor[posicao] = valor;
		lista->qtdade++;
	}
}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
	if (posicao >= 0 && posicao < lista->qtdade) {
		lista->vetor[posicao] = valor;
	};
}

void removerElementoNoFim(struct arraylist* lista) {
	lista->qtdade--;
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
	if (posicao >= 0 && posicao < lista->qtdade) {
		while (posicao < lista->qtdade - 1) {
			lista->vetor[posicao] = lista->vetor[posicao + 1];
			posicao++;
		}
		lista->qtdade--;
	}
}

void exibirLista(struct arraylist* lista) {
	printf("[");
	for (int i = 0; i < lista->qtdade; i++) {
		printf("%d", lista->vetor[i]);
		if (i < lista->qtdade - 1) {
			printf(", ");
		}
	}
	printf("]");
}


