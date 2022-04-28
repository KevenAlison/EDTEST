#pragma once
#include <stdio.h>
#include <stdlib.h>

	struct no {
		int valor;
		struct no* prox;
		struct no* ante;
	};

	struct doublylinkedlist {
		//primiro n� da lista
		struct no* cabeca;
		struct no* cauda;
		int tamanho;
	};

	struct doublylinkedlist* inicializar() {
		//aloca��o do in�cio da lista
		struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
		//iniciando uma lista vazia
		lista->cabeca = NULL;
		lista->cauda = NULL;
		lista->tamanho = NULL;
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

	class testDoublyLinkedList
	{
	};


