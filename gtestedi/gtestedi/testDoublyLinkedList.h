#pragma once
#include <stdio.h>
#include <stdlib.h>

	struct no {
		int valor;
		struct no* prox;
		struct no* ante;
	};

	struct doublylinkedlist {
		//primiro nó da lista
		struct no* cabeca;
		struct no* cauda;
		int tamanho;
	};

	struct doublylinkedlist* inicializar() {
		//alocação do início da lista
		struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
		//iniciando uma lista vazia
		lista->cabeca = NULL;
		lista->cauda = NULL;
		lista->tamanho = NULL;
		return lista;
	}

	struct no* alocarNovoNo(int valor)
	{
		//alocando novo espaço de memoria para o nó
		struct no* novoNo = (struct no*)malloc(sizeof(struct no));
		//atribuindo valor do nó
		novoNo->valor = valor;
		//nó apontando para espaço nulo
		novoNo->prox = NULL;
		novoNo->ante = NULL;
		return novoNo;
	}

	void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor) {
		//alocndo novo vetor 
		struct no* noInicio = alocarNovoNo(valor);
		//caso a lista esteja vazia
		if (lista->cabeca == NULL) {
			lista->cabeca = noInicio;
			lista->cauda = noInicio;
		}
		//caso a lista possua elementos
		else {
			struct no *aux = NULL;

			noInicio->prox = lista->cabeca;
			lista->cabeca->ante = noInicio->prox;
			lista->cabeca = noInicio;
		}
		//registro de aumento da lista
		lista->tamanho++;
	}


	void inserirElementoNoFim(struct doublylinkedlist* lista, int valor) {
		//alocndo novo vetor 
		struct no *noFim = alocarNovoNo(valor);
		//caso a lista esteja vazia
		if (lista->cabeca == NULL) {
			lista->cabeca = noFim;
			lista->cauda = noFim;
		}
		//caso a lista possua elementos
		else {
			lista->cauda->prox = noFim;
			noFim->ante = lista->cauda;
			lista->cauda = noFim;


		}
		//registro de aumento da lista
		lista->tamanho++;
	}

	int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
		//verificar se a posição selecionada existe dentro da lista
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

	class testDoublyLinkedList
	{
	};


